#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[10];

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= r) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) {
        a[i] = b[i];
    }
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void printArray(int a[], int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[6] = {9, 2, 26, 1, 98, 10};
    int l = 0;
    int r = 5;

    mergesort(a, l, r);
    printArray(a, l, r);

    return 0;
}