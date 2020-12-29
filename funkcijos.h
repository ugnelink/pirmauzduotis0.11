#pragma once
#include "trycatch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
struct baze { string vardas; string pavarde; float vid; vector< int >paz; int kiekis; float egz; float galutinismed; float galutinisvid; float sum = 0; float med; };
void ketvirta(int irasusk);
void nuskaitymas(string failas, vector <baze>& studentai);
void funkcija(string failas, vector <baze> studentai);
void pirma(vector <baze> studentai, vector <baze>& vargsiukai, vector <baze>& galvociai);
void padalinimostrategija(vector <baze>& studentai, vector <baze>& vargsiukai);
