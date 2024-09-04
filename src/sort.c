#include <stdio.h>
#define NMAX 10

int input(int *a, int f);
void output(int *a, int f);
void sort(int *a);

int main() {
    int data[NMAX];
    int flag = 1;
    flag = input(data, flag);
    if (flag == 1) {
        sort(data);
    }
    output(data, flag);

    return 0;
}

int input(int *a, int f) {
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            f = 0;
        }
    }
    if (getchar() != '\n') {
        f = 0;
    }
    return f;
}

void output(int *a, int f) {
    if (f == 1) {
        for (int *p = a; p - a < NMAX; p++) {
            printf("%d ", *p);
        }
        printf("\n");
    } else {
        printf("n/a\n");
    }
}

void sort(int *a) {
    for (int *i = a; i < NMAX + a; i++) {
        for (int *j = a; j < NMAX + a - 1; j++) {
            if (*j > *(j + 1)) {
                int tmp = *j;
                *j = *(j + 1);
                *(j + 1) = tmp;
            }
        }
    }
}
