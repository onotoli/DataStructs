#include <iostream>


int* new_array(int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    return a;
}

int josephus(int* array, int size, int step) {
    int index = 1;
    while (size > 1) {
        index = (index + step) % size;
        int * tmp = new_array(size - 1);
        for (int i = 0; i < index; ++i) {
            tmp[i] = array[i];
        }
        for (int i = index; i < size - 1; ++i) {
            tmp[i] = array[i + 1];
        }
        array = tmp;
        size--;
    }
    return array[0];
}

int main() {
    std::cout << josephus(new_array(13), 13, 3);
    return 0;
}