/*
Given an integer array A with size N. Write a program to print the number of distinct integers in A.
Sample input:
7
2 3 3 4 5 5 5 

Sample output:
4
*/

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int A[N];

    // Let's imagine the constraint of array range highest is 100
    int counter[101];

    for (int i = 0; i < 101; i++)
    {
        counter[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        counter[A[i]] = 1;
    }
    int sum = 0;
    for (int i = 0; i < 101; i++)
    {
        sum += counter[i];
    }
    cout << sum << endl;
    return 0;
}