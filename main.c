#include "./nlogn.c"

int main(int argc, char const *argv[]) {
        int A[6] = {1, 5, 2, 1, 4, 0};
        int result = solution(A, 6);
        printf("%d\n", result);
        return 0;
}
