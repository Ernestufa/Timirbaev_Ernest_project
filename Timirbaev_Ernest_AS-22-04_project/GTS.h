#pragma once
#include <unordered_set>
#include <unordered_map>
#include <filesystem>
#include "Connection.h"
#include "Pipe.h"
#include "CS.h"


class GTS
{
public:

	std::unordered_set<int> search_pipe(std::unordered_map<int, Pipe>& p);
	std::unordered_set<int> search_cs(std::unordered_map<int, CS>& cs);

	int SelectId(std::unordered_set<int>& group, int id);
	template<typename T>
	int SearchId(std::unordered_map<int, T>& group);

	void Show(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Edit(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Remove(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Write(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Read(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);

	Connection connections;

	std::unordered_set<int> GetFreePipes(const std::unordered_set<int>& IDs);
	void Menu(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Create_Connection(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void View_Connections() { connections.ViewConnections(); }
	void Delete_Connection(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void TopologicalSort(std::unordered_map<int, Pipe>& p);
};