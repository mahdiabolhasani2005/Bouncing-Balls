//
// Created by hooma on 1/3/2024.
//

#ifndef BP_PROJECT_GAME_NORMAL_H
#define BP_PROJECT_GAME_NORMAL_H
#define TICK_INTERVAL 15

void UpdateValid(khoone current, BallField& BF, vector<vector<uint8_t>>& valid);
void UpdateExplode(khoone current, BallField& BF, vector<vector<uint8_t>>& Explode,int rang,int &number);
void shootingLine (mousie& mouse,mokhtasat& cannon,SDL_Rect& PlayBound,int radious,bool laser,mousie temp);
khoone Hamsaie(khoone khane, int n);
bool isValid(int row, int col, BallField& BF);
double speedofball0(int &StopCounter);
bool EndGameLose(BallField& BF);
bool EndGameWin(BallField& BF);
int gameover(vector<user> users,int score,bool win,uint8_t mode);
bool Pausef();
void laser(mousie& mouse,mokhtasat& cannon,SDL_Rect& PlayBound,int radious,BallField &BF,vector<vector<uint8_t>>& exploding,bool blue);
void bomb(int radious,BallField &BF,vector<vector<uint8_t>>& exploding,khoone bomb);
FallingBall falling(vector<vector<uint8_t>> &valid,BallField &BF,int& CounterFalling);


int Game_normal (vector<user> users,int row){
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
    int k = 0,shelikshode =0,tempint;
    uint32_t InitTime;
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
    SDL_Point Center = {50,80};
    //==================================================================================================================
    tosurface = SDL_LoadBMP("../Data/Canon/Ghofl.bmp");
    SDL_Texture* GhoflText = SDL_CreateTextureFromSurface(m_renderer,tosurface);

    //==================================================================================================================
    //event initializer
    SDL_Event* e = new SDL_Event();
    bool Quit = false;


    //==================================================================================================================
    //ballfield constructor
    BallField BF;
    vector<vector<uint8_t>> valid;
    vector<vector<uint8_t>> Explode;
    vector<vector<uint8_t>> Exploding;
    vector<uint8_t> validrow;
    vector<bool> ValidC = {false,false,false,false,false};

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

            if (EndGameLose(BF)) {
                score-=shelikshode*100+ (SDL_GetTicks()-InitTime)/10;
                gameover(users, score, false,1);
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
                gameover(users, score, true,1);
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

bool isValid(int row, int col, BallField& BF) {
    return row >= 0 && row < BF.Balls.size() && col >= 0 && col < BF.Balls[0].size();
}

void UpdateValid(khoone current, BallField& BF, vector<vector<uint8_t>>& valid) {
    khoone tempkhoone;
    valid[current.radif][current.sotoon] = 1;
    for (int i = 0; i < 6; ++i) {
         tempkhoone = Hamsaie(current,i);
        if (isValid(tempkhoone.radif,tempkhoone.sotoon,BF)) {
            if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] > 0 && !valid[tempkhoone.radif][tempkhoone.sotoon]){
                UpdateValid(tempkhoone,BF,valid);
            }
        }
    }
}

