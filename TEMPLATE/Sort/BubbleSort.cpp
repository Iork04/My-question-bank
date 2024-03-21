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

void bubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }

        printArr(arr);
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cout.tie(0), std::cin.tie(0);
    std::vector<int> arr;
    readData(arr);
    printArr(arr);

    bubbleSort(arr);
}
