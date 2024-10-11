#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5; // size of the array
    int arr[SIZE];
    
    // Input array elements
    cout << "Enter " << SIZE << " elements for the array: ";
    int totalSum = 0; // declaring totalSum to 0
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
        totalSum = totalSum +  arr[i]; // adding the array values to totalSum
    }

    // Compute and print the sum array
    cout << "The sum array is: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << (totalSum - arr[i]) << " "; // substracting arr[i] from totalSum and printing the output array
    }
    cout << endl;

    return 0;
}
hi
