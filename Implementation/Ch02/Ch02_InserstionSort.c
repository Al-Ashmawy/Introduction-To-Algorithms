/*
    Chapter:      02 - Getting Started
    Algorithm:    Insertion Sort
    Contributor:  [Ahmed Adel / Ahmed-Adel-Ramadan]
    Complexity:   
        Best Case:     theta(n)
        Worst Case:  theta(n^2)
    --------------------------------------------------------------------
    Description: 
        This program implements the Insertion Sort algorithm to sort an array of integers.
        It prompts the user to input the number of elements and the elements themselves,
        then sorts the array using Insertion Sort and prints the sorted array.
    --------------------------------------------------------------------
*/
#include <stdio.h>

void insertion_sort(int arr[], int length);

int main(void) {
    printf("Enter The Number Of Elements: ");
    int length;
    scanf("%i", &length);

    int arr[length];
    for (int i = 0; i < length; ++i) {
        printf("Enter Element %i: ", i + 1);
        scanf("%i", arr + i);
    }

    insertion_sort(arr, length);

    for (int i = 0; i < length; ++i) {
        printf("%i ", arr[i]);
    }
}

void insertion_sort(int arr[], int length) {
    for (int i = 1; i < length; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}