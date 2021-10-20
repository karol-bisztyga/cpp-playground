#include <iostream>

#include <hey.h>

using namespace std;

int main()
{
  Hey h("aaaa");
  cout << "Hello " << h.get() << endl;
}