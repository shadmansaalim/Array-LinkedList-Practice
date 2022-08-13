/*
Given an integer array A with size N and k. Write a program to find out how many pairs exist in array A whose sum is equal to k.
      
          Sample input:
           7 8
           1 2 3 4 5 6 7

          Sample output:
          3
[Here, 1+7=8, 2+6=8, 3+5=8 ]
*/

#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int k)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (k == arr[mid])
        {
            return mid;
        }

        else if (k < arr[mid])
        {
            return binarySearch(arr, low, mid - 1, k);
        }
        else
        {
            return binarySearch(arr, mid + 1, high, k);
        }
    }

    return -1;
}

int main(void)
{
    int N, k;
    cin >> N >> k;
    int A[N];

    int pairs = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        int value = A[i];
        int req_value = k - value;
        int index = binarySearch(A, i + 1, N - 1, req_value);
        if (index != -1)
        {
            pairs++;
        }
    }
    cout << pairs << endl;
    return 0;
}