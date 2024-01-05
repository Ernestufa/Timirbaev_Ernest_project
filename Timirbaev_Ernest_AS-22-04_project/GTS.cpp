#include "GTS.h"


using namespace std;


template <typename T1, typename T2>
using Filter = bool(*)(const T1& obgect, T2& param);


template <typename T>
bool CheckbyName(const T& object, string& param) {
	return (object.Getname().find(param) != string::npos);
}

bool CheckRepair(const Pipe& object, bool& param) {
	return (object.Getstate() == param);
}

bool CheckProcent(const CS& object, int& param)
{
	float procent = float((object.Getworkshops() - object.Getactive_workshops())) / float(object.Getworkshops()) * 100;
	return (procent >= param);
}

bool CheckByDiameter(const Pipe& object, int& param)
{
	return object.GetDiameter() == param;
}

template <typename T1, typename T2>
unordered_set<int> FindbyFilter(const unordered_map<int, T1>& group, Filter<T1, T2> f, T2& param) {
	unordered_set<int> result;
	for (auto& s : group) {
		if (f(s.second, param)) {
			result.insert(s.first);
		}
	}

	return result;
}


unordered_set<int> GTS::search_pipe(unordered_map<int, Pipe>& p)
{   
	unordered_set<int> find;

	while (true) {

		cout << endl << "Choose" << endl
			<< "1 Search by name" << endl
			<< "2 Search by 'In repair'" << endl
			<< "0 Exit" << endl
			<< "Enter the command number: ";

		switch (GetCorrectNumber(0, 2)) {

		case 0:
			ENDL();
			return find;

		case 1: {
			string name = "Unknown";
			cout << endl << "Input name: ";
			getline(cin, name);
			LOG(name);
			unordered_set<int> find = FindbyFilter(p, CheckbyName, name);
			return find;
		}

		case 2: {
			bool state = 0;
			cout << endl << "Input state: ";
			state = GetCorrectNumber(0, 1);
			unordered_set<int> find = FindbyFilter(p, CheckRepair, state);
			return find;
		}

		default:
			cout << endl << "Error! Try again" << endl << endl;
		}
	}
    return unordered_set<int>();
}

unordered_set<int> GTS::search_cs(unordered_map<int, CS>& cs)
{
	unordered_set<int> find;

	while (true) {

		cout << endl << "Choose" << endl
			<< "1 Search by name" << endl
			<< "2 Search by %" << endl
			<< "0 Exit" << endl
			<< "Enter the command number: ";

		switch (GetCorrectNumber(0, 2)) {

		case 0:
			ENDL();
			return find;

		case 1: {
			string name = "Unknown";
			cout << endl << "Input name: ";
			getline(cin, name);
			LOG(name);
			unordered_set<int> find = FindbyFilter(cs, CheckbyName, name);
			return find;
		}

		case 2: {
			int procent = 50;
			cout << endl << "Input procent (%>): ";
			procent = GetCorrectNumber(0, 100);
			unordered_set<int> find = FindbyFilter(cs, CheckProcent, procent);
			return find;
		}

		default:
			cout << endl << "Error! Try again" << endl << endl;
		}
	}
	return unordered_set<int>();
}

template <typename T>
int GTS::SearchId(unordered_map<int, T>& group) {
	while (true) {
		int id;
		id = GetCorrectNumber(0, 1000000);
		if (auto i = group.find(id); i != group.end()) { return id; }
		else { cout << "ID not found! Please try again: "; }
	}
}

int GTS::SelectId(std::unordered_set<int>& group, int id)
{
	if (auto i = group.find(id); i != group.end()) { return id; }
	else { cout << "ID not found! Please try again: "; }
}


