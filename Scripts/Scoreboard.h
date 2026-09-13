
#ifndef BP_PROJECT_SCOREBOARD_H
#define BP_PROJECT_SCOREBOARD_H

#include "GameSelect.h"

int Scoreboard() {
    TTF_Init();
    bool Quit;
    string a = "aaa";
    vector<userRank> sumScoreUsers;
    SDL_Texture *BKimage = nullptr;SDL_Texture *BKimage1 = nullptr;
    SDL_Surface *tempsurface = SDL_LoadBMP("../Data/BackGround/38d8d63e-1075-47fc-af2a-4a78e9dac1f8.bmp");
    SDL_Texture *Btext ;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    BKimage = SDL_CreateTextureFromSurface(m_renderer, tempsurface);
    SDL_Rect BKimage_Rect1 = {0, 0, 900, 800};
    SDL_Rect tempRect = {50, 50, 800, 700};
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    string tempstr;
    vector<user> tempuser = ReadUserFile(true);
    vector<vector<SDL_Texture*>>  temptexture;
    vector<SDL_Texture*>  temptexturerow ={0,0,0,0,0,0};
    vector<vector<SDL_Rect>> temptextRects;
    vector<SDL_Rect> temptextRectsrow = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int tempw,temph;
    SDL_Event* ea = new SDL_Event();
    SDL_Rect BackRect = {};
    mousie mouse = {0,0};
    bool BackSelected = false;

    for (int i = 0; i < tempuser.size(); ++i) {
        for (int j = i + 1; j <tempuser.size() ; ++j) {
            if (tempuser[i].scoreNormal+tempuser[i].scoreInfinity+tempuser[i].scoreTime < tempuser[j].scoreNormal+tempuser[j].scoreInfinity+tempuser[j].scoreTime)
                swap(tempuser[i],tempuser[j]);
        }
    }
    for (int i = 0; i < tempuser.size(); ++i) {
        sumScoreUsers.push_back({tempuser[i].username,tempuser[i].scoreNormal,tempuser[i].scoreTime,tempuser[i].scoreInfinity,tempuser[i].scoreNormal+tempuser[i].scoreInfinity+tempuser[i].scoreTime});
    }

    TTF_Font *font = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 24);
    TTF_Font *SDG = TTF_OpenFont("../Data/Fonts/SDGlitchRobot.ttf", 50);
    TTF_SizeText(SDG,"Back",&BackRect.w,&BackRect.h);
    BackRect = {450 - BackRect.w/2,700 -BackRect.h/2,BackRect.w,BackRect.h};

    for (int i = 0; i < sumScoreUsers.size(); ++i) {
        tempstr = to_string(i+1);
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[0] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[0]= {100 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        tempstr = sumScoreUsers[i].username.c_str();
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[1] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[1] = {255 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        tempstr = to_string(sumScoreUsers[i].scoreNormal);
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[2] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[2] = {426 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        tempstr = to_string(sumScoreUsers[i].scoreTime);
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[3] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[3] = {538 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        tempstr = to_string(sumScoreUsers[i].scoreInfinity);
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[4] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[4] = {650 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        tempstr = to_string(sumScoreUsers[i].sumScores);
        tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
        temptexturerow[5] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
        TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
        temptextRectsrow[5] = {762 - tempw/2,90+50*(i+1) - temph/2,tempw,temph};

        temptexture.push_back(temptexturerow);
        temptextRects.push_back(temptextRectsrow);
    }

    tempstr = "Rank";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[0] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[0]= {100 - tempw/2,90 - temph/2,tempw,temph};

    tempstr = "Name";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[1] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[1] = {255 - tempw/2,90 - temph/2,tempw,temph};

    tempstr = "Normal";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[2] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[2] = {426 - tempw/2,90 - temph/2,tempw,temph};

    tempstr = "Time";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[3] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[3] = {538 - tempw/2,90 - temph/2,tempw,temph};

    tempstr = "Infinite";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[4] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[4] = {650 - tempw/2,90 - temph/2,tempw,temph};

    tempstr = "Sum";
    tempsurface = TTF_RenderText_Solid(font,tempstr.c_str(), {0, 0, 0, 255});
    temptexturerow[5] = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    TTF_SizeText(font,tempstr.c_str(),&tempw,&temph);
    temptextRectsrow[5] = {762 - tempw/2,90 - temph/2,tempw,temph};

    tempsurface = SDL_LoadBMP("../Data/BackGround/image_2024-01-28_221024555.bmp");
    BKimage1 = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
    SDL_SetTextureAlphaMod(BKimage1,100);
    tempsurface = TTF_RenderText_Solid(SDG,"Back",{0,0,0,255});
    Btext = SDL_CreateTextureFromSurface(m_renderer,tempsurface);


    while (!Quit) {
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, BKimage, nullptr, &BKimage_Rect1);
        for (int i = 0; i < sumScoreUsers.size(); ++i) {
            for (int j = 0; j < temptexturerow.size(); ++j) {
                SDL_RenderCopy(m_renderer,temptexture[i][j],NULL,&temptextRects[i][j]);
            }
        }
        SDL_RenderCopy(m_renderer,temptexturerow[0],NULL,&temptextRectsrow[0]);
        SDL_RenderCopy(m_renderer,temptexturerow[1],NULL,&temptextRectsrow[1]);
        SDL_RenderCopy(m_renderer,temptexturerow[2],NULL,&temptextRectsrow[2]);
        SDL_RenderCopy(m_renderer,temptexturerow[3],NULL,&temptextRectsrow[3]);
        SDL_RenderCopy(m_renderer,temptexturerow[4],NULL,&temptextRectsrow[4]);
        SDL_RenderCopy(m_renderer,temptexturerow[5],NULL,&temptextRectsrow[5]);

        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        lineRGBA(m_renderer,60,65,60,615,0,0,0,255);
        lineRGBA(m_renderer,140,65,140,615,0,0,0,255);
        lineRGBA(m_renderer,370,65,370,615,0,0,0,255);
        lineRGBA(m_renderer,482,65,482,615,0,0,0,255);
        lineRGBA(m_renderer,594,65,594,615,0,0,0,255);
        lineRGBA(m_renderer,706,65,706,615,0,0,0,255);
        lineRGBA(m_renderer,818,65,818,615,0,0,0,255);

        for (uint16_t i = 0; i < 12; ++i) {
            lineRGBA(m_renderer, 60, 65+i*50, 818, 65+i*50, 0, 0, 0, 255);
        }

        SDL_RenderCopy(m_renderer,Btext,NULL,&BackRect);

        while (SDL_PollEvent(ea)){
            if (ea->type == SDL_MOUSEMOTION){
                SDL_GetMouseState(&mouse.x,&mouse.y);
                if (is_inRect(mouse.x,mouse.y,BackRect) && !BackSelected){
                    BackSelected = true;
                    tempsurface = TTF_RenderText_Solid(SDG,"Back",{255,0,0,255});
                    Btext = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
                }
                else if(!is_inRect(mouse.x,mouse.y,BackRect) && BackSelected){
                    BackSelected = false;
                    tempsurface = TTF_RenderText_Solid(SDG,"Back",{0,0,0,255});
                    Btext = SDL_CreateTextureFromSurface(m_renderer,tempsurface);
                }
            }
            if (ea->type == SDL_MOUSEBUTTONDOWN )
            {
                if (ea->button.button == SDL_BUTTON_LEFT){
                    if (BackSelected){
                        int imax = sumScoreUsers.size(),jmax = temptexturerow.size();
                        for (int i = 0; i < imax; ++i) {
                            for (int j = 0; j < jmax; ++j) {
                                SDL_DestroyTexture(temptexture[i][j]);
                            }
                            SDL_DestroyTexture(temptexturerow[i]);
                        }
                        SDL_FreeSurface(tempsurface);
                        return 0;
                    }
                }
            }

            if (ea->type == SDL_KEYDOWN){
                if (ea->key.keysym.sym == SDLK_ESCAPE){
                    return -1;
                }
            }
        }
        SDL_RenderPresent(m_renderer);
        SDL_Delay(30);
    }
}

#endif //BP_PROJECT_SCOREBOARD_H
