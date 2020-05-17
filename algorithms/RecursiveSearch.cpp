#include <iostream>

int recursiveSearch(int arr[], int left, int right, int number) {
    if (right < left) {
        return -1;
    }
    if (arr[left] == number) {
        return left;
    }
    if (arr[right] == number) {
        return right;
    }
    return recursiveSearch(arr, left + 1, right - 1, number);
}

int main() {
    int arr[] = {12, 34, 54, 2, 3}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int number = 3; 
    int index = recursiveSearch(arr, 0, size - 1, number); 
    if (index == -1) {
        std::cout << "Element is not present" << std::endl;
    } else {
        std::cout << "Element is present at index " << index << std::endl;
    }
}