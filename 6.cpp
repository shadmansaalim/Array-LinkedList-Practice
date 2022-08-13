/*
Given a sorted integer array A with size N integers and an integer k. Write a program to find out the position of k from array A using binary search. 
Sample input:
7 9
1 2 3 4 9 7 8
Sample output:
5

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
            return mid + 1;
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

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int position = binarySearch(A, 0, N - 1, k);

    if (position == -1)
    {
        cout << "Element doesn't exists in array" << endl;
    }
    else
    {
        cout << position << endl;
    }

    return 0;
}