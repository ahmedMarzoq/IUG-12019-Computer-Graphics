void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (float ii = 0; ii < num_segments; ii += .5)
	{
		GLfloat angle = ii * 0.0174533;
		glVertex2f(cx, cy);//output vertex
		glVertex2d(cx + (cos(angle) * r), cy + (sin(angle) * r));
	}
	glEnd();
}