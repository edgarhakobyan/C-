#include <iostream>

int binarySearch(int arr[], int leftIndex, int rightIndex, int number) {
    if (rightIndex >= 1) {
        int mid = leftIndex + (rightIndex - 1) / 2;

        if (arr[mid] == number) {
            return mid;
        }
        if (arr[mid] > number) {
            return binarySearch(arr, leftIndex, mid - 1, number);
        }
        return binarySearch(arr, mid + 1, rightIndex, number);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int number = 10; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int index = binarySearch(arr, 0, size - 1, number);
    if (index == -1) {
        std::cout << "Element is not present in array" << std::endl;
    } else {
        std::cout << "Element is present at index " << index << std::endl;
    }
    return 0;
}