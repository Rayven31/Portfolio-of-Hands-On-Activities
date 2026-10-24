#include <iostream>
#include <thread>

int global_var = 0;

void add(int value) {
    global_var += value;
}

int main() {
    std::cout << "Global_var: " << global_var << std::endl;

    std::thread T1(add, 10);
    std::cout << "Before T1.join(): " << global_var << std::endl;
    T1.join();
    std::cout << "After T1.join(): " << global_var << std::endl;

    std::thread T2(add, 20);
    std::cout << "Aefore T2.join(): " << global_var << std::endl;
    T2.join();
    std::cout << "After T2.join(): " << global_var << std::endl;

    std::thread T3(add, 30);
    std::cout << "Before T3.join(): " << global_var << std::endl;
    T3.join();
    std::cout << "After T3.join(): " << global_var << std::endl;

    return 0;
}