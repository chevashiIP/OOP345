// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	Grades grades(argv[1]);

	auto letter = [](double grades_)->std::string
	{
		std::string letterGrade;

		if (grades_ >= 90) {
			letterGrade = "A+";
		} else if (grades_ >= 80) {
			letterGrade = "A";
		} else if (grades_ >= 75) {
			letterGrade = "B+";
		} else if (grades_ >= 70) {
			letterGrade = "B";
		} else if (grades_ >= 65) {
			letterGrade = "C+";
		} else if (grades_ >= 60) {
			letterGrade = "C";
		} else if (grades_ >= 55) {
			letterGrade = "D+";
		} else if (grades_ >= 50) {
			letterGrade = "D";
		} else {
			letterGrade = "F";
		}
		return letterGrade;
	};

	grades.displayGrades(cout, letter);

	cerr << argv[0] << ": Failed to open file " << argv[1] << "\n"; // Error Message
	return 2;
}