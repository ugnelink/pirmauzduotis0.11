# v0.41.cpp
#include "funkcijos.h"

int main() {
vector <baze> studentai;
int m; int h; int g; int p; string antraste;
	cout <<"Jei norite atlikti spartos greicio analize, iveskite 1, jei nenorite, iveskite 0" << endl;
iv_ir_tikr(p);
cout << " jei norite duomenis nuskaityti is failo, iveskite 1, jei nenorite iveskite 0 " << endl;
iv_ir_tikr(h);
	if (p==1){
	
		
	}
	else { 
		
if (h == 1) {
	string failas;
	cout << "iveskite failo pavadinima" << endl;
	cin >> failas;
nuskaitymas (failas,studentai);
	
funckija("rezultatai", studentai);
}
else {

cout << "iveskite studentu skaiciu: " << endl;
skaicius_ir_tikr(m);
for (long i = 1; i <= m; i = i + 1)
{
baze b;
cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
cin >> b.vardas >> b.pavarde;
skaicius_ir_tikr(b.kiekis);
for (int j = 0; j < b.kiekis; j++) {
float sk;
paz_ir_tikr(sk);
b.paz.push_back(sk);
b.sum = b.sum + sk;
b.paz.reserve(b.kiekis);
}

 paz_ir_tikr(b.egz);
b.vid = b.sum / b.kiekis;

 sort(b.paz.begin(), b.paz.end());
if (b.kiekis % 2 == 1) b.med = b.paz.at((b.kiekis + 1) / 2); else b.med = b.paz.at(b.kiekis / 2) + b.paz.at(((b.kiekis / 2) + 1) / 2);
b.galutinisvid = 0.4 * b.vid + 0.6 * b.egz;
b.galutinismed = 0.4 * b.med + 0.6 * b.egz;
studentai.push_back(b);
studentai.reserve(m);
}
cout << endl;
cout << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
cout << string(60, '-') << endl;
for (auto& a : studentai) {
cout << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinisvid << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinismed << endl;
}
}
	}
return (0);
}
//ofstream rf2("vargsiukai.txt");
//ofstream rf3("galvociai.txt");

