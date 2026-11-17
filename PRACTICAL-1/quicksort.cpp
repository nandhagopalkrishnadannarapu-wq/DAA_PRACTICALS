#include <iostream>
#include <utility>
using namespace std;

class QuickSort
{
public:
    int size, arr[100];

    void arrayinput()
    {
        cout << "Enter array size: ";
        cin >> size;

        cout << "Enter array elements: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void printarray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int partition(int lb, int ub)
    {
        int pivot = arr[lb];
        int start = lb;
        int end = ub;

        while (start < end)
        {
            while (start <= ub && arr[start] <= pivot)
                start++;

            while (arr[end] > pivot)
                end--;

            if (start < end)
                swap(arr[start], arr[end]);
        }

        swap(arr[lb], arr[end]);
        return end;
    }

    void quicksortlogic(int lb, int ub)
    {
        if (lb < ub)
        {
            int loc = partition(lb, ub);
            quicksortlogic(lb, loc - 1);
            quicksortlogic(loc + 1, ub);
        }
    }

    void sort()
    {
        quicksortlogic(0, size - 1);
    }
};

int main()
{
    QuickSort qs;

    qs.arrayinput();

    cout << "Before sorting: ";
    qs.printarray();

    qs.sort();

    cout << "After sorting: ";
    qs.printarray();

    return 0;
}