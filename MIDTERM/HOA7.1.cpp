#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function Declarations
template <typename T> void bubbleSort(T arr[], size_t arrSize);
template <typename T> void selectionSort(T arr[], const int N);
template <typename T> int Routine_Smallest(T A[], int K, const int arrSize);
template <typename T> void insertionSort(T arr[], const int N);

// Helper function to print array
template <typename T>
void printArray(T arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    srand(time(0));
    const int SIZE = 100;

    // Preparation Task: Generate array with 100 unsorted random elements
    int originalArray[SIZE];
    for(int i = 0; i < SIZE; i++) {
        originalArray[i] = rand() % 100;
    }

    std::cout << "Table 7-1: Preparation Task - Unsorted Array:\n";
    printArray(originalArray, SIZE);

    // Testing Bubble Sort (Table 7-2)
    int arrBubble[SIZE];
    std::copy(originalArray, originalArray + SIZE, arrBubble);
    bubbleSort(arrBubble, SIZE);
    std::cout << "Table 7-2: Bubble Sort Output:\n";
    printArray(arrBubble, SIZE);

    // Testing Selection Sort (Table 7-3)
    int arrSelection[SIZE];
    std::copy(originalArray, originalArray + SIZE, arrSelection);
    selectionSort(arrSelection, SIZE);
    std::cout << "Table 7-3: Selection Sort Output:\n";
    printArray(arrSelection, SIZE);

    // Testing Insertion Sort (Table 7-4)
    int arrInsertion[SIZE];
    std::copy(originalArray, originalArray + SIZE, arrInsertion);
    insertionSort(arrInsertion, SIZE);
    std::cout << "Table 7-4: Insertion Sort Output:\n";
    printArray(arrInsertion, SIZE);

    return 0;
}

// A.1. Bubble Sort Technique
template <typename T> 
void bubbleSort(T arr[], size_t arrSize){ 
    //Step 1: For i = 0 to N-1 repeat Step 2 
    for(int i = 0; i < arrSize; i++){ 
        //Step 2: For J = i + 1 to N – I repeat 
        for(int j = i+1; j < arrSize; j++){  
            //Step 3: if A[J] > A[i] 
            if(arr[j]>arr[i]){ 
                //Swap A[J] and A[i] 
                std::swap(arr[j], arr[i]); 
            } 
            //[End of Inner for loop] 
        } 
        //[End if Outer for loop] 
    } 
    //Step 4: Exit 
} 

// Routine smallest (Array, Current Position, Size of Array) 
template <typename T> 
int Routine_Smallest(T A[], int K, const int arrSize){ 
    int position, j; 
    //Step 1: [initialize] set smallestElem = A[K] 
    T smallestElem = A[K]; 
    //Step 2: [initialize] set POS = K 
    position = K; 
    //Step 3: for J = K+1 to N -1,repeat 
    for(int J=K+1; J < arrSize; J++){ 
        if(A[J] < smallestElem){ 
            smallestElem = A[J];  
            position = J; 
        } 
    } 
    //Step 4: return POS 
    return position; 
}

// A.2. Selection Sort Algorithm 
template <typename T> 
void selectionSort(T arr[], const int N){ 
    int POS, temp, pass=0; 
    //Step 1: Repeat Steps 2 and 3 for K = 1 to N-1 
    for(int i = 0; i < N; i++){ 
        //Step 2: Call routine smallest(A, K, N,POS) 
        POS = Routine_Smallest(arr, i, N); 
        temp = arr[i]; 
        //Step 3: Swap A[K] with A [POS] 
        arr[i] = arr[POS]; 
        arr[POS] = temp; 
        //Count 
        pass++; 
    } 
    //[End of loop] 
    //Step 4: EXIT 
} 

// A.3. Insertion Sort Algorithm 
template <typename T> 
void insertionSort(T arr[], const int N){ 
    int K = 0, J, temp; 
    //Step 1: Repeat Steps 2 to 5 for K = 1 to N-1 
    while(K < N){ 
        //Step 2: set temp = A[K] 
        temp = arr[K]; 
        //Step 3: set J = K – 1 
        J = K-1; 
        //Step 4: Repeat while temp <=A[J] 
        while(temp <= arr[J]){ 
            //set A[J + 1] = A[J] 
            arr[J+1] = arr[J]; 
            //set J = J – 1 
            J--; 
            //[end of inner loop] 
        } 
        //Step 5: set A[J + 1] = temp 
        arr[J+1] = temp; 
        //[end of loop] 
        K++; 
    } 
    //Step 6: exit 
}