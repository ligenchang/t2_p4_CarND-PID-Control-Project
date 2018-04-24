#include "PID.h"
#include <math.h>
using namespace std;
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
    Kp=_Kp;
    Ki=_Ki;
    Kd=_Kd;
    best_err=100;
    Dp=0.5;
    Di=0.5;
    Dd=0.5;
    
    dp = {Dp,Di,Dd};
    p = {Kp,Ki,Kd};
    
    

}

void PID::UpdateError(double cte) {
    d_error = (cte - p_error);
    p_error = cte;
    i_error += cte;
    
}

double PID::TotalError() {
    std::cout << "total error " << -Kp * p_error - Kd * d_error - Ki * i_error<< std::endl;
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}


void PID::Twiddle(double current_error) {
    
    std::cout << "current_error " << current_error<< std::endl;
    std::cout << "best_err" << best_err<< std::endl;
    std::cout << "state " << state<< std::endl;
    std::cout << "mystate " << mystate<< std::endl;
    std::cout << "Kp " << Kp<< std::endl;
    std::cout << "Ki " << Ki<< std::endl;
    std::cout << "Kd " << Kd<< std::endl;
    
    if (curr_step % (n_steps+2*n_steps) > n_steps)
    {
        cout << "9999999999999999999999: " << curr_step % (n_steps+2*n_steps) << endl;
        err += pow(current_error,2);
    }
    
    if(mystate==2)
    {
        if( fabs(err) < fabs(best_err)) {
            best_err = current_error;
        if(state==1)
            Dp *= 1.1;
        else if(state==2)
            Di*=1.1;
        else if(state==3)
            Dd*=1.1;

            
            
        } else {
            
            
            if(state==1)
            {
                Dp*= .9;
                Kp += Dp;
            }
            else if(state==2)
            {
                Di*= .9;
                Ki += Di;
            }
            else if(state==3)
            {
                Dd*= .9;
                Kd += Dd;
            }
            
            //        Di*= .9;
            //        Dd*= .9;
            
            
        }
        
        if (state==1)
            state=2;
        else if (state==2)
            state=3;
        else if (state==3)
            state=1;
        
        mystate=1;
        return;
        
    }
    mystate=1;
    
    if(state==1)
        Kp += Dp;
    else if(state==2)
       Ki += Di;
    else if(state==3)
        Kd += Dd;
    if( fabs(err) < fabs(best_err)) {
        best_err = current_error;
        if(state==1)
            Dp *= 1.1;
        else if(state==2)
            Di*=1.1;
        else if(state==3)
            Dd*=1.1;
        
        
        if (state==1)
            state=2;
        else if (state==2)
            state=3;
        else if (state==3)
            state=1;

        
    } else {
        mystate=2;

        
        if(state==1)
        {
            Dp*= .9;
            Kp -= 2*Dp;
        }
        else if(state==2)
        {
            Di*= .9;
            Ki -= 2*Di;
        }
        else if(state==3)
        {
            Dd*= .9;
            Kd -= 2*Dd;
        }

    }
    

    curr_step++;
}

