#include "AnalyseNDBCTxt.h"
#include <math.h>

AnalyseNDBCTxt::AnalyseNDBCTxt()
{

}

AnalyseNDBCTxt::~AnalyseNDBCTxt()
{

}

// 从字符串中找到数字
list<string> AnalyseNDBCTxt::findNum(string str)
{
    int k = str.size();
    list<string> numList;
    string result = "";
    int n = 0;
    while(n<k)
    {
        if(isNum(str[n]))
        {
            while(n<k && isNum(str[n++]))
                result += str[n-1];
            if(!result.empty())
            {
                numList.push_back(result);
                result = "";
                n=n-1;
            }
        }
        n++;
    }
    list<string> timeList;
    for(auto iter=numList.begin(); iter!=numList.end(); iter++)
    {
        string tempNum = *iter;
        if(tempNum.size()>4)
            timeList.push_back(tempNum);
    }
    return timeList;
}

//判断是否是数字
bool AnalyseNDBCTxt::isNum(char num)
{
    return (num>='0' && num<='9');
}

//************************************
// 函数名称: splitStringToVector
// 函数说明：给定一个字符和一个字符串分割该字符串
// 返 回 值: int
// 参    数: vector<string> &splitVector
// 参    数: string splitStr
// 参    数: char ch
// 作    者：WTB
// 作成日期：2018/3/14
// 修改记录：
//************************************
int AnalyseNDBCTxt::splitStringToVector(vector<string> &splitVector, string splitStr, char ch)
{
    if (splitStr.size() > 0)
    {
        int pos,lastpos;
        lastpos = 0;
        pos = 0;
        do
        {
            pos = splitStr.find(ch,lastpos);
            if (pos != string::npos)
            {
                splitVector.push_back(splitStr.substr(lastpos,pos-lastpos));
                lastpos = pos+1;
            }
        } while (pos != string::npos);
        splitVector.push_back(splitStr.substr(lastpos));
    }
    return splitVector.size();
}

// 解析buoy_pos.txt文件
bool AnalyseNDBCTxt::analyseBuoyPos(const string filePath, vector<AnalyseNDBCTxt::BUOY_POS> &buoyVector)
{
    ifstream readStream(filePath);
    if(!readStream.is_open())
        return false;

    vector<string> tempLineVector;                              //将所有行以string格式读取到vector中
    while(!readStream.eof())
    {
        string lineStr = "";
        if(getline(readStream,lineStr))
        {
            cout <<  lineStr << endl;
            tempLineVector.push_back(lineStr);
        }
    }

    if(tempLineVector.empty())
        return false;

    for(auto iter=tempLineVector.begin(); iter!=tempLineVector.end(); iter++)    //遍历vector
    {
        string everyLine = *iter;
        if(!everyLine.empty())                                                 
        {
            vector<string> splitVector;
            char ch = '\t';
            int count = splitStringToVector(splitVector,everyLine,ch);              //将每一行字符串分隔成若干字符串保存到splitvector中
            if(count<1){continue;}
            string numStr = "";
            string latBuoy = "";
            string lonBuoy = "";

            for(auto iter=splitVector.begin(); iter!=splitVector.end(); iter++)     //遍历splitvector，将对应的字符串保存到string中
            {
                string tempStr = *iter;                                             
                if(tempStr.empty()){ continue;}

                if(numStr.empty())
                    numStr = tempStr;
                else if(latBuoy.empty())
                    latBuoy = tempStr;
                else if(lonBuoy.empty())
                    lonBuoy = tempStr;
                else
                    break;
            }
            if(!numStr.empty() && !latBuoy.empty() && !lonBuoy.empty())           //将string转换为对应型别，保存到结构体
            {
                BUOY_POS pBuoyPos;
                pBuoyPos.numStr = numStr;
                pBuoyPos.latBuoy = stringToNum<float>(latBuoy);
                pBuoyPos.lonBuoy = stringToNum<float>(lonBuoy);
                buoyVector.push_back(pBuoyPos);
            }
        }
    }

    if(buoyVector.empty())
        return false;
    return true;
}

