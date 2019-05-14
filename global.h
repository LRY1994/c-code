#include <vector>
using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef GLOABL_C
   int min_sum = 99999999;
   vector<double> min_path;
#else  
    extern  int min_sum ;
    extern vector<double> min_path;   
#endif  


#endif  