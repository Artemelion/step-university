#include <iostream>
using namespace std;

class Car
{
private:
    char* model,* country,* color;
    int year;
    double price;

public:
    Car()
    {
        model = country = color = nullptr; // чтобы не хранить мусор
        year = 0;
        price = 0.0;
        cout << "Constructor by default\n";
    }

    // конструктор с параметрами
    Car(const char* m, const char* ctry, const char* clr, int y, double pr)
    {
        model = new char[strlen(m) + 1];
        strcpy_s(model, strlen(m) + 1, m);

        country = new char[strlen(ctry) + 1];
        strcpy_s(country, strlen(ctry) + 1, ctry);

        color = new char[strlen(clr) + 1];
        strcpy_s(color, strlen(clr) + 1, clr);

        year = y;
        price = pr;

        cout << "Constructor by params\n";
    }

    void Print()
    {
        cout << "Model: " << model << "\nCountry: " << country << "\nColor: " << color
            << "\nYear: " << year << "\nPrice: " << price << endl;
    }

    void Init(const char* m, const char* ctry, const char* clr, int y, double p)
    {
        if (model != nullptr)
        {
            delete[] model;
        }
        model = new char[strlen(m) + 1];
        strcpy_s(model, strlen(m) + 1, m);

        if (country != nullptr)
        {
            delete[] country;
        }

        country = new char[strlen(ctry) + 1];
        strcpy_s(country, strlen(ctry) + 1, ctry);

        if (color != nullptr)
        {
            delete[] color;
        }
        color = new char[strlen(clr) + 1];
        strcpy_s(color, strlen(clr) + 1, clr);

        year = y;
        price = p;
    }

    const char* GetModel()
    {
        if (model != nullptr)
        {
            return model;
        }
        else cout << "model is nullptr" << endl;
    }
    const char* GetCountry()
    {
        if (country != nullptr)
        {
            return country;
        }
        else cout << "country is nullptr" << endl;
    }
    const char* GetColor()
    {
        if (color != nullptr)
        {
            return color;
        }
        else cout << "color is nullptr" << endl;
    }
    int GetYear()
    {
        if (year != 0) 
        {
            return year;
        }
        else cout << "year == 0" << endl;
    }
    double GetPrice()
    {
        if (price != 0.0)
        {
            return price;
        }
        else cout << "price == 0.0" << endl;
    }


    void SetModel(const char* m)
    {
        if (model != nullptr)
        {
            delete[] model;
        }
        model = new char[strlen(m) + 1];
        strcpy_s(model, strlen(m) + 1, m);
