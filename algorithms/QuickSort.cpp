#include <iostream>

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = low - 1; // index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size) {  
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";  
    std::cout << std::endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    std::cout << "Sorted array: \n";  
    printArray(arr, n);
    return 0;
}