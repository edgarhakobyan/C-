#include <iostream>

int search(int arr[], int size, int number)  { 
    for (int i = 0; i < size; ++i) {
        if (arr[i] == number) return i;
    }
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int number = 10; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int result = search(arr, size, number);
    if (result == -1) {
        std::cout << "Element is not present in array" << std::endl;
    } else {
        std::cout << "Element is present at index " << result << std::endl;
    }
    
   return 0; 
} 