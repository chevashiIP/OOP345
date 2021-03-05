#ifndef _DATATABLE_H_
#define _DATATABLE_H_

#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

namespace w8 {
	template<typename T>
	class DataTable {
		int m_field;
		int m_decimals;
		vector<T> m_x;
		vector<T> m_y;
	public:
		DataTable(ifstream& is, int field, int decimals) {
			m_field = field;
			m_decimals = decimals;
			T x, y;
			if (is.is_open()) {
				while (!is.eof()) {
					is >> x;
					m_x.push_back(x);
					is >> y;
					m_y.push_back(y);
				}
			}
		}
		T mean() const {
			T sum = accumulate(m_y.begin(), m_y.end(), (T)0);
			return sum / m_y.size();
		}
		T sigma() const {
			T m = mean();
			T sum = 0;
			for (size_t i = 0; i < m_y.size(); i++)
				sum = sum + (m_y.at(i) - m) * (m_y.at(i) - m);
			return sqrt(static_cast<double>(sum / (m_y.size() - 1)));
		}
		T median() const {
			vector<T> v = m_y;
			sort(v.begin(), v.end());
			T t = m_y.size();
			return v[t / 2];
		}
		void regression(T& slope, T& y_intercept) const {
			T tatal_xy = inner_product(m_x.begin(), m_x.end(), m_y.begin(), (T)0);
			T tatal_x = accumulate(m_x.begin(), m_x.end(), (T)0);
			T tatal_y = accumulate(m_y.begin(), m_y.end(), (T)0);
			T tatal_xx = inner_product(m_x.begin(), m_x.end(), m_x.begin(), (T)0);
			T num = m_y.size();
			slope = (num * tatal_xy - tatal_x * tatal_y) / (num * tatal_xx - tatal_x * tatal_x);
			y_intercept = (tatal_y - slope * tatal_x) / num;
		}
		void display(ostream& os) const {
			os << setw(FW) << setprecision(ND) << fixed << 'X';
			os << setw(FW) << 'Y' << endl;
			for (int i = 0; i < m_x.size(); i++) {
				os << setw(FW) << m_x[i] << setw(FW) << m_y[i] << endl;
			}
		}
		friend ostream& operator<<(ostream& os, const DataTable& datatable) {
			datatable.display(os);
			return os;
		}
	};
}

#endif // !_DATATABLE_H_

