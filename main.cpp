/**
 * 一般树
 */
#include "header.h"
using namespace std;


struct Point 
{
    double x;//时间
    double y;//温度
    Point(double a,double b){ x=a;y=b;}
};


int main()
{
    int segment;
    printf("输入时间间隔数：");
    scanf("%d", &segment);

    double initialVal;
    printf("输入初始温度：");
    scanf("%lf", &initialVal);

    int firstLayerNum;
    printf("输入第一层节点个数：");
    scanf("%d", &firstLayerNum);

    int node_num = firstLayerNum * (pow(2, segment) - 1) + 1;
     printf("一共将有%d个节点\n4",node_num);

    BTree tree;
    CreatBTree(tree, initialVal ,firstLayerNum,node_num);

    printf("深度优先遍历二叉树结果(包括剪枝): \n");

    depthFirstSearch(tree);

    printf("最小功耗为%lf\n",min_sum);

    printf("最小功耗路径为：\n");
    vector<Point> point;
    for (int i = 0; i < min_path.size(); i++)
    {
        point.push_back(Point(i,min_path[i]));
        printf("%lf,", min_path[i]);
    }

    printf("即将拟合的点是：\n");
    
    for (int i = 0; i < point.size(); i++)
    {   
        printf("(%lf,%lf)   ", point[i].x,point[i].y);
    }

    return 0;
}