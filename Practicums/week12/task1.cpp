#include <iostream>

template<typename T>
void sortArray(T* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<>
void sortArray<char>(char* arr, size_t size) {
    int count[256] = {0};

    for (size_t i = 0; i < size; ++i) {
        ++count[(unsigned char)arr[i]];
    }

    size_t index = 0;
    for (int i = 0; i < 256; ++i) {
        while (count[i]-- > 0) {
            arr[index++] = (char)i;
        }
    }
}

int main() {
    int a[] = {5, 2, 3, 1, 4};
    sortArray(a, 5);

    for (size_t i = 0; i < 5; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    char letters[] = {'d', 'a', 'c', 'b'};
    sortArray(letters, 4);

    for (size_t i = 0; i < 4; ++i) {
        std::cout << letters[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
