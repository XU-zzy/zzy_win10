#include<iostream>
#include<thread>
#include<mutex>

void hello(){
    int c;
    std::cout << "hello thread" << std::endl;
}

int main(){

    std::thread t(hello);
    t.join();

    return 0;
}