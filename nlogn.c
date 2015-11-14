
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort (long A[], int n) {
    if (n < 2) { return; }

    long left, right;
    long pivot = A[n / 2];
    for (left = 0, right = n - 1; ; left++, right--) {
        while (A[left] < pivot) { left++; }
        while (pivot < A[right]) { right--; }
        if (left >= right) { break; }
        long temp = A[left];
        A[left] = A[right];
        A[right] = temp;
    }
    quick_sort(A, left);
    quick_sort(A + left, n - left);
}

int solution(int A[], int N) {
        // Init empty arrays
        long starts[N]; memset(starts, 0, N*sizeof(long));
        long ends[N]; memset(ends, 0, N*sizeof(long));

        // Get starting and ending points
        for (size_t i = 0; i < N; i++) {
                starts[i] = i - A[i];
                ends[i] = i + A[i];
        }

        // Sort arrays from lowest to higher
        quick_sort(starts, N);
        quick_sort(ends, N);

        // Count intersections
        int intersections = 0;

        // Save the index of the last opening circle at the moment.
        size_t marker = 0;

        // Iterate the ending list
        for (size_t e = 0; e < N; e++) {
                // Rise the marker until the starts[marker] becomes higher than the current ending point
                for (; marker < N && starts[marker] <= ends[e]; marker++) { }
                // Do not count current circle neither already counted collitions
                intersections += (marker - 1 - e);
                // Check top condition
                if (intersections > 10000000) { return -1; }
        }
        // Return intersection count
        return intersections;
}
