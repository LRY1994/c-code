
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <cmath>
#include <vector>
#include <Stack>
using namespace std;

typedef struct BTNode
{
    double temperature; 
    double sum;         
    vector<double> path;
    vector<BTNode *> children;
} * BTree;

double cal_power(double a, double b);
double get_hightest_temp(double origin);
double get_lowest_temp(double origin);
double get_firstLayer_temp(int index,double rootVal);

void CreatBTree(BTNode *&root, double initial,int firstLayerNum,int node_num);
void depthFirstSearch(BTree root);

void interpolation();


int min_sum = 99999999;  
vector<double> min_path; 