void GTS::Show(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	unordered_set<int> find;

	while (true) {

		CHOOSE();

		switch (GetCorrectNumber(0, 2)) {
		case 0:
			ENDL();
			return;
		case 1: {
			find = search_pipe(p);
			if (find.size() != 0) {
				for (int i : find) {
					p[i].show_pipe(p[i]);
				};
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		case 2: {
			find = search_cs(cs);
			if (find.size() != 0) {
				for (int i : find) {
					cs[i].show_cs(cs[i]);
				};
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		default:
			cout << endl << "Error! Try again" << endl << endl;
		}
	}
}

void GTS::Edit(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	unordered_set<int> find;

	while (true) {

		CHOOSE();

		switch (GetCorrectNumber(0, 2)) {
		case 0:
			ENDL();
			return;
		case 1: {
			find = search_pipe(p);
			if (find.size() != 0) {
				cout << endl << "Enter new state: ";
				int new_state = GetCorrectNumber(0, 1);
				for (int i : find) {
					p[i].edit_pipe(p[i], new_state);
				};
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		case 2: {
			find = search_cs(cs);
			if (find.size() != 0) {
				cout << endl << "Enter active workshops: ";
				int new_workshops = GetCorrectNumber(0, 10000000);
				for (int i : find) {
					cs[i].edit_cs(cs[i], new_workshops);
				};
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		default:
			cout << endl << "Error! Try again" << endl << endl;

		}
	}
}

void GTS::Remove(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	unordered_set<int> find;

	while (true) {

		CHOOSE();

		switch (GetCorrectNumber(0, 2)) {
		case 0:
			ENDL();
			return;
		case 1: {
			find = search_pipe(p);
			if (find.size() != 0) {
				for (int i : find) {
					p.erase(i);
				}
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		case 2: {
			find = search_cs(cs);
			if (find.size() != 0) {
				for (int i : find) {
					cs.erase(i);
				}
			}
			else cout << endl << "Not Found!" << endl;
			ENDL();
			return;
		}
		}
	}
}

void GTS::Write(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	if (p.size() != 0 or cs.size() != 0) {

		cout << endl << "Write name of the file to save: ";
		string name = "notfound.txt";
		getline(cin, name);
		LOG(name);

		ofstream file;
		file.open(name, ios::out);
		file << p.size() << " " << cs.size() << endl;
		for (auto& pipe : p) { file << pipe.second; }
		for (auto& station : cs) { file << station.second; };
		file.close();

		cout << endl << "Successful save!" << endl;
	}
	else cout << endl << "No objects to save!" << endl;
	ENDL();
}

void GTS::Read(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	ifstream file;
	string path = "C:/Users/timir/Documents/GitHub/Timirbaev_Ernest_project/Timirbaev_Ernest_AS-22-04_project/";
	vector<filesystem::directory_entry> names;
	int count = 0;
	for (auto& name : filesystem::directory_iterator(path)) {
		count++;
		names.push_back(name);
		cout << endl << count << ". " << name << endl;
	}
	cout << endl << "Choose the file: ";
	int download = GetCorrectNumber(1, count);

	p.clear();
	cs.clear();
	Pipe pipe;
	CS station;
	int count_pipes, count_cs;

	file.open(names[download - 1]);
	file >> count_pipes >> count_cs;

	while (count_pipes--)
	{
		file >> pipe;
		p.insert({ pipe.GetID(), pipe });
	}
	while (count_cs--)
	{
		file >> station;
		cs.insert({ station.GetID(), station });
	}
	cout << endl << "Successful download!" << endl;
	file.close();
	ENDL();
}


unordered_set<int> GTS::GetFreePipes(const unordered_set<int>& IDs)
{
	unordered_set<int> free_IDs;
	for (auto& id : IDs) {
		if (!connections.edges.contains(id)) {
			free_IDs.insert(id);
		}
	}
	return free_IDs;
}

void GTS::Menu(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	cout << endl << "1 Add connection" << endl
		<< "2 View connection" << endl
		<< "3 Remove connection" << endl
		<< "4 Topological sort" << endl
		<< "5 Shortest path" << endl
		<< "6 Algorithm Ford-Falkerson" << endl
		<< "0 Exit" << endl << endl
		<< "Enter the command number: ";

	switch (GetCorrectNumber(0, 6)) {
	case 0:
		ENDL();
		return;
	case 1:
		Create_Connection(p, cs);
		break;
	case 2:
		View_Connections();
		break;
	case 3:
		Delete_Connection(p, cs);
		break;
	case 4:
		TopologicalSort(p);
		break;
	case 5:
		ShortestPath(p, cs);
		break;
	case 6:
		MaxFlow(p, cs);
		break;
	default:
		cout << endl << "Error! Try again" << endl << endl;
	}
	ENDL();
}

void GTS::Create_Connection(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	if (cs.size() < 2) { cout << endl << "There are not enough stations to create a connection!" << endl; return; }
	for (auto& station : cs) station.second.show_cs(station.second);
	int start_station, terminal_station, pipe_id;
	cout << "Enter the ID of the starting station: ";
	start_station = SearchId(cs);
	cout << "Enter the ID of the terminal station: ";
	terminal_station = SearchId(cs);

	if (connections.UncorrectNodes(start_station, terminal_station)) { return; }
	cout << "Diameters of the pipes:" << endl << "1. 500" << endl << "2. 700" << endl << "3. 1000" << endl << "4. 1400" << endl
		<< "Enter the diameter of the pipe (millimeters): ";
	int diameter = GetCorrectNumber(0, 1400);
	unordered_set<int> select_pipes = FindbyFilter(p, CheckByDiameter, diameter);
	for (int i : select_pipes)
		p[i].show_pipe(p[i]);
	if (select_pipes.size()) {
		cout << "Enter the ID of the pipe: ";
		pipe_id = SelectId(select_pipes, SearchId(p));
		select_pipes = GetFreePipes({ pipe_id });
	}

	if (!select_pipes.size()) {
		cout << "The pipes have not been found or they are already in connection.\nDo you want to create such a pipe?\nNo(0), Yes(1): ";
		if (!GetCorrectNumber(0, 1)) { return; }
		else {
			Pipe pipe;
			pipe.add_pipe_with_diameter(pipe, diameter);
			pipe_id = pipe.GetID();
			p.insert({ pipe_id, pipe });
			connections.CreateConnection(start_station, terminal_station, pipe_id);
			return;
		}
	}
	else {
		connections.CreateConnection(start_station, terminal_station, pipe_id);
		return;
	}
}

void GTS::Delete_Connection(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	if (connections.Empty()) {
		cout << endl << "No connections available!" << endl;
		return;
	}

	connections.ViewConnections();
	cout << endl << "Delete connection by pipe ID (0) or by station ID (1): ";
	switch (GetCorrectNumber(0, 1))
	{
	case 0:
	{
		cout << "Enter the pipe ID to remove the connection: ";
		int id;
		do {
			id = SearchId(p);
			if (!connections.edges.contains(id)) { cout << "There is no such ID among the pipes found! Enter it again." << endl; }
		} while (!connections.edges.contains(id));
		connections.DeleteConnection_ByPipeID(id);
		break;
	}
	case 1:
	{
		cout << "Enter the station ID to remove the connection: ";
		int id;
		do {
			id = SearchId(cs);
			if (!connections.nodes.contains(id)) { cout << "There is no such ID among the stations found! Enter it again." << endl; }
		} while (!connections.nodes.contains(id));
		connections.DeleteConnection_ByStationID(id);
		break;
	}
	default: { return; }
	}
}

void GTS::TopologicalSort(unordered_map<int, Pipe>& p)
{
	if (connections.Empty()) { cout << endl << "No connections available!"; return; }
	Graph graph = Graph(connections.edges, connections.nodes, p);
	vector<int> result = graph.TopologicalSort();
	if (!result.size()) { cout << "Topological sort: - " << endl; return; }
	cout << "Topological sorting: ";
	for (auto& i : result) {
		cout << i << " ";
	}
	cout << endl;
}

void GTS::ShortestPath(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	if (connections.Empty()) { cout << endl << "No connections available!"; return; }
	Graph graph = Graph(connections.edges, connections.nodes, p);

	connections.ViewConnections();
	cout << "Enter the starting vertex of the path: ";
	int StartNode = SearchId(cs);

	cout << "Enter the final vertex of the path: ";
	int EndNode = SearchId(cs);

	vector<int> result = graph.Metod_Deikstra(StartNode, EndNode);
	if (!result.size()) { cout << "Path: - "; return; }
	cout << "Path: ";
	for (auto& i : result) {
		cout << i << " -> ";
	}
	cout << "End" << endl;
	cout << "Path length: " << graph.Lenght_ShortestPath(result) << endl;
}

void GTS::MaxFlow(unordered_map<int, Pipe>& p, unordered_map<int, CS>& cs)
{
	if (connections.Empty()) { cout << endl << "No connections available!"; return; }
	Graph graph = Graph(connections.edges, connections.nodes, p);

	connections.ViewConnections();
	cout << "Enter the starting vertex of the path: ";
	int StartNode = SearchId(cs);

	cout << "Enter the final vertex of the path: ";
	int EndNode = SearchId(cs);

	double result = graph.Ford_Fulkerson(StartNode, EndNode);
	cout << "Maximum flow: " << result << endl;
}