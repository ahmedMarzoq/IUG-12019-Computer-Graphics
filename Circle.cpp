// give it x1 & y1
glBegin(GL_POINTS);
for (int ii = 0; ii < 1000; ii++) {
	float theta = 2.0f * 3.1415926f * float(ii) / float(1000);//get the current angle
	float x = (20 + i) * cosf(theta);//calculate the x component
	float y = (20 + i) * sinf(theta);//calculate the y component
	glVertex2f(x + x1, y + y1);//output vertex
}
glEnd();