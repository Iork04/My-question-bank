#include <bits/stdc++.h>

void readData(std::vector<int> &arr)
{
    std::freopen("./in.in", "r", stdin);
    int value;
    while (std::cin >> value)
        arr.push_back(value);
}

void printArr(std::vector<int> &arr)
{
    for (auto &val : arr)
        std::cout << val << " ";
    std::cout << "\n";
}

void InsertionSort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        printArr(arr);
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
    std::vector<int> arr;
    readData(arr);
    printArr(arr);

    InsertionSort(arr);
}
