//
// Created by hooma on 1/23/2024.
//

#ifndef BP_PROJECT_ESSENTIALS_H
#define BP_PROJECT_ESSENTIALS_H

static uint64_t next_time;
uint64_t  time_left(){
    uint64_t now;
    now = SDL_GetTicks();
    if (next_time <= now)
        return 0;
    else
        return next_time - now;
}


bool is_inRect(int x,int y,SDL_Rect rect){
    if (x>rect.x && x < rect.x + rect.w && y>rect.y && y < rect.y + rect.h)
        return true;
    return false;
}

struct Probfield{
    uint8_t noball=0,isball=0,r=0,g=0,b=0,ps=0,pd=0,br=0,pu=0;
};

struct khoone{
    int radif, sotoon;};
struct mokhtasat{
    double x,y;
};
struct mousie{
    int x,y;
};
struct user {
    string username;
    int scoreNormal,scoreTime,scoreInfinity;
};
struct userRank {
    string username;
    int scoreNormal,scoreTime,scoreInfinity,sumScores;
};
struct FallingBall{
    double speedofball0=0,x,y;
    vector <vector<uint8_t>> ball;
};
khoone Hamsaie(khoone khane, int n) {
    khoone a;
    if (khane.radif % 2 == 0) {
        if (n == 0) { a.radif = khane.radif; a.sotoon = khane.sotoon + 1; }
        else if (n == 1) { a.radif = khane.radif - 1; a.sotoon =  khane.sotoon; }
        else if (n == 2) { a.radif = khane.radif - 1; a.sotoon =  khane.sotoon - 1; }
        else if (n == 3) { a.radif = khane.radif; a.sotoon = khane.sotoon - 1; }
        else if (n == 4) { a.radif = khane.radif + 1; a.sotoon = khane.sotoon - 1; }
        else if (n == 5) { a.radif = khane.radif + 1; a.sotoon = khane.sotoon; }
        return a;
    } else {
        if (n == 0) { a.radif = khane.radif; a.sotoon = khane.sotoon + 1; }
        else if (n == 1) { a.radif = khane.radif - 1; a.sotoon =  khane.sotoon + 1; }
        else if (n == 2) { a.radif = khane.radif - 1; a.sotoon =  khane.sotoon; }
        else if (n == 3) { a.radif = khane.radif; a.sotoon = khane.sotoon - 1; }
        else if (n == 4) { a.radif = khane.radif + 1; a.sotoon = khane.sotoon; }
        else if (n == 5) { a.radif = khane.radif + 1; a.sotoon = khane.sotoon + 1; }
        return a;
    }
}

