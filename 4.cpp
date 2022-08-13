/*
Given an integer array A with size N and an integer Q for queries, where 0< N,Q < 10^6.
Write a program using prefix sum concept to find the sum of a given range L to R for each query. (1 <= L,R <= N and L <= R)
N
A1 A2 A3…….AN
Q
L1  R1
L2  R2
.    .
.     .
LQ  RQ
Sample input:
6
1 2 3 4 5 6
3
1 3
4 6
2 4

Sample output:
6
15
9
*/

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int Q;
    cin >> Q;

    int pre[N];
    pre[0] = arr[0];

    for (int i = 1; i < N; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    int answers[Q];
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > 1)
        {
            answers[i] = pre[r - 1] - pre[l - 2];
        }
        else
        {
            answers[i] = pre[r - 1];
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}