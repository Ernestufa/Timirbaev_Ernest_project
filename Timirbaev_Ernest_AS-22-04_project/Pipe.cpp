#include "Pipe.h"


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

Pipe Pipe::add_pipe_with_diameter(Pipe& pipe, int diameter)
{
    while (true) {
        cout << endl << "Enter the name of the pipe: ";
        getline(cin, pipe.pipe_name);
        if (pipe.pipe_name.empty())
            cout << "Error!" << endl;
        else LOG(pipe.pipe_name) break;
    }
    cout << "Enter the length of the pipe (meters): ";
    pipe.pipe_length = GetCorrectNumber(0, 1000);
    pipe.pipe_diameter = diameter;
    cout << "Pipe under repair (0; 1): ";
    pipe.pipe_state = GetCorrectNumber(0, 1);
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

int Pipe::GetID() const
{
    return id;
}

std::string Pipe::Getname() const
{
    return pipe_name;
}

int Pipe::GetDiameter() const
{
    return pipe_diameter;
}

bool Pipe::Getstate() const
{
    return pipe_state;
}

double Pipe::GetCapacity() const {
    double capacity = sqrt(pow(pipe_diameter / 1000.0, 5) / pipe_length);
    return !pipe_state ? capacity : -DBL_MAX;
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