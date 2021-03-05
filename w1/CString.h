
#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>

namespace W1 {
	const int MAX = 3;
	class CString {
		char str[MAX + 1];
	public:
		CString(char* src);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const CString& src);
}



#endif // !CSTRING_H
