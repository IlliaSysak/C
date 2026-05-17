#pragma once
#include <cmath>
#include <iostream>

class Math{
private:
 double a, b ,eps;
public:
  Math(){}

 void setinterval(double A, double B);
 void setEPS(double e);

 double f(double x);
 double df(double x);


 double newton();
 double dichotomy();
 ~Math (){}
};

