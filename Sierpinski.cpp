/*
 * Sierpinski
 * IUG 12019 
 * Computer Graphics (Lab)
 */
#include <windows.h>
#include <math.h>
#include <gl/Gl.h>
#include <gl/glut.h>  //OpenGL Utility Toolkit for creating openGL window

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // set white background color
	glColor3f(0.5f, 0.0f, 0.5f);       // set the drawing color 
	glPointSize(.5);                   // a ‘dot’ is 7 by 7 pixels
	glMatrixMode(GL_PROJECTION);    // GL_MODELVIEW (Default), GL_PROJECTION, and GL_TEXTURE
	glLoadIdentity();                // replace the current matrix with the identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);      // Determine The coordinates of window
}

class GLintPoint {
public:
	GLint x, y;
};

void drawDot(GLint x, GLint y)
{ // draw dot at integer point (x, y)
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

int random(int m) { return rand() % m; }

void Sierpinski(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3] = { {50,50},{320,450},{590, 50} };
	int index = random(3); // 0, 1, or 2 equally likely
	GLintPoint point = T[index]; // initial point
	drawDot(point.x, point.y); // draw initial point
	for (int i = 0; i < 100000; i++) // draw 1000 dots
	{
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);   // set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Sierpinski"); // open the screen window
	glutDisplayFunc(Sierpinski); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}