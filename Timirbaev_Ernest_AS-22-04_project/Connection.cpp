#include "Connection.h"


using namespace std;


ofstream& operator<<(ofstream& file, const Connection& connections)
{
	if (file.is_open()) {
		for (auto& edge : connections.edges) { file << edge.second; }
	}
	return file;
}

bool Connection::Empty()
{
	if (edges.size())
		return false;
	else
		return true;
}

void Connection::Insert(Edge& edge) {
	edges.insert({ edge.pipe_id, edge });
	nodes.insert({ edge.start });
	nodes.insert({ edge.terminal });
}

bool Connection::UncorrectNodes(int start, int terminal)
{
	if (start == terminal) {
		cout << "Impossible to connect the same station!" << endl;
		return true;
	}
	else
		return false;
}

void Connection::CreateConnection(int start, int terminal, int pipe_id)
{
	if (UncorrectNodes(start, terminal))
		return;
	if (edges.contains(pipe_id)) {
		cout << "The stations or the pipe are already involved!" << endl;
		return;
	}

	Edge edge = Edge(start, terminal, pipe_id);
	edges.insert({ pipe_id, edge });
	nodes.insert(start);
	nodes.insert(terminal);
	cout << "The connection created!" << endl;
}

void Connection::ViewConnections()
{
	if (edges.empty())
		cout << "There are no connections!" << endl; 
	for (auto& edge : edges) {
		cout << "Connection: pipe " << edge.second.pipe_id << " connects stations "
			<< edge.second.start << " -> " << edge.second.terminal << endl;
	}
}

void Connection::DeleteConnection_ByPipeID(int id)
{
	if (edges.contains(id)) {
		edges.erase(id);
		cout << "Connection " << id << " deleted" << endl;
		ResetNodes();
	}
}

void Connection::DeleteConnection_ByStationID(int id)
{
	vector<int> ID_edges;
	for (auto& [pipe_id, edge] : edges) {
		if (edge.start == id || edge.terminal == id) { ID_edges.push_back(pipe_id); }
	}

	for (int id : ID_edges) {
		edges.erase(id);
		cout << "Connection " << id << " deleted" << endl;
	}
	ResetNodes();
}

void Connection::ResetNodes()
{
	nodes.clear();
	for (auto& edge : edges) {
		nodes.insert(edge.second.start);
		nodes.insert(edge.second.terminal);
	}
}