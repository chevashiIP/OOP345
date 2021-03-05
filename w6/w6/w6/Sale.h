#ifndef _SALE_H_
#define _SALE_H_

#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include "Product.h"

namespace w7 {
	class Sale {
		std::vector<iProduct*> products;
	public:
		Sale(const char* file);
		virtual ~Sale();
		void display(std::ostream& os) const;
	};
}


#endif // !_SALE_H_
