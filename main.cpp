#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"

bool update( int dt ) {

	return true;
}

void draw() {

}

int main ( int agrc, char ** argv ) {

	auto gameloop = true;

	int lastframe = 0;
	int delta = 0;

	if ( SDL_Init (SDL_INIT_EVERYTHING) == -1 ) {
		printf("SDL_ERROR: SDL_INIT_EVERYTHING");
		gameloop = false;
	}

	if ( IMG_Init (IMG_INIT_PNG) == -1 ) {

		printf("SDL_ERROR: IMG_INIT_PNG");
		gameloop = false;
	}

	if ( TTF_Init() == -1 ) {
		printf("SDL_ERROR: TTF_INIT");
		gameloop = false;

	}

	auto window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if ( window == NULL ) {
		gameloop = false;
		printf("SDL_ERROR: Window init failed.");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	auto context = SDL_GL_CreateContext(window);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glOrtho(0,800,600,0,-1,1);

	while ( gameloop ) {

		SDL_Event e;
		while ( SDL_PollEvent(&e) ) {
			if ( e.type == SDL_QUIT) {
				gameloop = false;
			}
		}

		update(delta);
		draw();

		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);

		auto currentframe = SDL_GetTicks();

		delta = currentframe - lastframe;

		lastframe = currentframe;
	}


	glDisable(GL_BLEND);

	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();

	TTF_Quit();
	return 0;
}
