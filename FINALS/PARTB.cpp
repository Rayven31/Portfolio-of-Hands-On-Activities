#include <iostream>
#include <thread>

int global_counter = 0; // Global variable

void add(int value) {
    global_counter += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Initial Display: " << global_counter << std::endl;

    T1.join();
    std::cout << "After T1.join(): " << global_counter << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << global_counter << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << global_counter << std::endl;

    return 0;
}