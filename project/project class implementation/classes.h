#ifndef CLASSES_H
#define CLASSES_H
#include "header.h"

class Enemy
{
    private:
        char E;
        int E_i, E_j;
    public:
        Enemy(char E=' ', int E_i=0, int E_j=0);
        void setEi(int E_io){E_i=E_io;}
        void setEj(int E_jo){E_j=E_jo;}
        void setE(char (&Mat)[MIN_LVL][MAX_LVL], Enemy E1);
        int getEi(){return E_i;}
        int getEj(){return E_j;}
        char getE(){return E;}
        void MoveE(char (&Mat)[MIN_LVL][MAX_LVL], Enemy &E1);
        void RevertLastMoveE(char (&Mat)[MIN_LVL][MAX_LVL], Enemy &E1, char &last);
};

class Player
{
    private:
        char P;
        int P_i, P_j;
    public:
        Player(char P=' ', int P_i=0, int P_j=0);
        void setPi(int P_io){P_i=P_io;}
        void setPj(int P_jo){P_j=P_jo;}
        void setP(char (&Mat)[MIN_LVL][MAX_LVL], Player P1);
        int getPi(){return P_i;}
        int getPj(){return P_j;}
        char getP(){return P;}
        void MoveP(char (&Mat)[MIN_LVL][MAX_LVL], Player &P, char &c);
        void RevertLastMoveP(char (&Mat)[MIN_LVL][MAX_LVL], Player &P, char &c);
};

Player::Player(char P1, int I, int J)
{
    P=P1;
    P_i=I;
    P_j=J;
}

void Player::setP(char (&Mat)[MIN_LVL][MAX_LVL], Player P1)
{
    Mat[P1.getPi()][P1.getPj()]='P';
}

void Player::MoveP(char (&Mat)[MIN_LVL][MAX_LVL], Player &P, char &c)
{
    {
        char tmp;
        if(c=='w')
        {
            tmp=Mat[P.getPi()][P.getPj()];
            Mat[P.getPi()][P.getPj()]=' ';
            P.setPi(P.getPi()-1);
            Mat[P.getPi()][P.getPj()]=tmp;
        }
        else if(c=='a')
        {
            tmp=Mat[P.getPi()][P.getPj()];
            Mat[P.getPi()][P.getPj()]=' ';
            P.setPj(P.getPj()-1);
            Mat[P.getPi()][P.getPj()]=tmp;
        }
        else if(c=='s')
        {
            tmp=Mat[P.getPi()][P.getPj()];
            Mat[P.getPi()][P.getPj()]=' ';
            P.setPi(P.getPi()+1);
            Mat[P.getPi()][P.getPj()]=tmp;
        }
        else if(c=='d')
        {
            tmp=Mat[P.getPi()][P.getPj()];
            Mat[P.getPi()][P.getPj()]=' ';
            P.setPj(P.getPj()+1);
            Mat[P.getPi()][P.getPj()]=tmp;
        }
    }
}

void Player::RevertLastMoveP(char (&Mat)[MIN_LVL][MAX_LVL], Player &P, char &last)
{
    char tmp;
    if(last=='w')
    {
        tmp=Mat[P.getPi()][P.getPj()];
        Mat[P.getPi()][P.getPj()]='X';
        P.setPi(P.getPi()+1);
        Mat[P.getPi()][P.getPj()]=tmp;
    }
    else if(last=='a')
    {
        tmp=Mat[P.getPi()][P.getPj()];
        Mat[P.getPi()][P.getPj()]='X';
        P.setPj(P.getPj()+1);
        Mat[P.getPi()][P.getPj()]=tmp;
    }
    else if(last=='s')
    {
        tmp=Mat[P.getPi()][P.getPj()];
        Mat[P.getPi()][P.getPj()]='X';
        P.setPi(P.getPi()-1);
        Mat[P.getPi()][P.getPj()]=tmp;
    }
    else if(last=='d')
    {
        tmp=Mat[P.getPi()][P.getPj()];
        Mat[P.getPi()][P.getPj()]='X';
        P.setPj(P.getPj()-1);
        Mat[P.getPi()][P.getPj()]=tmp;
    }
}

#endif