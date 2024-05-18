#include "Skaiciavimaidarbai.h"
#include "MokiniuProcessing.h"
void NetinkamaIvestis()
{
    cout << "Netinkama �vestis. Programa i�jungiama...";
}
void NeraFailo()
{
    cout << "Failas nerastas. Programa i�jungiama...";
}

double Mediana(deque<double>& dq) {
    if (dq.empty()) return 0;
    deque<double> copy = dq;
    sort(copy.begin(), copy.end());
    int n = copy.size();
    if (n % 2 == 0) {
        return (copy[n / 2 - 1] + copy[n / 2]) / 2.0;
    }
    else {
        return copy[n / 2];
    }
}

double GenerateRandomGrade()
{
    return rand() % 11;
}

void PrintStudents(const deque<Studentas>& studentai)
{
    auto start_print = chrono::high_resolution_clock::now();
    cout << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    for (const auto& stud : studentai)
    {
        cout << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
    }
    auto end_print = chrono::high_resolution_clock::now();
    chrono::duration<double> write_time = end_print - start_print;
    cout << "Rasymo i ekrana trukme: " << write_time.count() << " sekundes" << endl;
}
void GeneruotiFaila(const string& pavadinimas, int studentuskaicius) {
    ofstream failas(pavadinimas);
    if (failas.is_open()) {
        failas << left << setw(20) << "Vardas" << setw(24) << "Pavarde" << setw(6) << "ND1" << setw(6) << "ND2" << setw(6) << "ND3" << setw(6) << "ND4" << setw(6) << "ND5" << setw(6) << "Egz." << endl;
        for (int i = 1; i <= studentuskaicius; i++) {
            failas << left << setw(20) << ("Vardas" + to_string(i)) << setw(20) << ("Pavarde" + to_string(i)) << right;
            for (int j = 0; j < 5; j++) {
                int pazymys = GenerateRandomGrade();
                failas << setw(6) << pazymys;
            }
            failas << setw(6) << GenerateRandomGrade() << endl;
        }
        failas.close();
        cout << "Failas sugeneruotas." << endl;
    }
    else {
        cout << "Ne�manoma atidaryti failo." << endl;
    }

}
bool compareByGalutinisVid(const Studentas& a, const Studentas& b) {
    return a.galutinisbalasvidurkis < b.galutinisbalasvidurkis;
}
bool compareByGalutinisMed(const Studentas& a, const Studentas& b) {
	return a.galutinisbalasmediana < b.galutinisbalasmediana;
}
void readAndProcessData(const string& filename, deque<Studentas>& studentai, int namudarbai) {
    ifstream failas1(filename);
    string line;
    getline(failas1, line);
    auto atidarymo_pradzia = chrono::high_resolution_clock::now();
    while (failas1.good()) {
        Studentas stud;
        if (!(failas1 >> stud.vardas >> stud.pavarde)) break;
        double grade;
        for (int i = 0; i < namudarbai; i++) {
            failas1 >> grade;
            stud.namudarburez.push_back(grade);
        }
        failas1 >> stud.egzaminorez;
        stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
        stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
        stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
        stud.mediana = Mediana(stud.namudarburez);
        stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
        studentai.push_back(stud);
    }
    auto atidarymo_pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> read_time = atidarymo_pabaiga - atidarymo_pradzia;
    cout << "Duomenu nuskaitymas i� failo � konteiner� u�truko: " << read_time.count() << " sekund�i�" << endl;
}

void sortStudents(deque<Studentas>& studentai, int sortpasirinkimas) {
    auto sort_pradzia = chrono::high_resolution_clock::now();
    switch (sortpasirinkimas) {
    case 1: sort(studentai.begin(), studentai.end(), compareByGalutinisVid); break;
    case 2: sort(studentai.begin(), studentai.end(), compareByGalutinisMed); break;
    default: cout << "Netinkamas pasirinkimas. Pasirinkite i� naujo." << endl; return;
    }
    auto sort_pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> sort_time = sort_pabaiga - sort_pradzia;
    cout << "Mokiniu rusiavimas naudojant sort funkcija uztruko " << sort_time.count() << " sekund�i�" << endl;
}

void partitionStudents1(const deque<Studentas>& studentai, deque<Studentas>& normalus, deque<Studentas>& nenormalus) {
    cout << "Studentai dalinami � normalius ir nenormalius." << endl;
    auto normnenorm_pradzia = chrono::high_resolution_clock::now();
    for (const auto& stud : studentai) {
        if (stud.galutinisbalasvidurkis >= 5.0) normalus.push_back(stud);
        else nenormalus.push_back(stud);
    }
    auto normnenorm_pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> normnenorm_time = normnenorm_pabaiga - normnenorm_pradzia;
    cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << normnenorm_time.count() << " sekund�i�" << endl;
}

void partitionStudents2(deque<Studentas>& studentai, deque<Studentas>& nenormalus) {
    cout << "Studentai dalinami � normalius ir nenormalius." << endl;
    auto normnenorm_pradzia = chrono::high_resolution_clock::now();
    auto iter = remove_if(studentai.begin(), studentai.end(),
        [&nenormalus](const Studentas& s) {
            if (s.galutinisbalasvidurkis < 5.0) {
                nenormalus.push_back(s); // Add to nenormalus deque
                return true; // Remove from studentai
            }
            return false; // Keep in studentai
        });
    studentai.erase(iter, studentai.end());
    auto normnenorm_pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> normnenorm_time = normnenorm_pabaiga - normnenorm_pradzia;
    cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << normnenorm_time.count() << " sekund�i�" << endl;
}

void partitionStudents3(deque<Studentas>& studentai, deque<Studentas>& normalus, deque<Studentas>& nenormalus) {
    cout << "Studentai dalinami � normalius ir nenormalius." << endl;
    auto normnenorm_pradzia = chrono::high_resolution_clock::now();
    auto partition_point = partition(studentai.begin(), studentai.end(),
        [](const Studentas& stud) {
            return stud.galutinisbalasvidurkis >= 5.0;
        });
    move(studentai.begin(), partition_point, back_inserter(normalus));
    move(partition_point, studentai.end(), back_inserter(nenormalus));
    auto normnenorm_pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double> normnenorm_time = normnenorm_pabaiga - normnenorm_pradzia;
    cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << normnenorm_time.count() << " sekund�i�" << endl;
}