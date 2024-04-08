#include <iostream>
#include <vector>
#include <algorithm>

// пузырьки
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// выбор 
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

// вставко1
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// подсчетом
void countingSort(std::vector<int>& arr) {
    int n = arr.size();
    int maxVal = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(maxVal + 1, 0);
    std::vector<int> output(n, 0);

    // считат каждый эелемент в массиве
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // считает сумму 
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    //создает массив поместив каждый элемент в его правильное место
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //  копирует сортированные элементы назад в массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// цифровая сортировка
void radixSort(std::vector<int>& arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int maxDigits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        maxDigits++;
    }

    for (int i = 1; i <= maxDigits; i++) {
        std::vector<std::vector<int>> buckets(10);

        //распределяет элементы исходя из индекса
        for (int j = 0; j < arr.size(); j++) {
            int digit = (arr[j] / static_cast<int>(std::pow(10, i - 1))) % 10;
            buckets[digit].push_back(arr[j]);
        }

        // обновляет элементы в массиве
        int index = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < buckets[j].size(); k++) {
                arr[index++] = buckets[j][k];
            }
        }
    }
}

int main() {
    std::vector<int> arr = { 5, 3, 8, 4, 2 };

    std::cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr);
    std::cout << "Bubble sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = { 5, 3, 8, 4, 2 };
    selectionSort(arr2);
    std::cout << "Selection sorted array: ";
    for (int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr3 = { 5, 3, 8, 4, 2 };
    insertionSort(arr3);
    std::cout << "Insertion sorted array: ";
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr4 = { 5, 3, 8, 4, 2 };
    countingSort(arr4);
    std::cout << "Counting sorted array: ";
    for (int i = 0; i < arr4.size(); i++) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr5 = { 5, 3, 8, 4, 2 };
    radixSort(arr5);
    std::cout << "Radix sorted array: ";
    for (int i = 0; i < arr5.size(); i++) {
        std::cout << arr5[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
