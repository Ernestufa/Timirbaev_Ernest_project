#include "Graph.h"
#include <queue>


using namespace std;


ofstream& operator<<(ofstream& file, const Edge& edge)
{
	if (file.is_open()) {
		file << edge.pipe_id << " ";
		file << edge.start << " ";
		file << edge.terminal << endl;
	}
	return file;
}

ifstream& operator>>(ifstream& file, Edge& edge)
{
	if (file.is_open()) {
		file >> edge.pipe_id;
		file >> edge.start;
		file >> edge.terminal;
	}
	return file;
}

Graph::Graph(const unordered_map<int, Edge>& edges, const set<int>& nodes, const unordered_map<int, Pipe>& p) : edges(edges)
{
	int count = 0;
	for (int node : nodes) {
		this->nodes.insert({ count, node });
		count++;

	}
	SizeGraph = nodes.size();
	capacity.resize(SizeGraph, vector<double>(SizeGraph, 0.0));
	adj_weight.resize(SizeGraph, vector<int>(SizeGraph, 0.0));
	for (auto& [pipe_id, edge] : edges) {
		auto i = GetIndex(edge.start);
		auto j = GetIndex(edge.terminal);
		capacity[i][j] = p.at(pipe_id).GetCapacity();
		adj_weight[i][j] = p.at(pipe_id).GetLength();
	}
}

std::vector<int> Graph::TopologicalSort()
{
	if (edges.empty()) {
		cout << endl << "The graph has no edges. Topological sort is not possible" << endl;
		return vector<int>();
	}
	else if (HasCycle()) {
		cout << endl << "There is a cycle in the graph. Topological sort is not possible" << endl;
		return vector<int>();
	}

	vector<bool> visited(SizeGraph, false);
	vector<int> result;

	for (int i = 0; i < SizeGraph; ++i) {
		if (!visited[i]) {
			DFS_Sort(i, visited, result);
		}
	}
	reverse(result.begin(), result.end());

	return result;
}

bool Graph::DFS_Cycle(int node, vector<bool>& visited, vector<bool>& recStack) {
	if (!visited[node]) {
		visited[node] = true;
		recStack[node] = true;

		for (int i = 0; i < SizeGraph; ++i) {
			if (adj_weight[node][i]) {
				if (!visited[i] && DFS_Cycle(i, visited, recStack)) { return true; }
				else if (recStack[i]) { return true; }
			}
		}
	}
	recStack[node] = false;
	return false;
}

void Graph::DFS_Sort(int v, vector<bool>& visited, vector<int>& nodes)
{
	visited[v] = true;

	for (int i = 0; i < SizeGraph; ++i) {
		if (adj_weight[v][i] && !visited[i]) {
			DFS_Sort(i, visited, nodes);
		}
	}

	nodes.push_back(this->nodes.at(v));
}

bool Graph::HasCycle() {
	vector<bool> visited(SizeGraph, false);
	vector<bool> recStack(SizeGraph, false);

	for (int i = 0; i < SizeGraph; ++i) {
		if (DFS_Cycle(i, visited, recStack)) { return true; }
	}

	return false;
}

int Graph::GetIndex(int vertice) const
{
	for (auto& [index, node] : nodes) {
		if (node == vertice) { return index; }
	}
	return INT16_MAX;
}

bool Graph::Conteins(int Node) const
{
	for (auto& [index, node] : nodes) {
		if (node == Node) { return true; }
	}
	return false;
}