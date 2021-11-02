#include <iostream>

using namespace std;

extern "C" void helloRust();

int main()
{
  helloRust();
  cout << "Hello" << endl;
}