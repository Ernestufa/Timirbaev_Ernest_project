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
			if (number <= workshops && number > 0) {
				return number;
			} else {
				cout << "Error! The number of active workshops cannot be greater than the number of all workshops" << endl;
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

void input_pipe() {
	pipeline new_pipe;
	cout << "Enter pipe name: "; cin >> new_pipe.pipe_name;
	cout << "Enter pipe length: "; new_pipe.pipe_length = int_check();
	cout << "Enter pipe diameter: "; new_pipe.pipe_diameter = int_check();
	cout << "Enter state in repair: "; new_pipe.pipe_state = bool_check(); cout << endl;
}

void input_cs() {
	cs new_cs;
	cout << "Enter cs name: "; cin >> new_cs.cs_name;
	cout << "Enter number of workshops: "; new_cs.workshops = int_check();
	cout << "Enter number of active workshops: "; new_cs.active_workshops = workshops_check(new_cs.workshops);
	cout << "Enter effciency: "; new_cs.effciency = effciency_check(); cout << endl;
}