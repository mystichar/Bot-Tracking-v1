// Bot Tracking  v1.cpp : Defines the entry point for the console application.
//

#include "position and movement.h"
#include <math.h>
#include <iostream>
int main()
{
	double accx;   //acceleration east west
	double accy;   //acceleration north south
	double theta;  //offset from due east
	double acc_lr_int; //acceleration parallel to wheels to start movement
	double acc_fb_int; //acceleration perpendicular to wheels to start movement
	double acc_lr_fin; //acceleration parallel to wheels to end movement
	double acc_fb_fin; //acceleration perpendicular to wheels to end movement
	double velocity_int;
	double theta_int;
	double velocity_x_int;
	double velocity_y_int;
	double velocity_x;
	double velocity_y;
	double position_x=0;
	double position_y=0;
	double theo_time_acc; //theoretical time it will be accelerating
	double theo_time_vel; //theoretical time it will be moving at a constant velocity 
	int debugfixer; //ignore this


	std::cout << "initialy velocity?: ";
	std::cin >> velocity_int;
	std::cout << "at what angle? (rad): ";
	std::cin >> theta_int;

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
	position_x = positionx(position_x, theo_time_acc, theo_time_vel, accx, theta_int, velocity_int );
	position_y = positiony(position_y, theo_time_acc, theo_time_vel, accy, theta_int, velocity_int);

	std::cout << "the initial acceleration in the x is: " << accx << std::endl;
	std::cout << "the intitial acceleration in the y is: " << accy << std::endl;
	std::cout << "the new velocity in the x is: " << velocity_x << std::endl;
	std::cout << "the new velocity in the y is: " << velocity_y << std::endl;
	std::cout << "the new position in the x is: " << position_x << std::endl;
	std::cout << "the new position in the y is: " << position_y << std::endl;

	std::cout << "type 0:";
	std::cin >> debugfixer;
	return debugfixer;
}

