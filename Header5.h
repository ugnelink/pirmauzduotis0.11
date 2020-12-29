#pragma once

#include "trycatch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <list>
#include <string> 
#include <chrono> 
using namespace std;
struct baze1 { string vardas; string pavarde; float vid; list < int >paz; int kiekis; float egz; float galutinismed; float galutinisvid; float sum = 0; float med; 
bool operator<(const baze1&f) const{
	if (vardas != f.vardas) return vardas.compare(f.vardas) < 0;
	if (pavarde != f.pavarde) return pavarde.compare(f.pavarde) < 0;
	return galutinisvid < f.galutinisvid;
}
};
void ketvirta1(int irasusk);
void nuskaitymas1(string failas, list <baze1>& studentai);
void funkcija1(string failas, list <baze1> studentai);
void pirma1(list <baze1> studentai, list <baze1>& vargsiukai, list <baze1>& galvociai);
void padalinimostrategija1(list <baze1>& studentai, list <baze1>& vargsiukai);

 
