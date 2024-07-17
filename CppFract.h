#include <iostream>
#include <stdexcept>

class CppFract {

// TODO normalise method
// TODO comment
// TODO test all the features

      /*

 /!\ [WIP] /!\ 
(not tested yet)
      
      */

private:
	typedef long long ll;
	ll n,d;

public:
	CppFract(const ll& _n=0, const ll& _d=1):n(_n),d(_d) {
		if (!d) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		//TODO normalise
	} 

	void Show() const {
		Show(std::cout);
	}

	std::ostream& Show(std::ostream& os) const {
		return os << n << '/' << d;
	}
	
	
	
	
	CppFract& operator +=(const CppFract& f) {
		n = n*f.d + f.n*d;
		d *= f.d;
		//TODO normalise
		return *this;
	}
	
	CppFract& operator -=(const CppFract& f) {
		n = n*f.d - f.n*d;
		d *= f.d;
		//TODO normalise
		return *this;
	}
	
	CppFract& operator *=(const CppFract& f) {
		n *= f.n;
		d *= f.d;
		//TODO normalise
		return *this;
	}
	
	CppFract& operator /=(const CppFract& f) {
		if (!f.n) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		n *= f.d;
		d *= f.n;
		//TODO normalise
		return *this;
	}
	
	
	
	
	CppFract operator +(const CppFract& f) const {
		return CppFract(*this)+=f;
	}
	
	CppFract operator -(const CppFract& f) const {
		return CppFract(*this)-=f;
	}
	
	CppFract operator *(const CppFract& f) const {
		return CppFract(*this)*=f;
	}
	
	CppFract operator /(const CppFract& f) const {
		return CppFract(*this)/=f;
	}
	
	
	
	
	CppFract operator +() const {
		return CppFract(n,d);
	}
	
	CppFract operator -() const {
		return CppFract(-n,d);
	}
	
	
	
	
	CppFract operator !() const {
		if (!n) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		} else {
			return CppFract(d,n);
		}
	}
	
	CppFract operator ~() {
		int temp = n;
		n = d;
		d = temp;
		return *this;
	}
	
	
	
	
	bool operator ==(const CppFract& f) const {
		return (n == f.n) && (d == f.d);
	}
	
	bool operator <(const CppFract& f) const {
		return (n < f.n) && (d < f.d);
	}
	
	bool operator <=(const CppFract& f) const {
		return (n <= f.n) && (d <= f.d);
	}
	
	bool operator >(const CppFract& f) const {
		return (n > f.n) && (d > f.d);
	}
	
	bool operator >=(const CppFract& f) const {
		return (n >= f.n) && (d >= f.d);
	}
	
	bool operator !=(const CppFract& f) const {
		return (n != f.n) && (d != f.d);
	}
	

	
	
	CppFract& operator ++() {
		return (*this)+=1;
	}
	
	CppFract operator ++(int) {
		CppFract temp(*this);
		++(*this);
		return temp;
	}
	
	CppFract& operator --() {
		return (*this)-=1;
	}
	
	CppFract operator --(int) {
		CppFract temp(*this);
		--(*this);
		return temp;
	}
	

};

inline std::ostream& operator<<(std::ostream& os, const CppFract& f) {
	return f.Show(os);
}
