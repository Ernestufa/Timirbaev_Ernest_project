#include <iostream>

using namespace std;

void input_pipe();
void input_cs();

int main() {
	int number = 0;

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
	switch (number) {
	case 0:
		break;
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
		cout << "Ќеправильные данные, повторите попытку!";
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
	cin >> new_pipe.pipe_name >> new_pipe.pipe_length
		>> new_pipe.pipe_diameter >> new_pipe.pipe_state;
}

void input_cs() {
	cs new_cs;
	cin >> new_cs.cs_name >> new_cs.workshops
		>> new_cs.active_workshops >> new_cs.effciency;
}