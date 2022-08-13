/*
Given a matrix A with dimension n*m. Write a program to print the sum of the elements where the rows are even and the columns are odd .
          Sample input:
          3 3
          1 2 3
          4 5 6
          7 8 9
         Sample output:
         10
[Here ,highlighted  4 is located in the 2nd row and 1st column , 6 is located in         the 2nd row  and 3rd column. ]
*/

#include <iostream>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2 != 0 && j % 2 == 0)
            {
                sum += arr[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}