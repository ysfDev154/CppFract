#include <iostream>
#include <stdexcept>

class CppFract {

private:
	typedef long long ll;
	ll n,d;

public:
	CppFract(const ll& _n, const ll& _d):n(_n),d(_d) {
		if (!d) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
	} 

	void Show() const {
		Show(std::cout);
	}

	std::ostream& Show(std::ostream& os) const {
		return os << n << '/' << d;
	}

};

inline std::ostream& operator<<(std::ostream& os, const CppFract& f) {
	return f.Show(os);
}
