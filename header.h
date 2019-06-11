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

//config.cpp
double cal_power(double a, double b);
double get_highest_temp(double origin);
double get_lowest_temp(double origin);
double get_firstLayer_temp(int index,double parent,int N);

//tree.cpp,里面用到了config.cpp
void creatBTree(BTNode *&root, double initial,int firstLayerNum,int node_num);
void depthFirstSearch(BTree root);

//spline.cpp
vector<double> interpolation(vector<Point> pointList,int option);
double getValue(double xx);

//main.cpp
vector<double> getMArray(int segment,double initialVal,int firstLayerNum);
double getM(int index);
double getX(int index);
double getY(int index);

#endif
