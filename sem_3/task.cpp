#include <iostream>
#include <vector>
#include <algorithm>

// Shell sort task

void shellSort(std::vector<int>&);
void printData(std::vector<int>&);

int main() {
    std::vector<int> test1{6, 2, 67, 12, 42, 90, 10, 13, 12, 101};
    printData(test1);
    shellSort(test1);
    printData(test1);
    std::cout << std::endl;

    std::vector<int> test2{1, 2, 3, 4, 5, 6, 8, 9, 7};
    printData(test2);
    shellSort(test2);
    printData(test2);
    std::cout << std::endl;

    std::vector<int> test3{-1, 3, 5, 6, 7, 83, 42, 42, 42, 901};
    printData(test3);
    shellSort(test3);
    printData(test3);
    std::cout << std::endl;

    std::vector<int> test4{1, 1, 1, 1, 1};
    printData(test4);
    shellSort(test4);
    printData(test4);
    std::cout << std::endl;

    std::vector<int> test5{10, 9, 8, 7, 6, 5};
    printData(test5);
    shellSort(test5);
    printData(test5);

    return EXIT_SUCCESS;
}

void shellSort(std::vector<int>& data) {
    int n = data.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {

            int temp = data[i];
            int j;

            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }

            data[j] = temp;
        }
    }
}

void printData(std::vector<int>& data) {
    for (auto num : data)
        std::cout << num << " ";
    std::cout << std::endl;
}


