#include "MyMath.h"

MyMath::MyMath()
{

}

MyMath::~MyMath()
{

}

//************************************
// 函数名称: averageValue
// 函数说明：求一组数的平均值
// 返 回 值: float
// 参    数: vector<float> numVector
// 作    者：WTB
// 作成日期：2018/4/24
// 修改记录：
//************************************
float MyMath::averageValue(vector<float> numVector)
{
    if(numVector.empty())
        return 0;
    int numCount = numVector.size();
    float avg = accumulate(numVector.begin(),numVector.end(),0)/numCount;
    return avg;
}

//************************************
// 函数名称: biasValue
// 函数说明：相对偏差
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/5/15
// 修改记录：
//************************************
float MyMath::biasValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    int numCount = checkVector.size() < checkedVector.size() ? checkVector.size() : checkedVector.size();
    float retValue = 0.0;
    float totalNum = 0.0;
    for(int i=0;i<numCount;++i)
    {
        totalNum = checkVector.at(i)-checkedVector.at(i);
    }
    retValue = totalNum/numCount;
    return retValue;
}

//************************************
// 函数名称: rmseValue
// 函数说明：均方根误差
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/5/15
// 修改记录：
//************************************
float MyMath::rmseValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    int numCount = checkVector.size() < checkedVector.size() ? checkVector.size() : checkedVector.size();
    float retValue = 0.0;
    float totalNum = 0.0;
    for(int i=0;i<numCount;++i)
    {
        totalNum = pow((checkVector.at(i)-checkedVector.at(i)),2);
    }
    retValue = sqrt(totalNum/numCount);
    return retValue;
}

//************************************
// 函数名称: rpdValue
// 函数说明：相对百分比偏差
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/5/15
// 修改记录：
//************************************
float MyMath::rpdValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    //int numCount = checkVector.size();
    int numCount = checkVector.size() < checkedVector.size() ? checkVector.size() : checkedVector.size();
    float retValue = 0.0;
    float totalNum = 0.0;
    for(int i=0;i<numCount;++i)
    {
        if(checkVector.at(i)>-EPSINON && checkVector.at(i)<EPSINON)// 分母不能为0
            {continue;}
        totalNum = (checkVector.at(i)-checkedVector.at(i))/checkVector.at(i);
    }
    retValue = totalNum/numCount;
    return retValue;
}

//************************************
// 函数名称: apdValue
// 函数说明：绝对百分比偏差
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/5/15
// 修改记录：
//************************************
float MyMath::apdValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    //int numCount = checkVector.size();
    int numCount = checkVector.size() < checkedVector.size() ? checkVector.size() : checkedVector.size();
    float retValue = 0.0;
    float totalNum = 0.0;
    for(int i=0;i<numCount;++i)
    {
        if(checkVector.at(i)>-EPSINON && checkVector.at(i)<EPSINON) // 分母不能为0
            {continue;}
        totalNum += fabs((checkVector.at(i)-checkedVector.at(i))/checkVector.at(i));
    }
    retValue = totalNum/numCount;
    return retValue;
}

//************************************
// 函数名称: rLrsValue
// 函数说明：线性相关系数(线性回归决定系数)
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/6/15
// 修改记录：
//************************************
float MyMath::rLrsValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    //int numCount = checkVector.size();
    int numCount = checkVector.size() < checkedVector.size() ? checkVector.size() : checkedVector.size();

    // 求两个vector中数值相乘的和
    float NXY =  0.0;
    float squareX = 0.0;
    float squareY = 0.0;
    for(int i=0;i<numCount;++i)
    {
        NXY += checkVector.at(i)*checkedVector.at(i);
        squareX += pow(checkVector.at(i),2);
        squareY += pow(checkedVector.at(i),2);
    }

    // 对两个vector分别求和再相乘，最后除以N
    float NXNYDivedeN = 0.0;
    float checkSum = accumulate(checkVector.begin(),checkVector.end(),0);
    float checkedSum = accumulate(checkedVector.begin(),checkedVector.end(),0);
    NXNYDivedeN = checkSum*checkedSum/numCount;
    float NXAndDivedN = pow(checkSum,2)/numCount;
    float NYAndDivedN = pow(checkedSum,2)/numCount;

    float sumTop = NXY-NXNYDivedeN; // 公式上半部分
    float sumDown = sqrt((squareX-NXAndDivedN)*(squareY-NYAndDivedN));// 公式下半部分

    if(sumDown>-EPSINON && sumDown<EPSINON) // 判断分母不能为0
        return 0;

    // 公式最后结果
    float retValue = 0.0;
    retValue = sumTop/sumDown;
    return retValue;
}

//************************************
// 函数名称: rLrsValue
// 函数说明：线性回归斜率
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/6/15
// 修改记录：
//************************************
float MyMath::kLrsValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    int numCount = checkVector.size()<checkedVector.size() ? checkVector.size():checkedVector.size();
    float xAvg = averageValue(checkVector);
    float yAvg = averageValue(checkedVector);

    float topNum = 0.0; // 公式上半部分结果
    float downNum = 0.0;// 公式下半部分结果
    for(int i=0; i<numCount; i++)
    {
        topNum += (checkVector.at(i)-xAvg)*(checkedVector.at(i)-yAvg);
        downNum += pow((checkVector.at(i)-xAvg),2);
    }

    if(downNum>-EPSINON && downNum<EPSINON) // 判断分母不能为0
        return 0;

    float retValue = 0.0;
    retValue = topNum/downNum;
    return retValue;
}

//************************************
// 函数名称: rLrsValue
// 函数说明：线性回归截距
// 返 回 值: float
// 参    数: vector<float> checkVector
// 参    数: vector<float> checkedVector
// 作    者：WTB
// 作成日期：2018/6/15
// 修改记录：
//************************************
float MyMath::bLrsValue(vector<float> checkVector, vector<float> checkedVector)
{
    if(checkVector.empty() || checkedVector.empty())
        return 0;

    //int numCount = checkVector.size()<checkedVector.size() ? checkVector.size():checkedVector.size();
    float xAvg = averageValue(checkVector);
    float yAvg = averageValue(checkedVector);
    float kLrs = kLrsValue(checkVector,checkedVector);
    float retValue = yAvg-kLrs*xAvg;
    return retValue;
}


