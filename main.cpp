  
#include "header.h"
#include "global.h"
using namespace std;


int min_sum = 99999999;
vector<double> min_path;
vector<double> mArray;
vector<Point> point;

/**
 * @description 执行函数
 * @param {int} segment ，时间间隔数
 * @param {double} initialVal 初始温度
 * @param {int} firstLayerNum 第一层节点个数
 * @returns {vector<double>} 返回m数组
 */
vector<double> getMArray(int segment,double initialVal,int firstLayerNum)
{
    int node_num = firstLayerNum * (pow(2, segment) - 1) + 1;
     printf("一共将有%d个节点\n",node_num);

    BTree tree;
    CreatBTree(tree, initialVal ,firstLayerNum,node_num);

    // printf("深度优先遍历二叉树结果(包括剪枝): \n");

    depthFirstSearch(tree);

    printf("最小功耗为%.2lf\n",min_sum);

    printf("最小功耗路径为:");
   
    for (int i = 0; i < min_path.size(); i++)
    {
        point.push_back(Point(i,min_path[i]));
        printf("%.2lf,", min_path[i]);
    }

    // // printf("\n即将拟合的点是：\n");
    
    // for (int i = 0; i < point.size(); i++)
    // {   
    //     printf("(%.0lf,%.2lf)   ", point[i].x,point[i].y);
    // }

    
		
	printf("\n开始三次样条插值......\n");
    return interpolation(point,2);


    // double xx;
    // printf("输入x：");
    // while(scanf("%lf", &xx)){
    //     printf("f(%lf) is %lf\n", xx, get_value(xx));
    //     printf("输入x：");
    // }
    

    // return 0;
}

double getM(int index){
    return mArray[index];
}

double getX(int index){
 return point[index].x;
}

double getY(int index){
 return point[index].y;
}

// g++ -fexec-charset=GBK  main.cpp Tree.cpp Config.cpp Cubic_Spline_Interpolation.cpp && a.exe