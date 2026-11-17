#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100];

    cout << "Enter the cost adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    bool selected[100] = {false};

    selected[0] = true;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = 9999;
        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " = " << min << endl;

        totalCost += min;
        selected[y] = true;

        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}