#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

bool check(string number) {
	for (int i = 0; i < number.length(); i++) {
		if (isdigit(number[i]) || number[i] == '-') continue;
		else return false;
	}
	if (number.length() == 0) return false;
	return true;
}

int int_check() {
	int number = 0;
	string input;
	while (true) {
		getline(cin, input);
		if (check(input) == true) {
			number = stoi(input);
			if (number > 0) return number;
			else {
				cout << "Error! Number less than 0" << endl;
				cin.clear();
			}
		} else {
			cout << endl << "Error! Enter number" << endl;
			cin.clear();
		}
	}
}

bool bool_check() {
	string input;
	int number;
	bool flag = 0;
	while (true) {
		getline(cin, input);
		if (check(input) == true) {
			number = stoi(input);
			if (number == 0 || number == 1) {
				flag = number;
				return flag;
			}
			else {
				cout << "Error! Choose 0 or 1" << endl;
				cin.clear();
			}
		}
		else {
			cout << "Error! Choose 0 or 1" << endl;
			cin.clear();
		}
	}
}

int workshops_check(int workshops) {
	string input;
	int number = 0;
	while (true) {
		getline(cin, input);
		if (check(input) == true) {
			number = stoi(input);
			if (number <= workshops && number >= 0) {
				return number;
			}
			else if (number >= workshops) {
				cout << "Error! The number of active workshops cannot be greater than the number of all workshops" << endl;
				cin.clear();
			}
			else {
				cout << "Error! The number less than 0" << endl;
				cin.clear();
			}
		} else {
			cout << endl << "Error! Enter number" << endl;
			cin.clear();
		}
	}
}

int effciency_check() { //По возможности исправить
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

void input_pipe(pipeline& new_pipe) {
	cout << "Enter pipe name: "; getline(cin, new_pipe.pipe_name);
	cout << "Enter pipe length: "; new_pipe.pipe_length = int_check();
	cout << "Enter pipe diameter: "; new_pipe.pipe_diameter = int_check();
	cout << "Enter state in repair: "; new_pipe.pipe_state = bool_check(); cout << endl;
}

void input_cs(cs& new_cs) {
	cout << "Enter cs name: "; getline(cin, new_cs.cs_name);
	cout << "Enter number of workshops: "; new_cs.workshops = int_check();
	cout << "Enter number of active workshops: "; new_cs.active_workshops = workshops_check(new_cs.workshops);
	cout << "Enter effciency: "; new_cs.effciency = effciency_check(); cout << endl;
	cin.ignore(1000, '\n');
}

void show(const pipeline& pipe, const cs& station) {
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
		//cin.ignore(1000, '\n');
	}
}

void edit_cs(cs& station) {
	if (station.cs_name.empty()) cout << endl << "No added cs!" << endl << endl;
	else {
		cout << "Enter active workshops: ";
		station.active_workshops = workshops_check(station.workshops);
		cout << endl;
		//cin.ignore(1000, '\n');
	}
}

void write_file(const pipeline& pipe, const cs& station) {
	if (pipe.pipe_name.empty() && station.cs_name.empty()) cout << endl << "Add a pipe or a cs before!" << endl << endl;
	else {
		ofstream file;
		file.open("file.txt", ios::out);
		if (file.is_open()) {
			if (pipe.pipe_name.empty() == 0 && station.cs_name.empty() == 0) {
				file << "Pipe" << endl
					<< pipe.pipe_name << endl
					<< pipe.pipe_length << endl
					<< pipe.pipe_diameter << endl
					<< pipe.pipe_state << endl << endl;
				file << "CS" << endl
					<< station.cs_name << endl
					<< station.workshops << endl
					<< station.active_workshops << endl
					<< station.effciency;
			}
			else if (pipe.pipe_name.empty() == 0 && station.cs_name.empty() == 1) {
				file << "Pipe" << endl
					<< pipe.pipe_name << endl
					<< pipe.pipe_length << endl
					<< pipe.pipe_diameter << endl
					<< pipe.pipe_state << endl << endl;
			}
			else if (pipe.pipe_name.empty() == 1 && station.cs_name.empty() == 0) {
				file << "CS" << endl
					<< station.cs_name << endl
					<< station.workshops << endl
					<< station.active_workshops << endl
					<< station.effciency;
			}
			file.close();
			cout << endl;
		} else cout << endl << "Error!" << endl << endl;
	}
}

//string split(string line) {
//	for (int i = 0; i < line.length(); i++) {
//		if (line[i] == ':') {
//			line.erase(0, i + 2);
//			return line;
//		}
//	}
//}

void read_file(pipeline& pipe, cs& station) {
	string line;
	string type = "Noun";
	bool flag = false;
	vector<string> data;
	ifstream file;
	file.open("file.txt", ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			data.push_back(line);
		}
		for (int i = 0; i < data.size(); i++) {
			if (data[i].find("Pipe") != string::npos) {
				type = "pipe";
				flag = true;
			}
			else if (data[i].find("CS") != string::npos) {
				type = "cs";
				flag = true;
			}
			else if (type == "pipe" && flag == true) {
				pipe.pipe_name = data[i];
				pipe.pipe_diameter = stoi(data[i + 1]);
				pipe.pipe_length = stoi(data[i + 2]);
				pipe.pipe_state = stoi(data[i + 3]);
				flag = false;
			}
			else if (type == "cs" && flag == true) {
				station.cs_name = data[i];
				station.workshops = stoi(data[i + 1]);
				station.active_workshops = stoi(data[i + 2]);
				station.effciency = stoi(data[i + 3]);
				flag = false;
			}
		}
		file.close();
		cout << endl << "Successfully!" << endl << endl;
	} else cout << endl << "Error! Not found file" << endl << endl;
}

int main() {
	string input;
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

		getline(cin, input);
		if (check(input) == true) {
			number = stoi(input);
			switch (number) {
			case 0:
				exit(0);
			case 1:
				input_pipe(pipe);
				break;
			case 2:
				input_cs(cs);
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
				cout << endl << "Error! Try again" << endl << endl;
			}
			cin.clear();
		} else {
			cout << endl << "Error! Try again" << endl << endl;
			cin.clear();
		}
	}
	return 0; 
}