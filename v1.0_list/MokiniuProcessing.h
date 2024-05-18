#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <locale>
#include <numeric>
#include <fstream>
#include <sstream>
#include <cctype>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
struct Studentas
{
    string vardas;
    string pavarde;
    list<double> namudarburez;
    double egzaminorez = 0.0;
    double namudarburezsuma = 0.0;
    double vidurkis = 0.0;
    double galutinisbalasvidurkis = 0.0;
    double mediana = 0.0;
    double galutinisbalasmediana = 0.0;
};
string GeneruotiVardus();
string GeneruotiPavardes();
bool vardolyginimas(const Studentas& a, const Studentas& b);
bool pavardeslyginimas(const Studentas& a, const Studentas& b);
bool vidurkiolyginimas(const Studentas& a, const Studentas& b);
bool medianoslyginimas(const Studentas& a, const Studentas& b);
void PatikrintiTeigiamajiSkaiciu(int skaicius);
bool ContainsNumbers(const string& str);