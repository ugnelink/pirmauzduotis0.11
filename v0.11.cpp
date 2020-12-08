# v0.11.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;
struct baze{string vardas; string pavarde; float vid; float paz[5]; int kiekis; float egz; float galutinismed; float galutinisvid; float sum=0; float med;}; 
baze b[1000];
int main() {		
long m;

cout <<"iveskite studentu skaiciu: "<< endl;
cin >> m;
for(long i=1;i<=m;i=i+1)
{
cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
cin >> b[i].vardas >> b[i].pavarde >> b[i].kiekis;
for (int j=0; j<b[i].kiekis; j++) {
cin >> b[i].paz[j];
b[i].sum=b[i].sum+b[i].vid;
}
cin >> b[i].egz;
b[i].vid=b[i].sum/b[i].kiekis;

sort (b[i].paz, b[i].paz+b[i].kiekis);
	if(b[i].kiekis%2==1) b[i].med=b[i].paz[(b[i].kiekis+1)/2]; else b[i].med=b[i].paz[b[i].kiekis/2]+b[i].paz[((b[i].kiekis/2)+1)/2];
  b[i].galutinisvid=0.4*b[i].vid+0.6*b[i].egz;
  b[i].galutinismed=0.4*b[i].med+0.6*b[i].egz;
}
cout << endl;
cout << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
cout << string(60, '-') << endl; 
for(long i=1;i<=m;i=i+1) {
cout << left << setw(15) << setfill(' ') << b[i].vardas << left << setw(15) << setfill(' ') << b[i].pavarde << left << setw(15) << setfill(' ') << fixed << setprecision(2) << b[i].galutinisvid << left << setw(15) << setfill(' ') << fixed << setprecision(2) << b[i].galutinismed << endl;

}
return (0);
}
