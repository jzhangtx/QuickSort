// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

size_t Partition(std::vector<int>& arr, size_t low, size_t high)
{
    int pivot = arr[high - 1];

    size_t i = low - 1;
    for (size_t j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[j], arr[i]);
        }
    }

    std::swap(arr[++i], arr[high-1]);
    return i;
}

void Sort(std::vector<int>& arr, size_t low, size_t high)
{
    if (high - low <= 1)
        return;

    size_t pi = Partition(arr, low, high);

    Sort(arr, low, pi);
    Sort(arr, pi+1, high);
}

void QuickSort(std::vector<int>& arr)
{
    Sort(arr, 0, arr.size());
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The number array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        QuickSort(vec);
        std::cout << "Sorted:" << std::endl;
        for (auto i = vec.cbegin(); i != vec.cend(); ++i)
        {
            if (i != vec.cbegin())
                std::cout << ", ";
            std::cout << *i;
        }
        std::cout << std::endl;
    }
}
