#include <bits/stdc++.h>
#include <fstream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_ttf.h>

SDL_Window* m_window;
SDL_Renderer* m_renderer;
TTF_Font* mmFont;
Mix_Music* CMusic = nullptr;
Mix_Music* Music1 = nullptr;
Mix_Music* Music2 = nullptr;
Mix_Music* Music3 = nullptr;
Mix_Chunk* POP= nullptr;
Mix_Chunk* Collide= nullptr;
Mix_Chunk* Bounce= nullptr;
Mix_Chunk* Shoot= nullptr;
Mix_Chunk* Cheering= nullptr;
Mix_Chunk* PlasmaballSound= nullptr;
Mix_Chunk* BombSound= nullptr;
double MusicVolume = 0.5;
double SFXVolume = 0.5;
using namespace std;
uint8_t theme = 1;

//include here
#include "Scripts/Essentials.h"
#include "Scripts/MainMenue.h"
#include "Scripts/Scoreboard.h"
#include "Scripts/Gameover.h"
#include "Scripts/Setting.h"
#include "Scripts/Game_normal.h"
#include "Scripts/Game_time.h"
#include "Scripts/Game_unlimited.h"
#include "Scripts/GameSelect.h"


//include end

int main(int argc, char * argv[] ){
    bool Quit = false;
    int Screenw = 900, Screenh = 800 , n=0;
    Uint32 WND_flags = SDL_WINDOW_SHOWN  ;
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS  );
    m_window = SDL_CreateWindow("BallBash",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Screenw,Screenh,SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
    TTF_Init();
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "3");
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 1024) == -1)
    {
        cout<<Mix_GetError();
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME*MusicVolume);
    Mix_Volume(-1,MIX_MAX_VOLUME*SFXVolume);
    CMusic = Mix_LoadMUS("../Data/Music/x2mate.com - Tokyo Blur - Mario Kart Tour [OST] (128 kbps).mp3");
    if(CMusic == NULL){
        cout<<"failed to load music:" << Mix_GetError();
    }
    Mix_PlayMusic(CMusic,1000);

    Music1 = Mix_LoadMUS("../Data/Music/x2mate.com - Tokyo Blur - Mario Kart Tour [OST] (128 kbps).mp3");
    Music2 = Mix_LoadMUS("../Data/Music/peritune-spook4(chosic.com).mp3");
    Music3 = Mix_LoadMUS("../Data/Music/Cooking-Long-Version(chosic.com).mp3");
    POP = Mix_LoadWAV("../Data/SFX/POPnew.wav");
    Bounce = Mix_LoadWAV("../Data/SFX/plastic-ball-bounce-14790- (mp3cut.net).wav");
    Collide = Mix_LoadWAV("../Data/SFX/Metal balls impact - Sound Effect (SFX) (mp3cut.net).wav");
    Shoot = Mix_LoadWAV("../Data/SFX/Shootnew.wav");
    PlasmaballSound = Mix_LoadWAV("../Data/SFX/plasmaballsound.wav");
    BombSound = Mix_LoadWAV("../Data/SFX/BombSound.wav");
    Cheering = Mix_LoadWAV("../Data/SFX/cheering.mp3");

    while(!Quit) {
        switch (n) {
            case 0:
                n = MainMenue();
                break;
            case 1:
                n = GameSelect();
                break;
            case 2:
                n = GameOver();
                break;
            case 3:
                n = Scoreboard();
                break;
            case 4:
                n = Setting();
                break;
            case 10:
                //n = Game_normal();
                break;
            case 11:
                n = Game_time({},20);
                break;
            case 12:
                //n = Game_unlimited();
                break;
            case -1:
                Quit = true;
                break;
            default:
                break;
        }
    }


    return 0;
}

