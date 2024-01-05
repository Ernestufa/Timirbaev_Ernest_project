#include "Pipe.h"
#include "Utils.h"
#include "CS.h"
#include "GTS.h"
#include "Connection.h"


using namespace std;
using namespace chrono;


int main() {
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	unordered_map<int, CS> cs_group;
	unordered_map<int, Pipe> pipe_group;

	GTS gts;

	while (true) {

		cout << "1 Add pipe" << endl 
			<< "2 Add CS" << endl
			<< "3 View objects" << endl
			<< "4 Edit objects" << endl
			<< "5 Remove"  << endl
			<< "6 Save" << endl
			<< "7 Download" << endl
			<< "8 Work with graph" << endl
			<< "0 Exit" << endl << endl
			<< "Enter the command number: ";

		switch (GetCorrectNumber(0, 8)) {
		case 0:
			exit(0);
		case 1: {
			Pipe pipe;
			pipe = pipe.input_pipe(pipe);
			pipe_group.insert({ pipe.GetID(), pipe});
			break;
		}
		case 2: {
			CS cs;
			cs = cs.input_cs(cs);
			cs_group.insert({ cs.GetID(), cs});
			break;
		}
		case 3:
			gts.Show(pipe_group, cs_group);
			break;
		case 4:
			gts.Edit(pipe_group, cs_group);
			break;
		case 5:
			gts.Remove(pipe_group, cs_group);
			break;
		case 6:
			gts.Write(pipe_group, cs_group);
			break;
		case 7:
			gts.Read(pipe_group, cs_group);
			break;
		case 8: {
			gts.Menu(pipe_group, cs_group);
			break;
		}
		default:
			cout << endl << "Error! Try again";
			ENDL();
		}
	}
	return 0; 
}