bool EndGameLose(BallField& BF){
    for (int i = BF.Balls.size()-1; i >= 0; --i) {
        for (int j = 0; j < BF.Balls[0].size(); ++j) {
            if (BF.Balls[i][j] != 0){
                return BF.BallLocation({i,0}).y+18 > 660;
            }
        }
    }
}
bool EndGameWin(BallField& BF){
    for (int i = BF.Balls.size()-1; i >= 0; --i) {
        for (int j = 0; j < BF.Balls[0].size(); ++j) {
            if (BF.Balls[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

void UpdateExplode(khoone current, BallField& BF, vector<vector<uint8_t>>& Explode,int rang,int &number) {
    khoone tempkhoone;
    Explode[current.radif][current.sotoon] = 1;
    if (rang == 8) {
        for(int k=1;k<6;k++){
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == k &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, k, number);
                }
            }
        }
        }
    }else if(rang==9){
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 1 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 1, number);
                }
            }
        }
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 2 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 2, number);
                }
            }
        }
    }
    else if(rang==10){
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 3 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 3, number);
                }
            }
        }
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 4 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 4, number);
                }
            }
        }
    }else if(rang==11){
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 1 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 1, number);
                }
            }
        }
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == 5 &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, 5, number);
                }
            }
        }
    }
        else {
        for (int i = 0; i < 6; ++i) {
            tempkhoone = Hamsaie(current, i);
            if (isValid(tempkhoone.radif, tempkhoone.sotoon, BF)) {
                if (BF.Balls[tempkhoone.radif][tempkhoone.sotoon] == rang &&
                    !Explode[tempkhoone.radif][tempkhoone.sotoon]) {
                    number++;
                    UpdateExplode(tempkhoone, BF, Explode, rang, number);
                }
            }
        }
    }
}
double speedofball0(int& StopCounter){
    double speedofballs = 10;
    if(StopCounter<=0){
        StopCounter = 0;
    } else{
        if (StopCounter>30){
            speedofballs =0;
        }else if (StopCounter>20){
            speedofballs *= 0.25;
        }else if (StopCounter>10){
            speedofballs *= 0.5;
        }else if (StopCounter>0){
            speedofballs *= 0.75;
        }
        StopCounter--;
    }
    return speedofballs;
}
void shootingLine (mousie& mouse,mokhtasat& cannon,SDL_Rect& PlayBound,int radious,bool laser,mousie temp) {

    int shafafiat=150;
    if(laser){
        shafafiat=255;
        double m=(temp.y-cannon.y)/(temp.x-cannon.x);
        if(m>0) {
            double deltay = m * (PlayBound.w -2* radious );
            lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + radious,
                     -0.5 * deltay + cannon.y, 255, 0,0, shafafiat);

        }
        else {
            double deltay = -2 * m * (PlayBound.x + PlayBound.w - radious - cannon.x);
            int n = (PlayBound.h / (deltay)) + 1;
            lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + PlayBound.w - radious,
                     -0.5 * deltay + cannon.y, 255, 0, 0, shafafiat);
        }
    }
    else{
        double m=(mouse.y-cannon.y)/(mouse.x-cannon.x);
    if(m>0) {
        double deltay = m * (PlayBound.w -2* radious );
        int n = (PlayBound.h / (deltay)) + 1;
        lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + radious,
                 -0.5 * deltay + cannon.y, 255, 255, 255, shafafiat);
        lineRGBA(m_renderer, PlayBound.x + radious, -0.5 * deltay + cannon.y, PlayBound.x + PlayBound.w - radious,
                 -1.5 * deltay + cannon.y, 255, 255, 255, shafafiat);
        for (int i = 1; i < n+1; i++) {
            lineRGBA(m_renderer, PlayBound.x + PlayBound.w - radious, -(2 * i - 0.5) * deltay + cannon.y,
                     PlayBound.x + radious,
                     -(2 * i + 0.5) * deltay + cannon.y, 255, 255, 255, shafafiat);
            lineRGBA(m_renderer, PlayBound.x + radious, -(2 * i + 0.5) * deltay + cannon.y,
                     PlayBound.x + PlayBound.w - radious,
                     -(2 * i + 1.5) * deltay + cannon.y, 255, 255, 255, shafafiat);
        }
    }
    else {
        double deltay = -2 * m * (PlayBound.x + PlayBound.w - radious - cannon.x);
        int n = (PlayBound.h / (deltay)) + 1;
        lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + PlayBound.w - radious,
                 -0.5 * deltay + cannon.y, 255, 255, 255, shafafiat);
        lineRGBA(m_renderer, PlayBound.x + PlayBound.w - radious, -0.5 * deltay + cannon.y, PlayBound.x + radious,
                 -1.5 * deltay + cannon.y, 255, 255, 255, shafafiat);
        for (int i = 1; i < n; i++) {
            lineRGBA(m_renderer, PlayBound.x + radious, -(2 * i - 0.5) * deltay + cannon.y,
                     PlayBound.x + PlayBound.w - radious,
                     -(2 * i + 0.5) * deltay + cannon.y, 255, 255, 255, shafafiat);
            lineRGBA(m_renderer, PlayBound.x + PlayBound.w - radious, -(2 * i + 0.5) * deltay + cannon.y,
                     PlayBound.x + radious,
                     -(2 * i + 1.5) * deltay + cannon.y, 255, 255, 255, shafafiat);
        }
    }
}}
int gameover(vector<user> users,int score,bool win,uint8_t mode){
    bool quit = false,selected = false;
    if (win)
        Mix_PlayChannel(-1,Cheering,0);
    if (mode == 1) {
        if (win) {
            if (users[0].scoreNormal < score) {
                users[0].scoreNormal = score;
            }
            cout << score;
            ReadUserFile(false, users);
        }
    }else if (mode == 2) {
        if (win) {
            if (users[0].scoreTime < score) {
                users[0].scoreTime = score;
            }
            cout << score;
            ReadUserFile(false, users);
        }
    }else if (mode == 3) {
            if (users[0].scoreInfinity < score) {
                users[0].scoreInfinity = score;
            }
            cout << score;
            ReadUserFile(false, users);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_Surface* t_surface = SDL_LoadBMP("../Data/BackGround/Setting1.bmp");
    SDL_Texture* BKText = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    SDL_Rect BKimage_Rect = {0,0,900,800};
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    int temph,tempw;
    mousie mouse;
    SDL_Event* e = new SDL_Event;

    SDL_Texture* Text1 = nullptr;
    SDL_Texture* Text2 = nullptr;
    SDL_Texture* Text3 = nullptr;
    SDL_Texture* Text4 = nullptr;
    SDL_Rect Text1_Rect;
    SDL_Rect Text2_Rect;
    SDL_Rect Text3_Rect;

    TTF_Font* SDGFont = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",37);
    TTF_Font* SDGFontlarge = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",45);
    TTF_Font* SDGFontsmall = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",16);
    if (win && mode != 3) {
        t_surface = TTF_RenderText_Solid(SDGFontlarge, "YOU WIN!!", normalg);
        TTF_SizeText(SDGFont, "YOU WIN!!", &tempw, &temph);
        Text1_Rect = {450 - tempw/2,250 - temph/2,tempw,temph};
    }else if (!win && mode !=3) {
        t_surface = TTF_RenderText_Solid(SDGFontlarge, "YOU LOSE :(", normalg);
        TTF_SizeText(SDGFont, "YOU LOSE :(", &tempw, &temph);
        Text1_Rect = {450 - tempw/2,250 - temph/2,tempw,temph};
    }
    Text1 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    if (win || mode == 3) {
        t_surface = TTF_RenderText_Solid(SDGFont, users[0].username.c_str(), normalg);
        Text2 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        TTF_SizeText(SDGFont, users[0].username.c_str(), &tempw, &temph);
        Text2_Rect = {240 - tempw / 2, 400 - temph / 2, tempw, temph};

        t_surface = TTF_RenderText_Solid(SDGFont, to_string(score).c_str(), normalg);
        Text3 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        TTF_SizeText(SDGFontlarge, to_string(score).c_str(), &tempw, &temph);
        Text3_Rect = {700 - tempw / 2, 400 - temph / 2, tempw, temph};
    }
    t_surface = TTF_RenderText_Solid(SDGFont, "BACK", normalg);
    Text4 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontlarge, "BACK", &tempw, &temph);
    SDL_Rect Text4_Rect = {450 - tempw / 2, 550 - temph / 2, tempw, temph};



    while(!quit){
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer,BKText,NULL,&BKimage_Rect);
        SDL_RenderCopy(m_renderer,Text1,NULL,&Text1_Rect);
        if (win || mode == 3) {
            SDL_RenderCopy(m_renderer, Text2, NULL, &Text2_Rect);
            SDL_RenderCopy(m_renderer, Text3, NULL, &Text3_Rect);
        }
        SDL_RenderCopy(m_renderer,Text4,NULL,&Text4_Rect);

        while (SDL_PollEvent(e)){
            if (e->type == SDL_MOUSEMOTION){
                SDL_GetMouseState(&mouse.x,&mouse.y);
                if (is_inRect(mouse.x,mouse.y,Text4_Rect) && !selected){
                    t_surface = TTF_RenderText_Solid(SDGFont, "BACK", selectg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                    selected = true;
                }
                else if (!is_inRect(mouse.x,mouse.y,Text4_Rect) && selected){
                    t_surface = TTF_RenderText_Solid(SDGFont, "BACK", selectg);
                    Text4 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
                    selected = false;
                }
            }
            if (e->type == SDL_MOUSEBUTTONDOWN){
                if (e->button.button == SDL_BUTTON_LEFT){
                    if (selected) {
                        SDL_DestroyTexture(Text1);
                        SDL_DestroyTexture(Text2);
                        SDL_DestroyTexture(Text3);
                        SDL_DestroyTexture(Text4);
                        SDL_FreeSurface(t_surface);
                        return 0;
                    }
                }
            }
        }
        SDL_RenderPresent(m_renderer);
        SDL_Delay(30);
    }
}

