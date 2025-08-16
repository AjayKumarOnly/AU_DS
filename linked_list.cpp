#include <iostream>
using namespace std;

#define MAX 10

struct Node {
    int data;
    int next;
};

class LinkedListArray {
    Node nodes[MAX];
    int head;
    int freeIndex;

public:
    LinkedListArray() {
        head = -1;
        freeIndex = 0;
        for (int i = 0; i < MAX - 1; i++) {
            nodes[i].next = i + 1;
        }
        nodes[MAX - 1].next = -1;
    }

    int getFreeNode() {
        if (freeIndex == -1) return -1;
        int index = freeIndex;
        freeIndex = nodes[freeIndex].next;
        return index;
    }

    void insertAtEnd(int value) {
        int newNode = getFreeNode();
        if (newNode == -1) {
            cout << "List is full!" << endl;
            return;
        }
        nodes[newNode].data = value;
        nodes[newNode].next = -1;
        if (head == -1) {
            head = newNode;
        } else {
            int temp = head;
            while (nodes[temp].next != -1) {
                temp = nodes[temp].next;
            }
            nodes[temp].next = newNode;
        }
    }

    void deleteValue(int value) {
        if (head == -1) {
            cout << "List is empty!" << endl;
            return;
        }
        int curr = head, prev = -1;
        while (curr != -1 && nodes[curr].data != value) {
            prev = curr;
            curr = nodes[curr].next;
        }
        if (curr == -1) {
            cout << "Value not found!" << endl;
            return;
        }
        if (prev == -1) {
            head = nodes[curr].next;
        } else {
            nodes[prev].next = nodes[curr].next;
        }
        nodes[curr].next = freeIndex;
        freeIndex = curr;
    }

    void display() {
        if (head == -1) {
            cout << "List is empty!" << endl;
            return;
        }
        int temp = head;
        while (temp != -1) {
            cout << nodes[temp].data << " ";
            temp = nodes[temp].next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListArray list;
    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete by Value\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
