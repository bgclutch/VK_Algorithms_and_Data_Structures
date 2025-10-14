#include <iostream>
#include <vector>

/*
#1 Two sum -> leetcode 1 + 167
#2 Развернуть массив
#3 Развернуть часть массива -> leetcode 189

#4 Слияние 2х сортированных массива -> leetcode 88
#5 Сортировка массива нулей и единиц
#6 Задача флага Нидерландов -> leetcode 75

#7 Передвинуть чётные числа вперёд -> leetcode 905
#8 Передвинуть нули в конец -> leetcode 283
*/

// #2 Reverse array
void reverseArray (std::vector<int>& data) {
    if (data.empty())
        return;

    for (int begin = 0, end = data.size() - 1; begin < end; ++begin, --end)
        std::swap(data[begin], data[end]);
}

// #5 Sort ones and zeroes
void sortOnesAndZeroes (std::vector<int>& data) {
    if (data.empty())
        return;

    int begin = 0;
    int end = data.size() - 1;

    while (begin < end) {
        while (begin < end && data[begin] == 0)
            ++begin;
        while (begin < end && data[end] == 1)
            --end;
        if (begin < end)
            std::swap(data[begin], data[end]);
    }
}

void PrintRes (const std::vector<int>& data) {
    for (auto num : data) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}


int main() {
    std::vector<int> testcaseRevArr1 {1, 2, 4, 5, 6, 6, 7, 8, 9, 190, 20, 42};
    std::vector<int> testcaseRevArr2 {};
    std::vector<int> testcaseRevArr3 {0,1};

    reverseArray(testcaseRevArr1);
    std::cout << "Reverse array testcase 1:" << std::endl;
    PrintRes(testcaseRevArr1);

    reverseArray(testcaseRevArr2);
    std::cout << "Reverse array testcase 2:" << std::endl;
    PrintRes(testcaseRevArr2);

    reverseArray(testcaseRevArr3);
    std::cout << "Reverse array testcase 3:" << std::endl;
    PrintRes(testcaseRevArr3);

    std::vector<int> testcaseSortOnesAndZeroes1 {0, 0, 0, 0, 1, 1, 1, 1, 1};
    std::vector<int> testcaseSortOnesAndZeroes2 {};
    std::vector<int> testcaseSortOnesAndZeroes3 {0, 1, 1, 0, 0, 0, 1, 0, 1, 0};

    sortOnesAndZeroes(testcaseSortOnesAndZeroes1);
    std::cout << "Sort ones and zeroes testcase 1:" << std::endl;
    PrintRes(testcaseSortOnesAndZeroes1);

    sortOnesAndZeroes(testcaseSortOnesAndZeroes2);
    std::cout << "Sort ones and zeroes testcase 2:" << std::endl;
    PrintRes(testcaseSortOnesAndZeroes2);

    sortOnesAndZeroes(testcaseSortOnesAndZeroes3);
    std::cout << "Sort ones and zeroes testcase 3:" << std::endl;
    PrintRes(testcaseSortOnesAndZeroes3);

    return EXIT_SUCCESS;
}