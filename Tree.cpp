#include "header.h"
#include "global.h"
using namespace std;

void CreatBTree(BTNode *&root, double initial,int firstLayerNum,int node_num)
{
    int count_num = 0; 
    vector<BTNode *> list;

    //根
    root = new BTNode();
    root->temperature = initial;
    root->sum = 0;
    root->path.push_back(root->temperature);
    count_num++;  

    //第一层
    BTNode * tmp;int i=0;
    while(i<firstLayerNum){
        i++;
        tmp = new BTNode();
        tmp->temperature = get_firstLayer_temp(i,initial);
        tmp->sum = 0;
        tmp->path.push_back(root->temperature);

        root->children.push_back(tmp);

        count_num++;  
        list.push_back(tmp);
    }

    
    while (count_num < node_num)
    {
        vector<BTNode *> tmplist;

        for (int i = 0; i < list.size(); i++)
        {
            BTNode *node = list[i];
            //左节点
            tmp = new BTNode();
            tmp->temperature = get_lowest_temp(node->temperature);
            tmp->sum=0;
            count_num++;
            node->children.push_back(tmp);
            tmplist.push_back(tmp);
            //右节点
            tmp = new BTNode();
            tmp->temperature = get_hightest_temp(node->temperature);
            tmp->sum=0;
            count_num++;
            node->children.push_back(tmp);
            tmplist.push_back(tmp);
        }

        list = tmplist;
    }
}

void depthFirstSearch(BTree root)
{
    stack<BTNode *> nodeStack; 
    nodeStack.push(root);
    BTNode *node;

    vector<double> tmp;
    while (!nodeStack.empty())
    {

        node = nodeStack.top();
        // printf("%lf\n", node->temperature); 
        nodeStack.pop();
        tmp = node->path;

        BTNode *child;
        for(int i=0;i<node->children.size();i++){
            child = node->children[i];
            child->sum = node->sum + cal_power(node->temperature, child->temperature);
            if (child->sum < min_sum)
            { //剪枝
                child->path = tmp;
                child->path.push_back(child->temperature);
                nodeStack.push(child); 
            }
        }

        if (node->children.size() == 0)
        { //叶子节点
            if (node->sum < min_sum)
            {
                min_sum = node->sum;
                min_path = node->path;
            }
        }
    }
}
