/*
Given an integer N. Write a program to print all prime numbers between 1 and N.

Sample input:
5

Sample output:
2 3 5 

*/

#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for (int num = 2; num <= N; num++)
    {
        int flag = 0;
        for (int j = 2; (j < num && flag == 0); j++)
        {
            if (num % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << num << " ";
        }
    }
    cout << endl;

    return 0;
}