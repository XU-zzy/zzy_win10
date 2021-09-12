#include <algorithm>
#include <iostream>
#include <memory>
#include <thread>
#include <semaphore.h>
#include <time.h>

class Foo {
private:

public:

    Foo() {
    }

    void first() {
        // printFirst() outputs "first".
        std::cout << "first";
    }

    void second() {
        // printSecond() outputs "second".
        std::cout << "second";

    }

    void third() {
        // printThird() outputs "third".
        std::cout << "third";
    }
};

int main(int argc, char** argv) {
    int array[3] = {1, 2, 3};

    // int array[3] = {1, 3, 2};
    // ::srand((unsigned)time(NULL));
    // std::random_shuffle(array, array + 3);

    std::thread th1, th2, th3;
    std::unique_ptr<Foo> foo(new Foo());
    for (int i : array) {
        switch(i) {
        case 1:
            th1 = std::thread(&Foo::first, foo.get());
            break;
        case 2:
            th2 = std::thread(&Foo::second, foo.get());
            break;
        case 3:
            th3 = std::thread(&Foo::third, foo.get());
            break;
        default:
            break;
        }
    }
    th1.join();
    th2.join();
    th3.join();

    std::cout << std::endl;
    return 0;
}