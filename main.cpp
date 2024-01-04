#include <iostream>


void testing(int);

int main() {
    std::cout << "Hello, World!" << std::endl;

    for(int i = 0; i < 10; i++)   {
        testing(i);
    }

    return 0;
}

void testing(int runNumber)   {

    if(runNumber > 3)   {
        std::cout <<(runNumber) << std::endl;
    }


}
