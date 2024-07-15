#include <stdio.h>

class CppFract {

typedef long long ll;

private:
	ll n,d;

public:
	CppFract(const ll& _n, const ll& _d):n(_n),d(_d) {}

	void Show() const {
		printf("CppFract : (%lld/%lld)\n",n,d);
	}
};
