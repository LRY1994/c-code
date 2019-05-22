#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <cmath>
#include <vector>
#include <Stack>
using namespace std;

#ifndef TEST_H
#define TEST_H

typedef struct BTNode
{
    double temperature; 
    double sum;         
    vector<double> path;
    vector<BTNode *> children;
} * BTree;

struct Point 
{
    double x;//时间
    double y;//温度
    Point(double a,double b){ x=a;y=b;}
};

//Config.cpp
double cal_power(double a, double b);
double get_hightest_temp(double origin);
double get_lowest_temp(double origin);
double get_firstLayer_temp(int index,double rootVal);

//Tree.cpp,里面用到了Config.cpp
void CreatBTree(BTNode *&root, double initial,int firstLayerNum,int node_num);
void depthFirstSearch(BTree root);

//Cubic_Spline_Interpolation.cpp
vector<double> interpolation(vector<Point> pointList,int option);
double get_value(double xx);

#endif