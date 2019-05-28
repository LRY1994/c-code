  
#include "header.h"
#include "global.h"
using namespace std;


int min_sum = 99999999;
vector<double> min_path;
vector<double> mArray;
vector<Point> point;

int main (){
    mArray = getMArray(5,4,5);
    
    for (int i = 0;i < mArray.size();i++)  
    {  	
        printf("m%d=%lf\n", i, getM(i)); 
    }
      printf("\n拟合的点是：\n");
     for (int i = 0; i < point.size(); i++)
    {   
        printf("(%.0lf,%.2lf)   ", getX(i), getY(i));
    }
    getchar();

    // for (int i = 0;i<6;i++)  
    // {  	
    //     printf("m%d=%lf\n", i, *(m+i)); 
    // }

   return 0;
 
};
// g++ -fexec-charset=GBK test.cpp main.cpp Tree.cpp Config.cpp Cubic_Spline_Interpolation.cpp && a.exe