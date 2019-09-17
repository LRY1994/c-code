#include "header.h"
#include "global.h"
using namespace std;


double min_sum = 99999999;
vector<double> min_path;
vector<double> mArray;
vector<Point> point;
vector<double> pointX;
vector<double> pointY;
/**
 * @description 执行函数
 * @param {int} segment ，时间间隔数
 * @param {double} initialVal 初始温度
 * @param {int} firstLayerNum 第一层节点数
 * @returns {vector<double>} 返回m数组
 */
vector<double> getMArray(int segment,double initialVal,int firstLayerNum)
{
    double I = getI();
    getDt(segment,I);
    int node_num = firstLayerNum * (pow(2, segment) - 1) + 1;
     printf("there are %ld nodes\n",node_num);

    BTree tree;
    creatBTree(tree, initialVal ,firstLayerNum,node_num,I);

 
    depthFirstSearch(tree,I);
    

    printf("the min_cost of Ah is %.2lf\n",min_sum);

    printf("the temperature of min_sum path is:");
   
    double t;
    for (int i = 0; i < min_path.size(); i++)
    {    
        if(i > 0) t = getTime(pointX[i-1],i);
        else t = 0;
        point.push_back(Point(t,min_path[i]));
        pointX.push_back(t);
        pointY.push_back(min_path[i]);
        printf("%.2lf,", min_path[i]);
    }

	printf("\nstart splining......\n");
    return interpolation(point,2);

}

double getM(int index){
    return mArray[index];
}

double getX(int index){
 return pointX[index];
}

double getY(int index){
 return pointY[index];
}

// g++ -fexec-charset=GBK test.cpp main.cpp tree.cpp config.cpp spline.cpp && a.exe