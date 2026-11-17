#include <iostream>
using namespace std;

class MergeSort
{
public:
    int size, arr[100], i;

    void arrayinput()
    {
        cout << "Enter array size: ";
        cin >> size;

        cout << "Enter array elements:\n";
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void printarray()
    {
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void merge(int low, int mid, int high)
    {
        int temp[100];
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        while (j <= high)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }

        for (i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        }
    }

    void mergelogic(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;

            mergelogic(low, mid);
            mergelogic(mid + 1, high);

            merge(low, mid, high);
        }
    }
};

int main()
{
    MergeSort ms;

    ms.arrayinput();

    cout << "Before sorting: ";
    ms.printarray();

    ms.mergelogic(0, ms.size - 1);

    cout << "After sorting: ";
    ms.printarray();

    return 0;
}