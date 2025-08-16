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

    void insertAtFirst(int value) {
        int newNode = getFreeNode();
        if (newNode == -1) {
            cout << "List is full!" << endl;
            return;
        }
        nodes[newNode].data = value;
        nodes[newNode].next = head;
        head = newNode;
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

    void insertByPosition(int value, int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            insertAtFirst(value);
            return;
        }
        int newNode = getFreeNode();
        if (newNode == -1) {
            cout << "List is full!" << endl;
            return;
        }
        int temp = head;
        for (int i = 0; i < pos - 1 && temp != -1; i++) {
            temp = nodes[temp].next;
        }
        if (temp == -1) {
            cout << "Position out of range!" << endl;
            nodes[newNode].next = freeIndex;
            freeIndex = newNode;
            return;
        }
        nodes[newNode].data = value;
        nodes[newNode].next = nodes[temp].next;
        nodes[temp].next = newNode;
    }

    void deleteFirst() {
        if (head == -1) {
            cout << "List is empty!" << endl;
            return;
        }
        int temp = head;
        head = nodes[head].next;
        nodes[temp].next = freeIndex;
        freeIndex = temp;
    }

    void deleteLast() {
        if (head == -1) {
            cout << "List is empty!" << endl;
            return;
        }
        if (nodes[head].next == -1) {
            deleteFirst();
            return;
        }
        int prev = -1, curr = head;
        while (nodes[curr].next != -1) {
            prev = curr;
            curr = nodes[curr].next;
        }
        nodes[prev].next = -1;
        nodes[curr].next = freeIndex;
        freeIndex = curr;
    }

    void deleteByPosition(int pos) {
        if (pos < 0 || head == -1) {
            cout << "Invalid position or list empty!" << endl;
            return;
        }
        if (pos == 0) {
            deleteFirst();
            return;
        }
        int prev = -1, curr = head;
        for (int i = 0; i < pos && curr != -1; i++) {
            prev = curr;
            curr = nodes[curr].next;
        }
        if (curr == -1) {
            cout << "Position out of range!" << endl;
            return;
        }
        nodes[prev].next = nodes[curr].next;
        nodes[curr].next = freeIndex;
        freeIndex = curr;
    }

    void search(int value) {
        int temp = head;
        int pos = 0;
        while (temp != -1) {
            if (nodes[temp].data == value) {
                cout << "Value found at position " << pos << endl;
                return;
            }
            temp = nodes[temp].next;
            pos++;
        }
        cout << "Value not found!" << endl;
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
    int choice, value, pos;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at First\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert by Position\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete by Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtFirst(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertByPosition(value, pos);
                break;
            case 4:
                list.deleteFirst();
                break;
            case 5:
                list.deleteLast();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteByPosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
