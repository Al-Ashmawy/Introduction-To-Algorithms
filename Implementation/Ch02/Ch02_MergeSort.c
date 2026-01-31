/*
    Chapter:      02 - Getting Started
    Algorithm:    Merge Sort (Divide and Conquer)
    Contributor:  [Ahmed Adel / Ahmed-Adel-Ramadan]
    Complexity:   theta(n log n)
    --------------------------------------------------------------------
    Description: 
        Merge Sort is a Divide and Conquer algorithm that divides the input array into two halves,
        calls itself for the two halves, and then merges the two sorted halves.
    --------------------------------------------------------------------
    
*/
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int length);

int main(void) {
    printf("Enter The Number Of Elements: ");
    int length;
    scanf("%i", &length);

    int* arr = malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i) {
        printf("Enter Element %i: ", i + 1);
        scanf("%i", arr + i);
    }

    merge_sort(arr, length);

    for (int i = 0; i < length; ++i) {
        printf("%i ", arr[i]);
    }

    free(arr);
}

void merge_sort(int arr[], int length) {
    if (length <= 1) {
        return;
    }

    // Sort Left Half
    merge_sort(arr, length / 2);
    // Sort Right Half
    merge_sort(arr + length / 2, length - length / 2);

    int* merged = malloc(length * sizeof(int));
    int l = 0, r = length / 2;
    for (int i = 0; i < length; ++i) {
        if (l < length / 2 && (r == length || arr[l] <= arr[r])) {
            merged[i] = arr[l++];
        } else {
            merged[i] = arr[r++];
        }
    }

    for (int i = 0; i < length; ++i)
        arr[i] = merged[i];

    free(merged);
}
