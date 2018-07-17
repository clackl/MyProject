#ifndef MYMATH_H
#define MYMATH_H
#include <numeric>
#include <vector>
#include <math.h>
using namespace std;
class MyMath
{
public:
    MyMath();
    ~MyMath();

    // 平均值
    float averageValue(vector<float> numVector);

    // 相对偏差
    float biasValue(vector<float> checkVector,vector<float> checkedVector);

    // 均方根误差
    float rmseValue(vector<float> checkVector,vector<float> checkedVector);

    // 相对百分比偏差
    float rpdValue(vector<float> checkVector,vector<float> checkedVector);

    // 绝对百分比偏差
    float apdValue(vector<float> checkVector,vector<float> checkedVector);

    // 线性相关系数(线性回归决定系数)
    float rLrsValue(vector<float> checkVector,vector<float> checkedVector);

    // 线性回归斜率
    float kLrsValue(vector<float> checkVector,vector<float> checkedVector);

    // 线性回归截距
    float bLrsValue(vector<float> checkVector,vector<float> checkedVector);
private:
    const float EPSINON = 0.00001;
};

#endif // MYMATH_H
