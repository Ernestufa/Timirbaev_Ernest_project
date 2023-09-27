#include <iostream>

using namespace std;

void input_pipe();
void input_cs();

int main() {
	int number = 0;

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
		} else {
			switch (number) {
			case 0:
				exit(0);
			case 1:
				input_pipe();
				break;
			case 2:
				input_cs();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				cout << "Error! Try again" << endl << endl;
			}
		}

		cin.clear();
		cin.ignore(1000, '\n');
	}
	return 0;
}

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
	float effciency;
};

void input_pipe() {
	pipeline new_pipe;
	cout << "Enter pipe name: "; cin >> new_pipe.pipe_name;
	cout << "Enter pipe length: ";  cin >> new_pipe.pipe_length;
	cout << "Enter pipe diameter: "; cin >> new_pipe.pipe_diameter;
	cout << "Enter state in repair: "; cin >> new_pipe.pipe_state; cout << endl;
}

void input_cs() {
	cs new_cs;
	cout << "Enter cs name: "; cin >> new_cs.cs_name;
	cout << "Enter number of workshops: "; cin >> new_cs.workshops;
	cout << "Enter number of active workshops: "; cin >> new_cs.active_workshops;
	cout << "Enter effciency: "; cin >> new_cs.effciency; cout << endl;
}