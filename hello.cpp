#include <iostream>
using namespace std;
#include <sapi/tpm20.h>

#include "GenericDataStructure.h"

int main() {
    Data myData(32);

    cout << myData.getBufferSize() << endl;
    const TPM2B_DATA *p = Unpack(myData);
    return 0;
}
