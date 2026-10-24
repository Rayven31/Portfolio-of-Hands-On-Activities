#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

void partial_sum(const std::vector<int>& arr, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; ++i) {
        result += arr[i];
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    int sum1 = 0, sum2 = 0;
    int mid = numbers.size() / 2;

    std::thread t1(partial_sum, std::cref(numbers), 0, mid, std::ref(sum1));
    std::thread t2(partial_sum, std::cref(numbers), mid, numbers.size(), std::ref(sum2));

    t1.join();
    t2.join();

    int total = sum1 + sum2;
    std::cout << "First Half Sum: " << sum1 << std::endl;
    std::cout << "Second Half Sum: " << sum2 << std::endl;
    std::cout << "Total Parallel Sum: " << total << std::endl;

    return 0;
}