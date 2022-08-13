/*
Given an integer array A with size N and an integer K,where 0< N, K <10^5 . Write a program for getting Kth minimum and Kth maximum number from the given array.
 
Sample input:
6 3
1 13 20 4 15 17
Sample output:
13 15
Explanation: 1st minimum: 1, 2nd minimum: 4, third minimum: 13
1st maximum: 20, 2nd maximum: 17, 3rd maximum: 15
*/

#include <iostream>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int kMin = arr[K - 1];
    int kMax = arr[N - K];

    cout << kMin << " " << kMax << endl;

    return 0;
}