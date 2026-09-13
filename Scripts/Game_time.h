//
// Created by hooma on 1/3/2024.
//

#ifndef BP_PROJECT_GAME_TIME_H
#define BP_PROJECT_GAME_TIME_H
int Game_time(vector<user> users,int row){
    SDL_RenderClear(m_renderer);
    int score = 0;
    //==================================================================================================================
    //cordinate system and ball movement
    SDL_Rect PlayBound = {90,0,738,660};
    bool inflight = false,exploded = false,Pause = false,pauseability = false,slowmotionability = false,pauseavailable = true,slowmotionavailable = true;
    uint32_t abilityinit,ability = 5000;
    mokhtasat cannon = {450,730},v,location = {450,730},temppos;
    mousie mouse,tempmouse,lasermouse;
    double dt = (double )TICK_INTERVAL/1000 ,speed = 600;
    int Ycheck,StopCounter = 100,temp,lasercounter,laserb = false,fallchange = false;
    vector<FallingBall> FB;
    double angle = 0,angle2;
    int explodenumber =0;
    int k = 0,shelikshode =0,tempint,tempw,temph;
    uint32_t InitTime,Timenow,Titimeleft,Timeinit,Timeall = 90000;
    //==================================================================================================================
    //image loading
    SDL_Surface* tosurface = SDL_LoadBMP("../Data/ChristmasBalls/01.bmp");
    SDL_Texture* Btexture1 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/ChristmasBalls/06.bmp");
    SDL_Texture* Btexture2 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/ChristmasBalls/08.bmp");
    SDL_Texture* Btexture3 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/ChristmasBalls/12.bmp");
    SDL_Texture* Btexture4 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/ChristmasBalls/14.bmp");
    SDL_Texture* Btexture5 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/Canon/plasmaball.bmp");
    SDL_Texture* Btexture6 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/Canon/Bomb.bmp");
    SDL_Texture* Btexture7 = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/Canon/RainbowBall.bmp");
    SDL_Texture* RainbowBallText = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/BackGround/—Pngtree—space game planet surface landscape_1591282.bmp");
    SDL_Texture* BKimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/Canon/2024012722837.bmp");
    SDL_Texture* Canonimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/BackGround/SteamPunk/image_2024-01-31_195520494-transformed (1).png");
    SDL_Texture* wallimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/kenney_ui-pack-space-expansion/pause.bmp");
    SDL_Texture* PauseButton =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/BackGround/piston.bmp");
    SDL_Texture* PistonImage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/kenney_ui-pack-space-expansion/PauseAbility.bmp");
    SDL_Texture* PauseAbilityText =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/kenney_ui-pack-space-expansion/SlowMotion.bmp");
    SDL_Texture* SlowdownAbilityText =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/Animation/ExplodeAnimation.bmp");
    SDL_Texture* AText = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    tosurface = SDL_LoadBMP("../Data/BackGround/Neon/WallDownNeon.bmp");
    SDL_Texture* WallimageDown = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    SDL_Texture* TimerText;

    cout<<SDL_GetError();
    SDL_Rect Bkrects = {0,0,900,800};
    SDL_Rect Bkrecti = {487,0,3986,3543};
    SDL_Rect wallLeft={0,0,PlayBound.x,Bkrects.h};
    SDL_Rect wallRight={PlayBound.w+PlayBound.x,0,Bkrects.w-PlayBound.w-PlayBound.x,Bkrects.h};
    SDL_Rect wallDown={PlayBound.x ,PlayBound.h , PlayBound.w , 140};
    SDL_Rect wallLefti={740,0,252,2240};
    SDL_Rect wallRighti={3058,0,202,2240};
    SDL_Rect wallDowni={992,1848,2066,392};
    SDL_Rect wallrecti = {0,0,1280,832};
    SDL_Rect temprect;
    SDL_Rect tempiRect;
    SDL_Rect BallRect = {10,10,492,492};
    SDL_Rect PlasmaBallRect = {350,20,900,900};
    SDL_Rect BombBallRect = {280,470,885,890};
    SDL_Rect RainbowBallRect = {234,115,1649,1650};
    SDL_Rect CanonRect = {400,650,100,120};
    SDL_Rect PauseRect = {0,0,50,50};
    SDL_Rect PistonRect = {PlayBound.x,900,Bkrects.w-PlayBound.x,900};
    SDL_Rect SlowMotionRect = {100,0,50,50};
    SDL_Rect PauseAbilityRect = {150,0,50,50};
    SDL_Rect TimerRect;
    SDL_Point Center = {50,80};


    //==================================================================================================================
    //event initializer
    SDL_Event* e = new SDL_Event();
    bool Quit = false;
    string timeleft;


    tosurface = SDL_LoadBMP("../Data/Canon/Ghofl.bmp");
    SDL_Texture* GhoflText = SDL_CreateTextureFromSurface(m_renderer,tosurface);
    //==================================================================================================================
    //ballfield constructor
    BallField BF;
    vector<vector<uint8_t>> valid;
    vector<vector<uint8_t>> Explode;
    vector<vector<uint8_t>> Exploding;
    vector<uint8_t> validrow;
    vector<bool> ValidC = {false,false,false,false,false};
    TTF_Font *font = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 24);

    //==================================================================================================================
    //temp balls
    BF.CreateBallField(2*row,row);
    //==================================================================================================================

    for (int i = 0; i < BF.Balls[0].size(); ++i) {
        validrow.push_back(0);
    }
    for (int i = 0; i < BF.Balls.size(); ++i) {
        valid.push_back(validrow);
        Explode.push_back(validrow);
        Exploding.push_back(validrow);
    }
    next_time = SDL_GetTicks();

    if (theme == 1){
        tosurface = SDL_LoadBMP("../Data/BackGround/SteamPunk/SteamPunkBKimage.bmp");
        BKimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
        Bkrecti = {0,0,1620,1440};
        wallLefti={740,0,252,2240};
        wallRighti={3058,0,202,2240};
        wallDowni={992,1848,2066,392};
        tosurface = SDL_LoadBMP("../Data/BackGround/SteamPunk/AdobeStock_575444700_Preview-transformed (1).bmp");
        wallimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    }else if (theme == 2){
        tosurface = SDL_LoadBMP("../Data/BackGround/Neon/NeonBKimage.bmp");
        BKimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
        Bkrecti = {375,0,2250,2000};
        wallLefti={0,0,328,2240};
        wallRighti={0,0,328,2240};
        wallDowni={276,0,1687,324};
        tosurface = SDL_LoadBMP("../Data/BackGround/Neon/WallNeon.bmp");
        wallimage =  SDL_CreateTextureFromSurface(m_renderer,tosurface);
    }

    InitTime = SDL_GetTicks();
    Timeinit = SDL_GetTicks();
    while (!Quit) {
        if (!Pause) {
            SDL_RenderClear(m_renderer);
            PistonRect.y = BF.ball0.y-918;
            SDL_RenderCopy(m_renderer, BKimage, &Bkrecti, &Bkrects);
            SDL_RenderCopy(m_renderer, PistonImage, NULL, &PistonRect);
            for (int i = 0; i < FB.size(); ++i) {
                for (int j = 0; j < FB[i].ball.size(); ++j) {
                    for (int l = 0; l < 20; ++l) {
                        if (FB[i].ball[j][l] != 0) {
                            temppos = { BF.BallLocation({j,l}).x,(double )(FB[i].y-BF.ball0.y) + BF.BallLocation({j,l}).y};
                            temprect = {(int) temppos.x - BF.radious, (int) temppos.y - BF.radious, 2 * BF.radious,
                                        2 * BF.radious};
                            if (FB[i].ball[j][l] == 1)
                                SDL_RenderCopy(m_renderer, Btexture1, &BallRect, &temprect);
                            if (FB[i].ball[j][l] == 2)
                                SDL_RenderCopy(m_renderer, Btexture2, &BallRect, &temprect);
                            if (FB[i].ball[j][l] == 3)
                                SDL_RenderCopy(m_renderer, Btexture3, &BallRect, &temprect);
                            if (FB[i].ball[j][l] == 4)
                                SDL_RenderCopy(m_renderer, Btexture4, &BallRect, &temprect);
                            if (FB[i].ball[j][l] == 5)
                                SDL_RenderCopy(m_renderer, Btexture5, &BallRect, &temprect);
                        }
                    }
                }
            }
            SDL_RenderCopy(m_renderer, wallimage, &wallLefti, &wallLeft);
            SDL_RenderCopy(m_renderer, wallimage, &wallRighti, &wallRight);
            if (theme == 1)
                SDL_RenderCopy(m_renderer, wallimage, &wallDowni, &wallDown);
            else
                SDL_RenderCopy(m_renderer, WallimageDown, &wallDowni, &wallDown);
            SDL_RenderCopy(m_renderer, PauseButton, NULL, &PauseRect);
            if (pauseability||slowmotionability){
                if (SDL_GetTicks()>abilityinit+ability){
                    if (pauseability)
                        pauseability = false;
                    else
                        slowmotionability = false;
                }
            }
            if (!pauseability && !slowmotionability)
                BF.ball0.y += speedofball0(StopCounter) * dt;
            if (!pauseability && slowmotionability)
                BF.ball0.y += speedofball0(StopCounter) * dt/3;
            if (pauseability )
                BF.ball0.y += 0;


            while (BF.inputBalls.size() < 3) {
                ValidC = BF.ValidColor();
                temp = rand() % 5;
                if(rand()%20==0){
                    BF.inputBalls.push_back(6);
                }else if(rand()%20==1){
                    BF.inputBalls.push_back(7);
                }else if(rand()%20==1){
                    BF.inputBalls.push_back(8);
                }
                else {
                    while (!ValidC[temp]) {
                        temp = rand() % 5;
                    }
                    BF.inputBalls.push_back(temp + 1);
                }
            }
            while (SDL_PollEvent(e)) {
                if (e->type == SDL_MOUSEMOTION) {
                    SDL_GetMouseState(&mouse.x, &mouse.y);
                    if (mouse.y >= 720) {
                        mouse.y = 720;
                    }
                    if(laserb) {
                        angle = atan((lasermouse.x - cannon.x) / (-lasermouse.y + cannon.y)) * 180 / M_PI;
                    }else{
                        angle = atan((mouse.x - cannon.x) / (-mouse.y + cannon.y)) * 180 / M_PI;
                    }
                }

                if (e->type == SDL_MOUSEBUTTONDOWN) {
                    if (e->button.button == SDL_BUTTON_LEFT) {
                        SDL_GetMouseState(&tempmouse.x, &tempmouse.y);
                        if (is_inRect(tempmouse.x, tempmouse.y, {350, 730, 2 * BF.radious, 2 * BF.radious}) &&
                            !inflight) {
                            swap(BF.inputBalls[1], BF.inputBalls[0]);
                        } else if (is_inRect(tempmouse.x, tempmouse.y, PauseRect)) {
                            Pause = true;
                        } else if (is_inRect(tempmouse.x, tempmouse.y, PauseAbilityRect) && pauseavailable && !pauseability&&!slowmotionability) {
                            pauseability = true;
                            pauseavailable = false;
                            abilityinit = SDL_GetTicks();
                        } else if (is_inRect(tempmouse.x, tempmouse.y, SlowMotionRect) && slowmotionavailable && !pauseability&&!slowmotionability) {
                            slowmotionability = true;
                            slowmotionavailable = false;
                            abilityinit = SDL_GetTicks();
                        }else if (!inflight) {
                            if (BF.inputBalls[0] != 6) {
                                Mix_PlayChannel(-1, Shoot, 0);
                                inflight = true;
                                v.x = speed * (mouse.x - cannon.x) /
                                      sqrt((mouse.x - cannon.x) * (mouse.x - cannon.x) +
                                           (mouse.y - cannon.y) * (mouse.y - cannon.y));
                                v.y = speed * (mouse.y - cannon.y) /
                                      sqrt((mouse.x - cannon.x) * (mouse.x - cannon.x) +
                                           (mouse.y - cannon.y) * (mouse.y - cannon.y));
                            } else if (BF.inputBalls[0]==6 && !laserb){
                                laser(mouse,cannon,PlayBound,BF.radious,BF,Exploding, true);
                                BF.inputBalls.erase(BF.inputBalls.begin());
                                laserb = true;
                                SDL_GetMouseState(&lasermouse.x,&lasermouse.y);
                                lasercounter = 90;
                                Mix_PlayChannel(-1,PlasmaballSound,0);
                            }
                        }
                    }
                }
                if (e->type == SDL_KEYDOWN) {
                    if (e->key.keysym.sym == SDLK_ESCAPE) {
                        return -1;
                    }
                }
            }
            shootingLine(mouse, cannon, PlayBound, BF.radious,laserb,lasermouse);
            if (lasercounter>0){
                lasercounter--;
            } else {
                lasercounter = 0;
                laserb = false;
                angle = atan((mouse.x - cannon.x) / (-mouse.y + cannon.y)) * 180 / M_PI;
            }

            if (inflight) {
                location.x += v.x * dt;
                location.y += v.y * dt;
                if (location.x < PlayBound.x + 18) {
                    location.x += 2 * (PlayBound.x + 18 - location.x);
                    Mix_PlayChannel(-1, Bounce, 0);
                    v.x *= -1;
                }
                if (location.x > PlayBound.x + PlayBound.w - 18) {
                    location.x += 2 * (PlayBound.x + PlayBound.w - 18 - location.x);
                    Mix_PlayChannel(-1, Bounce, 0);
                    v.x *= -1;
                }
                temprect = {(int) (location.x - BF.radious), (int) (location.y - BF.radious), 2 * BF.radious,
                            2 * BF.radious};
                if (BF.inputBalls[0] == 1)
                    SDL_RenderCopy(m_renderer, Btexture1, &BallRect, &temprect);
                if (BF.inputBalls[0] == 2)
                    SDL_RenderCopy(m_renderer, Btexture2, &BallRect, &temprect);
                if (BF.inputBalls[0] == 3)
                    SDL_RenderCopy(m_renderer, Btexture3, &BallRect, &temprect);
                if (BF.inputBalls[0] == 4)
                    SDL_RenderCopy(m_renderer, Btexture4, &BallRect, &temprect);
                if (BF.inputBalls[0] == 5)
                    SDL_RenderCopy(m_renderer, Btexture5, &BallRect, &temprect);
                if (BF.inputBalls[0] == 6)
                    SDL_RenderCopy(m_renderer, Btexture6, &PlasmaBallRect, &temprect);
                if (BF.inputBalls[0] == 7)
                    SDL_RenderCopy(m_renderer, Btexture7, &BombBallRect, &temprect);
                if (BF.inputBalls[0] == 8)
                    SDL_RenderCopy(m_renderer, RainbowBallText, &RainbowBallRect, &temprect);

                Ycheck = (double) ((location.y - BF.ball0.y) / (sqrt(3) * BF.radious));
                for (int i = Ycheck - 2; i <= Ycheck + 2; i++) {
                    if (isValid(i, 0, BF)) {
                        for (int j = 0; j < BF.nballs; j++) {
                            if (BF.Balls[i][j] != 0) {
                                if (pow((BF.BallLocation({i, j}).x - location.x), 2) +
                                    pow((BF.BallLocation({i, j}).y - location.y), 2) <= pow((BF.radious * 2 - 2), 2)) {
                                    angle2 = atan2(BF.BallLocation({i, j}).y - location.y,location.x - BF.BallLocation({i, j}).x)*180/M_PI;
                                    if (angle2 <= 30 && angle2 >= -30)
                                        k=0;
                                    else if (angle2 >= 30 && angle2 <= 90)
                                        k=1;
                                    else if (angle2 >= 90 && angle2 <= 150)
                                        k=2;
                                    else if (angle2 >= 150 || angle2 <= -150)
                                        k=3;
                                    else if (angle2 >= -150 && angle2 <= -90)
                                        k=4;
                                    else if (angle2 >= -90 && angle2 <= -30)
                                        k=5;
                                    if (isValid(Hamsaie({i, j}, k).radif, Hamsaie({i, j}, k).sotoon, BF)) {
                                        BF.Balls[Hamsaie({i, j}, k).radif][Hamsaie({i, j},
                                                                                   k).sotoon] = BF.inputBalls[0];
                                        if (BF.inputBalls[0]!=7) {
                                            UpdateExplode({Hamsaie({i, j}, k).radif, Hamsaie({i, j}, k).sotoon}, BF,
                                                          Explode, BF.inputBalls[0], explodenumber);
                                            if (explodenumber > 1) {
                                                Mix_PlayChannel(-1, POP, 0);
                                                StopCounter = 90;
                                                for (int l = 0; l < Explode.size(); ++l) {
                                                    for (int m = 0; m < Explode[0].size(); ++m) {
                                                        if (Exploding[l][m] == 0 && Explode[l][m]) {
                                                            if (BF.Ghofl[l][m] == 0) {
                                                                BF.Balls[l][m] = 0;
                                                                Exploding[l][m] = 60;
                                                                Explode[l][m] = 0;
                                                            }else {
                                                                Explode[l][m] = 0;
                                                                BF.Ghofl[l][m] = 0;
                                                            }
                                                            if (explodenumber > 8)
                                                                score += 5;
                                                            else if (explodenumber > 3)
                                                                score += 3;
                                                            else
                                                                score += 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                Mix_PlayChannel(-1, Collide, 0);
                                                for (int l = 0; l < Explode.size(); ++l) {
                                                    for (int m = 0; m < Explode[0].size(); ++m) {
                                                        Explode[l][m] = 0;
                                                    }
                                                }
                                            }
                                            explodenumber = 0;
                                            BF.inputBalls.erase(BF.inputBalls.begin());
                                            inflight = false;
                                            shelikshode++;
                                            location = {450, 730};
                                        }else if(BF.inputBalls[0]==7){
                                            bomb(BF.radious,BF,Exploding,Hamsaie({i, j}, k));
                                            explodenumber = 0;
                                            BF.inputBalls.erase(BF.inputBalls.begin());
                                            inflight = false;
                                            shelikshode++;
                                            location = {450, 730};
                                        }
                                    } else {
                                        BF.Balls.push_back(validrow);
                                        BF.Ghofl.push_back(validrow);
                                        valid.push_back(validrow);
                                        Explode.push_back(validrow);
                                        Exploding.push_back(validrow);
                                        BF.Balls[Hamsaie({i, j}, k).radif][Hamsaie({i, j},
                                                                                   k).sotoon] = BF.inputBalls[0];
                                        if (BF.inputBalls[0]!=7) {
                                            UpdateExplode({Hamsaie({i, j}, k).radif, Hamsaie({i, j}, k).sotoon}, BF,
                                                          Explode, BF.inputBalls[0], explodenumber);
                                            if (explodenumber > 1) {
                                                Mix_PlayChannel(-1, POP, 0);
                                                for (int l = 0; l < Explode.size(); ++l) {
                                                    for (int m = 0; m < Explode[0].size(); ++m) {
                                                        if (Exploding[l][m] == 0 && Explode[l][m]) {
                                                            if (BF.Ghofl[l][m] == 0) {
                                                                BF.Balls[l][m] = 0;
                                                                Exploding[l][m] = 60;
                                                                Explode[l][m] = 0;
                                                            }else {
                                                                Explode[l][m] = 0;
                                                                BF.Ghofl[l][m] = 0;
                                                            }
                                                            if (explodenumber > 8)
                                                                score += 5;
                                                            else if (explodenumber > 3)
                                                                score += 3;
                                                            else
                                                                score += 1;
                                                        }
                                                    }
                                                }
                                            } else {
                                                Mix_PlayChannel(-1, Collide, 0);
                                                for (int l = 0; l < Explode.size(); ++l) {
                                                    for (int m = 0; m < Explode[0].size(); ++m) {
                                                        Explode[l][m] = 0;
                                                    }
                                                }
                                            }
                                            explodenumber = 0;
                                            BF.inputBalls.erase(BF.inputBalls.begin());
                                            inflight = false;
                                            location = {450, 730};
                                            shelikshode++;
                                        } else if (BF.inputBalls[0]==7){
                                            bomb(BF.radious,BF,Exploding,Hamsaie({i, j}, k));
                                            explodenumber = 0;
                                            BF.inputBalls.erase(BF.inputBalls.begin());
                                            inflight = false;
                                            shelikshode++;
                                            location = {450, 730};
                                        }
                                    }


                                }
                            }

                            if (location.y < BF.ball0.y ) {
                                if (BF.inputBalls[0]!=7) {
                                    Mix_PlayChannel(-1, Collide, 0);
                                    BF.Balls[0][round((location.x - BF.ball0.x) / (2 * BF.radious)) +
                                                1] = BF.inputBalls[0];
                                    BF.inputBalls.erase(BF.inputBalls.begin());
                                    inflight = false;
                                    location = {450, 730};
                                    shelikshode++;
                                }else if (BF.inputBalls[0]==7){
                                    bomb(BF.radious,BF,Exploding,Hamsaie({i, j}, k));
                                    explodenumber = 0;
                                    BF.inputBalls.erase(BF.inputBalls.begin());
                                    inflight = false;
                                    shelikshode++;
                                    location = {450, 730};
                                }
                            }
                        }
                    }
                }
            }else {
                temprect = {(int) (location.x - BF.radious), (int) (location.y - BF.radious), 2 * BF.radious,
                            2 * BF.radious};
                if (BF.inputBalls[0] == 1)
                    SDL_RenderCopy(m_renderer, Btexture1, &BallRect, &temprect);
                if (BF.inputBalls[0] == 2)
                    SDL_RenderCopy(m_renderer, Btexture2, &BallRect, &temprect);
                if (BF.inputBalls[0] == 3)
                    SDL_RenderCopy(m_renderer, Btexture3, &BallRect, &temprect);
                if (BF.inputBalls[0] == 4)
                    SDL_RenderCopy(m_renderer, Btexture4, &BallRect, &temprect);
                if (BF.inputBalls[0] == 5)
                    SDL_RenderCopy(m_renderer, Btexture5, &BallRect, &temprect);
                if (BF.inputBalls[0] == 6)
                    SDL_RenderCopy(m_renderer, Btexture6, &PlasmaBallRect, &temprect);
                if (BF.inputBalls[0] == 7)
                    SDL_RenderCopy(m_renderer, Btexture7, &BombBallRect, &temprect);
                if (BF.inputBalls[0] == 8)
                    SDL_RenderCopy(m_renderer, RainbowBallText, &RainbowBallRect, &temprect);
            }
            SDL_RenderCopyEx(m_renderer, Canonimage, NULL, &CanonRect, angle, &Center, SDL_FLIP_NONE);
            temprect = {350, 730, 2 * BF.radious, 2 * BF.radious};
            if (BF.inputBalls[1] == 1)
                SDL_RenderCopy(m_renderer, Btexture1, &BallRect, &temprect);
            else if (BF.inputBalls[1] == 2)
                SDL_RenderCopy(m_renderer, Btexture2, &BallRect, &temprect);
            else if (BF.inputBalls[1] == 3)
                SDL_RenderCopy(m_renderer, Btexture3, &BallRect, &temprect);
            else if (BF.inputBalls[1] == 4)
                SDL_RenderCopy(m_renderer, Btexture4, &BallRect, &temprect);
            else if (BF.inputBalls[1] == 5)
                SDL_RenderCopy(m_renderer, Btexture5, &BallRect, &temprect);
            else if (BF.inputBalls[1] == 6)
                SDL_RenderCopy(m_renderer, Btexture6, &PlasmaBallRect, &temprect);
            else if (BF.inputBalls[1] == 7)
                SDL_RenderCopy(m_renderer, Btexture7, &BombBallRect, &temprect);
            else if (BF.inputBalls[1] == 8)
                SDL_RenderCopy(m_renderer, RainbowBallText, &RainbowBallRect, &temprect);


            for (int i = 0; i < BF.Balls.size(); ++i) {
                for (int j = 0; j < BF.Balls[0].size(); ++j) {
                    valid[i][j] = 0;
                }
            }
            for (int i = 0; i < BF.Balls[0].size(); ++i) {
                if (BF.Balls[0][i] > 0)
                    UpdateValid({0, i}, BF, valid);
            }

            for (int i = 0; i < BF.Balls.size() && fallchange == false; ++i) {
                for (int j = 0; j < BF.Balls[0].size() && fallchange == false; ++j) {
                    if (BF.Balls[i][j] != 0) {
                        if (valid[i][j] == 0) {
                            fallchange = true;
                        }
                    }
                }
            }
            if(fallchange){
                FB.push_back(falling(valid,BF,explodenumber));
                fallchange = false;
            }
            if (explodenumber > 9)
                score += explodenumber * 6;
            else if (explodenumber > 5)
                score += explodenumber * 5;
            else if (explodenumber > 3)
                score += explodenumber * 4;
            else
                score += explodenumber * 3;
            explodenumber=0;
            for (int i = 0; i < FB.size(); ++i) {
                FB[i].speedofball0+=150*dt;
                FB[i].y += FB[i].speedofball0*dt;
                if(FB[i].y > 800)
                    FB.erase(FB.begin()+i);
            }

            for (int i = 0; i < Exploding.size(); ++i) {
                for (int j = 0; j < Exploding[0].size(); ++j) {
                    if (Exploding[i][j] != 0) {
                        Exploding[i][j]--;
                        tempint = 72 - Exploding[i][j];
                        temppos = BF.BallLocation({i, j});
                        temprect = {(int) temppos.x - BF.radious, (int) temppos.y - BF.radious, 2 * BF.radious,
                                    2 * BF.radious};
                        tempiRect = {((int )(tempint%9))*219,((int )tempint/9)*220+40,219,220};
                        SDL_RenderCopy(m_renderer, AText, &tempiRect, &temprect);
                    }
                }
            }

            for (int i = 0; i < BF.Balls.size(); ++i) {
                for (int j = 0; j < BF.Balls[0].size(); ++j) {
                    if (BF.Balls[i][j] != 0) {
                        temppos = BF.BallLocation({i, j});
                        temprect = {(int) temppos.x - BF.radious, (int) temppos.y - BF.radious, 2 * BF.radious,
                                    2 * BF.radious};
                        if (BF.Balls[i][j] == 1)
                            SDL_RenderCopy(m_renderer, Btexture1, &BallRect, &temprect);
                        if (BF.Balls[i][j] == 2)
                            SDL_RenderCopy(m_renderer, Btexture2, &BallRect, &temprect);
                        if (BF.Balls[i][j] == 3)
                            SDL_RenderCopy(m_renderer, Btexture3, &BallRect, &temprect);
                        if (BF.Balls[i][j] == 4)
                            SDL_RenderCopy(m_renderer, Btexture4, &BallRect, &temprect);
                        if (BF.Balls[i][j] == 5)
                            SDL_RenderCopy(m_renderer, Btexture5, &BallRect, &temprect);
                        temprect = {(int)temppos.x - BF.radious+17, (int)temppos.y - BF.radious+17, 2 * BF.radious-17,2 * BF.radious-17};
                        if (BF.Ghofl[i][j] == 1)
                            SDL_RenderCopy(m_renderer, GhoflText, NULL, &temprect);
                    }
                }
            }
            if (pauseavailable){
                SDL_RenderCopy(m_renderer, PauseAbilityText, NULL, &PauseAbilityRect);
            }
            if (slowmotionavailable){
                SDL_RenderCopy(m_renderer,SlowdownAbilityText,NULL,&SlowMotionRect);
            }

            Timenow = SDL_GetTicks() - Timeinit;
            Timenow = Timeall - Timenow;
            timeleft = "";
            timeleft += to_string(Timenow/60000);
            timeleft += ":";
            timeleft += to_string((Timenow/1000)%60);
            tosurface = TTF_RenderText_Solid(font,timeleft.c_str(),{255,255,255,255});
            TimerText = SDL_CreateTextureFromSurface(m_renderer,tosurface);
            TTF_SizeText(font,timeleft.c_str(),&tempw,&temph);
            TimerRect = {40-tempw/2,100-temph/2,tempw,temph};
            SDL_RenderCopy(m_renderer,TimerText,NULL,&TimerRect);

            Timenow = SDL_GetTicks() - Timeinit;
            if (Timenow>Timeall){
                gameover(users, score, false,2);
                SDL_DestroyTexture(BKimage);
                SDL_DestroyTexture(wallimage);
                SDL_DestroyTexture(Canonimage);
                SDL_DestroyTexture(Btexture1);
                SDL_DestroyTexture(Btexture2);
                SDL_DestroyTexture(Btexture3);
                SDL_DestroyTexture(Btexture4);
                SDL_DestroyTexture(Btexture5);
                SDL_FreeSurface(tosurface);
                return 0;
            }

            if (EndGameLose(BF)) {
                score-=shelikshode*100+ (SDL_GetTicks()-InitTime)/10;
                gameover(users, score, false,2);
                SDL_DestroyTexture(BKimage);
                SDL_DestroyTexture(wallimage);
                SDL_DestroyTexture(Canonimage);
                SDL_DestroyTexture(Btexture1);
                SDL_DestroyTexture(Btexture2);
                SDL_DestroyTexture(Btexture3);
                SDL_DestroyTexture(Btexture4);
                SDL_DestroyTexture(Btexture5);
                SDL_FreeSurface(tosurface);
                return 0;
            }
            if (EndGameWin(BF)) {
                score-=shelikshode*100+ (SDL_GetTicks()-InitTime)/10;
                gameover(users, score, true,2);
                SDL_DestroyTexture(BKimage);
                SDL_DestroyTexture(wallimage);
                SDL_DestroyTexture(Canonimage);
                SDL_DestroyTexture(Btexture1);
                SDL_DestroyTexture(Btexture2);
                SDL_DestroyTexture(Btexture3);
                SDL_DestroyTexture(Btexture4);
                SDL_DestroyTexture(Btexture5);
                SDL_FreeSurface(tosurface);
                return 0;
            }
            SDL_RenderPresent(m_renderer);
            SDL_Delay(time_left());
            next_time += TICK_INTERVAL;
        }else{
            Pause = Pausef();
            if (Pause){
                SDL_DestroyTexture(BKimage);
                SDL_DestroyTexture(wallimage);
                SDL_DestroyTexture(Canonimage);
                SDL_DestroyTexture(Btexture1);
                SDL_DestroyTexture(Btexture2);
                SDL_DestroyTexture(Btexture3);
                SDL_DestroyTexture(Btexture4);
                SDL_DestroyTexture(Btexture5);
                SDL_FreeSurface(tosurface);
                return 0;
            }
            next_time=SDL_GetTicks() + TICK_INTERVAL;
        }
    }
}
#endif //BP_PROJECT_GAME_TIME_H
