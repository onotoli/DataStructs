#include <iostream>
#include <fstream>


void OUT (std::string file_name, int n, long long t) {
    std::ofstream out(file_name, std::ios::app);
    if (out.is_open()) {
        out << n << ";" << t << std::endl;
    }
    out.close();
}

struct DynamicArray {
    int* elements = nullptr;
    int capacity = 0 , size = 0;
};

DynamicArray new_array(int capacity, int size, int init_val = 0) {
    DynamicArray a;
    a.size = size;
    a.capacity = capacity;
    a.elements = new int[capacity];
    for (int i = 0; i < size; i++)
        a.elements[i] = init_val;
    return a;
}

void erase(DynamicArray &da) {
    delete [] da.elements;
}

DynamicArray& reserve(DynamicArray &da, int capacity) {
    if (da.capacity < capacity) {
        DynamicArray a = new_array(capacity, 0);
        for (int i = 0; i < da.size; ++i) {
            a.elements[i] = da.elements[i];
        }
        erase(da);
        return a;
    }
    else
        return da;
}

DynamicArray clone(DynamicArray &da) {
    DynamicArray a = new_array(da.size, da.size);
    for (int i = 0; i < da.size; ++i)
        a.elements[i] = da.elements[i];
    return a;
}

DynamicArray& assign(DynamicArray &src, DynamicArray &dst) {
    if (dst.capacity <= src.size)
        dst = clone(src);

    else {
        for (int i = 0; i < src.size; ++i)
            dst.elements[i] = src.elements[i];
        for (int i = src.size; i < dst.capacity; ++i)
            dst.elements[i] = 0;
    }
    return dst;
}

DynamicArray resize(DynamicArray da, int new_capacity) {
    DynamicArray a = new_array(new_capacity, 0);
    for (int i = 0; i < da.size; i++) {
        a.elements[i] = da.elements[i];
    }
    a.size = da.size;
    a.capacity = new_capacity;
    delete[] da.elements;
    return a;
}

void push_back_x2(DynamicArray& da, int val){
    int size = da.size;
    if (da.capacity < size + 1)
        da = resize(da, da.size * 2);
    da.size = size + 1;
    da.elements[size] = val;
}

void push_back_1(DynamicArray& da, int val){
    int size = da.size;
    if (da.capacity < size + 1)
        da = resize(da, da.size + 1);
    da.size = size + 1;
    da.elements[size] = val;
}

void print(DynamicArray& da) {
    for (int i = 0; i < da.size; i++)
        std::cout << da.elements[i] << std::endl;
}

int* array(int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    return a;
}

int main() {
    long long t;
    clock_t end, begin;
    begin = clock();
    for (int j = 100000; j <= 10000000; j = j + 100000) {
        DynamicArray a = new_array(j, j);
        for (int i = 0; i < 1000; ++i)
            push_back_1(a, 0);
        end = clock();
        t = (long long) (end - begin);
        std::cout << j << '\t' << t << std::endl;
        OUT("push_back_1.csv", j, t);
        erase(a);
    }
    /*
    DynamicArray a = new_array(5, 5);
    push_back_x2(a, 0);
    //a = resize(a, 10);
    std::cout << a.capacity << " " << a.size << std::endl;
    print(a);
    */
    return 0;
}