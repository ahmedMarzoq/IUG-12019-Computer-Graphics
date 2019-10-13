/*
 * Chess Board
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
	gluOrtho2D(0.0, 640.0, 0.0, 640.0);      // Determine The coordinates of window
}

void myDisplay(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				glColor3f(0, 0, 0);
			}
			else {
				glColor3f(1, 1, 1);
			}
			glRecti(i * 80, j * 80, 80 * (i + 1), 80 * (j + 1));
		}
	}
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);  // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(640, 640);   // set window size
	glutInitWindowPosition(50, 50); // set window position on screen
	glutCreateWindow("Checker Bourd"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}