

#include "process.h"
#include "CString.h"

namespace W1 {
	void process(char * src)
	{
		CString cstring(src);
		std::cout << src << std::endl;
	}
}
