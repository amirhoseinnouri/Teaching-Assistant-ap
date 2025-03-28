#include <iostream>
using namespace std;
class BubbleSort {
private:
    int* arr;
    int size;
public:
    BubbleSort(int* array, int n) : arr(array), size(n) {}
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
    int* getSortedArray() const {
        return arr;
    }
};
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "array before sort : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    BubbleSort bubbleSorter(arr, n);
    bubbleSorter.sort();
    cout << "array after sort : ";
    bubbleSorter.display();
}