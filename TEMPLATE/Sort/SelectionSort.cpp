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

void SelectionSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int minValIndex = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[j] < arr[minValIndex])
                minValIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minValIndex];
        arr[minValIndex] = temp;
        printArr(arr);
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
    std::vector<int> arr;
    readData(arr);
    printArr(arr);

    SelectionSort(arr);
}
