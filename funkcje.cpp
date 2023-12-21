#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

#include "funkcje.h"

using namespace std;

double logN(int num) {
	return log(num);
}

float odchylenieSt(vector<int> tab) {
	int tabSize = tab.size();
	int average = 0;
	float result = 0;

	for (int i = 0; i < tabSize; i++) average += tab[i];
	average /= tabSize;

	for (int i = 0; i < tabSize; i++) result += pow((tab[i] - average), 2);
	result /= tabSize;

	result = sqrt(result);

	return result;
}

float expon(int num) {
	return exp(num);
}

float quadEquation(int num) {
	return pow(num, num - 1);
}

vector<Produkt> wczytajDaneZBazy(){
    vector<Produkt> produkty;
    string nazwaPliku = "produkty.txt";
    
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie można otworzyć pliku: " << nazwaPliku << endl;
        return produkty;
    }

    while (!plik.eof()) {
        Produkt nowyProdukt;
        plik >> nowyProdukt.nazwa >> nowyProdukt.ilosc >> nowyProdukt.termin_przydatnosci;
        produkty.push_back(nowyProdukt);
    }

    plik.close(); 
    
    return produkty;
}

void usunProduktZLodowki(int numerProduktu, vector<Produkt>& produkty, string nazwaPliku){
    if(numerProduktu >= 1 && numerProduktu <= produkty.size()) {
        produkty.erase(produkty.begin() + numerProduktu - 1);

        ofstream nowyPlik(nazwaPliku, ios::trunc);
        
        if(nowyPlik.is_open()) {
            for(int i = 0; i < produkty.size(); i++) {
                string nowaLinia = i + 1 == produkty.size() ? "" : "\n"; 
                
                nowyPlik << produkty[i].nazwa << " " << produkty[i].ilosc 
                         << " " << produkty[i].termin_przydatnosci << nowaLinia;
            }

            cout << "Produkt usunięty." << endl;
        } else {
            cerr << "Nie można otworzyć pliku do zapisu." << endl;
        }
    } else {
        cerr << "Nieprawidłowy numer linii do usunięcia." << endl;
    }    
}