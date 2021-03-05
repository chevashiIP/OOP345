#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iomanip>
#include "iProduct.h"

namespace w7 {
	class Product : public iProduct {
		int m_productnum;
		double m_price;
	public:
		Product(int productnum, double price);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
	class TaxableProduct : public Product {
		char m_taxed;
	public:
		TaxableProduct(int productnum, double price, char taxed);
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
}




#endif // !_PRODUCT_H_
