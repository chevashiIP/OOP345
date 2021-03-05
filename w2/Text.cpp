
#include "Text.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace sict {
	Text::Text(const string file) {
		fstream fs(file);
		string numline;
		unsigned int Count = 0;

		if (fs.fail() == true) {
			this->NumberofRec = 0;
			delete[] text;
			return;
		}
		else {
			while (getline(fs, numline)) {
				Count++;
			}
			fs.close();
			this->NumberofRec = Count;
			this->text = new string[NumberofRec];

			fs.open(file);
			Count = 1;
			while (getline(fs, numline)) {
				this->text[Count] = numline;
				Count;
			}
		}
	}

	Text::Text(const Text &src) { // copy constructor
		*this = src;
	}

	Text::Text(Text &&src) { // move constructor
		*this = move(src);
	}

	Text& Text::operator=(const Text &src) { //copy assignment constructor
		if (this != &src) {
			this->NumberofRec = src.NumberofRec;
			delete[] this->text;

			this->text = new string[NumberofRec];
			for (int i = 0; i < NumberofRec; i++) {
				this->text[i] = src.text[i];
			}

		}
		return *this;
	}

	Text& Text::operator=(Text &&src) { // move assignment constructor
		if (this != &src) {
			this->NumberofRec = src.NumberofRec;
			delete[] this->text;
			this->text = src.text;
			src.text = nullptr;
		}
		return *this;
	}

	size_t Text::size() const{
		return this->NumberofRec;
	}
	//destructor
	Text::~Text(){
		delete[] this->text;
	}
	
}