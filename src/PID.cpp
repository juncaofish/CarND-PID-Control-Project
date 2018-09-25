#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  i_error = 0;
  p_error = 0;
}

void PID::UpdateError(double cte) {
  i_error += cte;
  d_error = cte - p_error;
  p_error = cte;
}

double PID::TotalError() {
  return -(Kp * p_error + Ki * i_error + Kd * d_error);
}

