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

void ShellSort(std::vector<int> &arr)
{
    int key;
    int i, j;
    for (int inc = arr.size() / 2; inc > 0; inc /= 2)
    {
        for (i = inc; i < arr.size(); ++i)
        {
            key = arr[i];
            for (j = i; j >= inc && key < arr[j - inc]; j -= inc)
                arr[j] = arr[j - inc];
            arr[j] = key;
            printArr(arr);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
    std::vector<int> arr;
    readData(arr);
    printArr(arr);

    ShellSort(arr);
}
