#include <iostream>
#include <math.h>



double bgs_sqrt(double rhs){
    // Special case speeds up perfect squares.  
    double epsilon = rhs*1.e-17;  
    int nearest_whole_root = rhs;
    while(nearest_whole_root * nearest_whole_root > rhs) {
        nearest_whole_root/=2;
    }
    while(nearest_whole_root * nearest_whole_root < rhs) {
        nearest_whole_root++;
    }
    if(nearest_whole_root * nearest_whole_root == rhs) {
        return (double)(nearest_whole_root);
    }
    double result = nearest_whole_root - 0.5;
    int diff_whole_squares = 
        (nearest_whole_root+1) * (nearest_whole_root+1) - 
            nearest_whole_root * nearest_whole_root;

    double diff_precise_squares = result * result - rhs;
    double y = rhs;
    while(fabs(y-result) > epsilon) {
        y = result;
        result = (y + rhs/y)/2;
    }

    return result;
}
