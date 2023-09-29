#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct pipeline {
	string pipe_name;
	int pipe_length;
	double pipe_diameter;
	bool pipe_state;
};

struct cs {
	string cs_name;
	int workshops;
	int active_workshops;
	int effciency;
};

int int_check() {
	int number = 0;
	while (true) {
		cin >> number;
		if (cin.fail()) {
			cout << "Error! Enter number" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			if (number > 0) return number;
			else {
				cout << "Error! Enter number" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
}

bool bool_check() {
	bool flag = 0;
	while (true) {
		cin >> flag;
		if (cin.fail()) {
			cout << "Error! Choose 0 or 1" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else return flag;
	}
}

int workshops_check(int workshops) {
	int number = 0;
	while (true) {
		cin >> number;
		if (cin.fail()) {
			cout << "Error! Enter number" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			if (number <= workshops && number >= 0) {
				return number;
			}
			else if (number >= workshops) {
				cout << "Error! The number of active workshops cannot be greater than the number of all workshops" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				cout << "Error! The number less than 0" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
}

int effciency_check() {
	int number = 0;
	while (true) {
		cin >> number;
		if (cin.fail()) {
			cout << "Error! Enter number" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			cs cs;
			if (number <= 100 && number > 0) return number;
			else {
				cout << "Error! The number must be from 0 to 100" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	}
}

pipeline input_pipe() {
	pipeline new_pipe;
	cout << "Enter pipe name: "; cin >> new_pipe.pipe_name;
	cout << "Enter pipe length: "; new_pipe.pipe_length = int_check();
	cout << "Enter pipe diameter: "; new_pipe.pipe_diameter = int_check();
	cout << "Enter state in repair: "; new_pipe.pipe_state = bool_check(); cout << endl;
	return new_pipe;
}

cs input_cs() {
	cs new_cs;
	cout << "Enter cs name: "; cin >> new_cs.cs_name;
	cout << "Enter number of workshops: "; new_cs.workshops = int_check();
	cout << "Enter number of active workshops: "; new_cs.active_workshops = workshops_check(new_cs.workshops);
	cout << "Enter effciency: "; new_cs.effciency = effciency_check(); cout << endl;
	return new_cs;
}

void show(pipeline pipe, cs station) {
	if (pipe.pipe_name.empty()) cout << endl << "No added pipe!" << endl << endl;

	else {
		cout << endl << "Pipe" << endl << endl
			<< "Name: " << pipe.pipe_name << endl
			<< "Length: " << pipe.pipe_length << endl
			<< "Diameter: " << pipe.pipe_diameter << endl;
		if (pipe.pipe_state == 1) cout << "In repair: Yes" << endl << endl;
		else cout << "In repair: No" << endl << endl;
	}
	if (station.cs_name.empty()) cout << "No added cs!" << endl << endl;

	else {
		cout << "CS" << endl << endl
			<< "Name: " << station.cs_name << endl
			<< "Workshops: " << station.workshops << endl
			<< "Active workshops: " << station.active_workshops << endl
			<< "Effciency: " << station.effciency << endl << endl;
	}
}

void edit_pipe(pipeline& pipe) {
	if (pipe.pipe_name.empty()) cout << endl << "No added pipe!" << endl << endl;
	else {
		cout << "Enter new state: ";
		pipe.pipe_state = bool_check();
		cout << endl;
	}
}

void edit_cs(cs& station) {
	if (station.cs_name.empty()) cout << endl << "No added cs!" << endl << endl;
	else {
		cout << "Enter active workshops: ";
		station.active_workshops = workshops_check(station.workshops);
		cout << endl;
	}
}

void write_file(pipeline pipe, cs station) {
	if (pipe.pipe_name.empty() || station.cs_name.empty()) cout << endl << "Add a pipe and a cs before!" << endl << endl;
	else {
		ofstream file;
		file.open("file.txt", ios::out);
		if (file.is_open()) {
			file << "Pipe" << endl << endl
				<< "Name: " << pipe.pipe_name << endl
				<< "Length: " << pipe.pipe_length << endl
				<< "Diameter: " << pipe.pipe_diameter << endl;
			if (pipe.pipe_state == 1) file << "In repair: Yes" << endl << endl;
			else file << "In repair: No" << endl << endl;
			file << "CS" << endl << endl
				<< "CS_name: " << station.cs_name << endl
				<< "Workshops: " << station.workshops << endl
				<< "Active workshops: " << station.active_workshops << endl
				<< "Effciency: " << station.effciency;
			cout << endl;
		}
		file.close();
	}
}

string split(string line) {
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ':') {
			line.erase(0, i + 2);
			return line;
		}
	}
}

void read_file(pipeline& pipe, cs& station) {
	string line;
	ifstream file;
	file.open("file.txt", ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.find("Name: ") != string::npos) pipe.pipe_name = split(line);

			else if (line.find("Length: ") != string::npos) pipe.pipe_length = stoi(split(line));

			else if (line.find("Diameter: ") != string::npos) pipe.pipe_diameter = stoi(split(line));

			else if (line.find("In repair: ") != string::npos) {
				if (split(line) == "Yes") pipe.pipe_state = 1;
				else pipe.pipe_state = 0;
			}

			else if (line.find("CS_name: ") != string::npos) station.cs_name = split(line);

			else if (line.find("Workshops: ") != string::npos) station.workshops = stoi(split(line));

			else if (line.find("Active workshops: ") != string::npos) station.active_workshops = stoi(split(line));

			else if (line.find("Effciency: ") != string::npos) station.effciency = stoi(split(line));
		}
		file.close();
		cout << endl;
	}
	else cout << endl << "Error!" << endl << endl;
}

int main() {
	int number = 0;
	cs cs;
	pipeline pipe;

	while (true) {

		cout << "1 Add pipe" << endl 
			<< "2 Add CS" << endl
			<< "3 View all objects" << endl
			<< "4 Edit pipe" << endl
			<< "5 Edit CS" << endl
			<< "6 Save" << endl
			<< "7 Download" << endl
			<< "0 Exit" << endl << endl
			<< "Enter the command number: ";

		cin >> number;
		if (cin.fail()) {
			cout << "Error! Try again" << endl << endl;
			cin.clear();
		} else
		switch (number) {
		case 0:
			exit(0);
		case 1:
			pipe = input_pipe();
			break;
		case 2:
			cs = input_cs();
			break;
		case 3:
			show(pipe, cs);
			break;
		case 4:
			edit_pipe(pipe);
			break;
		case 5:
			edit_cs(cs);
			break;
		case 6:
			write_file(pipe, cs);
			break;
		case 7:
			read_file(pipe, cs);
			break;
		default:
			cout << "Error! Try again" << endl << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return 0; 
}