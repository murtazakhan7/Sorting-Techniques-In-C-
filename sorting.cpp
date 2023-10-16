#include <iostream>
#include <ctime>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
        cout << "After " << i + 1 << " Step\n";
        display(arr, n);
        cout << endl;
    }
}

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            cout << "After " << i + 1 << " Step\n";
            display(arr, n);
            cout << endl;
        }
    }
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            cout << "After " << i + 1 << " Step\n";
            display(arr, n);
            cout << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    int op;
    clock_t start, end;

    do {
        cout << "Select Sorting Technique\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Exit\n";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Bubble Sort\n";
                start = clock();
                bubblesort(arr, n);
                end = clock();
                cout << "\nAfter Sorting\n";
                display(arr, n);
                cout << "Time taken by Bubble Sort: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
                cout << "Size of the array: " << sizeof(arr) << " bytes" << endl;
                break;

            case 2:
                cout << "Insertion Sort\n";
                start = clock();
                insertionsort(arr, n);
                end = clock();
                cout << "\nAfter Sorting\n";
                display(arr, n);
                cout << "Time taken by Insertion Sort: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
                cout << "Size of the array: " << sizeof(arr) << " bytes" << endl;
                break;

            case 3:
                cout << "Selection Sort\n";
                start = clock();
                selectionsort(arr, n);
                end = clock();
                cout << "\nAfter Sorting\n";
                display(arr, n);
                cout << "Time taken by Selection Sort: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
                cout << "Size of the array: " << sizeof(arr) << " bytes" << endl;
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;
            
            default:
                cout << "Invalid option. Please choose a valid sorting technique or exit.\n";
        }
    } while (op != 4);

    return 0;
}
