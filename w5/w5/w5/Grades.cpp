#include <fstream>
#include <string>

#include "Grades.h"

namespace sict {
	Grades::Grades() {
		studentnumber = nullptr;
		grade = 0;
		strlines = 0;
	}
	Grades::Grades(string FileName) {
		string line;
		ifstream f(FileName);

		if (!f.is_open()) {
			throw string("Cannot open file '" + FileName + "'\n");
		}
		if (f.is_open()){
			while (getline(f, line)) strlines++;

			grade = new double[strlines];
			studentnumber = new string[strlines];

			f.clear();
			f.seekg(0);

			for (int i = 0; i < strlines; i++)
			{
				f >> studentnumber[i];
				f.ignore(1, ' ');
				f >> grade[i];
				f.ignore(1, '\n');
			}
			f.close();
		}
	}
}
