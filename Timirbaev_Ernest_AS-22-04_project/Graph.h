#pragma once
#include "Utils.h"
#include "Pipe.h"
#include <unordered_map>
#include <set>
#include <map>


class Graph;
class GTS;
class Connection;

class Edge
{
	friend Graph;
	friend GTS;
	friend Connection;
	friend std::ofstream& operator << (std::ofstream& file, const Edge& edge);
	friend std::ifstream& operator >> (std::ifstream& file, Edge& edge);

public:
	Edge() {};

private:
	int start, terminal, pipe_id;
	Edge(int start, int terminal, int pipe_id) : start(start), terminal(terminal), pipe_id(pipe_id) {};
};


class Graph
{
	friend GTS;
	bool DFS_Cycle(int, std::vector<bool>&, std::vector<bool>&);
	void DFS_Sort(int v, std::vector<bool>& visited, std::vector<int>& nodes);
	bool HasCycle();
	int GetIndex(int node) const;
	bool Conteins(int Node) const;
	std::map<int, int> nodes;
	std::unordered_map<int, Edge> edges;
	std::vector<std::vector<double>> capacity;
	std::vector<std::vector<int>> adj_weight;
	int SizeGraph;

public:

	Graph(const std::unordered_map<int, Edge>& edges, const std::set<int>& nodes, const std::unordered_map<int, Pipe>& p);
	std::vector<int> TopologicalSort();
	/*std::vector<int> Metod_Deikstra(int StartNode, int EndNode) const;
	double Ford_Fulkerson(int StartNode, int  EndNode) const;
	double Lenght_ShortestPath(std::vector<int>&);
	bool BFS_MaxFlow(std::vector<std::vector<double>>& capacity, int StartNode, int EndNode, std::vector<int>& parent) const;*/
};