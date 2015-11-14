
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * If the distance beetween two circunferences is less than the sum of their radius, they intercept.
 * @param  p1 First position
 * @param  r1 First radius
 * @param  p2 Second position
 * @param  r2 Second center
 * @return    True if they intercept
 */
int intersect(int p1, int r1, int p2, int r2) {
        return abs(p1 - p2) <= (r1 + r2);
}

int solution(int A[], int N) {
        int intersections = 0;

        for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                        intersections += intersect(i, A[i], j, A[j]);
                }
        }
        return (intersections > 10000000) ? -1 : intersections;
}
