#ifndef ANALYSENDBCTXT_H
#define ANALYSENDBCTXT_H
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <regex>
#include <algorithm>

using namespace std;
class AnalyseNDBCTxt
{
public:
    AnalyseNDBCTxt();
    ~AnalyseNDBCTxt();

    struct BUOY_POS
    {
        string    numStr;
        float latBuoy;
        float lonBuoy;
    }*pBuoy;

    struct NDBC
    {
        string timeNDBC;
        int wdirNDBC;
        float wspdNDBC;
    }*pNDBC;

    template <typename T>
    T stringToNum(const string numStr)
    {
        istringstream iss(numStr);
        T num;
        iss >> num;
        return num;
    }
    // 从字符串中找到数字
    list<string> findNum(string str);
    bool isNum(char num);

    // 给定一个字符和一个字符串分割该字符串
    int splitStringToVector(vector<string> &splitVector,string splitStr,char ch);

    // 解析buoy_pos.txt文件
    bool analyseBuoyPos(const string filePath,vector<AnalyseNDBCTxt::BUOY_POS> &buoyVector);

    // 解析4104452016.txt文件
    bool analyseNDBC(const string filePath,vector<AnalyseNDBCTxt::NDBC> &ndbcVector);

    // 计算地球表面经纬度之间的距离，单位km
    float getTwoPointDistance(const float srcLat,const float srcLon,const float dstLat,const float dstLon);

    // 计算检验源与被检验源时间差，单位分钟
    int getTwoTimeDifference(const string srcTime,const string dstTime);
};

#endif // ANALYSENDBCTXT_H
