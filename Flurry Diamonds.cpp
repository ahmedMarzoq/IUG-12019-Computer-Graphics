/*
 * Flurry Assignment
 * Date : 05/11/2018
 * Writen by : Ahmed M. Marzoq , ID : 120160415 , Group : Monday / 8:00 - 10:00
 * To : Mr.Ahmed Alhessi , Course : Computer Graphics (Lab)
 */
#include <windows.h>
#include <math.h>
#include <gl/Gl.h>
#include <gl/glut.h>  //OpenGL Utility Toolkit for creating openGL window
int random(int m) { return rand() % m; }
class GLintPoint {
public:
	GLint x, y;
};
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // set white background color
	glColor3f(0.5f, 0.0f, 0.5f);       // set the drawing color 
	glPointSize(.5);                   // a ‘dot’ is 7 by 7 pixels
	glMatrixMode(GL_PROJECTION);    // GL_MODELVIEW (Default), GL_PROJECTION, and GL_TEXTURE
	glLoadIdentity();                // replace the current matrix with the identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);      // Determine The coordinates of window
}
void drawDiamond(GLintPoint C, int size) {
	glBegin(GL_POLYGON);// draw the line Loop
	glVertex2f(C.x, C.y + size);
	glVertex2f(C.x - size, C.y);
	glVertex2f(C.x, C.y - size);
	glVertex2f(C.x + size, C.y);
	glEnd();
	glFlush();
}

void drawFlurry(int num, int Size, int Width, int Height) {
	GLintPoint c;
	float diamondSize;

	for (int i = 0; i < num; i++) {
		c.x = random(Width);	// place center randomly 
		c.y = random(Height);
		diamondSize = random(Size);
		glColor3f(random(10) / 10.0, random(10) / 10.0, random(10) / 10.0);
		drawDiamond(c, diamondSize);
	}
}



void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawFlurry(70, 100, 640, 480);
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);   // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Flurry Assignment"); // open the screen window
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop(); // go into a perpetual loop
}