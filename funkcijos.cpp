#include "funkcijos.h"
void ketvirta(int irasusk) {
	ofstream rf(to_string(irasusk) + ".txt");
	int r, t, k;
	string name[] = { "Jonas", "Petras", "Justinas","Adomas", "Tadas", "Dominykas", "Donatas", "Remigijus", "Antanas", "Vincas" };
	string pavarde[] = { "Jonaitis", "Petraitis", "Justinaitis", "Adomaitis", "Tadaitis", "Dominykaitis", "Donataitis", "Kazlauskas", "Antanaitis", "Vincaitis" };
	int nd;
	srand(time(NULL));
	vector <baze> studentai;
	cout << "iveskite namu darbu skaiciu " << endl;
	cin >> nd;
	skaicius_ir_tikr(nd);

	for (int i = 0; i < irasusk; i++) {
		r = rand() % 10;
		t = rand() % 10;
		baze b;
		b.vardas = name[r] + to_string(rand() % 100 + 1);
		b.pavarde = pavarde[t] + to_string(rand() % 100 + 1);
		b.kiekis = nd;
		vector <int> paz;

		for (int j = 0; j < nd; j++) {
			k = rand() % 10 + 1;
			paz.push_back(k);
		}
		b.paz = paz;
		b.egz = rand() % 10 + 1;
		studentai.push_back(b);

	}

	rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde";
	for (int j = 0; j < nd; j++) { rf << left << setw(15) << setfill(' ') << "ND" << j + 1; }
	rf << left << setw(15) << setfill(' ') << "egzaminas" << endl;
	for (auto& a : studentai) {
		rf << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde;
		for (auto& aa : a.paz) { rf << left << setw(15) << setfill(' ') << aa; }
		rf << left << setw(15) << setfill(' ') << a.egz << endl;
	}
	rf.close();
}
void nuskaitymas(string failas, vector <baze>& studentai) {
	int n = 0;
	ifstream df(failas + ".txt");
	int g;
	string antraste;
	getline(df, antraste, '\n');
	g = count(antraste.begin(), antraste.end(), 'N');
	while (!df.eof()) {
		baze b;
		b.kiekis = g;
		n = n + 1;
		b.sum = 0;
		df >> b.vardas >> b.pavarde;
		for (int i = 0; i < b.kiekis; i++) {
			float sk;
			df >> sk; b.paz.push_back(sk); b.sum = b.sum + sk;
		}
		b.vid = b.sum / b.kiekis;

		sort(b.paz.begin(), b.paz.end());
		if (b.kiekis % 2 == 1) b.med = b.paz.at((b.kiekis + 1) / 2); else b.med = b.paz.at(b.kiekis / 2) + b.paz.at(((b.kiekis / 2) + 1) / 2);
		df >> b.egz;
		b.galutinisvid = 0.4 * b.vid + 0.6 * b.egz;
		b.galutinismed = 0.4 * b.med + 0.6 * b.egz;
		studentai.push_back(b);
		studentai.reserve(n);
	}
	df.close();
}

void funkcija(string failas, vector <baze> studentai) {

	ofstream rf(failas + ".txt");
	rf << left << setw(15) << setfill(' ') << "vardas" << left << setw(15) << setfill(' ') << "pavarde" << left << setw(15) << setfill(' ') << "galutinisvid" << left << setw(15) << setfill(' ') << "galutinismed" << endl;
	rf << string(60, '-') << endl;
	for (auto& a : studentai) {
		rf << left << setw(15) << setfill(' ') << a.vardas << left << setw(15) << setfill(' ') << a.pavarde << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinisvid << left << setw(15) << setfill(' ') << fixed << setprecision(2) << a.galutinismed << endl;
	}

	rf.close();
}
void pirma(vector <baze> studentai, vector <baze> &vargsiukai, vector <baze> &galvociai) {
	for (auto& a : studentai) {
		if (a.galutinisvid >= 5) galvociai.push_back(a);
		else vargsiukai.push_back(a);

	}

}
void padalinimostrategija(vector <baze>& studentai, vector <baze>& vargsiukai) {
	

    for (auto& a : studentai) {
     
		if (a.galutinisvid < 5)  vargsiukai.push_back(a); 		 
}

	studentai.erase(remove_if(studentai.begin(), studentai.end(), [&](baze
		const& studentas) { return studentas.galutinisvid < 5; }), studentai.end());
}

