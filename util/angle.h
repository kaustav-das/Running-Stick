/*
 * angle.h
 *
 *  Created on: 15-Dec-2016
 *      Author: kaustav
 */

#ifndef UTIL_ANGLE_H_
#define UTIL_ANGLE_H_

class Angle {
public:
	Angle(float, float, float);
	virtual ~Angle();

	float x, y, z;
};

#endif /* UTIL_ANGLE_H_ */
