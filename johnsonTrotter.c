#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0, mobileIndex = -1;
    for (int i = 0; i < n; i++) {
        if ((dir[i] == LEFT && i != 0 && a[i] > a[i - 1]) ||
            (dir[i] == RIGHT && i != n - 1 && a[i] > a[i + 1])) {
            if (a[i] > mobile) {
                mobile = a[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n], dir[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while (1) {
        int mobileIndex = getMobile(a, dir, n);
        if (mobileIndex == -1)
            break;

        int swapWith = (dir[mobileIndex] == LEFT) ? mobileIndex - 1 : mobileIndex + 1;
        int temp = a[mobileIndex];
        a[mobileIndex] = a[swapWith];
        a[swapWith] = temp;

        int tmp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapWith];
        dir[swapWith] = tmp;

        for (int i = 0; i < n; i++)
            if (a[i] > a[swapWith])
                dir[i] = -dir[i];

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
