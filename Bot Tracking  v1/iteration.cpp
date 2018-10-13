#include "position and movement.h"
#include <iostream>
#include <math.h>

 double * iteration(double nextint[])
{
double theta;
double acc_fb_int;
double acc_lr_int;
double theo_time_acc;
double theo_time_vel;
double accx;   //acceleration east west
double accy;   //acceleration north south
double velocity_x;
double velocity_y;
double end_velocity;
double velocity_int = nextint[1];
double theta_int = nextint[2];
double position_x = nextint[3];
double position_y = nextint[4];
double intend[4];


std::cout << "angle of new acceleration? (rad): ";
std::cin >> theta;
std::cout << "input acceleration from the back to the front: ";
std::cin >> acc_fb_int;
std::cout << "input acceleration from the left to right: ";
std::cin >> acc_lr_int;
std::cout << "how long will it be accelerating? ";
std::cin >> theo_time_acc;
std::cout << "how long will it be moving after accelerating? ";
std::cin >> theo_time_vel;

accx = acc_x(theta, acc_lr_int, acc_fb_int);
accy = acc_y(theta, acc_lr_int, acc_fb_int);
velocity_x = velocityx(accx, theo_time_acc, velocity_int, theta_int);
velocity_y = velocityy(accy, theo_time_acc, velocity_int, theta_int);
position_x = positionx(position_x, theo_time_acc, theo_time_vel, accx, theta_int, velocity_int);
position_y = positiony(position_y, theo_time_acc, theo_time_vel, accy, theta_int, velocity_int);
end_velocity = tan(velocity_y/velocity_x);

std::cout << "the initial acceleration in the x is: " << accx << std::endl;
std::cout << "the intitial acceleration in the y is: " << accy << std::endl;
std::cout << "the new velocity in the x is: " << velocity_x << std::endl;
std::cout << "the new velocity in the y is: " << velocity_y << std::endl;
std::cout << "the new total velocity is: " << end_velocity << std::endl;
std::cout << "the new position in the x is: " << position_x << std::endl;
std::cout << "the new position in the y is: " << position_y << std::endl;

intend[1] = end_velocity;
intend[2] = theta;
intend[3] = position_x;
intend[4] = position_y;
return intend;
}