#include <iostream>
#include <SDL.h>

int main (int argc, char* argv[]){

    SDL_Window* window = nullptr;

    if (SDL_Init (SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not br initialized: " <<
                    SDL_GetError ();
    } else {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow ("C++ SDL Window", 
            0,
            0,
            640,
            480,
            SDL_WINDOW_SHOWN);
    if (window == NULL){
        std::cout << "Could not create window:" <<
                SDL_GetError ();
        return 1;
    }
    SDL_Delay (5000);
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
}
    SDL_DestroyWindow (window);
    SDL_Quit ();
    
    return 0;
}
