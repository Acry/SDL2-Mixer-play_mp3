//BEGIN PROGRAM HEAD
//BEGIN DESCRIPTION
/* SDL2-Mixer-play_mp3:
  * plays mp3 chunk on left mouse button
  */
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
Mix_Chunk *mp3_chunk   = NULL;
//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
//END	FUNCTION PROTOTYPES

/* DEFINED PROGRESS GOALS
 * 
 * todo todo todo
 *
 */
//END 	PROGRAM HEAD

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();
Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
mp3_chunk = Mix_LoadWAV("./start_game.mp3" );
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - Renderer");
SDL_ShowWindow(Window);
SDL_Event event;
int running = 1;
//END   INIT

//BEGIN Event Loop
while(running){
//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				Mix_PlayChannel(-1, mp3_chunk, 0);
			}
		}
	}
//END   EVENT LOOP

//BEGIN RENDERING
SDL_Delay(66);//~15fps
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 255);
SDL_RenderClear(Renderer);
SDL_RenderPresent(Renderer);
//END   RENDERING

}
//END   Event Loop
Mix_FreeChunk(mp3_chunk);
Mix_CloseAudio();
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
