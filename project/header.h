#include <termios.h>
#include <stdio.h>
#include <iostream>

#define MAX_LVL 80
#define MIN_LVL 20

using namespace std;

char getch(void);
char getche(void);
void GenMat(char (&Mat)[MIN_LVL][MAX_LVL]);
void PrintMat(char (&Mat)[MIN_LVL][MAX_LVL]);
void Gameplay(char (&Mat)[MIN_LVL][MAX_LVL], int (&P_i), int (&P_j));