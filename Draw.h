
#ifndef _SDL_DRAW_H_
#define _SDL_DRAW_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"

namespace SDLDraw {

	void Rectangle(float x0, float y0, float x1, float y1);
	void Rectangle(float x0, float y0, float x1, float y1, float R, float G, float B);
	void Line(float x0, float y0, float x1, float y1);
	void Line(float x0, float y0, float x1, float y1, float R, float G, float B);
	void Line(float x0, float y0, float x1, float y1, float R, float G, float B, float lw);

};

#endif