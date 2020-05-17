#include <iostream>

void printArray(int arr[], int size) {    
    for (int i = 0; i < size; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;  
}

void merge(int arr[], int low, int high, int mid) {
    int temp[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            ++i;
        } else {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        ++i;
        ++k;
    }
    while (j <= high) {
        temp[k] = arr[j];
        ++j;
        ++k;
    }

    for (int i = low; i <= high; ++i) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, high, mid);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 7, 6}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    std::cout << "Given array is" << std::endl;
    printArray(arr, size);

    mergeSort(arr, 0, size - 1); 
  
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size);

    return 0;
}