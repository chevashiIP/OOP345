

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace sict {
	class Text {
		string *text;
		size_t NumberofRec;
	public:
		Text(const string file = ""); //string constructor of file
		Text(const Text & src); //copy constructor
		Text(Text&& src); //move constructor
		Text& operator = (const Text & src); // copy assignment constructor
		Text& operator = (Text&& src); //move assignment constructor
		size_t size() const; // returns the number of records
		~Text(); //Destructor
	};

}




#endif // !TEXT_H

