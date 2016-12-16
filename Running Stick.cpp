/*******************************************************************************
 * Copyright 2016 Kaustav Das All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#include <GL/glut.h>

#include "models/character.h"

void init(void);
void display(void);
void reshape(int, int);
void update(void);
void keyInput(unsigned char, int, int);
void specialKeyboard(int, int, int);
void lightSettings();

Character character = Character();

void init(void)
{
	character.init();
}

void display(void)
{
	// Clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


//	glMatrixMode(GL_MODELVIEW);

	gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glTranslatef(0.0, -5.0, 8.0);
	character.drawCharacter(0,0,0);
	glFlush();
}

void reshape(int width, int height)
{
	if(height == 0)
		height = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window

	// Set the correct perspective.
	gluPerspective(90, (GLfloat) width/(GLfloat) height, 1.0, 100.0);
}

void update(void)
{

}

void keyInput(unsigned char key, int x, int y)
{

}

void specialKeyboard(int key, int x, int y)
{

}

void lightSettings()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 5.0 };

	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


	// Need to enable lighting calculations
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int main (int argc, char **argv)
{
	glutInit(&argc,argv); // Initialize GLUT
	glutInitWindowSize(800, 600); // Set the width and height of the window
	glutInitWindowPosition(800, 0); // Set the position of the window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB); // Set up a basic display buffer
	glutCreateWindow("Running Stick"); // Set the title for the window
	init();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Allow alpha calculations
	glEnable( GL_BLEND );
	glEnable(GL_COLOR_MATERIAL); // Enable material colour on lighting

	lightSettings();

	glutDisplayFunc(display); // Tell GLUT to use "display" for rendering
	glutReshapeFunc(reshape); // Tell GLUT to use "reshape" for rendering
	glutIdleFunc(update);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyboard);

	glEnable(GL_DEPTH_TEST); // Enable depth testing
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glutMainLoop();
	return 0;
}
