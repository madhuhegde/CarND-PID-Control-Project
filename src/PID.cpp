#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    
    /* Initialize PID Coefficients */
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    
    /* Initialize error terms to 0 */
    p_error = 0;
    i_error = 0;
    d_error = 0;
    
    first_update = 1;
    
}

void PID::UpdateError(double cte) {
    
    /* match Python implementation in class tutorial */
    if(first_update)
    {
        p_error = cte;
        first_update = 0;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error = i_error + cte;
    
}

double PID::TotalError() {
    /*PID output */
    return(-(Kp*p_error+Kd*d_error+Ki*i_error));
}

