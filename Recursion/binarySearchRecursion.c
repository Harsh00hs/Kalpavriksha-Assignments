#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid] > x) {
        return binarySearch(arr, low, mid - 1, x);
    }

    return binarySearch(arr, mid + 1, high, x);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
