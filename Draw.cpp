
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