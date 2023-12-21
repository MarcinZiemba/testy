#include <iostream>
#include <vector>

#include "funkcje.h"

using namespace std;

int main()
{
	vector<int> tab = {1, 4, 12, 8};

	cout << logN(3) << endl;

	cout << odchylenieSt(tab) << endl;

	cout << expon(3) << endl;

	cout << quadEquation(3) << endl;

	return 0;
}

// dodaj tak� funkcj� x^(x-1)
