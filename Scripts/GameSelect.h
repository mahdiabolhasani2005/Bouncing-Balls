//
// Created by hooma on 1/3/2024.
//

#ifndef BP_PROJECT_GAMESELECT_H
#define BP_PROJECT_GAMESELECT_H


#include "Game_normal.h"

using namespace std;
int Game_time(vector<user> users,int row);
int Game_unlimited(vector<user> users,int row);

int userFound(vector<user>& users , string username);
int GameSelect() {
    vector<user> users;
    bool quit = false,ft = true,renderText = true;
    SDL_Event* e = new SDL_Event();
    mousie mousepos;
    int selected=0,modselect=1;
    SDL_Texture *gozineha[7];
    SDL_Surface *t_surface = nullptr;
    SDL_Texture *BKimage = nullptr;
    SDL_Texture *Text0 = nullptr;
    SDL_Texture *Text1 = nullptr;
    SDL_Texture *Text2 = nullptr;
    SDL_Texture *Text3 = nullptr;
    SDL_Texture *Text4 = nullptr;
    SDL_Texture *Text5 = nullptr;
    SDL_Texture *Text6 = nullptr;
    SDL_Texture *Text7 = nullptr;
    SDL_Texture *TempText = nullptr;
    int tempw,temph;
    SDL_Rect TempRect;
    TTF_Font* SDGFont = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",37);
    TTF_Font* SDGFontlarge = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",45);
    TTF_Font* SDGFontsmall = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",16);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    t_surface = SDL_LoadBMP("../Data/BackGround/Setting1.bmp");
    BKimage = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    SDL_Rect BKimage_Rect = {0,0,900,800};
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    t_surface = TTF_RenderText_Solid(SDGFont,"Enter Your Username:",normalg);
    Text0 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Enter Your Username",&tempw,&temph);
    SDL_Rect Text0_Rect = {240 - tempw/2,200 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"USERNAME",normalg);
    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"USERNAME",&tempw,&temph);
    SDL_Rect Text1_Rect = {240 - tempw/2,280 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"NORMAL",normalg);
    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontlarge,"NORMAL",&tempw,&temph);
    SDL_Rect Text2_Rect = {700 - tempw/2,150 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"LIMITED TIME",normalg);
    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontlarge,"LIMITED TIME",&tempw,&temph);
    SDL_Rect Text3_Rect = {700 - tempw/2,300 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"UNLIMITED" ,normalg);
    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontlarge,"UNLIMITED",&tempw,&temph);
    SDL_Rect Text4_Rect = {700 - tempw/2,450 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"BACK" ,normalg);
    Text5 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontlarge,"BACK",&tempw,&temph);
    SDL_Rect Text5_Rect = {200 - tempw/2,700 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"PLAY",normalg);
    Text6 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontlarge,"PLAY",&tempw,&temph);
    SDL_Rect Text6_Rect = {700 - tempw/2,700 - temph/2,tempw,temph};

    SDL_SetTextInputRect(&Text1_Rect);
    gozineha[1]=Text1;
    gozineha[2]=Text2;
    gozineha[3]=Text3;
    gozineha[4]=Text4;
    gozineha[5]=Text5;
    gozineha[6]=Text6;
    SDL_Texture *copygozineha[7];
    for(int i=1;i<7;i++){
        copygozineha[i]=gozineha[i];
    }
    string username="Username";
    users=ReadUserFile(true);
    t_surface = TTF_RenderText_Solid(SDGFont, "NORMAL", selectg);
    copygozineha[2] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    modselect =2;
    SDL_StopTextInput();
    while(!quit) {
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, BKimage,nullptr, &BKimage_Rect);
        SDL_RenderCopy(m_renderer, Text0,nullptr, &Text0_Rect);
        //SDL_RenderCopy(m_renderer, copygozineha[1], nullptr, &Text1_Rect);
        SDL_RenderCopy(m_renderer, copygozineha[2], nullptr, &Text2_Rect);
        SDL_RenderCopy(m_renderer, copygozineha[3], nullptr, &Text3_Rect);
        SDL_RenderCopy(m_renderer, copygozineha[4], nullptr, &Text4_Rect);
        SDL_RenderCopy(m_renderer, copygozineha[5], nullptr, &Text5_Rect);
        SDL_RenderCopy(m_renderer, copygozineha[6], nullptr, &Text6_Rect);
        if (renderText) {
            t_surface = TTF_RenderText_Solid(SDGFont, username.c_str(), normalg);
            TTF_SizeText(SDGFontlarge, username.c_str(), &tempw, &temph);
            TempText = SDL_CreateTextureFromSurface(m_renderer, t_surface);
            TempRect = {240 - tempw / 2, 280 - temph / 2, tempw, temph};
            renderText = false;
        }
        SDL_RenderCopy(m_renderer,TempText,NULL,&TempRect);
        while (SDL_PollEvent(e)) {
            if (e->type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mousepos.x, &mousepos.y);
                if (is_inRect(mousepos.x, mousepos.y, Text1_Rect) && selected != 1) {
                    selected = 1;
                } else if (is_inRect(mousepos.x, mousepos.y, Text2_Rect) && selected != 2) {
                    selected = 2;
                } else if (is_inRect(mousepos.x, mousepos.y, Text3_Rect) && selected != 3) {
                    selected = 3;
                } else if (is_inRect(mousepos.x, mousepos.y, Text4_Rect) && selected != 4) {
                    selected = 4;
                } else if (is_inRect(mousepos.x, mousepos.y, Text5_Rect) && selected != 5) {
                    t_surface = TTF_RenderText_Solid(SDGFont, "BACK", selectg);
                    copygozineha[5] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                    if (selected != 0) {
                        copygozineha[selected] = gozineha[selected];
                    }
                    selected = 5;
                } else if (is_inRect(mousepos.x, mousepos.y, Text6_Rect) && selected != 6) {
                    t_surface = TTF_RenderText_Solid(SDGFont, "PLAY", selectg);
                    copygozineha[6] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                    if (selected != 0) {
                        copygozineha[selected] = gozineha[selected];
                    }
                    selected = 6;
                } else if (selected != 0 && !is_inRect(mousepos.x, mousepos.y, Text1_Rect) &&
                           !is_inRect(mousepos.x, mousepos.y, Text2_Rect)
                           && !is_inRect(mousepos.x, mousepos.y, Text3_Rect) &&
                           !is_inRect(mousepos.x, mousepos.y, Text4_Rect)
                           && !is_inRect(mousepos.x, mousepos.y, Text5_Rect) &&
                           !is_inRect(mousepos.x, mousepos.y, Text6_Rect)) {
                    if (selected !=2 && selected !=3 &&selected !=4 && selected !=1) {
                        copygozineha[selected] = gozineha[selected];
                    }
                    selected = 0;
                }
            }

            if (e->type == SDL_MOUSEBUTTONDOWN) {
                if (e->button.button == SDL_BUTTON_LEFT) {
                    switch (selected) {
                        case 0:
                            if (SDL_IsTextInputActive())
                                SDL_StopTextInput();
                            if (username == ""){
                                username = "Username";
                                ft = true;
                            }
                            renderText = true;
                            break;
                        case 1:
                            if (!SDL_IsTextInputActive())
                            {
                                if(ft){
                                    username = "";
                                    ft = false;
                                }
                                SDL_StartTextInput();
                                renderText = true;
                            }
                            break;
                        case 2:
                            if (modselect != 2) {
                                t_surface = TTF_RenderText_Solid(SDGFont, "NORMAL", selectg);
                                copygozineha[2] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                                copygozineha[modselect] = gozineha[modselect];
                                modselect = 2;
                            }
                            break;
                        case 3:
                            if (modselect != 3) {
                                t_surface = TTF_RenderText_Solid(SDGFont, "LIMITED TIME", selectg);
                                copygozineha[3] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                                copygozineha[modselect] = gozineha[modselect];
                                modselect = 3;
                            }
                            break;
                        case 4:
                            if (modselect != 4) {
                                t_surface = TTF_RenderText_Solid(SDGFont, "UNLIMITED", selectg);
                                copygozineha[4] = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                                copygozineha[modselect] = gozineha[modselect];
                                modselect = 4;
                            }
                            break;
                        case 5:
                            return 0;
                            break;
                        case 6:
                            if (userFound(users, username) != -1) {
                                swap(users[userFound(users, username)],users[0]);
                            } else {
                                users.insert(users.begin(), {username, 0,0,0});
                            }
                            switch (modselect) {
                                case 2:
                                    return Game_normal(users,20);
                                    break;
                                case 3:
                                    return Game_time(users,20);
                                    break;
                                case 4:
                                    return Game_unlimited(users,20);
                                    break;
                            }
                            break;
                    }
                }
            }
            if (e->type == SDL_KEYDOWN){
                if (e->key.keysym.sym == SDLK_BACKSPACE && SDL_IsTextInputActive()) {
                    if (!username.empty()) {
                        username.pop_back();
                        renderText = true;
                    }
                }
                if (e->type == SDLK_RETURN && SDL_IsTextInputActive()){
                    if (userFound(users, username) != -1) {
                        users.insert(users.begin(), {username, users[userFound(users, username)].scoreNormal,
                                                     users[userFound(users, username)].scoreTime,
                                                     users[userFound(users, username)].scoreInfinity});
                        users.erase(users.begin() + userFound(users, username));
                    } else {
                        users.insert(users.begin(), {username, 0});
                    }
                }
            }
            else if( e->type == SDL_TEXTINPUT )
            {
                    username += e->text.text;
                    renderText = true;
            }
        }
        SDL_RenderPresent(m_renderer);
        SDL_Delay(30);
    }
}
int userFound(vector<user>& users , string username){
    for(int i=0;i<users.size();i++){
        if(username==users[i].username){
            return i;
        }
    }
    return -1;
}

#endif //BP_PROJECT_GAMESELECT_H