#ifndef PID_H
#define PID_H
#include <vector>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double best_err;
  int mystate=1;
  int state=1;

    bool tried_add, tried_subtract;

  int index;

  unsigned int curr_step;

  bool TWIDDLE;

  unsigned int n_steps;

  double err;

  std::vector<double> dp;
  std::vector<double> p;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  double Dp;
  double Di;
  double Dd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);
  void Twiddle(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
