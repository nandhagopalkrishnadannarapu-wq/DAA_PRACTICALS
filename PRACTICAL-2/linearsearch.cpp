#include <iostream>
using namespace std;

int main()
{
    int size, arr[100], key, i;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> key;

    i = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            break;
        }
    }

    if (i == size)
    {
        cout << "Element not found";
    }

    return 0;
}