/*
 * character.h
 *
 *  Created on: 15-Dec-2016
 *      Author: kaustav
 */

#ifndef MODELS_CHARACTER_H_
#define MODELS_CHARACTER_H_

#include <GL/glut.h>
#include "../util/angle.h"

class Character {
public:
	Character();
	virtual ~Character();
	unsigned int head, body, limb, joint;

	Angle left_shoulder  = Angle(0.0f, 0.0f, 0.0f);
	Angle left_elbow = Angle(0.0f, 0.0f, 0.0f);

	Angle right_shoulder = Angle(0.0f, 0.0f, 0.0f);
	Angle right_elbow = Angle(0.0f, 0.0f, 0.0f);

	Angle left_hip = Angle(0.0f, 0.0f, 0.0f);
	Angle left_knee = Angle(0.0f, 0.0f, 0.0f);

	Angle right_hip = Angle(0.0f, 0.0f, 0.0f);
	Angle right_knee = Angle(0.0f, 0.0f, 0.0f);

	void init(void);
	void drawCharacter(float x, float y, float z);

private:

	void drawHead(void);
	void drawBody(void);
	void drawJoint(void);
	void drawLimb(void);
};

#endif /* MODELS_CHARACTER_H_ */