bool Pausef() {
    SDL_Event* e = new SDL_Event();
    mousie mousepos ,circle,volume;
    volume.x=420,volume.y=170,circle.y=170,circle.x=volume.x+150;
    bool quit = false,s=false;
    int tempw,temph;
    SDL_Color r4=normalg,r3=normalg,r5=normalg,r16=normalg;
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

    TTF_Font* SDGFont = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf",37);
    TTF_Font *SDGFontlarge = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 45);
    TTF_Font *SDGFontsmall = TTF_OpenFont("../Data/Fonts/Merriweather-Regular.ttf", 16);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    t_surface = SDL_LoadBMP("../Data/BackGround/Setting1.bmp");
    BKimage = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    SDL_Rect BKimage_Rect = {0,0,900,800};
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    t_surface = TTF_RenderText_Solid(SDGFontlarge, "Resume", normalg);
    Text1 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
    TTF_SizeText(SDGFontlarge, "Resume", &tempw, &temph);
    SDL_Rect Text1_Rect = {440 - tempw / 2, 100 - temph / 2, tempw, temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"pick a music",{0,170,255,255});
    Text2 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"pick a music",&tempw,&temph);
    SDL_Rect Text2_Rect = {270 - tempw/2,200 - temph/2,tempw,temph};

    t_surface = TTF_RenderText_Solid(SDGFont,"Mario",{0,170,255,255});
    Text3 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Music1",&tempw,&temph);
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


    t_surface = TTF_RenderText_Solid(SDGFont,"Return to main menu",r16);
    Text16 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
    TTF_SizeText(SDGFont,"Return to main menu",&tempw,&temph);
    SDL_Rect Text16_Rect = {265 - tempw/2,650 - temph/2,tempw,temph};

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
            if (is_inRect(mousepos.x, mousepos.y, Text1_Rect)) {
                r1 = selectg;
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
                    SDL_FreeSurface(t_surface);
                    return false;
                }
            } else {
                r1 = normalg;
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
                    SDL_FreeSurface(t_surface);
                    return true;
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
        t_surface = TTF_RenderText_Solid(SDGFont,"Spooki",r4);
        Text4 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont,"Cooking",r5);
        Text5 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont,"Return to main menu",r16);
        Text16 = SDL_CreateTextureFromSurface(m_renderer,t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "OFF", r8);
        Text8 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "ON", r7);
        Text7 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "ON", r12);
        Text12 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        t_surface = TTF_RenderText_Solid(SDGFont, "OFF", r13);
        Text13 = SDL_CreateTextureFromSurface(m_renderer, t_surface);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(30);
    }
}
void laser(mousie& mouse,mokhtasat& cannon,SDL_Rect& PlayBound,int radious,BallField &BF,vector<vector<uint8_t>>& exploding,bool blue){
    uint8_t b,r;
    double h2, m=(mouse.y-cannon.y)/(mouse.x-cannon.x);
    int shafafiat=255;
    if(blue){
        b=255;
        r=0;
    }else{
        b=0;
        r=255;
    }
    if(m>0) {
        double deltay = m * (PlayBound.w -2* radious );
        lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + radious,
                 -0.5 * deltay + cannon.y, r, 0,b, shafafiat);

    }
    else {
        double deltay = -2 * m * (PlayBound.x + PlayBound.w - radious - cannon.x);
        int n = (PlayBound.h / (deltay)) + 1;
        lineRGBA(m_renderer, cannon.x, cannon.y, PlayBound.x + PlayBound.w - radious,
                 -0.5 * deltay + cannon.y, r, 0, b, shafafiat);
    }
    for(int i=0;i<BF.Balls.size();i++){
        for(int j=0;j<BF.Balls[i].size();j++){
            if(BF.Balls[i][j]!=0) {
                int x = BF.BallLocation({i, j}).x, y = BF.BallLocation({i, j}).y, xc = cannon.x, yc = cannon.y;
                h2 = pow(x - (x + m * (y - yc) + m * m * xc) / (m * m + 1), 2) +
                     pow(y - (yc-m*xc + m * (x + m * (y - yc) + m * m * xc) / (m * m + 1)), 2);
                if (h2 < pow(radious, 2)) {
                    BF.Balls[i][j] = 0;
                    exploding[i][j] = 73;
                    BF.Ghofl[i][j] = 0;
                }
            }
        }
    }
}
void bomb(int radious,BallField &BF,vector<vector<uint8_t>>& exploding,khoone bomb){
    Mix_PlayChannel(-1,BombSound,0);
    int xb=BF.BallLocation(bomb).x,yb=BF.BallLocation(bomb).y,R=40000;
    BF.Balls[bomb.radif][bomb.sotoon]=0;
    for(int i=0;i<BF.Balls.size();i++) {
        for (int j = 0; j < BF.Balls[i].size(); j++) {
            if (BF.Balls[i][j] != 0) {
                int x = BF.BallLocation({i, j}).x, y = BF.BallLocation({i, j}).y;
                int h2=pow(x-xb,2)+pow(y-yb,2);
                if(h2<R){
                    BF.Balls[i][j] = 0;
                    exploding[i][j] = 73;
                    BF.Ghofl[i][j] = 0;
                }
            }
        }
    }
}
FallingBall falling(vector<vector<uint8_t>> &valid,BallField &BF,int& CounterFalling){
    FallingBall falling;
    falling.y=BF.ball0.y;
    falling.x=BF.ball0.x;
    falling.speedofball0=10;
    vector<uint8_t> tempball;
    for (int i = 0; i < 20; ++i) {
        tempball.push_back(0);
    }
    for(int i=0;i<BF.Balls.size();i++) {
        falling.ball.push_back(tempball);
    }
    for(int i=0;i<BF.Balls.size();i++) {
        for (int j = 0; j < BF.Balls[i].size(); j++) {
            if(valid[i][j]==0){
                falling.ball[i][j]=BF.Balls[i][j];
                CounterFalling++;
                BF.Balls[i][j]=0;
                BF.Ghofl[i][j]=0;
            }
        }
    }
    return falling;
}
#endif //BP_PROJECT_GAME_NORMAL_H