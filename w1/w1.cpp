

#include <iostream>

#include"CString.h"
#include"process.h"

extern int STORED;

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		std::cout << "Insufficient number of arguments" << std::endl;
		return 1;
	}
	std::cout << "Maximum number of characters stored : " << STORED << std::endl;
	for (int i = 1; i < argc; i++) {
		W1::process(argv[i]);
	}
	return 0;
}