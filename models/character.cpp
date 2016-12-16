/*
 * character.cpp
 *
 *  Created on: 15-Dec-2016
 *      Author: kaustav
 */

#include "character.h"

Character::Character() {
	head = glGenLists(1);
	body = glGenLists(1);
	joint = glGenLists(1);
	limb = glGenLists(1);
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::init(void)
{
	// Generatiog all objects in the screen

	glNewList(head, GL_COMPILE);
		glPushMatrix();
			drawHead();
		glPopMatrix();
	glEndList();

	glNewList(body, GL_COMPILE);
		glPushMatrix();
			drawBody();
		glPopMatrix();
	glEndList();

	glNewList(joint, GL_COMPILE);
		glPushMatrix();
			drawJoint();
		glPopMatrix();
	glEndList();

	glNewList(limb, GL_COMPILE);
		glPushMatrix();
			drawLimb();
		glPopMatrix();
	glEndList();
}

void Character::drawHead(void)
{
	// Head generation
	glColor3f(0.88627451, 0.407843137, 0.0862745098);
	glutSolidSphere(0.5, 20, 20);
	glColor3f(0.258823529, 0.250980392, 0.317647059);

	// Hat generation
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(0.0, 0.2, 0.0);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluDisk(quadratic, 0.0, 1.0, 32, 32);
	glTranslatef(0.0, 0.0, -0.4);
	gluCylinder(quadratic, 0.5, 0.5, 0.4, 32, 32);
	gluDisk(quadratic, 0.0, 0.5, 32, 32);
}

void Character::drawBody(void)
{
	// Upper part of body
	glPushMatrix();
		glTranslatef(0.0, 0.5, 0.0);
		glColor3f(0.807843137, 0.0392156863, 0.0470588235);
		glScalef(1.5, 2.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();

	// Lower part of body
	glPushMatrix();
		glTranslatef(0.0, -1.0, 0.0);
		glColor3f(0.145098039, 0.105882353, 0.898039216);
		glScalef(1.5, 1.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
}

void Character::drawJoint(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.1, 20, 20);
}

void Character::drawLimb(void)
{
	glScalef(0.4, 1.0, 0.4);
	glutSolidCube(1.0);
}

void Character::drawCharacter(float x, float y, float z)
{
	glPushMatrix();

		// Body
		glTranslatef(x, 0.0, 0.0);
		glPushMatrix();
			glColor4f(0.5, 0.5, 0.5, 0.1);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			glTranslatef(0.0, -3.3, 2.0);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			gluDisk(quadratic, 0.0, 1.0 - y/15, 32, 32);
		glPopMatrix();
		glTranslatef(0.0, y, 0.0);
		glRotatef(-20, 1, 0, 0);
//		glCallList(body);
		drawBody();


		// Head
		glPushMatrix();
			glTranslatef(0.0, 2.0, 0.0);
//			glCallList(head);
			drawHead();
		glPopMatrix();

		// Hands
		glPushMatrix();
			glTranslatef(0.0, 1.3, 0.0);

			// Right
			glPushMatrix();
				glTranslatef(0.85, 0.0, 0.0);
				// glRotatef(r_s_angle, r_s_x, r_s_y, r_s_z);
				// glRotatef(180, 1, 1, 1);
				glRotatef(right_shoulder.x, 1, 0, 0);
				glRotatef(right_shoulder.y, 1, 0, 0);
				glRotatef(right_shoulder.z, 1, 0, 0);
//				glCallList(joint);
				drawJoint();
				glTranslatef(0.0, -0.6, 0.0);
				glColor3f(0.807843137, 0.0392156863, 0.0470588235);
//				glCallList(limb);
				drawLimb();
				glPushMatrix();
					glTranslatef(0.0, -0.6, 0.0);
					glRotatef(right_elbow.x, 1, 0, 0);
					glRotatef(right_elbow.y, 0, 1, 0);
					glRotatef(right_elbow.z, 0, 0, 1);
//					glCallList(joint);
					drawJoint();
					glTranslatef(0.0, -0.6, 0.0);
					glColor3f(0.539215686, 0.137254902, 0.0784313725);
//					glCallList(limb);
					drawLimb();
				glPopMatrix();
			glPopMatrix();


			// Left
			glPushMatrix();
				glTranslatef(-0.85, 0.0, 0.0);
				glRotatef(left_shoulder.x, 1, 0, 0);
				glRotatef(left_shoulder.y, 0, 1, 0);
				glRotatef(left_shoulder.z, 0, 0, 1);
//				glCallList(joint);
				drawJoint();
				glTranslatef(0.0, -0.6, 0.0);
				glColor3f(0.807843137, 0.0392156863, 0.0470588235);
//				glCallList(limb);
				drawLimb();
				glPushMatrix();
					glTranslatef(0.0, -0.6, 0.0);
					glRotatef(left_elbow.x, 1, 0, 0);
					glRotatef(left_elbow.y, 0, 1, 0);
					glRotatef(left_elbow.z, 0, 0, 1);
//					glCallList(joint);
					drawJoint();
					glTranslatef(0.0, -0.6, 0.0);
					glColor3f(0.539215686, 0.137254902, 0.0784313725);
//					glCallList(limb);
					drawLimb();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

		// Legs
		glPushMatrix();
			glTranslatef(0.0, -1.6, 0.0);

			// Right
			glPushMatrix();
				glTranslatef(0.65, 0.0, 0.0);
				glRotatef(right_hip.x, 1, 0, 0);
				glRotatef(right_hip.y, 0, 1, 0);
				glRotatef(right_hip.z, 0, 0, 1);
				glCallList(joint);
				glTranslatef(0.0, -0.6, 0.0);
				glColor3f(0.145098039, 0.105882353, 0.898039216);
				glCallList(limb);
				glPushMatrix();
					glTranslatef(0.0, -0.6, 0.0);
					glRotatef(right_knee.x, 1, 0, 0);
					glRotatef(right_knee.y, 0, 1, 0);
					glRotatef(right_knee.z, 0, 0, 1);
					glCallList(joint);
					glTranslatef(0.0, -0.6, 0.0);
					glColor3f(0.539215686, 0.137254902, 0.0784313725);
					glCallList(limb);
				glPopMatrix();
			glPopMatrix();

			// Left
			glPushMatrix();
				glTranslatef(-0.65, 0.0, 0.0);
				glRotatef(left_hip.x, 1, 0, 0);
				glRotatef(left_hip.y, 0, 1, 0);
				glRotatef(left_hip.z, 0, 0, 1);
				glCallList(joint);
				glTranslatef(0.0, -0.6, 0.0);
				glColor3f(0.145098039, 0.105882353, 0.898039216);
				glCallList(limb);
				glPushMatrix();
					glTranslatef(0.0, -0.6, 0.0);
					glRotatef(left_knee.x, 1, 0, 0);
					glRotatef(left_knee.y, 0, 1, 0);
					glRotatef(left_knee.z, 0, 0, 1);
					glCallList(joint);
					glTranslatef(0.0, -0.6, 0.0);
					glColor3f(0.539215686, 0.137254902, 0.0784313725);
					glCallList(limb);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}
