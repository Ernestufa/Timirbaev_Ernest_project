#pragma once
#include <iostream>
#include <string>
#include <fstream>


class CS
{
	int id;
	std::string cs_name;
	int workshops;
	int active_workshops;
	int effciency;

public:

	static int MaxID;

	CS();

	CS input_cs(CS& cs);
	void show_cs(const CS& station);
	void edit_cs(CS& station, int new_workshops);

	std::string Getname() const;
	int Getworkshops() const;
	int Getactive_workshops() const;

	friend std::ofstream& operator << (std::ofstream& fout, const CS& cs);
	friend std::ifstream& operator >> (std::ifstream& fin, CS& cs);
};