// 解析4104452016.txt文件
bool AnalyseNDBCTxt::analyseNDBC(const string filePath, vector<AnalyseNDBCTxt::NDBC> &ndbcVector)
{
    ifstream readStream(filePath);
    if(!readStream.is_open())
        return false;

    vector<string> tempLineVector;
    while(!readStream.eof())
    {
        string lineStr = "";
        if(getline(readStream,lineStr))
        {
            cout << lineStr << endl;
            tempLineVector.push_back(lineStr);
        }
    }
    if(tempLineVector.empty())
        return false;

    for(auto iter=tempLineVector.begin(); iter!=tempLineVector.end(); iter++)
    {
        string  everyLine = *iter;
        if(!everyLine.empty())
        {
            vector<string> splitVector;
            char ch = ' ';
            int count = splitStringToVector(splitVector,everyLine,ch);
            if(count<1){continue;}
            string year = "";
            string month = "";
            string day = "";
            string hour = "";
            string minute = "";
            string wdirStr = "";
            string wspdStr = "";
            for(auto iter=splitVector.begin(); iter!=splitVector.end(); iter++)
            {
                string tempStr = *iter;
                if(tempStr.empty()){continue;}

                if(year.empty())
                    year = tempStr;
                else if(month.empty())
                    month = tempStr;
                else if(day.empty())
                    day = tempStr;
                else if(hour.empty())
                    hour = tempStr;
                else if(minute.empty())
                    minute = tempStr;
                else if(wdirStr.empty())
                    wdirStr = tempStr;
                else if(wspdStr.empty())
                    wspdStr = tempStr;
                else
                    break;

            }

            string timeStr = "";
            if(!year.empty() && !month.empty() && !day.empty() && !hour.empty() &&!minute.empty())
                timeStr = year + month + day + hour + minute;

            if(!timeStr.empty() && !wdirStr.empty() && !wspdStr.empty())
            {
                int wdirNum = stringToNum<int>(wdirStr);
                float wspdNum = stringToNum<float>(wspdStr);
                if(wdirNum == 0 || wspdNum == 0)
                    continue;
                NDBC ndbcStruct;
                ndbcStruct.timeNDBC = timeStr;
                ndbcStruct.wdirNDBC = wdirNum;
                ndbcStruct.wspdNDBC = wspdNum;
                ndbcVector.push_back(ndbcStruct);
            }
        }
    }

    if(ndbcVector.empty())
        return false;
    return true;
}

// 计算时间差，单位分钟
int AnalyseNDBCTxt::getTwoTimeDifference(const string srcTime, const string dstTime)
{
    if(srcTime.empty() || dstTime.empty())
        return 1000;

    string srcYmdStr = srcTime.substr(0,8);
    string srcHourStr = srcTime.substr(9,2);
    string srcMinutStr = srcTime.substr(12,2);
    string dstYmdStr = dstTime.substr(0,8);
    string dstHourStr = dstTime.substr(8,2);
    string dstMinuStr = dstTime.substr(10,2);
    int srcHourInt = atoi(srcHourStr.c_str());
    int srcMinutInt = atoi(srcMinutStr.c_str());
    int dstHourInt = atoi(dstHourStr.c_str());
    int dstMinutInt = atoi(dstMinuStr.c_str());

    if(srcYmdStr.compare(dstYmdStr) != 0)
        return 1000;

    int timeDiff = abs(srcHourInt*60+srcMinutInt - dstHourInt*60 - dstMinutInt);
    return timeDiff;
}

// 计算地球表面经纬度之间的距离,单位km
float AnalyseNDBCTxt::getTwoPointDistance(const float srcLat, const float srcLon, const float dstLat, const float dstLon)
{
    const double pi=3.1415926;
    float a = 6378.14; // 地球的半径
    float f = 1 / 298.257;
    float F = (srcLon + dstLon) / 2;
    float G = (srcLon - dstLon) / 2;
    float ramda = (srcLat - dstLat) / 2;

    float S = (sin(G*pi / 180) *sin(G*pi / 180))*(cos(ramda*pi / 180) *cos(ramda*pi / 180)) + (cos(F*pi / 180) *cos(F*pi / 180))*(sin(ramda*pi / 180)*sin(ramda*pi / 180));
    float C = (cos(G*pi / 180) *cos(G*pi / 180))*(cos(ramda*pi / 180) *cos(ramda*pi / 180)) + (sin(F*pi / 180) *sin(F*pi / 180))*(sin(ramda*pi / 180) *sin(ramda*pi / 180));

    float omega = atan(sqrt(S / C));
    float R = sqrt(S*C) / omega;
    float D = 2 * omega*a;

    float H1 = (3 * R - 1) / (2 * C);
    float H2 = (3 * R + 1) / (2 * S);

    float res = D*(1 + f*H1*(sin(F*pi / 180)*sin(F*pi / 180))*(cos(G*pi / 180) *cos(G*pi / 180)) - f*H2*(cos(F*pi / 180) *cos(F*pi / 180))*(sin(G*pi / 180) *sin(G*pi / 180)));

    float distance = res/1000;
    return distance;
}
