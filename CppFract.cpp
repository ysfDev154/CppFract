#include "CppFract.h"

long long PGCD(long long a, long long b) {
  long long temp;
  while (b!=0) {
    temp = a;
    a = b;
    b = temp%b;
  }
  return a;
}
