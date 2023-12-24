#pragma once
#include <unordered_set>
#include <unordered_map>
#include <filesystem>
#include "Pipe.h"
#include "CS.h"


class GTS
{
public:
	std::unordered_set<int> search_pipe(std::unordered_map<int, Pipe>& p);
	std::unordered_set<int> search_cs(std::unordered_map<int, CS>& cs);

	void Show(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Edit(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Remove(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Write(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
	void Read(std::unordered_map<int, Pipe>& p, std::unordered_map<int, CS>& cs);
};