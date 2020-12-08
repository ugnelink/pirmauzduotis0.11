# v0.11v.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
struct baze{string vardas; string pavarde; float vid; vector< int >paz; int kiekis; float egz; float galutinismed; float galutinisvid; float sum=0; float med;}; 

int main() {	
	vector <baze> studentai;
long m;

cout <<"iveskite studentu skaiciu: "<< endl;
cin >> m;
for(long i=1;i<=m;i=i+1)
{
	baze b;
cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
cin >> b.vardas >> b.pavarde >> b.kiekis;
for (int j=0; j<b.kiekis; j++) {
	float sk;
cin >> sk; b.paz.push_back(sk);
b.sum=b.sum+sk;
	b.paz.reserve(b.kiekis);
}
cin >> b.egz;
b.vid=b.sum/b.kiekis;

sort (b.paz.begin(), b.paz.end());
	if(b.kiekis%2==1) b.med=b.paz.at((b.kiekis+1)/2); else b.med=b.paz.at(b.kiekis/2)+b.paz.at(((b.kiekis/2)+1)/2);
  b.galutinisvid=0.4*b.vid+0.6*b.egz;
  b.galutinismed=0.4*b.med+0.6*b.egz;
	studentai.push_back(b);
	studentai.reserve(m);
}
cout << endl;
cout << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
cout << string(60, '-') << endl; 
for (auto& a:studentai) {
cout << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinisvid << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinismed << endl;

}
return (0);
}
