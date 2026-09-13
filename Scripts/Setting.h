//
// Created by hooma on 1/3/2024.
//

#ifndef BP_PROJECT_SETTING_H
#define BP_PROJECT_SETTING_H
int Setting(){

    SDL_Event* e = new SDL_Event();
    mousie mousepos ,circle,volume;
    volume.x=420,volume.y=170,circle.y=170,circle.x=volume.x+150;
    bool quit = false,s=false;
    int tempw,temph;
    SDL_Color r4=normalg,r3=normalg,r5=normalg,r16=normalg,r18=normalg,r19=normalg;
    mousie circle1, circle2, volume1, volume2;
    uint8_t  r10=255,r15=255;
    volume1.x = 550, volume1.y = 400;
    volume2.x = 550, volume2.y = 550;
    circle1.x = volume1.x + 150, circle2.x = volume2.x + 150;
    circle1.y = volume1.y, circle2.y = volume2.y;
    bool s1 = false, s2 = false, pausemusic = false;
    SDL_Color r1 = normalg, r7 = normalg, r8 = normalg, r12 = normalg, r13 = normalg;

    SDL_Surface *t_surface = nullptr;
    SDL_Texture *BKimage = nullptr;

    SDL_Texture *Text1 = nullptr;
    SDL_Texture *Text2 = nullptr;
    SDL_Texture *Text3 = nullptr;
    SDL_Texture *Text4 = nullptr;
    SDL_Texture *Text5 = nullptr;
    SDL_Texture *Text6 = nullptr;
    SDL_Texture *Text7 = nullptr;
    SDL_Texture *Text8 = nullptr;
    SDL_Texture *Text9 = nullptr;
    SDL_Texture *Text10 = nullptr;
    SDL_Texture *Text11 = nullptr;
    SDL_Texture *Text12 = nullptr;
    SDL_Texture *Text13 = nullptr;
    SDL_Texture *Text14 = nullptr;
    SDL_Texture *Text15 = nullptr;
    SDL_Texture *Text16 = nullptr;
    SDL_Texture *Text17 = nullptr;
    SDL_Texture *Text18 = nullptr;
    SDL_Texture *Text19 = nullptr;



    TTF_Font* SDGFont = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",37);
    TTF_Font *SDGFontlarge = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 45);
    TTF_Font *SDGFontsmall = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 16);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    t_surface = SDL_LoadBMP("../Data/BackGround/Setting1.bmp");
    BKimage = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    SDL_Rect BKimage_Rect = {0,0,900,800};
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    SDL_Rect Text1_Rect = {volume.x ,volume.y,300,30};

    t_surface = TTF_RenderText_Solid(SDGFont,"Pick a Music",{0,170,255,255});
    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Pick a Music",&tempw,&temph);
    SDL_Rect Text2_Rect = {270 - tempw/2,200 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Mario",{0,170,255,255});
    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Mario",&tempw,&temph);
    SDL_Rect Text3_Rect = {590 - tempw/2,155- temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Spooki",{0,170,255,255});
    Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Spooki",&tempw,&temph);
    SDL_Rect Text4_Rect = {590 - tempw/2,225 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Cooking",{0,170,255,255});
    Text5 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Cooking",&tempw,&temph);
    SDL_Rect Text5_Rect = {590 - tempw/2,295 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFontlarge, "MUSIC", normalg);
    Text6 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontlarge, "MUSIC", &tempw, &temph);
    SDL_Rect Text6_Rect = {210 - tempw / 2, 400 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFontsmall, "ON", normalg);
    Text7 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontsmall, "ON", &tempw, &temph);
    SDL_Rect Text7_Rect = {340 - tempw / 2, 380 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFontsmall, "OFF", normalg);
    Text8 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontsmall, "OFF", &tempw, &temph);
    SDL_Rect Text8_Rect = {340 - tempw / 2, 420 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFont, "Volume", normalg);
    Text9 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFont, "Volume", &tempw, &temph);
    SDL_Rect Text9_Rect = {470 - tempw / 2, 400 - temph / 2, tempw, temph};

    SDL_Rect Text10_Rect = {volume1.x, volume1.y-15, 300, 30};

    t_surface = TTF_RenderText_Solid(SDGFontlarge, "SFX", normalg);
    Text11 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontlarge, "SFX", &tempw, &temph);
    SDL_Rect Text11_Rect = {210 - tempw / 2, 550 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFontsmall, "ON", normalg);
    Text12 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontsmall, "ON", &tempw, &temph);
    SDL_Rect Text12_Rect = {340 - tempw / 2, 530 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFontsmall, "OFF", normalg);
    Text13 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontsmall, "OFF", &tempw, &temph);
    SDL_Rect Text13_Rect = {340 - tempw / 2, 570 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFont, "Volume", normalg);
    Text14 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFont, "Volume", &tempw, &temph);
    SDL_Rect Text14_Rect = {470 - tempw / 2, 550 - temph / 2, tempw, temph};

    SDL_Rect Text15_Rect = {volume2.x, volume2.y-15, 300, 30};


    t_surface = TTF_RenderText_Solid(SDGFont,"BACK",{0,170,255,255});
    Text16 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"BACK",&tempw,&temph);
    SDL_Rect Text16_Rect = {265 - tempw/2,750 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Pick a Theme",{0,170,255,255});
    Text17 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"pick a Theme",&tempw,&temph);
    SDL_Rect Text17_Rect = {270 - tempw/2,650 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Steam Punk",{0,170,255,255});
    Text18 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Steam Punk",&tempw,&temph);
    SDL_Rect Text18_Rect = {590 - tempw/2,620- temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Neon",{0,170,255,255});
    Text19 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Neon",&tempw,&temph);
    SDL_Rect Text19_Rect = {590 - tempw/2,680 - temph/2,tempw,temph};
    circle.x = 300*MusicVolume+volume.x;

    if (Mix_PausedMusic()) {
        r7 = normalg;
        r8 = selectg;
        pausemusic = true;
    } else if (!Mix_PausedMusic()) {
        r7 = selectg;
        r8 = normalg;
        pausemusic = false;
    }
    if (SFXVolume == 0){
        r12 = normalg;
        r13 = selectg;
        circle2.x = volume2.x;
    }else{
        r12 = selectg;
        r13 = normalg;
    }

    circle1.x = 300*MusicVolume+volume1.x;
    circle2.x = 300*SFXVolume+volume2.x;

    while(!quit) {
       r10 = 255, r15 = 255;
       SDL_RenderClear(m_renderer);
       SDL_RenderCopy(m_renderer, BKimage, nullptr, &BKimage_Rect);
       SDL_RenderCopy(m_renderer, Text1, nullptr, &Text1_Rect);
       SDL_RenderCopy(m_renderer, Text2, nullptr, &Text2_Rect);
       SDL_RenderCopy(m_renderer, Text3, nullptr, &Text3_Rect);
       SDL_RenderCopy(m_renderer, Text4, nullptr, &Text4_Rect);
       SDL_RenderCopy(m_renderer, Text5, nullptr, &Text5_Rect);
       SDL_RenderCopy(m_renderer, Text6, nullptr, &Text6_Rect);
       SDL_RenderCopy(m_renderer, Text7, nullptr, &Text7_Rect);
       SDL_RenderCopy(m_renderer, Text8, nullptr, &Text8_Rect);
       SDL_RenderCopy(m_renderer, Text9, nullptr, &Text9_Rect);
       SDL_RenderCopy(m_renderer, Text10, nullptr, &Text10_Rect);
       SDL_RenderCopy(m_renderer, Text11, nullptr, &Text11_Rect);
       SDL_RenderCopy(m_renderer, Text12, nullptr, &Text12_Rect);
       SDL_RenderCopy(m_renderer, Text13,nullptr, &Text13_Rect);
       SDL_RenderCopy(m_renderer, Text14, nullptr, &Text14_Rect);
       SDL_RenderCopy(m_renderer, Text15,nullptr, &Text15_Rect);
       SDL_RenderCopy(m_renderer, Text16, nullptr, &Text16_Rect);
        SDL_RenderCopy(m_renderer, Text17, nullptr, &Text17_Rect);
        SDL_RenderCopy(m_renderer, Text18,nullptr, &Text18_Rect);
        SDL_RenderCopy(m_renderer, Text19, nullptr, &Text19_Rect);
       if (s1) {

           circle1.x = mousepos.x;
           r10 = 100;
           MusicVolume = (mousepos.x - volume1.x) / 300.0;
           Mix_VolumeMusic(MIX_MAX_VOLUME*MusicVolume);
       } else if (s2) {
           circle2.x = mousepos.x;
           r15 = 100;
           SFXVolume = (mousepos.x - volume2.x) / 300.0;
           Mix_Volume(-1,SFXVolume*MIX_MAX_VOLUME);
       }
       while (SDL_PollEvent(e)) {
           if (e->type == SDL_MOUSEMOTION) {
               SDL_GetMouseState(&mousepos.x, &mousepos.y);
           }
           if (e->type == SDL_MOUSEBUTTONUP) {
               s1 = false;
               s2 = false;
           }

           if (is_inRect(mousepos.x, mousepos.y, Text10_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN)
                   s1 = true;
           }
           if (is_inRect(mousepos.x, mousepos.y, Text15_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   s2 = true;
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text7_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN && pausemusic) {
                   pausemusic = false;
                   if (Mix_PausedMusic() == 1) {
                       Mix_ResumeMusic();
                   }
                   r7 = selectg;
                   r8 = normalg;
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text8_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN && !pausemusic) {
                   pausemusic = true;
                   Mix_PauseMusic();
                   r7 = normalg;
                   r8 = selectg;
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text12_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   r12 = selectg;
                   r13 = normalg;
                   Mix_Volume(-1,SFXVolume*MIX_MAX_VOLUME);
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text13_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   r12 = normalg;
                   r13 = selectg;
                   SFXVolume = 0;
                   Mix_Volume(-1,0);
                   circle2.x = volume2.x;
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text3_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   CMusic = Music1;
                   r3 = selectg;
                   r4 = normalg;
                   r5 = normalg;
                   Mix_PlayMusic(CMusic,1000);
                   cout<<Mix_GetError();
               }
           } else if (is_inRect(mousepos.x, mousepos.y, Text4_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   CMusic = Music2;
                   r3 = normalg;
                   r4 = selectg;
                   r5 =normalg;
                   Mix_PlayMusic(CMusic,1000);
               }
           } else if (is_inRect(mousepos.x, mousepos.y, Text5_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   CMusic = Music3;
                   r3 = normalg;
                   r4 = normalg;
                   r5 = selectg;
                   Mix_PlayMusic(CMusic,1000);
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text18_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   theme=1;
                   r18 = selectg;
                   r19 = normalg;
                   normalg = {167,100,2,255};
                   title = {140,0,0,255};
                   selectg = {0,0,200,0};
               }
           } else if (is_inRect(mousepos.x, mousepos.y, Text19_Rect)) {
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   theme=2;
                   r18 = normalg;
                   r19 = selectg;
                   normalg = {255,255,255,255};
                   title = {192,192,192,255};
                   selectg = {255,127,80,255};
               }
           }
           if (is_inRect(mousepos.x, mousepos.y, Text16_Rect)) {
               r16 = selectg;
               if (e->type == SDL_MOUSEBUTTONDOWN) {
                   SDL_DestroyTexture(Text1);
                   SDL_DestroyTexture(Text2);
                   SDL_DestroyTexture(Text3);
                   SDL_DestroyTexture(Text4);
                   SDL_DestroyTexture(Text5);
                   SDL_DestroyTexture(Text6);
                   SDL_DestroyTexture(Text7);
                   SDL_DestroyTexture(Text8);
                   SDL_DestroyTexture(Text9);
                   SDL_DestroyTexture(Text10);
                   SDL_DestroyTexture(Text11);
                   SDL_DestroyTexture(Text12);
                   SDL_DestroyTexture(Text13);
                   SDL_DestroyTexture(Text15);
                   SDL_DestroyTexture(Text16);
                   SDL_DestroyTexture(Text14);
                   SDL_DestroyTexture(Text17);
                   SDL_DestroyTexture(Text18);
                   SDL_DestroyTexture(Text19);
                   SDL_FreeSurface(t_surface);
                   return 0;
               }
           } else {
               r16 = normalg;
           }
       }
//       if(s){
//           circle.x=mousepos.x;
//           r=255;
//           MusicVolume=(mousepos.x-volume.x)/300.0;
//           Mix_VolumeMusic(MIX_MAX_VOLUME*MusicVolume);
//       }
        filledCircleRGBA(m_renderer, circle1.x, circle1.y, 6, r10, 255, 255, 255);
        thickLineRGBA(m_renderer, volume1.x, volume1.y, volume1.x + 300, volume1.y, 5, 255, 255, 255, 255);
        filledCircleRGBA(m_renderer, circle2.x, circle2.y, 6, r15, 255, 255, 255);
        thickLineRGBA(m_renderer, volume2.x, volume2.y, volume2.x + 300, volume2.y, 5, 255, 255, 255, 255);
        t_surface = TTF_RenderText_Solid(SDGFont,"Mario",r3);
       Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
       t_surface = TTF_RenderText_Solid(SDGFont,"Spook",r4);
       Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
       t_surface = TTF_RenderText_Solid(SDGFont,"Cooking",r5);
       Text5 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
       t_surface = TTF_RenderText_Solid(SDGFont,"BACK",r16);
       Text16 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "OFF", r8);
        Text8 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "ON", r7);
        Text7 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "ON", r12);
        Text12 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "OFF", r13);
        Text13 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont,"Steam Punk",r18);
        Text18 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont,"Neon",r19);
        Text19 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
       SDL_RenderPresent(m_renderer);
       SDL_Delay(30);
   }
}
#endif //BP_PROJECT_SETTING_H
