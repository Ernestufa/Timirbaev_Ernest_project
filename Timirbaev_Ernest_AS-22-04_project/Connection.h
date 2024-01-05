#pragma once
#include "Utils.h"
#include "Graph.h"
#include <fstream>


class Connection
{

    void ResetNodes();

public:

    std::unordered_map<int, Edge> edges;
    std::set<int> nodes;

    bool Empty();
    void Clear() { edges.clear(); }
    void Insert(Edge& edge);
    bool UncorrectNodes(int start, int terminal);
    void CreateConnection(int start, int terminal, int pipe_id);
    void ViewConnections();
    void DeleteConnection_ByPipeID(int id);
    void DeleteConnection_ByStationID(int id);

    friend std::ofstream& operator << (std::ofstream& file, const Connection& connections);
};