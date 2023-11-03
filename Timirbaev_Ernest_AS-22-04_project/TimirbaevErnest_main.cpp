#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>

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
	if (number.length() == 0 || number == "-") return false;
	return true;
}

template <typename N>
N GetCorrectNumber(N min, N max) {
	string input;
	while (getline(cin, input).fail() || check(input) == false || stoi(input) < min || stoi(input) > max) {
		cout << endl << "Error! Try again: ";
	}
	return stoi(input);
}

//template <typename T>
//istream& operator >> (istream& in, T& s) {
//	in >> s;
//	return in;
//}

int workshops_check(int workshops) {
	while (true) {
		int number = GetCorrectNumber(0, 10000000);
		if (number <= workshops) {
			return number;
		}
		else if (number >= workshops) {
			cout << endl << "Error! The number of active workshops cannot be greater than the number of all workshops" << endl
				<< "Try again: ";
		}
	}
}

void input_pipe(pipeline& new_pipe) {
	cout << endl << "Enter pipe name: "; getline(cin, new_pipe.pipe_name);
	cout << "Enter pipe length: "; new_pipe.pipe_length = GetCorrectNumber(1, 10000000);
	cout << "Enter pipe diameter: "; new_pipe.pipe_diameter = GetCorrectNumber(1, 10000000); cout << endl;
	new_pipe.pipe_state = 0;
}

void input_cs(cs& new_cs) {
	cout << endl << "Enter cs name: "; getline(cin, new_cs.cs_name);
	cout << "Enter number of workshops: "; new_cs.workshops = GetCorrectNumber(1, 10000000);
	cout << "Enter number of active workshops: "; new_cs.active_workshops = workshops_check(new_cs.workshops);
	cout << "Enter effciency(0-100): "; new_cs.effciency = GetCorrectNumber(1, 100); cout << endl;
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
		cout << endl << "Enter new state: ";
		pipe.pipe_state = GetCorrectNumber(0, 1);
		cout << endl;
	}
}

void edit_cs(cs& station) {
	if (station.cs_name.empty()) cout << endl << "No added cs!" << endl << endl;
	else {
		cout << endl << "Enter active workshops: ";
		station.active_workshops = workshops_check(station.workshops);
		cout << endl;
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

pipeline& SelectPipe(vector <pipeline>& g) {
	cout << endl << "Chosse pipe`s index: "; int index = GetCorrectNumber(0, int(g.size() - 1));
	return g[index];
}

cs& SelectCS(vector <cs>& g) {
	cout << endl << "Choose cs`s index: "; int index = GetCorrectNumber(0, int(g.size() - 1));
	return g[index];
}


int main() {
	vector <cs> cs_group;
	vector <pipeline> pipe_group;

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

		switch (GetCorrectNumber(0, 7)) {
		case 0:
			exit(0);
		case 1: {
			pipeline pipe;
			input_pipe(pipe);
			break;
		}
		case 2: {
			cs cs;
			input_cs(cs);
			break;
		}
		case 3:
			show(SelectPipe(pipe_group), SelectCS(cs_group));
			break;
		case 4:
			edit_pipe(SelectPipe(pipe_group));
			break;
		case 5:
			edit_cs(SelectCS(cs_group));
			break;
		case 6:
			write_file(SelectPipe(pipe_group), SelectCS(cs_group));
			break;
		case 7:
			read_file(SelectPipe(pipe_group), SelectCS(cs_group));
			break;
		default:
			cout << endl << "Error! Try again" << endl << endl;
		}
	}
	return 0; 
}