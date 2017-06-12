#include <iostream>
#include "mingw.thread.h"

using namespace std;

void printFast(){
    for (int i = 0; i < 100; i++) {
        cout << i;
    }
}

int main()
{
    thread th(printFast);
    cout << "Hello world!" << endl;
    th.join();
    return 0;
}
