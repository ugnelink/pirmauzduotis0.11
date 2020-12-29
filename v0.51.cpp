
#include "funkcijos.h"
#include "Header5.h"
void antra(int irasusk);
int main() {
	vector <baze> studentai;
	int m; int h; int g; int p; 
	cout << "Jei norite atlikti spartos greicio analize, iveskite 1, jei nenorite, iveskite 0" << endl;
	cin >> p;
	iv_ir_tikr(p);
	
	if (p == 1) {

		antra(1000);  antra(10000); antra(100000); antra(1000000); antra(10000000); 
	}
	else {
		cout << " jei norite duomenis nuskaityti is failo, iveskite 1, jei nenorite iveskite 0 " << endl;
		cin >> h;
		iv_ir_tikr(h); 

		if (h == 1) {
			string failas;
			cout << "iveskite failo pavadinima" << endl;
			cin >> failas;
			nuskaitymas(failas, studentai);

			funkcija("rezultatai", studentai);
		}
		else {

			cout << "iveskite studentu skaiciu: " << endl;
			cin >> m;
			skaicius_ir_tikr(m);
			for (long i = 1; i <= m; i = i + 1)
			{
				baze b;
				cout << "iveskite " << i << "studento varda, pavarde, namu darbu skaiciu, namu darbus, egzamina : ";
				cin >> b.vardas >> b.pavarde;
				cin >> b.kiekis; 
				skaicius_ir_tikr(b.kiekis);
				for (int j = 0; j < b.kiekis; j++) {
					float sk;
					cin >> sk;
					paz_ir_tikr(sk);
					
					b.paz.push_back(sk);
					b.sum = b.sum + sk;
					b.paz.reserve(b.kiekis);
				}
				cin >> b.egz;
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

void antra(int irasusk)
{
	vector <baze> studentai; vector <baze> vargsiukai; vector <baze> galvociai;
	cout << "testas su vektoriais" << endl;
	ketvirta(irasusk);
	nuskaitymas(to_string(irasusk), studentai);

	auto start = chrono::high_resolution_clock::now();
	pirma(studentai, vargsiukai, galvociai);

	chrono::duration <double> diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal pirma strategija, uztruko: " << diff.count() << " s\n";
	studentai.clear();
	vargsiukai.clear();
	galvociai.clear();
	nuskaitymas(to_string(irasusk), studentai);
	start = chrono::high_resolution_clock::now();
	padalinimostrategija(studentai, vargsiukai);
    diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal antra strategija, uztruko: " << diff.count() << " s\n";
	studentai.clear();
	vargsiukai.clear();
	galvociai.clear();
	list <baze1> studentai1; list <baze1> vargsiukai1; list <baze1> galvociai1;
	cout << "testas su listais" << endl;
	nuskaitymas1(to_string(irasusk), studentai1);

	start = chrono::high_resolution_clock::now();
	pirma1(studentai1, vargsiukai1, galvociai1);

    diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal pirma strategija, uztruko: " << diff.count() << " s\n";
	studentai1.clear();
	vargsiukai1.clear();
	galvociai1.clear();
	nuskaitymas1(to_string(irasusk), studentai1);
	start = chrono::high_resolution_clock::now();
	padalinimostrategija1(studentai1, vargsiukai1);
	diff = chrono::high_resolution_clock::now() - start;
	cout << "Failo is " << irasusk << " irasu rusiavimas, pagal antra strategija, uztruko: " << diff.count() << " s\n";
	studentai1.clear();
	vargsiukai1.clear();
	galvociai1.clear();
}
