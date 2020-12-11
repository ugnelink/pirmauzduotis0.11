# v0.41.cpp
#include "trycatch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct baze{string vardas; string pavarde; float vid; vector< int >paz; int kiekis; float egz; float galutinismed; float galutinisvid; float sum=0; float med;}; 

int main() {	
	vector <baze> studentai;
int m; int h; int g; string antraste; 
cout << " jei norite duomenis nuskaityti is failo, iveskite 1, jei nenorite iveskite 0 " << endl;
        iv_ir_tikr(h);
	if (h==1){
int n=0;
ifstream df("kursiokai.txt");
ofstream rf("Rez.txt");
		getline(df,antraste,'\n');
		g=count(antraste.begin(), antraste.end(), 'N'); 
while (!df.eof()) {
	baze b;
	b.kiekis=g;
n=n+1;
b.sum=0; 
df >> b.vardas >> b.pavarde;
for(int i=0; i<b.kiekis; i++) { 	
	float sk;
df >> sk; b.paz.push_back(sk);  b.sum=b.sum+sk;}
b.vid=b.sum/b.kiekis;

sort (b.paz.begin(), b.paz.end());
	if(b.kiekis%2==1) b.med=b.paz.at((b.kiekis+1)/2); else b.med=b.paz.at(b.kiekis/2)+b.paz.at(((b.kiekis/2)+1)/2);
  df>>b.egz;
	b.galutinisvid=0.4*b.vid+0.6*b.egz;
  b.galutinismed=0.4*b.med+0.6*b.egz;
	studentai.push_back(b);
	studentai.reserve(n);
 }
df.close(); 
		rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
rf << string(60, '-') << endl; 
for (auto& a:studentai) { 
rf << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinisvid << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinismed << endl;
}

 rf.close(); }
	else {
		
	
cout <<"iveskite studentu skaiciu: "<< endl;
 skaicius_ir_tikr(m);
for(long i=1;i<=m;i=i+1)
{
	baze b;
cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
cin >> b.vardas >> b.pavarde;
	skaicius_ir_tikr(b.kiekis);
for (int j=0; j<b.kiekis; j++) {
	float sk;
	 paz_ir_tikr(sk);
 b.paz.push_back(sk);
b.sum=b.sum+sk;
	b.paz.reserve(b.kiekis);
}
	
paz_ir_tikr(b.egz);
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
	}
return (0);
}
 ofstream rf2("vargsiukai.txt");
    ofstream rf3("galvociai.txt");

void ketvirta (int irasusk) {
	ofstream rf(to_string(irasusk)+".txt");
    int r,t,k;
	string name[]={"Jonas", "Petras", "Justinas","Adomas", "Tadas", "Dominykas", "Donatas", "Remigijus", "Antanas", "Vincas"};
	string pavarde[]={"Jonaitis", "Petraitis", "Justinaitis", "Adomaitis", "Tadaitis", "Dominykaitis", "Donataitis", "Kazlauskas", "Antanaitis", "Vincaitis"};
	int nd;
	srand(time(NULL));
	vector <baze> studentai;
	cout << "iveskite namu darbu skaiciu " << endl;
	skaicius_ir_tikr(nd);
	
	
	for(int i=0; i<irasusk; i++) {
	r=rand()%10;
	t=rand()%10;	
		baze b;
		b.vardas=name[r]+ to_string(rand()%100+1);
		b.pavarde=pavarde[t]+to_string(rand()%100+1);
		b.kiekis=nd;
		vector <int> paz;
		
		for(int j=0; j<nd; j++) {
			k=rand()%10+1;
		paz.push_back(k);}
		b.paz=paz;
		b.egz=rand()%10+1;
		studentai.push_back(b);
		
	}
	rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" ;
	for(int j=0; j<nd; j++){rf << left << setw(15) << setfill(' ') << "ND"<<j+1;}
	rf << left << setw(15) << setfill(' ') << "egzaminas" << endl; 
for (auto& a:studentai) { 
rf << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde;
	for (auto& aa:a.nd) {rf << left << setw(15) << setfill(' ') << a.nd;}
	rf << left << setw(15) << setfill(' ') << a.egzaminas  << endl;
}

 rf.close(); }

     

