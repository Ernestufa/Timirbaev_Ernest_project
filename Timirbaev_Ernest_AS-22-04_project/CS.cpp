#include "CS.h"

using namespace std;

int CS::MaxID = 0;


CS::CS()
{
    id = MaxID++;
}

CS CS::input_cs(CS& cs)
{
    cout << endl << "Enter cs name: "; getline(cin, cs.cs_name);
    LOG(cs.cs_name);
    cout << "Enter number of workshops: "; cs.workshops = GetCorrectNumber(1, 10000000);
    cout << "Enter number of active workshops: "; cs.active_workshops = workshops_check(cs.workshops);
    cout << "Enter effciency(0-100): "; cs.effciency = GetCorrectNumber(1, 100); cout << endl;
    return cs;
}

void CS::show_cs(const CS& station)
{
    cout << endl << "CS " << station.id << endl << endl
        << "Name: " << station.cs_name << endl
        << "Workshops: " << station.workshops << endl
        << "Active workshops: " << station.active_workshops << endl
        << "Effciency: " << station.effciency << endl << endl;
}

void CS::edit_cs(CS& station, int new_workshops)
{
    if (new_workshops <= CS::workshops)
        station.active_workshops = new_workshops;
}

int CS::GetID() const
{
    return id;
}

std::string CS::Getname() const
{
    return cs_name;
}

int CS::Getworkshops() const
{
    return workshops;
}

int CS::Getactive_workshops() const
{
    return active_workshops;
}

ofstream& operator << (ofstream& fout, const CS& cs) {
    if (fout.is_open()) {
        fout << cs.cs_name << endl;
        fout << cs.workshops << endl;
        fout << cs.active_workshops << endl;
        fout << cs.effciency << endl;
        fout << cs.id << endl;
    }
    return fout;
}

ifstream& operator >> (ifstream& fin, CS& cs) {
    if (fin.is_open()) {
        fin >> ws;
        getline(fin, cs.cs_name);
        fin >> cs.workshops;
        fin >> cs.active_workshops;
        fin >> cs.effciency;
        fin >> cs.id;
        if (cs.id > CS::MaxID)
            CS::MaxID = cs.id;
    }
    return fin;
}