  
#include "header.h"
#include "global.h"
using namespace std;


int main (){
    
    mArray = getMArray(2,0,5); // 时间间隔数；初始温度；第一层分裂数
    
    for (int i = 0;i < mArray.size();i++)  
    {  	
        printf("m%d=%lf\n", i, getM(i)); 
    }
      printf("points are:\n");
     for (int i = 0; i < point.size(); i++)
    {   
        printf("(%.0lf,%.2lf)   ", getX(i), getY(i));
    }
    getchar();

   return 0;
 
};
// g++ test.cpp main.cpp tree.cpp config.cpp spline.cpp Lookuptable.cpp Lookuptable_data.cpp