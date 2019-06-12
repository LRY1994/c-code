  
#include "header.h"
#include "global.h"
using namespace std;


int main (){
    mArray = getMArray(5,0,5);
    getDt(5);
    
    for (int i = 0;i < mArray.size();i++)  
    {  	
        printf("m%d=%lf\n", i, getM(i)); 
    }
      printf("\npoints are£º\n");
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
// g++ -fexec-charset=GBK test.cpp main.cpp tree.cpp config.cpp spline.cpp && a.exe