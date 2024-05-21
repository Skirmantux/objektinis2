#include "MokiniuProcessing.h"

string GeneruotiVardus()
{
    vector<string> vardai = { "Jonas", "Petras", "Antanas", "Marius", "Tomas" };
    return vardai[rand() % vardai.size()];
}

string GeneruotiPavardes()
{
    vector<string> pavardes = { "Kazlauskas", "Petrauskas", "Stankevi�ius", "Gudelis", "Luk�ys" };
    return pavardes[rand() % pavardes.size()];
}

void PatikrintiTeigiamajiSkaiciu(double skaicius) {
    if (skaicius < 0 || skaicius > 10) {
        throw invalid_argument("Netinkamas skai�ius");
    }
}

bool ContainsNumbers(const string& str) {
    return any_of(str.begin(), str.end(), ::isdigit);
}