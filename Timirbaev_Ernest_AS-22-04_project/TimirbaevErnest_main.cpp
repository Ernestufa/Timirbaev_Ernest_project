//#include <vector>
//#include <format>
//#include <chrono>
#include "Pipe.h"
#include "Utils.h"
#include "CS.h"
#include "GTS.h"
//#include <filesystem>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
using namespace chrono;


//template <typename T>
//int Select(unordered_map <T>& g) {
//	cout << endl << "Input index: "; int index = GetCorrectNumber(1, int(g.size()));
//	if (index <= g.size()) {
//		return index - 1;
//	}
//	else {
//		cout << endl << "Error! Try again" << endl << endl;
//		Select(g);
//	}
//}


//template <typename T1, typename T2>
//using Filter = bool(*)(const T1& obgect, T2& param);
//
//
//template <typename T>
//bool CheckbyName(const T& object, string& param) {
//	return (object.Getname().find(param) != string::npos);
//}
//
//bool CheckRepair(const Pipe& object, bool& param) {
//	return (object.Getstate() == param);
//}
//
//bool CheckProcent(const CS& object, int& param)
//{
//	float procent = float((object.Getworkshops() - object.Getactive_workshops())) / float(object.Getworkshops()) * 100;
//	return (procent >= param);
//}
//
//template <typename T1, typename T2>
//unordered_set<int> FindbyFilter(const unordered_map<int, T1>& group, Filter<T1, T2> f, T2& param) {
//	unordered_set<int> result;
//	for (auto& s : group) {
//		if (f(s.second, param)) {
//			result.insert(s.first);
//		}
//	}
//
//	return result;
//}
//
//
//unordered_set<int> search_pipe(unordered_map<int, Pipe>& p) {
//
//	unordered_set<int> find;
//
//	while (true) {
//
//		cout << endl << "Choose" << endl
//			//<< "1 Index search" << endl
//			<< "2 Search by name" << endl
//			<< "3 Search by 'In repair'" << endl
//			<< "0 Exit" << endl
//			<< "Enter the command number: ";
//
//		switch (GetCorrectNumber(0, 3)) {
//		case 0:
//			cout << endl;
//			return find;
//		//case 1: {
//		//	if (p.size() != 0)
//		//		find.push_back(Select(p));
//		//	return find;
//		//}
//		case 2: {
//			string name = "Unknown";
//			cout << endl << "Input name: ";
//			getline(cin, name);
//			LOG(name);
//			unordered_set<int> find = FindbyFilter(p, CheckbyName, name);
//			return find;
//		}
//		case 3: {
//			bool state = 0;
//			cout << endl << "Input state: ";
//			state = GetCorrectNumber(0, 1);
//			unordered_set<int> find = FindbyFilter(p, CheckRepair, state);
//			return find;
//		}
//		default:
//			cout << endl << "Error! Try again" << endl << endl;
//		}
//	}
//}
//
//unordered_set<int> search_cs(unordered_map<int, CS>& cs) {
//
//	unordered_set<int> find;
//
//	while (true) {
//
//		cout << endl << "Choose" << endl
//			//<< "1 Index search" << endl
//			<< "2 Search by name" << endl
//			<< "3 Search by %" << endl
//			<< "0 Exit" << endl
//			<< "Enter the command number: ";
//
//		switch (GetCorrectNumber(0, 3)) {
//		case 0:
//			cout << endl;
//			return find;
//		/*case 1: {
//			if (cs.size() != 0)
//				find.push_back(Select(cs));
//			return find;
//		}*/
//		case 2: {
//			string name = "Unknown";
//			cout << endl << "Input name: ";
//			getline(cin, name);
//			LOG(name);
//			unordered_set<int> find = FindbyFilter(cs, CheckbyName, name);
//			return find;
//		}
//		case 3: {
//			int procent = 50;
//			cout << endl << "Input procent (%>): ";
//			procent = GetCorrectNumber(0, 100);
//			unordered_set<int> find = FindbyFilter(cs, CheckProcent, procent);
//			return find;
//		}
//		default:
//			cout << endl << "Error! Try again" << endl << endl;
//		}
//	}
//}
//
//
//void Show(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs) {
//
//	unordered_set<int> find;
//
//	while (true) {
//
//		CHOOSE();
//
//		switch (GetCorrectNumber(0, 2)) {
//		case 0:
//			ENDL();
//			return;
//		case 1: {
//			find = search_pipe(p);
//			if (find.size() != 0) {
//				for (int i : find) {
//					p[i].show_pipe(p[i]);
//				};
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		case 2: {
//			find = search_cs(cs);
//			if (find.size() != 0) {
//				for (int i : find) {
//					cs[i].show_cs(cs[i]);
//				};
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		default:
//			cout << endl << "Error! Try again" << endl << endl;
//		}
//	}
//}
//
//
//void Edit(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs) {
//
//	unordered_set<int> find;
//
//	while (true) {
//
//		CHOOSE();
//
//		switch (GetCorrectNumber(0, 2)) {
//		case 0:
//			ENDL();
//			return;
//		case 1: {
//			find = search_pipe(p);
//			if (find.size() != 0) {
//				cout << endl << "Enter new state: ";
//				int new_state = GetCorrectNumber(0, 1);
//				for (int i : find) {
//					p[i].edit_pipe(p[i], new_state);
//				};
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		case 2: {
//			find = search_cs(cs);
//			if (find.size() != 0) {
//				cout << endl << "Enter active workshops: ";
//				int new_workshops = GetCorrectNumber(0, 10000000);
//				for (int i : find) {
//					cs[i].edit_cs(cs[i], new_workshops);
//				};
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		default:
//			cout << endl << "Error! Try again" << endl << endl;
//
//		}
//	}
//}
//
//
//void Remove(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs) {
//
//	unordered_set<int> find;
//
//	while (true) {
//
//		CHOOSE();
//
//		switch (GetCorrectNumber(0, 2)) {
//		case 0:
//			ENDL();
//			return;
//		case 1: {
//			find = search_pipe(p);
//			if (find.size() != 0) {
//				//int count = 0;
//				for (int i : find) {
//					p.erase(i);
//					/*if (p.size() == 1)
//						p.erase(p.begin());
//					else
//						p.erase(p.begin() + i - count);
//					count++;*/
//				}
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		case 2: {
//			find = search_cs(cs);
//			if (find.size() != 0) {
//				//int count = 0;
//				for (int i : find) {
//					cs.erase(i);
//					/*if (cs.size() == 1)
//						cs.erase(cs.begin());
//					else
//						cs.erase(cs.begin() + i - count);
//					count++;*/
//				}
//			}
//			else cout << endl << "Not Found!" << endl;
//			ENDL();
//			return;
//		}
//		}
//	}
//}
//
//
//void Write(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs) {
//	if (p.size() != 0 or cs.size() != 0) {
//
//		cout << endl << "Write name of the file to save: ";
//		string name = "notfound.txt";
//		getline(cin, name);
//		LOG(name);
//
//		ofstream file;
//		file.open(name, ios::out);
//		file << p.size() << " " << cs.size() << endl;
//		for (auto& pipe : p) { file << pipe.second; }
//		for (auto& station : cs) { file << station.second; };
//		file.close();
//
//		cout << endl << "Successful save!" << endl;
//	}
//	else cout << endl << "No objects to save!" << endl;
//	ENDL();
//}
//
//
//void Read(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs) {
//	ifstream file;
//	string path = "C:/Users/timir/Documents/GitHub/Timirbaev_Ernest_project/Timirbaev_Ernest_AS-22-04_project/";
//	vector<filesystem::directory_entry> names;
//	int count = 0;
//	for (auto& name : filesystem::directory_iterator(path)) {
//		count++;
//		names.push_back(name);
//		cout << endl << count << ". " << name << endl;
//	}
//	cout << endl << "Choose the file: ";
//	int download = GetCorrectNumber(1, count);
//
//	p.clear();
//	cs.clear();
//	Pipe pipe;
//	CS station;
//	int count_pipes, count_cs;
//
//	file.open(names[download - 1]);
//	file >> count_pipes >> count_cs;
//
//	while (count_pipes--)
//	{
//		file >> pipe;
//		p.insert({ pipe.GetID(), pipe });
//	}
//	while (count_cs--)
//	{
//		file >> station;
//		cs.insert({ station.GetID(), station });
//	}
//	cout << endl << "Successful download!" << endl;
//	file.close();
//	ENDL();
//}


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
		case 3: {
			gts.Show(pipe_group, cs_group);
			break;
		}
		case 4: {
			gts.Edit(pipe_group, cs_group);
			break;
		}
		case 5:
			gts.Remove(pipe_group, cs_group);
			break;
		case 6:
			gts.Write(pipe_group, cs_group);
			break;
		case 7: {
			gts.Read(pipe_group, cs_group);
			break;
		}
		default:
			cout << endl << "Error! Try again";
			ENDL();
		}
	}
	return 0; 
}