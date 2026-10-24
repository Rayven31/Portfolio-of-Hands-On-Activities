#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

    int i = 0, j = 0, k = start;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 76, 45};
    int n = arr.size();
    int mid = n / 2 - 1;

    cout << "Unsorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    thread t1(bubbleSort, ref(arr), 0, mid);
    thread t2(bubbleSort, ref(arr), mid + 1, n - 1);

    t1.join();
    t2.join();

    merge(arr, 0, mid, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}