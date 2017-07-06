
#include "Draw.h"


void SDLDraw::Rectangle(float x0, float y0, float x1, float y1) {

	glColor3f(1,1,1);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(x0,y0);

	glTexCoord2f(1,0);
	glVertex2f(x1,y0);

	glTexCoord2f(1,1);
	glVertex2f(x1,y1);

	glTexCoord2f(0,1);
	glVertex2f(x0,y1);

	glEnd();
}
void SDLDraw::Rectangle(float x0, float y0, float x1, float y1, float R, float G, float B) {

	glColor3f(R,G,B);
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex2f(x0,y0);

	glTexCoord2f(1,0);
	glVertex2f(x1,y0);

	glTexCoord2f(1,1);
	glVertex2f(x1,y1);

	glTexCoord2f(0,1);
	glVertex2f(x0,y1);

	glEnd();
}

void SDLDraw::Line(float x0, float y0, float x1, float y1) {

	glLineWidth(1.f);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_LINES);
	glVertex2f(x0,y0);
	glVertex2f(x1,y1);
	glEnd();
}
void SDLDraw::Line(float x0, float y0, float x1, float y1, float R, float G, float B){

	glLineWidth(1.f);
	glColor3f(R,G,B);
	glBegin(GL_LINES);
	glVertex2f(x0,y0);
	glVertex2f(x1,y1);
	glEnd();
}

void SDLDraw::Line(float x0, float y0, float x1, float y1, float R, float G, float B, float lw){

	glLineWidth(lw);
	glColor3f(R,G,B);
	glBegin(GL_LINES);
	glVertex2f(x0,y0);
	glVertex2f(x1,y1);
	glEnd();
}
