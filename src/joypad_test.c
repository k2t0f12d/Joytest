#include <SDL.h>
#include <stdio.h>

int main()
{
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);
        
        SDL_Window *win = SDL_CreateWindow("Hardmode Joytest",
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           1600,
                                           900,
                                           SDL_WINDOW_RESIZABLE);
        
        SDL_Renderer *r = SDL_CreateRenderer(win,
                                             -1,
                                             0);

        int joynum = SDL_NumJoysticks();
        SDL_Joystick *joy = NULL;
        for(int i = 0; i < joynum; ++i)
        {
                joy = SDL_JoystickOpen(i);
                if(joy)
                {
                        printf("JOY%d: %s\n", i, SDL_JoystickName(joy));
                        printf("JOY%d: NumAxes: %d\n", i, SDL_JoystickNumAxes(joy));
                        printf("JOY%d: NumBtns: %d\n", i, SDL_JoystickNumButtons(joy));
                        printf("JOY%d: NumBall: %d\n", i, SDL_JoystickNumBalls(joy));
                        printf("JOY%d: NumHats: %d\n", i, SDL_JoystickNumHats(joy));
                }
                else
                {
                        printf("Couldn't open JOY%d\n", i);
                }

                if(SDL_JoystickGetAttached(joy))
                {
                        SDL_JoystickClose(joy);
                }

                joy = NULL;
        }

        SDL_GameController *pad = NULL;
        for(int i = 0; i < joynum; ++i)
        {
                pad = SDL_GameControllerOpen(i);
                if(pad)
                {
                        printf("PAD%d: %s\n", i, SDL_GameControllerName(pad));

                }
        }

        SDL_Quit();
}
