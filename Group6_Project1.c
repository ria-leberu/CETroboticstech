#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void go_straight(float dist);
void rotate(float angle_of_rotation);

task main
{
	//go_straight(0.61);
	rotate(-PI);
}

void go_straight(float dist)
{

	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;



	float rightEncoder = (dist*360)/(2*PI*0.031);

	//While less than 1000 encoder counts of the right motor
	while(abs(nMotorEncoder[rightMotor]) < rightEncoder)
	{
		//Move forward at half power
		motor[rightMotor] = 45;
		motor[leftMotor]	= 45;
	}
	motor[rightMotor] = 0;
	motor[leftMotor]	= 0;

}

void rotate(float angle_of_rotation)
{
	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;

	int ccw;
	int cw;
	
	float rightEncoderCCW = abs(ccw*angle_of_rotation);
	float rightEncoderCW = abs(cw*angle_of_rotation);


	//While less than 1000 encoder counts of the right motor
	if (angle_of_rotation>=0)
	{
		rightEncoderCCW = abs(ccw*angle_of_rotation);
		while(abs(nMotorEncoder[rightMotor]) < rightEncoderCCW)
		{
			//Move CCW at half power
			motor[rightMotor] = 45;
			motor[leftMotor]	= -45;
		}
	}
	if (angle_of_rotation<0)
	{
		cw = 750;
		rightEncoderCW = abs(cw*angle_of_rotation);
		if(angle_of_rotation<=-PI/2)
		{
		cw = 325;
		rightEncoderCW = abs(cw*angle_of_rotation);
		}
		while(abs(nMotorEncoder[rightMotor]) < rightEncoderCW)
			{
				//Move CW at half power
				motor[rightMotor] = -45;
				motor[leftMotor]	= 45;
		}
	}

	motor[rightMotor] = 0;
	motor[leftMotor]	= 0;
}
