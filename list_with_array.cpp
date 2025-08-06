#include <iostream>
using namespace std;

#define MAX 100

void display(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertFirst(int arr[], int &size, int value) {
    if (size >= MAX) {
        cout << "Array is full!" << endl;
        return;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void insertLast(int arr[], int &size, int value) {
    if (size >= MAX) {
        cout << "Array is full!" << endl;
        return;
    }
    arr[size++] = value;
}

void insertByPosition(int arr[], int &size, int value, int pos) {
    if (size >= MAX || pos < 0 || pos > size) {
        cout << "Invalid position or array is full!" << endl;
        return;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
}

void deleteFirst(int arr[], int &size) {
    if (size <= 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteLast(int arr[], int &size) {
    if (size <= 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    size--;
}

void deleteByPosition(int arr[], int &size, int pos) {
    if (size <= 0 || pos < 0 || pos >= size) {
        cout << "Invalid position or array is empty!" << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void searchByIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element found at index " << i << endl;
        }
    }
}

int main() {
    int arr[MAX] = {10, 20, 30, 40, 50};
    int size = 5;
    int choice, value, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at First\n";
        cout << "2. Insert at Last\n";
        cout << "3. Insert by Position\n";
        cout << "4. Delete at First\n";
        cout << "5. Delete at Last\n";
        cout << "6. Delete by Position\n";
        cout << "7. Search by Index\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at first: ";
            cin >> value;
            insertFirst(arr, size, value);
            break;
        case 2:
            cout << "Enter value to insert at last: ";
            cin >> value;
            insertLast(arr, size, value);
            break;
        case 3:
            cout << "Enter value and position (0-based) to insert: ";
            cin >> value >> pos;
            insertByPosition(arr, size, value, pos);
            break;
        case 4:
            deleteFirst(arr, size);
            break;
        case 5:
            deleteLast(arr, size);
            break;
        case 6:
            cout << "Enter position (0-based) to delete: ";
            cin >> pos;
            deleteByPosition(arr, size, pos);
            break;
        case 7:
            cout << "Enter the element to search: ";
            cin >> pos;
            searchByIndex(arr, size, pos);
            break;
        case 8:
            display(arr, size);
            break;
        case 9:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
}