#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Message.h"

namespace sict {
	Message::Message(){
	}
	Message::Message(std::ifstream & in, char c){
		size_t index = 0;
		std::string line;
		getline(in, line, c);
		auto cr = line.find('\r');
		if (cr != std::string::npos) {
			line.erase(cr);
		}

		while (index < line.size()) {
			if (line[index] == ' ') break;
			user += line[index];
			index++;
		}
		index++;

		if (index < line.size() && line[index] == '@') {
			index++;
			while (index < line.size()) {
				if (line[index] == ' ') break;
				reply += line[index];
				index++;
			}
			index++;
		}
		while (index < line.size()) {
			tweet += line[index];
			index++;
		}
	}

	void Message::display(std::ostream & os) const{
			os << "Message" << endl;
			os << " User  : " << user << endl;
			if (reply != "") {
				os << " Reply : " << reply << endl;
			}
			os << " Tweet : " << tweet << '\r';
			os << '\n' << '\n';
	}
}
