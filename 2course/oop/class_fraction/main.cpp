#include <iostream>
using namespace std;

class Fraction
{
private: // реализация
	int Numerator; // числитель
	int Denominator; // знаменатель

public: // интерфейс

	void Init(int x, int y)
	{
		Numerator = x;
		Denominator = y;
	}

// перегрузка, если ничего не было введено
	void Init()
	{
		Numerator = rand() % 100;
		Denominator = rand() % 100;
	}

	void Print()
	{
		cout << Numerator << "/" << Denominator << endl;
	}

	void Sum(Fraction& b) // сумма: (a/b) + (c/d) = (a*d + c*b) / (b*d)
	{
		int resultNumerator = Numerator * b.Denominator + b.Numerator * Denominator;
		int resultDenominator = Denominator * b.Denominator;
		cout << "Сумма = " << resultNumerator << "/" << resultDenominator << "\n";
	}

	void Sub(Fraction& b) // вычитание (a/b) - (c/d) = (a*d - c*b) / (b*d)
	{
		int resultNumerator = Numerator * b.Denominator - b.Numerator * Denominator;
		int resultDenominator = Denominator * b.Denominator;
		cout << "Разность = " << resultNumerator << "/" << resultDenominator << "\n";
	}

	void Mul(Fraction& b) // умножение (a/b) * (c/d) = (a*c) / (b*d)
	{
		int resultNumerator = Numerator * b.Numerator;
		int resultDenominator = Denominator * b.Denominator;
		cout << "Произведение = " << resultNumerator << "/" << resultDenominator << "\n";
	}

	void Div(Fraction& b) // деление (a/b) / (c/d) = (a*d) / (b*c)
	{
		int resultNumerator = Numerator * b.Denominator;
		int resultDenominator = Denominator * b.Numerator;
		cout << "Деление = " << resultNumerator << "/" << resultDenominator << "\n";
	}


};

int main() // клиент.
{
	setlocale(LC_ALL, "");

	Fraction FirstFraction, SecondFraction; // для понимания сути процесса - даю определённые имена
	
	FirstFraction.Init(1, 2);
	FirstFraction.Print();


	SecondFraction.Init(3, 4);
	SecondFraction.Print();

	FirstFraction.Sum(SecondFraction);
	FirstFraction.Sub(SecondFraction);
	FirstFraction.Mul(SecondFraction);
	FirstFraction.Div(SecondFraction);


	return 0;
}
