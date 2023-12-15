#pragma once
#include <iostream>
#include <string>

#define LOG(log) std::cerr << log << std::endl;


class redirect_output_wrapper
{
	std::ostream& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ostream& src)
		:old_buf(src.rdbuf()), stream(src)
	{
	}

	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}
	void redirect(std::ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};


inline bool check(std::string number) {
	for (int i = 0; i < number.length(); i++) {
		if (isdigit(number[i]) || number[i] == '-') continue;
		else return false;
	}
	if (number.length() == 0 || number == "-") return false;
	return true;
}


template <typename N>
N GetCorrectNumber(N min, N max) {
	std::string input;
	while (std::getline(std::cin, input).fail() || check(input) == false || stoi(input) < min || stoi(input) > max) {
		LOG(input);
		std::cout << std::endl << "Error! Try again: ";
	}
	LOG(input);
	return stoi(input);
}


inline int workshops_check(int workshops) {
	while (true) {
		int number = GetCorrectNumber(0, 10000000);
		if (number <= workshops) {
			return number;
		}
		else if (number >= workshops) {
			std::cout << std::endl << "Error! The number of active workshops cannot be greater than the number of all workshops" << std::endl
				<< "Try again: ";
		}
	}
}