#include<iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <regex>
#include <algorithm>
#include "AnalyseNDBCTxt.h"
#include "MyMath.h"

using namespace std;

int main()
{

	AnalyseNDBCTxt txt;
	vector<string> splitVector;
	string splitStr = "zynclaclzyn,dkciawcs";
	char ch = ',';
	int ret = txt.splitStringToVector(splitVector, splitStr, ch);  
	
	string filePath = "/home/caoliang/buoy_pos.txt";
	vector<AnalyseNDBCTxt::BUOY_POS> buoyVector;
	txt.analyseBuoyPos(filePath, buoyVector);



	return 0;
}
