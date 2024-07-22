#include <iostream>
#include <stdexcept>

long long PGCD(long long a, long long b);

class CppFract {

private:
	typedef long long ll;
	ll n,d;
	
	void Norm() {
		ll oldPGCD;
		if (d < 0) {
			n = -n;
			d = -d;
		} 
		if (n == d) {
			n = 1;
			d = 1;
		}
		oldPGCD = PGCD(n,d);
		if (oldPGCD<0) oldPGCD = -oldPGCD;
		if (oldPGCD != 1) {
			n = n / oldPGCD;
			d = d / oldPGCD;
		}	
	}

public:

	// Constructor
	CppFract(const ll& _n=0, const ll& _d=1):n(_n),d(_d) {
		if (!d) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		Norm();
	} 
	
	
	
	
	// Methods that prints in the console
	void Show() const {
		Show(std::cout);
	}

	std::ostream& Show(std::ostream& os) const {
		return os << n << '/' << d;
	}
	
	
	
	
	// Compound assignments operators
	CppFract& operator +=(const CppFract& f) {
		n = n*f.d + f.n*d;
		d *= f.d;
		Norm();
		return *this;
	}
	
	CppFract& operator -=(const CppFract& f) {
		n = n*f.d - f.n*d;
		d *= f.d;
		Norm();
		return *this;
	}
	
	CppFract& operator *=(const CppFract& f) {
		n *= f.n;
		d *= f.d;
		Norm();
		return *this;
	}
	
	CppFract& operator /=(const CppFract& f) {
		if (!f.n) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		n *= f.d;
		d *= f.n;
		Norm();
		return *this;
	}
	
	
	
	
	// Arithmetic operators
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
	
	
	
	
	// Unary operators
	CppFract operator +() const {
		return CppFract(n,d);
	}
	
	CppFract operator -() const {
		return CppFract(-n,d);
	}
	
	// Returns the inverse of the fraction without modifying *this
	CppFract operator !() const {
		if (!n) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		return CppFract(d,n);

	}
	
	// Returns the inverse and modifies *this
	CppFract operator ~() {
		if (!n) {
			throw std::invalid_argument("Denominator CANNOT be zero.");
		}
		ll temp = n;
		n = d;
		d = temp;
		return *this;
	}
	
	
	
	
	// comparaisons
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
		return !((*this) == f);
	}
	
	
	
	
	// PRE/POST in/decrement operators
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

// stdio '<<' operator
inline std::ostream& operator<<(std::ostream& os, const CppFract& f) {
	return f.Show(os);
}
