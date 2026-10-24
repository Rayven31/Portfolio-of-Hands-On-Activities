#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> searchSizes = {1000, 10000, 100000};
    int target = -1;

    for (int n : searchSizes) {
        std::vector<int> data(n);
        for (int i = 0; i < n; i++) {
            data[i] = i * 2;
        }

        auto startBinary = std::chrono::high_resolution_clock::now();
        binarySearch(data, target);
        auto endBinary = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedBinary = endBinary - startBinary;

        auto startLinear = std::chrono::high_resolution_clock::now();
        linearSearch(data, target);
        auto endLinear = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedLinear = endLinear - startLinear;

        std::cout << "N = " << n << std::endl;
        std::cout << "Binary Search (Worst-Case): " << elapsedBinary.count() << " ms" << std::endl;
        std::cout << "Linear Search (Worst-Case): " << elapsedLinear.count() << " ms" << std::endl << std::endl;
    }

    std::vector<int> sortSizes = {100, 1000, 10000};

    std::cout << "Bubble Sort:" << std::endl;
    for (int n : sortSizes) {
        std::vector<int> bestData(n);
        for (int i = 0; i < n; i++) bestData[i] = i;

        auto startBest = std::chrono::high_resolution_clock::now();
        bubbleSort(bestData);
        auto endBest = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedBest = endBest - startBest;

        std::vector<int> worstData(n);
        for (int i = 0; i < n; i++) worstData[i] = n - i;

        auto startWorst = std::chrono::high_resolution_clock::now();
        bubbleSort(worstData);
        auto endWorst = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedWorst = endWorst - startWorst;

        std::cout << "N = " << n << std::endl;
        std::cout << "Best case: " << elapsedBest.count() << " ms" << std::endl;
        std::cout << "Worst case: " << elapsedWorst.count() << " ms" << std::endl << std::endl;
    }

    std::cout << "Quick Sort:" << std::endl;
    for (int n : sortSizes) {
        std::vector<int> bestData(n);
        for (int i = 0; i < n; i++) bestData[i] = n - i;

        auto startBest = std::chrono::high_resolution_clock::now();
        quickSort(bestData, 0, n - 1);
        auto endBest = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedBest = endBest - startBest;

        std::vector<int> worstData(n);
        for (int i = 0; i < n; i++) worstData[i] = i;

        auto startWorst = std::chrono::high_resolution_clock::now();
        quickSort(worstData, 0, n - 1);
        auto endWorst = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsedWorst = endWorst - startWorst;

        std::cout << "N = " << n << std::endl;
        std::cout << "Best case: " << elapsedBest.count() << " ms" << std::endl;
        std::cout << "Worst case: " << elapsedWorst.count() << " ms" << std::endl << std::endl;
    }

    return 0;
}