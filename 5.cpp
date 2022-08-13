/*
Given an integer array A with size N and an integer Q for queries, where
(0 <  N < 10^5) , (-10^7 < Ai  < 10^7) and (0 < Q < 10^7) .
Write a program using prefix sum concept to find the sum of positive integers from a given range L to R for each query. (1 <= L,R <= N)

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
1 -2 3 -4 5 6
3
1 3
4 6
2 4

Sample output:
4
11
3

*/

#include <iostream>
using namespace std;

int main(void)
{
    int N, Q;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int pre[N];
    int flag = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= 0)
        {
            pre[0] = arr[i];
            flag = 1;
            break;
        }
    }

    pre[0] = arr[0] >= 0 ? arr[0] : 0;

    if (flag == 0)
    {
        cout << "All numbers are negative in the array" << endl;
    }
    else
    {
        cin >> Q;
        for (int i = 1; i < N; i++)
        {
            if (arr[i] >= 0)
            {
                pre[i] = pre[i - 1] + arr[i];
            }
            else
            {
                pre[i] = pre[i - 1];
            }
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
    }

    return 0;
}