#include <iostream>
#include <queue>
#include <vector>

void printArr(const std::vector<int>& data);
std::vector<int> mergeArrays(std::vector<std::vector<int>>&);

struct Element {
    std::vector<int>::iterator current;
    std::vector<int>::iterator end;
    Element(std::vector<int>::iterator current, std::vector<int>::iterator end)
        : current(current)
        , end(end) {}
};

int main() {
    std::vector<std::vector<std::vector<int>>> testArray {
    std::vector<std::vector<int>> {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {},
        {1, 1, 1, 11, 12, 13, 42},
        {50, 90, 99, 100},
        {95}
    },
    std::vector<std::vector<int>> {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 1, 10, 12, 142},
        {1, 1, 1, 11, 129, 143, 432},
        {50, 920, 929, 10032},
        {95, 10000},
        {0, 0, 0, 0},
        {123456}
    },
    std::vector<std::vector<int>> {
        {}
    },
    std::vector<std::vector<int>> {
        {100}
    }
    };

    for (auto& data : testArray) {
        auto res = mergeArrays(data);
        printArr(res);
    }

    return EXIT_SUCCESS;
}

void printArr(const std::vector<int>& data) {
    for (auto num : data)
        std::cout << num << " ";
    std::cout << std::endl;
}

std::vector<int> mergeArrays(std::vector<std::vector<int>>& data) {
    struct greater {
        bool operator()(Element& a, Element& b) {
            return *a.current > *b.current;
        }
    };

    std::vector<int> result;
    std::priority_queue<Element, std::vector<Element>, greater> heap;

    for (auto& vector : data) {
        if (!vector.empty())
            heap.emplace(vector.begin(), vector.end());
    }

    while (!heap.empty()) {
        auto tmp = heap.top();
        heap.pop();
        result.emplace_back(*tmp.current);
        ++tmp.current;
        if (tmp.current != tmp.end) {
            heap.emplace(tmp.current, tmp.end);
        }
    }

    return result;
}