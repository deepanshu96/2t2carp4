#include "PID.h"
#include<math.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    prev_cte = 0.0;
    int_cte = 0.0;
    diff_cte = 0.0;
    cur_cte = 0.0;
    counter = 0;
    err = 0.0;
    best_err = -1;
    for(int i=0;i<2;i++)
        dp.push_back(0.1);
    p.push_back(Kp);
    p.push_back(Kd);
    curr1 = 0;
    curr2 = 0;
}

void PID::UpdateError(double cte) {

    //prev_cte

    int_cte += cte;
    diff_cte = cte - prev_cte;
    cur_cte = cte;
    if(counter>1)
        {
         err = cte*cte;
        }
    if(int_cte>35)
        int_cte = 35;
    if(int_cte<-35)
        int_cte = -35;
}

double PID::TotalError() {
    double steer = -1*(Kp * cur_cte + Ki*int_cte + Kd * diff_cte );
/*
    if(fabs(steer)>1)
    {
        while(fabs(steer)>1)
            {
                Kp *= 0.1;
                Ki *= 0.01;
                Kd *= 0.9;
                steer = -1*(Kp * cur_cte + Kd * diff_cte + Ki * int_cte);
            }
    }

}
*/
 return steer;
}
