#include <iostream>
#include "test.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Handler hh;
    test *obj = new test(&hh);
    obj->handler();
    obj->handlerCB(4,5);

    delete obj;
    return 0;
}
