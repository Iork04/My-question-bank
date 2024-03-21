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

void CountingSort(std::vector<int> &arr)
{
    int maxVal = arr[0], minVal = arr[0];
    for (auto &val : arr)
    {
        maxVal = std::max(maxVal, val);
        minVal = std::min(minVal, val);
    }

    std::vector<int> countArr(maxVal - minVal + 1, 0);
    for (auto val : arr)
        countArr[val - minVal]++;
    int index = 0;
    for (int i = 0; i < countArr.size(); ++i)
    {
        while (countArr[i]--)
        {
            arr[index++] = minVal + i;
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

    CountingSort(arr);
}
