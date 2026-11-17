#include <iostream>
using namespace std;

int main()
{
    int n;
    int p[100], c[100][100];

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        c[i][i] = 0;

    for (int d = 1; d < n; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;

            int min = 999999999;

            for (int k = i; k < j; k++)
            {
                int q = c[i][k]
                      + c[k + 1][j]
                      + p[i - 1] * p[k] * p[j];

                if (q < min)
                    min = q; 
            }

            c[i][j] = min;
        }
    }

    cout << "Minimum number of scalar multiplications: "
         << c[1][n] << endl;

    return 0;
}