class BallField {
public:
    vector<vector<uint8_t>> Balls;
    vector<vector<uint8_t>> Ghofl;
    vector<uint8_t> inputBalls;
    Probfield PB;
    int radious = 20;
    int nballs= 20;
    mokhtasat ball0 = {108,400};

//    void chineshRandomBalls(vector<vector<int>> randomBalls,khoone current,int radifs){
    bool isValid(int row, int col) {
        return row >= 0 && row < Balls.size() && col >= 0 && col < Balls[0].size();
    }
    mokhtasat BallLocation(khoone a){
        mokhtasat b;
        mokhtasat offset = {2,2};
        if (a.radif%2==0)
        {
            b.x = ball0.x + a.sotoon*(radious-offset.x)*2;
            b.y = ball0.y + a.radif*(37-offset.y);
        } else{
            b.x = ball0.x + (radious-offset.x)+2*(radious-offset.x)*a.sotoon;
            b.y = ball0.y + (37-offset.y)*a.radif;
        }
        return b;
    }
    struct randpoint{
        int radif, sotoon;
        bool gophl;
    };
    void CreateBallField(uint8_t n,int row) {
        bool go = true;
        vector<uint8_t> temp;
        vector<uint8_t> temp1;
        randpoint Spoints[n];
        ball0.y -= (row-1)*35;
        double r=0,dr=20;
        for (int i = 0; i < 20; ++i) {
            temp.push_back(255);
            temp1.push_back(0);
        }
        for (int i = 0; i < row; ++i) {
            Balls.push_back(temp);
            Ghofl.push_back(temp1);
        }
        for (int i = 0; i < n; ++i) {
            Spoints[i].radif = rand()%Balls.size();
            Spoints[i].sotoon = rand()%temp.size();
            Balls[Spoints[i].radif][Spoints[i].sotoon] = rand()%5+1;
            if (rand()%20 == 0)
                Spoints[i].gophl = true;
            else
                Spoints[i].gophl = false;
        }
        while (go)
        {
            r+=dr;
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < r / radious + 1; ++i) {
                    for (int j = 0; j < r / radious + 1; ++j) {
                        if (isValid(Spoints[k].radif + i, Spoints[k].sotoon + j)) {
                            if (Balls[Spoints[k].radif + i][Spoints[k].sotoon + j] == 255) {
                                if (pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon + j}).x -
                                        BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                    pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon + j}).y -
                                        BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) < pow(r, 2)) {
                                    Balls[Spoints[k].radif + i][Spoints[k].sotoon +j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                    Ghofl[Spoints[k].radif + i][Spoints[k].sotoon +j] = Spoints[k].gophl;
                                }
                            }
                        }
                        if (isValid(Spoints[k].radif + i , Spoints[k].sotoon - j))
                        if (Balls[Spoints[k].radif + i][Spoints[k].sotoon - j] == 255) {
                            if (pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon - j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon - j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                pow(r, 2)) {
                                Balls[Spoints[k].radif + i][Spoints[k].sotoon - j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                Ghofl[Spoints[k].radif + i][Spoints[k].sotoon -j] = Spoints[k].gophl;
                            }
                        }
                        if (isValid(Spoints[k].radif - i , Spoints[k].sotoon + j))
                        if (Balls[Spoints[k].radif - i][Spoints[k].sotoon + j] == 255) {
                            if (pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon + j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon + j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                pow(r, 2)) {
                                Balls[Spoints[k].radif - i][Spoints[k].sotoon + j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                Ghofl[Spoints[k].radif - i][Spoints[k].sotoon +j] = Spoints[k].gophl;
                            }
                        }
                        if (isValid(Spoints[k].radif - i , Spoints[k].sotoon - j))
                        if (Balls[Spoints[k].radif - i][Spoints[k].sotoon - j] == 255) {
                            if (pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon - j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon - j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                pow(r, 2)) {
                                Balls[Spoints[k].radif - i][Spoints[k].sotoon - j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                Ghofl[Spoints[k].radif - i][Spoints[k].sotoon -j] = Spoints[k].gophl;
                            }
                        }
                    }
                }
            }
            go = false;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < 20; ++j) {
                    if (Balls[i][j] == 255){
                        go = true;
                    }
                }
            }
        }
    }
    void CreateBallFieldapp(uint8_t n,int row,vector<vector<uint8_t>>& valid,vector<vector<uint8_t>>& Explode,vector<vector<uint8_t>>& Exploding,vector<FallingBall>& FB) {
        bool go = true;
        vector<uint8_t> temp;
        vector<uint8_t> temp1;
        randpoint Spoints[n];
        ball0.y -= (row)*35;
        for (int i = 0; i < FB.size(); ++i) {
            FB[i].y +=(row)*35;
        }
        double r=0,dr=20;
        for (int i = 0; i < 20; ++i) {
            temp.push_back(255);
            temp1.push_back(0);
        }
        for (int i = 0; i < row; ++i) {
            Balls.insert(Balls.begin(),temp);
            Ghofl.insert(Ghofl.begin(),temp1);
        }
        for (int i = 0; i < n; ++i) {
            Spoints[i].radif = rand()%row;
            Spoints[i].sotoon = rand()%temp.size();
            Balls[Spoints[i].radif][Spoints[i].sotoon] = rand()%5+1;
            if (rand()%20 == 0)
                Spoints[i].gophl = true;
            else
                Spoints[i].gophl = false;
        }
        for (int i = 0; i < row; ++i) {
            valid.insert(valid.begin(),temp1);
            Explode.insert(Explode.begin(),temp1);
            Exploding.insert(Exploding.begin(),temp1);
        }
        while (go)
        {
            r+=dr;
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < r / radious + 1; ++i) {
                    for (int j = 0; j < r / radious + 1; ++j) {
                        if (i<row) {
                            if (isValid(Spoints[k].radif + i, Spoints[k].sotoon + j)) {
                                if (Balls[Spoints[k].radif + i][Spoints[k].sotoon + j] == 255) {
                                    if (pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon + j}).x -
                                            BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                        pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon + j}).y -
                                            BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) < pow(r, 2)) {
                                        Balls[Spoints[k].radif + i][Spoints[k].sotoon +j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                        Ghofl[Spoints[k].radif + i][Spoints[k].sotoon +j] = Spoints[k].gophl;
                                    }
                                }
                            }
                            if (isValid(Spoints[k].radif + i , Spoints[k].sotoon - j))
                                if (Balls[Spoints[k].radif + i][Spoints[k].sotoon - j] == 255) {
                                    if (pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon - j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                        pow(BallLocation({Spoints[k].radif + i, Spoints[k].sotoon - j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                        pow(r, 2)) {
                                        Balls[Spoints[k].radif + i][Spoints[k].sotoon - j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                        Ghofl[Spoints[k].radif + i][Spoints[k].sotoon -j] = Spoints[k].gophl;
                                    }
                                }
                            if (isValid(Spoints[k].radif - i , Spoints[k].sotoon + j))
                                if (Balls[Spoints[k].radif - i][Spoints[k].sotoon + j] == 255) {
                                    if (pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon + j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                        pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon + j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                        pow(r, 2)) {
                                        Balls[Spoints[k].radif - i][Spoints[k].sotoon + j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                        Ghofl[Spoints[k].radif - i][Spoints[k].sotoon +j] = Spoints[k].gophl;
                                    }
                                }
                            if (isValid(Spoints[k].radif - i , Spoints[k].sotoon - j))
                                if (Balls[Spoints[k].radif - i][Spoints[k].sotoon - j] == 255) {
                                    if (pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon - j}).x - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).x, 2) +
                                        pow(BallLocation({Spoints[k].radif - i, Spoints[k].sotoon - j}).y - BallLocation({Spoints[k].radif,Spoints[k].sotoon}).y, 2) <
                                        pow(r, 2)) {
                                        Balls[Spoints[k].radif - i][Spoints[k].sotoon - j] = Balls[Spoints[k].radif][Spoints[k].sotoon];
                                        Ghofl[Spoints[k].radif - i][Spoints[k].sotoon -j] = Spoints[k].gophl;
                                    }
                                }
                        }
                    }
                }
            }
            go = false;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < 20; ++j) {
                    if (Balls[i][j] == 255){
                        go = true;
                    }
                }
            }
        }
    }
    vector<bool> ValidColor (){
        vector<bool> boo;
        for (int i = 0; i < 5; ++i) {
            boo.push_back(false);
        }
        for (int i = 0; i < Balls.size(); ++i) {
            for (int j = 0; j < Balls[0].size(); ++j) {
                if (Balls[i][j] == 1)
                    boo[0] = true;
                if (Balls[i][j] == 2)
                    boo[1] = true;
                if (Balls[i][j] == 3)
                    boo[2] = true;
                if (Balls[i][j] == 4)
                    boo[3] = true;
                if (Balls[i][j] == 5)
                    boo[4] = true;
            }
        }
        return boo;
    }
};
vector<user> ReadUserFile (bool read , vector<user> b = {} ){
    vector<user> a;
    user aa;
    if (read){
        ifstream fin("../Data/Saves/Users.txt",ios::in);
        if (fin.good()){
            while (fin.peek()!=EOF){
                fin>>aa.username>>aa.scoreNormal>>aa.scoreTime>>aa.scoreInfinity;
                a.push_back(aa);
            }
            fin.close();
            return a;
        } else{
            cout<<"failde to open save files"<<endl;
        }
    } else{
        ofstream fo("../Data/Saves/Users.txt",ios::trunc);
        if (fo.good()){
            for (int i = 0; i < b.size() -1; ++i) {
                fo<<b[i].username<<" "<<b[i].scoreNormal<<" "<<b[i].scoreTime<<" "<<b[i].scoreInfinity<<"\n";
            }
            fo<<b[b.size()-1].username<<" "<<b[b.size()-1].scoreNormal<<" "<<b[b.size()-1].scoreTime<<" "<<b[b.size()-1].scoreInfinity;
            fo.close();
        } else{
            cout<<"failde to open save files"<<endl;
        }
    }
}

/*
SDL_Event* e = new SDL_Event();
while (SDL_PollEvent(e)){
    if (e->type == SDL_MOUSEMOTION)
    {
    }
    if (e->type == SDL_MOUSEBUTTONDOWN )
    {
        if (e->button.button == SDL_BUTTON_LEFT){
            switch (selected) {
                case 1:
                    return 10;
                case 2:
                    return 3;
                case 3:
                    return 4;
                case 4:
                    return -1;
            }
        }
    }
    if (e->type == SDL_KEYDOWN){
        if (e->key.keysym.sym == SDLK_ESCAPE){
            SDL_DestroyTexture(BKimage);
            SDL_FreeSurface(t_surface);
            return -1;
        }
    }
}
*/



#endif //BP_PROJECT_ESSENTIALS_H
