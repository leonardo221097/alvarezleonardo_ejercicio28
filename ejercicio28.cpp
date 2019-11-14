
// para realizar el ejercicio me guie de un ejemplo de la clase de laboratorio que se encuentra en el suguiente link https://raw.githubusercontent.com/JoseMontanaC/Laboratorio-Metodos-Computacionales/master/c_tests/Rungekutta.cpp
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

 double g= 9.81; 
 double k= 0.7;
 double  vx= 10.0;
 double  vy= 10.0;

 double vs;
 double dt=0.1;


double f0(double x, double x0, double vx);
double fx(double x, double x0, double vx);
double f1(double x, double y0, double vy); 
double fy(double x, double y0, double vy); 
void rk4(double x, double h, double & x0, double & vx,double & y0, double & vy); // metodo de runge kutta 4 orden

int main(void)
{


  double x0,y0,time;
   
    
  for(time = 0; time <= 10; time += dt) {
    cout << time << "\t" << x0/10000 << "\t" << -y0/1000<< endl;
    vs=sqrt(vx*vx+vy*vy);
    rk4(0.0,dt,x0,vx,y0,vy);
  }


  return 0;
}

double f0(double x, double x0, double vx)
{
  return vx;
}

double fx(double x, double x0, double vx)
{
  return -k*vx*(vx/vs);
}

double f1(double x, double y0, double vy)
{
  return vy;
}
double fy(double x, double y0, double vy)
{
  return -g-k*vx*(vx/vs);
}

void rk4(double x, double h, double & x0, double & vx,double & y0, double & vy) // metodo de runge kutta 4 orden
{
  double k10, k11, k20, k21, k30, k31, k40, k41;
    double k_10,k_11,k_20,k_21,k_30,k_31,k_40,k_41;
    
  k10 = h*f0(x, x0, vx);
  k11 = h*fx(x, x0, vx);
  k20 = h*f0(x+h/2, vx + k10/2, vx+ k11/2);
  k21 = h*fx(x+h/2, x0 + k10/2, vx + k11/2);
  k30 = h*f0(x+h/2, x0 + k20/2, vx + k21/2);
  k31 = h*fx(x+h/2, x0 + k20/2, vx + k21/2);
  k40 = h*f0(x + h, x0 + k30, vx + k31);
  k41 = h*fx(x + h, x0 + k30, vx + k31);
    
    
  x0=x0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  vx = vx + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
    
k_10 = h*f0(x, y0, vy);
  k_11 = h*f1(x, y0, vy);
  k_20 = h*f0(x+h/2, y0 + k_10/2, vy + k_11/2);
  k_21 = h*f1(x+h/2, y0 + k_10/2, vy+ k_11/2);
  k_30 = h*f0(x+h/2, y0 + k_20/2, vy + k_21/2);
  k_31 = h*f1(x+h/2, y0 + k_20/2, vy + k_21/2);
  k_40 = h*f0(x + h, y0 + k_30, vy + k_31);
  k_41 = h*f1(x + h, y0 + k_30, vy+ k_31);

y0= y0 + (1.0/6.0)*(k_10 + 2*k_20 + 2*k_30 + k_40);
  vy = vy + (1.0/6.0)*(k_11 + 2*k_21 + 2*k_31 + k_41);
}