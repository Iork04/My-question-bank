#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int arr[N];
int n, k;
void quickSort(int left, int right)
{
    int i = left, j = right, mid = 2;
    while (i <= j)
    {
        while (arr[j] > arr[mid])
            j--;
        while (arr[i] < arr[mid])
            i++;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}