#include <iostream>
#include "CppFract.h"

using namespace std;

int main(void) {

	try {
		CppFract f1(1,3), f2(154,0);
		CppFract(5,10).Show();

		cout << std::endl << f1 << endl;
	}
	
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
		
	return 0;
}
