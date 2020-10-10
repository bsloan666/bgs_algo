#include <iostream>
#include <math.h>


double bgs_sqrt(double x) {
    // From www.cpp.re 
    int mults(0), adds(0), bitops(0);
    double tol = (double)x*1.e-17; 
    double y = (double)x; 
    double radicand = y; // radicand = number whose square root we seek 
    double msqrt = y/2;  // first guess 
    bitops += 6;   mults += 2; 
    while(fabs(y - msqrt) > tol) { 
        y = msqrt; 
        msqrt = (y + radicand/y)/2; 
        mults +=2; adds += 2; bitops += 4; 
    }
    cout << "sqrt1(" << x << ") mults= " << mults << " adds= " << adds << " bitops= " << bitops << endl;
    return(msqrt);
}

double bgs_sqrt_2(double rhs){
    // Cribbed main loop from above. Special condition speeds up perfect squares.  
    int mults(0), adds(0), bitops(0);
    double epsilon = rhs*1.e-17;  
    int nearest_whole_root = rhs;
    while(nearest_whole_root * nearest_whole_root > rhs) {
        mults++;
        bitops++;
        nearest_whole_root/=2;
    }
    while(nearest_whole_root * nearest_whole_root < rhs) {
        mults++;
        adds++;
        bitops++;
        nearest_whole_root++;
    }
    mults++;
    bitops++;
    if(nearest_whole_root * nearest_whole_root == rhs) {
        cout << "sqrt2(" << rhs << ") mults= " << mults << " adds= " << adds << " bitops= " << bitops << endl;
        return (double)(nearest_whole_root);
    }
    double result = nearest_whole_root - 0.5;
    adds++;
    int diff_whole_squares = 
        (nearest_whole_root+1) * (nearest_whole_root+1) - 
            nearest_whole_root * nearest_whole_root;
    adds+=3;
    mults+=2;

    double diff_precise_squares = result * result - rhs;
        mults++;
        adds++;
    double y = rhs;
    while(fabs(y-result) > epsilon) {
        mults+=2;
        adds+=2;
        bitops++;
        y = result;
        result = (y + rhs/y)/2;
    }

    cout << "sqrt2(" << rhs << ") mults= " << mults << " adds= " << adds << " bitops= " << bitops << endl;
    return result;
}
