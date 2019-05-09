/*
https://blog.csdn.net/mingwanganyu/article/details/72033122
https://blog.csdn.net/qq_33001647/article/details/69808560
http://www.cnblogs.com/davidxu/p/9031055.html

*/

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <Stack>
#include <Queue>
#include <vector>
#include <cmath>
using namespace std;

int node_num = 0;
int min_sum = 99999999;  //最小功耗
vector<double> min_path; //最小功耗路径

typedef struct BTNode
{
    double temperature; //温度
    double sum;         //从根节点到此节点的功耗
    vector<double> path;
    BTNode *lchild;
    BTNode *rchild;
} * BTree;

double cal_power(double a, double b);
double get_hightest_temp(double origin);
double get_lowest_temp(double origin);
void CreatBTree(BTree &root, double initial);
void depthFirstSearch(BTree root);

//计算功耗
double cal_power(double a, double b)
{
    return 0;
}
//计算最高温度
double get_hightest_temp(double origin)
{
    return origin + 1;
}
//计算最低温度
double get_lowest_temp(double origin)
{
    return origin - 1;
}

//按层次建立二叉树
void CreatBTree(BTNode *&root, double initial)
{
    int count_num = 0; //计数器  
    vector<BTNode *> list;

    root = new BTNode();
    root->temperature = initial;
    root->sum = 0;
    root->path.push_back(root->temperature);
    count_num++;  
    list.push_back(root);

    //单独把第一层放进栈
    // int firstLayer = firstLayerNum;
    // while(firstLayer--){
    //     root = new BTNode();
    //     root->temperature = initial;
    //     root->sum = 0;
    //     root->path.push_back(root->temperature);
    //     count_num++;  
    //     list.push_back(root);
    // }
    


    while (count_num < node_num)
    {
        vector<BTNode *> tmplist;

        for (int i = 0; i < list.size(); i++)
        {
            BTNode *node = list[i];
            //左节点
            node->lchild = new BTNode();
            node->lchild->temperature = get_lowest_temp(node->temperature);
            node->lchild->sum = 0;
            count_num++;
            tmplist.push_back(node->lchild);
            //右节点
            node->rchild = new BTNode();
            node->rchild->temperature = get_hightest_temp(node->temperature);
            node->lchild->sum = 0;
            count_num++;
            tmplist.push_back(node->rchild);
        }

        list = tmplist;
    }
}
//深度搜索
void depthFirstSearch(BTree root)
{
    stack<BTNode *> nodeStack; //使用C++的STL标准模板库
    nodeStack.push(root);
    BTNode *node;

    vector<double> tmp;
    while (!nodeStack.empty())
    {

        node = nodeStack.top();
        printf("%lf\n", node->temperature); //遍历根结点
        nodeStack.pop();
        tmp = node->path;

        if (node->rchild)
        {
            node->rchild->sum = node->sum + cal_power(node->temperature, node->rchild->temperature);
            if (node->rchild->sum < min_sum)
            { //剪枝
                node->rchild->path = tmp;
                node->rchild->path.push_back(node->rchild->temperature);
                nodeStack.push(node->rchild); //先将右子树压栈
            }
        }
        if (node->lchild)
        {
            node->lchild->sum = node->sum + cal_power(node->temperature, node->lchild->temperature);
            if (node->rchild->sum < min_sum)
            { //剪枝
                node->lchild->path = tmp;
                node->lchild->path.push_back(node->lchild->temperature);
                nodeStack.push(node->lchild); //再将左子树压栈
            }
        }

        if (!node->rchild && !node->lchild)
        { //叶子节点
            if (node->sum < min_sum)
            {
                min_sum = node->sum;
                min_path = node->path;
            }
        }
    }
}

int main()
{
    int segment;
    printf("输入时间段个数：");
    scanf("%d", &segment);

    double initialVal;
    printf("输入初始温度：");
    scanf("%lf", &initialVal);

    double firstLayerNum;
    printf("输入第一层节点个数：");
    scanf("%d", &firstLayerNum);

    node_num = 2 * (pow(2, segment) - 1) + 1;

    BTree tree;
    CreatBTree(tree, initialVal);

    printf("深度优先遍历二叉树结果: \n");

    depthFirstSearch(tree);

    printf("最小功耗为：\n");
    printf("%lf\n", min_sum);

    printf("最小功耗路径为：\n");
    for (int i = 0; i < min_path.size(); i++)
    {
        printf("%lf,", min_path[i]);
    }

    return 0;
}
