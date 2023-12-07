#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int arr[SIZE]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int k, value;

    cout << "Enter the position to insert (0 - " << SIZE - 1 << "): ";
    cin >> k;
    cout << "Enter the value to insert: ";
    cin >> value;

    // shift elements to the right from k to SIZE-2
    for (int i = SIZE - 2; i >= k; i--) {
        arr[i + 1] = arr[i];
    }

    // insert the value at k
    arr[k] = value;

    // print the updated array
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
