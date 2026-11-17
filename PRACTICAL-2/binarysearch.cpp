#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int search)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (search == arr[mid])
        {
            return mid;
        }
        else if (search < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int size, arr[100], search, result;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " elements in sorted order: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> search;

    result = BinarySearch(arr, size, search);

    if (result != -1)
    {
        cout << "Element found at position " << result + 1;
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}