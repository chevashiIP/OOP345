#include "Product.h"

using namespace std;

namespace w7 {
	iProduct* readProduct(ifstream& in) {
		int pn;
		double cost;
		char ts;

		in >> pn;
		if (in.fail())
			return (iProduct*)0;
		in >> cost;
		if (in.fail())
			return (iProduct*)0;

		ts = in.get();
		if (ts != '\n') {
			in >> ts;
			return new TaxableProduct(pn, cost, ts);
		}
		else {
			return new Product(pn, cost);
		}
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& P) {
		P.display(os);
		return os;
	}

	Product::Product(int productnum, double price){
		m_productnum = productnum;
		m_price = price;
	}

	double Product::getCharge() const{
		return m_price;
	}

	void Product::display(std::ostream & os) const{
		os << setw(10) << m_productnum << fixed << setprecision(2);
		os << setprecision(2) << setw(10) << m_price;
	}

	TaxableProduct::TaxableProduct(int productnum, double price, char taxed):Product(productnum, price) {
		m_taxed = taxed;
	}

	double TaxableProduct::getCharge() const{
		double charge = Product::getCharge();
		if (m_taxed == 'H') {
			charge *= 1.13;
		}
		if (m_taxed == 'P') {
			charge *= 1.08;
		}
		return charge;
	}

	void TaxableProduct::display(std::ostream & os) const{
		Product::display(os);
		os << ' ';
		if (m_taxed == 'H') {
			os << "HST";
		}
		else if (m_taxed == 'P') {
			os << "PST";
		}
		else {
			os << " ";
		}
	}
}