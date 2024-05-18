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
struct Studentas {
    string vardas;
    string pavarde;
    vector<double> namudarburez;
    double egzaminorez;
    double namudarburezsuma;
    double vidurkis;
    double galutinisbalasvidurkis;
    double mediana;
    double galutinisbalasmediana;
};
string GeneruotiVardus();
string GeneruotiPavardes();
bool vardolyginimas(const Studentas& a, const Studentas& b);
bool pavardeslyginimas(const Studentas& a, const Studentas& b);
bool vidurkiolyginimas(const Studentas& a, const Studentas& b);
bool medianoslyginimas(const Studentas& a, const Studentas& b);
void PatikrintiTeigiamajiSkaiciu(int skaicius);
bool ContainsNumbers(const string& str);