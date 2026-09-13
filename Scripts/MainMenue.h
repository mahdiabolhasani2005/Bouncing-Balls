

#ifndef BP_PROJECT_MAINMENUE_H
#define BP_PROJECT_MAINMENUE_H
SDL_Color normalg = {167,100,2,255};
SDL_Color title = {140,0,0,255};
SDL_Color selectg = {0,0,200,0};


int MainMenue() {
    bool Quit = false , rem;
    int selected = 1;
    mousie mousepos;
    SDL_Surface *t_surface = nullptr;
    SDL_Texture *BKimage = nullptr;
    SDL_Texture *Text0 = nullptr;
    SDL_Texture *Text1 = nullptr;
    SDL_Texture *Text2 = nullptr;
    SDL_Texture *Text3 = nullptr;
    SDL_Texture *Text4 = nullptr;
    int tempw,temph;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    t_surface = SDL_LoadBMP("../Data/BackGround/SteamPunk/AdobeStock_575444700_Preview-transformed (1).bmp");
    cout<<SDL_GetError();
    SDL_Rect BKimage_Rect = {0,0,900,800};
    SDL_Rect BKimage_Rect1;
    if (theme == 1) {
        t_surface = SDL_LoadBMP("../Data/BackGround/SteamPunk/AdobeStock_575444700_Preview-transformed (1).bmp");
        BKimage = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        BKimage_Rect1 = {715, 0, 2570, 2284};
        normalg = {167,100,2,255};
        title = {140,0,0,255};
        selectg = {0,0,200,255};
    } else if (theme == 2){
        t_surface = SDL_LoadBMP("../Data/BackGround/Neon/BKimage.bmp");
        BKimage = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        BKimage_Rect1 = {354, 0, 1291, 1148};
        normalg = {255,255,255,255};
        title = {192,192,192,255};
        selectg = {255,127,80,255};
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    TTF_Font* SDGFont = TTF_OpenFont("../Data/Fonts/SDGlitchRobot.ttf",80);
    TTF_Font* SDGFontL = TTF_OpenFont("../Data/Fonts/SDGlitchRobot.ttf",150);
    t_surface = TTF_RenderText_Solid(SDGFont,"BALL BASH",title);
    Text0 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFontL,"BALL BASH",&tempw,&temph);
    SDL_Rect Text0_Rect = {450-tempw/2,150-temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Play",normalg);
    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Play",&tempw,&temph);
    SDL_Rect Text1_Rect = {450-tempw/2,300-temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",normalg);
    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Leader Board",&tempw,&temph);
    SDL_Rect Text2_Rect = {450-tempw/2,400-temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",normalg);
    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Setting",&tempw,&temph);
    SDL_Rect Text3_Rect = {450-tempw/2,500-temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",normalg);
    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"QUIT",&tempw,&temph);
    SDL_Rect Text4_Rect = {450-tempw/2,600-temph/2,tempw,temph};




    SDL_Event* e = new SDL_Event();

    while (!Quit) {
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer,BKimage, &BKimage_Rect1,&BKimage_Rect);
        SDL_RenderCopy(m_renderer,Text0, nullptr,&Text0_Rect);
        SDL_RenderCopy(m_renderer,Text1, nullptr,&Text1_Rect);
        SDL_RenderCopy(m_renderer,Text2, nullptr,&Text2_Rect);
        SDL_RenderCopy(m_renderer,Text3, nullptr,&Text3_Rect);
        SDL_RenderCopy(m_renderer,Text4, nullptr,&Text4_Rect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(10);
        while (SDL_PollEvent(e))
        {
            if (e->type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&mousepos.x,&mousepos.y);
                if (is_inRect(mousepos.x,mousepos.y,Text1_Rect) && selected != 1) {
                    t_surface = TTF_RenderText_Solid(SDGFont,"Play",selectg);
                    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",normalg);
                    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",normalg);
                    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",normalg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    selected = 1;
                }
                else if (is_inRect(mousepos.x,mousepos.y,Text2_Rect) && selected != 2) {
                    t_surface = TTF_RenderText_Solid(SDGFont,"Play",normalg);
                    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",selectg);
                    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",normalg);
                    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",normalg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    selected = 2;
                }
                else if (is_inRect(mousepos.x,mousepos.y,Text3_Rect) && selected != 3) {
                    t_surface = TTF_RenderText_Solid(SDGFont,"Play",normalg);
                    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",normalg);
                    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",selectg);
                    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",normalg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    selected = 3;
                }
                else if (is_inRect(mousepos.x,mousepos.y,Text4_Rect) && selected != 4) {
                    t_surface = TTF_RenderText_Solid(SDGFont,"Play",normalg);
                    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",normalg);
                    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",normalg);
                    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",selectg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    selected = 4;
                }
                else if(selected != 0 && !is_inRect(mousepos.x,mousepos.y,Text1_Rect) && !is_inRect(mousepos.x,mousepos.y,Text2_Rect) && !is_inRect(mousepos.x,mousepos.y,Text3_Rect) && !is_inRect(mousepos.x,mousepos.y,Text4_Rect)){
                    t_surface = TTF_RenderText_Solid(SDGFont,"Play",normalg);
                    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Leader Board",normalg);
                    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"Setting",normalg);
                    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    t_surface = TTF_RenderText_Solid(SDGFont,"QUIT",normalg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
                    selected = 0;
                }
            }
            if (e->type == SDL_MOUSEBUTTONDOWN )
            {
                if (e->button.button == SDL_BUTTON_LEFT){
                    switch (selected) {
                        case 1:
                            return 1;
                        case 2:
                            return 3;
                        case 3:
                            return 4;
                        case 4:
                            SDL_DestroyTexture(BKimage);
                            SDL_FreeSurface(t_surface);
                            return -1;
                    }
                }
            }
            if (e->type == SDL_KEYDOWN)
            {
                if (e->key.keysym.sym == SDLK_ESCAPE){
                    SDL_DestroyTexture(BKimage);
                    SDL_FreeSurface(t_surface);
                    return -1;
                }
            }
        }
    }
    SDL_DestroyTexture(BKimage);
    SDL_FreeSurface(t_surface);
    return -1;
}

#endif //BP_PROJECT_MAINMENUE_H
