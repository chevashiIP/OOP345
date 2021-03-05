
#include "CString.h"
#include <iostream>

int STORED = W1::MAX;

namespace W1 {
	CString::CString(char * src){
		if (src[0] == '\0') {
			str[0] == '\0';
		}
		else {
			static int i = 0;
			for (i = 0; i < STORED; i++) {
				str[i] = src[i];
			}
		}
	}
	void CString::display(std::ostream & os) const{
		os << str;
	}
	std::ostream & operator<<(std::ostream & os, const CString & src){
		static int ar = 0;
		os << ar << ": ";
		src.display(os);
		ar++;
		return os;
	}
}