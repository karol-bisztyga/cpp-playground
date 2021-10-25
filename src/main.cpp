#include <iostream>

#include "opaque.h"

using namespace std;

Opaque_Ids ids = { 4, (uint8_t*)"user", 6, (uint8_t*)"server" };
Opaque_PkgConfig cfg = {
  .skU = NotPackaged,
  .pkU = NotPackaged,
  .pkS = InSecEnv,
  .idS = NotPackaged,
  .idU = NotPackaged,
};

int main()
{
  const uint32_t envLen = opaque_envelope_len(&cfg, &ids);
  cout << "Hello: " << envLen << endl;
}