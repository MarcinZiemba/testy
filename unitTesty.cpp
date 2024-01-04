#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <string>
#include "../Project1/funkcje.cpp"
#include "C:/Users/Marcin/Desktop/studia/Sem3/inż_op/cpp/testuchy/funkcje.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int sizee = 0;

namespace HelloWorldTests
{
	TEST_CLASS(HelloWorldTests)
	{
	public:
		TEST_METHOD(logarytmNaturalny)
		{
			double input = round(logN(3) * 100000.0) / 100000.0;
			double expected = 1.09861;

			Assert::AreEqual(input, expected);
		}
		TEST_METHOD(odchylenieStandardowe)
		{
			double input = round(odchylenieSt({ 1, 4, 12, 8 }) * 100000.0) / 100000.0;
			double expected = 4.15331;

			Assert::AreEqual(input, expected);
		}
		TEST_METHOD(wartoscExponentu)
		{
			double input = round(expon(3) * 10000.0) / 10000.0;
			double expected = 20.0855;

			Assert::AreEqual(input, expected);
		}
		TEST_METHOD(funkcjaKwadratowa)
		{
			int input = quadEquation(3);
			int expected = 9;

			Assert::AreEqual(input, expected);
		}
		TEST_METHOD(wczytywanieProduktow)
		{
			vector<Produkt> input = wczytajDaneZBazy();
			int inupt2 = input.size();
			int expected = 0;

			Assert::AreNotEqual(inupt2, expected);
		}
		TEST_METHOD(wczytywanieProduktow)
		{
			vector<Produkt> input = wczytajDaneZBazy();
			int input2 = input.size();
			sizee = input2;
			int expected = 0;

			Assert::AreNotEqual(input2, expected);
		}
		TEST_METHOD(usuwanieProduktow)
		{
			vector<Produkt> input = wczytajDaneZBazy();
			usunProduktZLodowki(1, input, "produkty.txt");
			int input2 = input.size();

			Assert::AreEqual(input2, sizee - 1);
		}
	};
}

