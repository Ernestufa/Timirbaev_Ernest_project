#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"


class Pipe
{
	int id;
	std::string pipe_name;
	int pipe_length;
	double pipe_diameter;
	bool pipe_state;

public:

	static int MaxID;

	Pipe();

	Pipe input_pipe(Pipe& pipe);
	void show_pipe(const Pipe& pipe);
	void edit_pipe(Pipe& pipe, int new_state);

	int GetID() const;
	std::string Getname() const;
	bool Getstate() const;

	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
};