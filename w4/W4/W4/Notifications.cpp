#include <iostream>
#include <fstream>
#include <string>

#include "Notifications.h"

namespace sict {
	Notifications::Notifications(std::ifstream & in){
		std::string line;
		while (getline(in, line)) {
			mescount++;
		}
		in.clear();
		in.seekg(0, ios::beg);

		if (this->tweets == nullptr) {
			this->tweets = new Message[mescount];
		}

		for (int i = 0; i<mescount; i++) {
			this->tweets[i] = Message(in, 10);
		}

	}
	Notifications::Notifications(Notifications && rhs) {
		this->tweets = nullptr;
		*this = std::move(rhs);
	}
	Notifications & Notifications::operator=(Notifications && rhs){
		if (this != &rhs) {
			delete[] tweets;
			this->tweets = rhs.tweets;
			this->mescount = rhs.mescount;

			rhs.tweets = nullptr;
			rhs.mescount = 0;
		}
		return (*this);
	}
	Notifications::~Notifications(){
		delete[] tweets;
	}
	void Notifications::display(std::ostream & os) const{
		for (int i = 0; i < mescount; i++) {
			tweets[i].display(os);
		}
	}
}