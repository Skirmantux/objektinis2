#include "MokiniuProcessing.h"
#include "Skaiciavimaidarbai.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Lithuanian");
    srand(time(NULL));
    list<Studentas> studentai;
    list<Studentas> normalus;
    list<Studentas> nenormalus;
    list<Studentas> studentai1;
    list<Studentas> studentai2;
    int pasirinkimas;
    chrono::duration <double> process_time;
    chrono::duration <double> read_time;
    cout << "Pasirinkite bal� �vedimo metod�/generavimo funkcij�:\n1. �vesti rankiniu b�du\n2. Sugeneruoti atsitiktinius balus\n3. Sugeneruoti balus, vardus ir pavardes\n4. Skaitymas i� failo.\n5. Baigti program�.\n6. Generuoti student� fail�.\n7. Strategij� testavimas.\nPasirinkimas: ";
    while (true) {
        try {
            cin >> pasirinkimas;
            if (pasirinkimas < 1 || pasirinkimas > 7) {
                throw invalid_argument("Netinkama �vestis.");
            }
            break;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
            cout << "Pasirinkimas: ";
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        }
    }
    while (true) {
        Studentas stud;
        if (pasirinkimas == 1) {
            while (true) {
                Studentas stud;
                try {
                    cout << "�veskite studento vard� ir pavard�. Nor�dami baigti �vedim�, �veskite -1: ";
                    cin >> stud.vardas;
                    if (stud.vardas == "-1")
                        break;
                    if (ContainsNumbers(stud.vardas)) {
                        throw invalid_argument("Vardas negali tur�ti skai�i�. Pra�ome �vesti vard� be skai�i�.");
                    }
                    cin >> stud.pavarde;
                    if (stud.pavarde == "-1")
                        break;
                    if (ContainsNumbers(stud.pavarde)) {
                        throw invalid_argument("Pavard� negali tur�ti skai�i�. Pra�ome �vesti pavard� be skai�i�.");
                    }
                    cout << "�veskite nam� darb� rezultatus. Nor�dami baigti �vedim�, �veskite -1: ";
                    while (true) {
                        double namudarburez;
                        if (!(cin >> namudarburez)) {
                            cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                            continue;
                        }
                        if (namudarburez == -1)
                            break;
                        if (namudarburez >= 0 && namudarburez <= 10) {
                            stud.namudarburez.push_back(namudarburez);
                        }
                        else {
                            cout << "Netinkama �vestis. �veskite skai�i� tarp 0 ir 10." << endl;
                        }
                    }
                    double egzaminorez;
                    cout << "�veskite egzamino rezultat�: ";
                    cin >> egzaminorez;
                    if (egzaminorez < 0 || egzaminorez > 10) {
                        throw out_of_range("Netinkama �vestis.");
                    }
                    stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                    stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                    stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + egzaminorez * 0.6;
                    studentai.push_back(stud);
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                }
            }
        }
        else if (pasirinkimas == 2) {
            while (true) {
                cout << "�veskite studento vard� ir pavard�. Nor�dami baigti �vedim�, �veskite -1: ";
                cin >> stud.vardas;
                if (stud.vardas == "-1")
                    break;
                cin >> stud.pavarde;
                cout << "Generuojami atsitiktiniai balai u� nam� darbus..." << endl;
                for (int i = 0; i < 5; ++i) {
                    stud.namudarburez.push_back(GenerateRandomGrade());
                }
                stud.egzaminorez = GenerateRandomGrade();
                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
                stud.namudarburez.clear();
            }
        }
        else if (pasirinkimas == 3) {
            cout << "Generuojami balai, vardai ir pavard�s ir student� kiekis spausdinimui" << endl;
            int studentukiekis;
            studentukiekis = rand() % 200;
            for (int i = 0; i < studentukiekis; ++i) {
                Studentas stud;
                for (int j = 0; j < 5; ++j) {
                    stud.namudarburez.push_back(GenerateRandomGrade());
                }
                stud.egzaminorez = GenerateRandomGrade();
                stud.vardas = GeneruotiVardus();
                stud.pavarde = GeneruotiPavardes();
                stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                stud.mediana = Mediana(stud.namudarburez);
                stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                studentai.push_back(stud);
                stud.namudarburez.clear();
            }
        }
        else if (pasirinkimas == 4) {
            while (true) {
                try {
                    auto start_read = chrono::high_resolution_clock::now();
                    cout << "Kuri faila norite atidaryti:\n1 - studentai10000.txt\n2 - studentai100000.txt\n3 - studentai1000000.txt\nPasirinkimas: ";
                    int failopasirinkimas;
                    cin >> failopasirinkimas;
                    ifstream failas;
                    switch (failopasirinkimas) {
                    case 1:
                        failas.open("studentai10000.txt");
                        break;
                    case 2:
                        failas.open("studentai100000.txt");
                        break;
                    case 3:
                        failas.open("studentai1000000.txt");
                        break;
                    default:
                        throw invalid_argument("Neteisingas pasirinkimas.");
                    }
                    if (!failas.is_open()) {
                        throw runtime_error("Nepavyko atidaryti failo.");
                    }
                    auto end_read = chrono::high_resolution_clock::now();
                    read_time = end_read - start_read;
                    auto start_process = chrono::high_resolution_clock::now();
                    string line;
                    getline(failas, line);
                    istringstream iss(line);
                    int stulpeliai = 0;
                    string zodziai;
                    while (iss >> zodziai) {
                        stulpeliai++;
                    }
                    int namudarbai = stulpeliai - 3;
                    while (failas.good()) {
                        Studentas stud;
                        if (!(failas >> stud.vardas >> stud.pavarde))
                            break;
                        double grade;
                        for (int i = 0; i < namudarbai; i++) {
                            failas >> grade;
                            stud.namudarburez.push_back(grade);
                        }
                        failas >> stud.egzaminorez;
                        stud.namudarburezsuma = accumulate(stud.namudarburez.begin(), stud.namudarburez.end(), 0.0);
                        stud.vidurkis = stud.namudarburezsuma / stud.namudarburez.size();
                        stud.galutinisbalasvidurkis = stud.vidurkis * 0.4 + stud.egzaminorez * 0.6;
                        stud.mediana = Mediana(stud.namudarburez);
                        stud.galutinisbalasmediana = stud.mediana * 0.4 + stud.egzaminorez * 0.6;
                        studentai.push_back(stud);
                    }
                    auto end_process = chrono::high_resolution_clock::now();
                    process_time = end_process - start_process;
                    failas.close();
                    break;
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                }
            }
        }
        else if (pasirinkimas == 5) {
            cout << "Programa baigia darb�." << endl;
            break;
        }
        else if (pasirinkimas == 6) {
            auto veikimo_pradzia = chrono::high_resolution_clock::now();
            cout << "Pasirinkite kiek student� norite sugeneruoti:\n1. 1 000\n2. 10 000\n3. 100 000\n4. 1 000 000\n5. 10 000 000\nPasirinkimas:";
            int studentugen;
            cin >> studentugen;
            auto start_read = chrono::high_resolution_clock::now();
            switch (studentugen) {
            case 1:
                GeneruotiFaila("studentaic1000.txt", 1000);
                break;
            case 2:
                GeneruotiFaila("studentaic10000.txt", 10000);
                break;
            case 3:
                GeneruotiFaila("studentaic100000.txt", 100000);
                break;
            case 4:
                GeneruotiFaila("studentaic1000000.txt", 1000000);
                break;
            case 5:
                GeneruotiFaila("studentaic10000000.txt", 10000000);
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pra�ome �vesti tinkam� pasirinkim�: " << endl;
                continue;
            }
            auto end_read = chrono::high_resolution_clock::now();
            read_time = end_read - start_read;
            cout << "Failo kurimas ir jo uzdarymas uztruko: " << read_time.count() << " sekundes" << endl;
            cout << "Kur� fail� norite skaityti?:\n1. 1 000\n2. 10 000\n3. 100 000\n4. 1 000 000\n5. 10 000 000\nPasirinkimas:" << endl;
            int failopasirinkimas;
            cin >> failopasirinkimas;
            auto atidarymo_pradzia = chrono::high_resolution_clock::now();
            ifstream failas1;
            int studentuskaicius;
            switch (failopasirinkimas) {
            case 1:
                failas1.open("studentaic1000.txt");
                studentuskaicius = 1000;
                break;
            case 2:
                failas1.open("studentaic10000.txt");
                studentuskaicius = 10000;
                break;
            case 3:
                failas1.open("studentaic100000.txt");
                studentuskaicius = 100000;
                break;
            case 4:
                failas1.open("studentaic1000000.txt");
                studentuskaicius = 1000000;
                break;
            case 5:
                failas1.open("studentaic10000000.txt");
                studentuskaicius = 10000000;
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pra�ome �vesti tinkam� pasirinkim�: " << endl;
                continue;
            }
            auto atidarymo_pabaiga = chrono::high_resolution_clock::now();
            read_time = atidarymo_pabaiga - atidarymo_pradzia;
            cout << "Duomenu nuskaitymas is failo uztruko: " << read_time.count() << " sekundes" << endl;
            auto rusiavimo_pradzia = chrono::high_resolution_clock::now();
            string line;
            getline(failas1, line);
            istringstream iss(line);
            int stulpeliai = 0;
            string zodziai;
            while (iss >> zodziai) {
                stulpeliai++;
            }
            int namudarbai = stulpeliai - 3;
            while (failas1.good()) {
                Studentas stud;
                if (!(failas1 >> stud.vardas >> stud.pavarde))
                    break;
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
                if (stud.galutinisbalasvidurkis >= 5.0)
                    normalus.push_back(stud);
                else
                    nenormalus.push_back(stud);
            }
            auto rusiavimo_pabaiga = chrono::high_resolution_clock::now();
            process_time = rusiavimo_pabaiga - rusiavimo_pradzia;
            cout << "Studentai dalinami � normalius ir nenormalius." << endl;
            cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Normalus studentai spausdinami � fail� 'normal�s.txt'." << endl;
            auto start_process = chrono::high_resolution_clock::now();
            ofstream failas2("normal�s.txt");
            failas2 << fixed << setprecision(2);
            failas2 << left << setw(20) << "Pavarde" << setw(20) << "Vardas";
            for (int i = 0; i < 5; ++i) {
                failas2 << setw(15) << "ND" + to_string(i + 1);
            }
            failas2 << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
            for (const auto& stud : normalus) {
                failas2 << left << setw(20) << stud.pavarde << setw(20) << stud.vardas;
                for (const auto& grade : stud.namudarburez) {
                    failas2 << setw(15) << grade;
                }
                failas2 << setw(30) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
            }
            failas2.close();
            cout << "Nenormal�s studentai spausdinami � fail� 'nenormal�s.txt'." << endl;
            ofstream failas3("nenormal�s.txt");
            failas3 << fixed << setprecision(2);
            failas3 << left << setw(15) << "Pavarde" << setw(15) << "Vardas";
            for (int i = 0; i < 5; ++i) {
                failas3 << setw(15) << "ND" + to_string(i + 1);
            }
            failas3 << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
            for (const auto& stud : nenormalus) {
                failas3 << left << setw(15) << stud.pavarde << setw(15) << stud.vardas;
                for (const auto& grade : stud.namudarburez) {
                    failas3 << setw(15) << grade;
                }
                failas3 << setw(30) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
            }
            failas3.close();
            failas1.close();
            failas2.close();
            auto end_process = chrono::high_resolution_clock::now();
            process_time = end_process - start_process;
            cout << "Surusiuotu studentu isvedimas i du naujus failus uztruko: " << process_time.count() << " sekundes" << endl;
            auto veikimo_pabaiga = chrono::high_resolution_clock::now();
            process_time = veikimo_pabaiga - veikimo_pradzia;
            cout << "Programa viso uztruko " << process_time.count() << " sekundes" << endl;
            break;
        }
        else if (pasirinkimas == 7) {
            cout << "Bandoma pirma strategija..." << endl;
            cout << "Kur� fail� norite skaityti?:\n1. 1 000\n2. 10 000\n3. 100 000\n4. 1 000 000\n5. 10 000 000\nPasirinkimas:" << endl;
            int failopasirinkimas;
            cin >> failopasirinkimas;
            ifstream failas1;
            int studentuskaicius;
            switch (failopasirinkimas) {
            case 1:
                failas1.open("studentaic1000.txt");
                studentuskaicius = 1000;
                break;
            case 2:
                failas1.open("studentaic10000.txt");
                studentuskaicius = 10000;
                break;
            case 3:
                failas1.open("studentaic100000.txt");
                studentuskaicius = 100000;
                break;
            case 4:
                failas1.open("studentaic1000000.txt");
                studentuskaicius = 1000000;
                break;
            case 5:
                failas1.open("studentaic10000000.txt");
                studentuskaicius = 10000000;
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pra�ome �vesti tinkam� pasirinkim�: " << endl;
                continue;
            }
            string line;
            getline(failas1, line);
            istringstream iss(line);
            int stulpeliai = 0;
            string zodziai;
            while (iss >> zodziai) {
                stulpeliai++;
            }
            int namudarbai = stulpeliai - 3;
            auto atidarymo_pradzia = chrono::high_resolution_clock::now();
            while (failas1.good()) {
                Studentas stud;
                if (!(failas1 >> stud.vardas >> stud.pavarde))
                    break;
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
            read_time = atidarymo_pabaiga - atidarymo_pradzia;
            cout << "Duomenu nuskaitymas i� failo � konteiner� u�truko: " << read_time.count() << " sekundes" << endl;
            cout << "Kaip norite rusiuoti studentu vektoriu?\n1. Pagal vidurk�\n2. Pagal median�\nPasirinkimas: ";
            int sortpasirinkimas;
            cin >> sortpasirinkimas;
            auto sort_pradzia = chrono::high_resolution_clock::now();
            switch (sortpasirinkimas) {
            case 1:
                studentai.sort(compareByGalutinisVid);
                break;
            case 2:
                studentai.sort(compareByGalutinisMed);
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pasirinkite i� naujo." << endl;
                continue;
            }
            auto sort_pabaiga = chrono::high_resolution_clock::now();
            process_time = sort_pabaiga - sort_pradzia;
            cout << "Mokiniu rusiavimas naudojant sort funkcija uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Studentai dalinami � normalius ir nenormalius." << endl;
            auto normnenorm_pradzia = chrono::high_resolution_clock::now();
            for (auto it = studentai.begin(); it != studentai.end();) {
                if (it->galutinisbalasvidurkis >= 5.0) {
                    normalus.push_back(*it);
                    it = studentai.erase(it);
                }
                else {
                    nenormalus.push_back(*it);
                    it = studentai.erase(it);
                }
            }
            auto normnenorm_pabaiga = chrono::high_resolution_clock::now();
            process_time = normnenorm_pabaiga - normnenorm_pradzia;
            cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Pirma strategija baigta, pradedama antra..." << endl;
            failas1.close();
            //--------------------------------------------------------------------------------------------------------------
            switch (failopasirinkimas) {
            case 1:
                failas1.open("studentaic1000.txt");
                studentuskaicius = 1000;
                break;
            case 2:
                failas1.open("studentaic10000.txt");
                studentuskaicius = 10000;
                break;
            case 3:
                failas1.open("studentaic100000.txt");
                studentuskaicius = 100000;
                break;
            case 4:
                failas1.open("studentaic1000000.txt");
                studentuskaicius = 1000000;
                break;
            case 5:
                failas1.open("studentaic10000000.txt");
                studentuskaicius = 10000000;
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pra�ome �vesti tinkam� pasirinkim�: " << endl;
                continue;
            }
            string line1;
            getline(failas1, line1);
            istringstream iss1(line1);
            int stulpeliai1 = 0;
            string zodziai1;
            while (iss1 >> zodziai1) {
                stulpeliai1++;
            }
            auto atidarymo1_pradzia = chrono::high_resolution_clock::now();
            while (failas1.good()) {
                Studentas stud;
                if (!(failas1 >> stud.vardas >> stud.pavarde))
                    break;
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
                studentai1.push_back(stud);
            }
            auto atidarymo1_pabaiga = chrono::high_resolution_clock::now();
            read_time = atidarymo1_pabaiga - atidarymo1_pradzia;
            cout << "Duomenu nuskaitymas i� failo � konteiner� u�truko: " << read_time.count() << " sekundes" << endl;
            auto sort_pradzia1 = chrono::high_resolution_clock::now();
            switch (sortpasirinkimas) {
            case 1:
                studentai1.sort(compareByGalutinisVid);
                break;
            case 2:
                studentai1.sort(compareByGalutinisMed);
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pasirinkite i� naujo." << endl;
                continue;
            }
            auto sort_pabaiga1 = chrono::high_resolution_clock::now();
            process_time = sort_pabaiga1 - sort_pradzia1;
            cout << "Mokiniu rusiavimas naudojant sort funkcija uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Studentai dalinami � normalius ir nenormalius." << endl;
            auto normnenorm_pradzia1 = chrono::high_resolution_clock::now();
            auto iter = std::remove_if(studentai1.begin(), studentai1.end(),
                [&nenormalus](const Studentas& s) {
                    if (s.galutinisbalasvidurkis < 5.0) {
                        nenormalus.push_back(s); // Add to nenormalus list
                        return true; // Remove from studentai1
                    }
                    return false; // Keep in studentai1
                });
            auto normnenorm_pabaiga1 = chrono::high_resolution_clock::now();
            process_time = normnenorm_pabaiga1 - normnenorm_pradzia1;
            cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Antra strategija baigta... Pradedama trecioji..." << endl;
            failas1.close();
            //--------------------------------------------------------------------------------------------------------------
            switch (failopasirinkimas) {
            case 1:
                failas1.open("studentaic1000.txt");
                studentuskaicius = 1000;
                break;
            case 2:
                failas1.open("studentaic10000.txt");
                studentuskaicius = 10000;
                break;
            case 3:
                failas1.open("studentaic100000.txt");
                studentuskaicius = 100000;
                break;
            case 4:
                failas1.open("studentaic1000000.txt");
                studentuskaicius = 1000000;
                break;
            case 5:
                failas1.open("studentaic10000000.txt");
                studentuskaicius = 10000000;
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pra�ome �vesti tinkam� pasirinkim�: " << endl;
                continue;
            }
            string line2;
            getline(failas1, line2);
            istringstream iss2(line2);
            int stulpeliai2 = 0;
            string zodziai2;
            while (iss2 >> zodziai2) {
                stulpeliai2++;
            }
            auto atidarymo2_pradzia = chrono::high_resolution_clock::now();
            while (failas1.good()) {
                Studentas stud;
                if (!(failas1 >> stud.vardas >> stud.pavarde))
                    break;
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
                studentai2.push_back(stud);
            }
            auto atidarymo2_pabaiga = chrono::high_resolution_clock::now();
            process_time = atidarymo2_pabaiga - atidarymo2_pradzia;
            cout << "Duomenu nuskaitymas i� failo � konteiner� u�truko: " << process_time.count() << " sekundes" << endl;
            auto sort_pradzia2 = chrono::high_resolution_clock::now();
            switch (sortpasirinkimas) {
            case 1:
                studentai2.sort(compareByGalutinisVid);
                break;
            case 2:
                studentai2.sort(compareByGalutinisMed);
                break;
            default:
                cout << "Netinkamas pasirinkimas. Pasirinkite i� naujo." << endl;
                continue;
            }
            auto sort_pabaiga2 = chrono::high_resolution_clock::now();
            process_time = sort_pabaiga2 - sort_pradzia2;
            cout << "Mokiniu rusiavimas naudojant sort funkcija uztruko " << process_time.count() << " sekundes" << endl;
            cout << "Studentai dalinami � normalius ir nenormalius." << endl;
            auto normnenorm_pradzia2 = chrono::high_resolution_clock::now();
            auto partition_point = std::partition(studentai2.begin(), studentai2.end(),
                [](const Studentas& stud) {
                    return stud.galutinisbalasvidurkis >= 5.0;
                });
            move(studentai2.begin(), partition_point, std::back_inserter(normalus));
            move(partition_point, studentai2.end(), std::back_inserter(nenormalus));
            auto normnenorm_pabaiga2 = chrono::high_resolution_clock::now();
            process_time = normnenorm_pabaiga2 - normnenorm_pradzia2;
            cout << "Studentu rusiavimas i normalius ir nenormalius uztruko " << process_time.count() << " sekundes" << endl;
            break;
            failas1.close();
        }

        if (!studentai.empty()) {
            cout << "Norite �ra�yti duomenis atspausdinant � ekran� ar � fail�?: 1 - ekran�; 2 - fail�" << endl;
            int skaicbudas;
            cin >> skaicbudas;
            cout << "Pasirinkite rikiavimo b�d�:\n1 - pagal vardus\n2 - pagal pavardes\n3 - pagal galutin� bal� (vid.)\n4 - pagal galutin� bal� (med.)\nPasirinkimas: ";
            int sorting_choice;
            cin >> sorting_choice;
            switch (sorting_choice) {
            case 1:
                studentai.sort(vardolyginimas);
                break;
            case 2:
                studentai.sort(pavardeslyginimas);
                break;
            case 3:
                studentai.sort(vidurkiolyginimas);
                break;
            case 4:
                studentai.sort(medianoslyginimas);
                break;
            default:
                NetinkamaIvestis();
                break;
            }
            if (skaicbudas == 1) {
                //PrintStudents(studentai);
                break;
            }
            else if (skaicbudas == 2) {
                auto start_writing = chrono::high_resolution_clock::now();
                ofstream failasr("kursioku_duomenys.txt");
                failasr << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(30) << "Galutinis balas (vid.)" << setw(30) << "Galutinis balas (med.)" << endl;
                failasr << "---------------------------------------------------------------------------------------------------" << endl;
                for (const auto& stud : studentai) {
                    failasr << setw(15) << stud.pavarde << setw(15) << stud.vardas << setw(30) << fixed << setprecision(2) << stud.galutinisbalasvidurkis << setw(30) << fixed << setprecision(2) << stud.galutinisbalasmediana << endl;
                }
                cout << "�ra�ymas s�kmingas. Rezultatai i�saugoti faile kursioku_duomenys.txt" << endl;
                failasr.close();
                auto end_writing = chrono::high_resolution_clock::now();
                chrono::duration < double > writeFile_time = end_writing - start_writing;
                cout << "Skaitymas i� failo truko: " << read_time.count() << " sekundes" << endl;
                cout << "Mokini� vidurkio/medianos skai�iavimas u�truko: " << process_time.count() << " sekundes" << endl;
                cout << "�ra�ymas � fail� truko: " << writeFile_time.count() << " sekundes" << endl;
                break;
            }
            else {
                NetinkamaIvestis();
                break;
            }
        }
        else {
            cout << "Student� masyvas tu��ias." << endl;
        }
    }
    return 0;
}