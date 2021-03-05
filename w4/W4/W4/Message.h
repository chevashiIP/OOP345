#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace sict {
	class Message {
		string user;
		string reply;
		string tweet;
	public:
		Message();
		Message(ifstream& in, char c);
		void display(ostream&) const;
	};
}


#endif // !_MESSAGE_H_

