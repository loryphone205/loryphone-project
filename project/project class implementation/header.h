#define MAX_LVL 80
#define MIN_LVL 20
#include <termios.h>
#include <stdio.h>
#include <random>
#include <iostream>
using namespace std;

random_device rd;
mt19937 gen(rd());
