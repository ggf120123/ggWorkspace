#include <iostream>
#include "helloworld/hello.h"

void hello::greeting(const string& name){
    cout << "Hello, " << name << "!" << endl;
}