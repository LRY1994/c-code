#include <vector>
using namespace std;

#ifdef GLOBAL_C
    double min_sum = 99999999;
    vector<double> min_path;
    vector<double> mArray;
    vector<Point> point;
    vector<double> pointX;
    vector<double> pointY; 
    
#else  
    extern  double min_sum ;
    extern vector<double> min_path;
    extern vector<double> mArray;
    extern vector<Point> point; 
    extern vector<double> pointX;
    extern vector<double> pointY;  
  
#endif  
