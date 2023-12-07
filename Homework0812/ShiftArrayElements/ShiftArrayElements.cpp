#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    int arr[SIZE]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int firstElement = arr[0];

    for (int i = 0; i < SIZE; i++) {
        if (i == SIZE - 1) {
            arr[SIZE - 1] = firstElement;
        }
        else {
            arr[i] = arr[i + 1];
        }
    }

    // print the updated array
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
