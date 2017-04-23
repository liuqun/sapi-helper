#include <iostream>
using namespace std;

#include "GenericDataStructure.h"

int main() {
    Data myData(32);

    cout << myData.getBufferSize() << endl;
    const void *p = myData.getBuffer();
    return 0;
}
