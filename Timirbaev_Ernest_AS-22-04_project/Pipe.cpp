#include "Pipe.h"
#include "Utils.h"


using namespace std;

int Pipe::MaxID = 0;


Pipe::Pipe()
{
    id = MaxID++;
}

Pipe Pipe::input_pipe(Pipe& pipe)
{
    cout << endl << "Enter pipe name: "; getline(cin, pipe.pipe_name);
    LOG(pipe.pipe_name);
    cout << "Enter pipe length: "; pipe.pipe_length = GetCorrectNumber(1, 10000000);
    cout << "Enter pipe diameter: "; pipe.pipe_diameter = GetCorrectNumber(1, 10000000); cout << endl;
    pipe.pipe_state = 0;
    return pipe;
}

void Pipe::show_pipe(const Pipe& pipe)
{
    cout << endl << "Pipe " << pipe.id << endl << endl
        << "Name: " << pipe.pipe_name << endl
        << "Length: " << pipe.pipe_length << endl
        << "Diameter: " << pipe.pipe_diameter << endl;
    if (pipe.pipe_state == 1) cout << "In repair: Yes" << endl << endl;
    else cout << "In repair: No" << endl << endl;
}

void Pipe::edit_pipe(Pipe& pipe, int new_state)
{
    pipe.pipe_state = new_state;
}

std::string Pipe::Getname() const
{
    return pipe_name;
}

bool Pipe::Getstate() const
{
    return pipe_state;
}

ofstream& operator << (ofstream& fout, const Pipe& p) {
    if (fout.is_open()) {
        fout << p.pipe_name << endl;
        fout << p.pipe_length << endl;
        fout << p.pipe_diameter << endl;
        fout << p.pipe_state << endl;
        fout << p.id << endl;
    }
    return fout;
}

ifstream& operator >> (ifstream& fin, Pipe& p) {
    if (fin.is_open()) {
        fin >> ws;
        getline(fin, p.pipe_name);
        fin >> p.pipe_length;
        fin >> p.pipe_diameter;
        fin >> p.pipe_state;
        fin >> p.id;
        if (p.id > Pipe::MaxID)
            Pipe::MaxID = p.id;
    }
    return fin;
}