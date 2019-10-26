// give it x1 & y1
for (int i = 0; i < num; i++) {
	glBegin(GL_POLYGON);
	GLint x1 = random(width);
	GLint y1 = random(height);


	for (int ii = 0; ii < 1000; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(1000);//get the current angle
		float x = (20 + i) * cosf(theta);//calculate the x component
		float y = (20 + i) * sinf(theta);//calculate the y component
		glVertex2f(x + x1, y + y1);//output vertex
	}
	GLfloat lev1 = random(10) / 10.0;
	GLfloat lev2 = random(10) / 10.0;
	GLfloat lev3 = random(10) / 10.0;
	glColor3f(lev1, lev2, lev3);
	glEnd();


}
glFlush();