#include <string>
#include <vector>


using namespace std;

struct Produkt {
	string nazwa;
	int ilosc;
	string termin_przydatnosci;
};


double logN(int num);
float odchylenieSt(vector<int> tab);
float expon(int num);
float quadEquation(int num);
vector<Produkt> wczytajDaneZBazy();
void usunProduktZLodowki(int numerProduktu, vector<Produkt>& produkty, string nazwaPliku);