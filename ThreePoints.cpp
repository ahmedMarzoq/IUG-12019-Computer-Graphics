/*
 * Three Points
 * IUG 12019 
 * Computer Graphics (Lab)
 */
#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>  //OpenGL Utility Toolkit for creating openGL window

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // set white background color
	glColor3f(0.0f, 0.0f, 0.0f);       // set the drawing color 
	glPointSize(5);                   // a ‘dot’ is 7 by 7 pixels
	glMatrixMode(GL_PROJECTION);    // GL_MODELVIEW (Default), GL_PROJECTION, and GL_TEXTURE
	glLoadIdentity();                // replace the current matrix with the identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);      // Determine The coordinates of window
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	// Draw Lines
	glBegin(GL_POINTS);
	glVertex2i(100, 50);	// First point
	glVertex2i(100, 130);	// Second point	
	glVertex2i(200, 130);  // third point
	glEnd();
	glFush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 480);   // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Drawing Basic Shapes"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}
