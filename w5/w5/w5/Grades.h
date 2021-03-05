#ifndef _GRADES_H_
#define _GRADES_H_

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

namespace sict {
	class Grades {
		string* studentnumber;
		int strlines;
		double* grade;
	public:
		Grades();
		Grades(string FileName);
		template<typename T>
		void displayGrades(ostream& os, T F) const {
			for (int i = 0; i < strlines; i++){
				cout << studentnumber[i] << " ";
				cout << grade[i] << " ";
				cout << F(grade[i]) << "\n";
			}
		};
	};
}


#endif // !_GRADES_H_
