#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (temp->data == value) {
            head = temp->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value;
    while (true) {
        cout << "\n1. Insert at Front\n2. Insert at End\n3. Delete Node\n4. Display Forward\n5. Display Backward\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertFront(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertEnd(value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteNode(value);
                break;
            case 4:
                dll.displayForward();
                break;
            case 5:
                dll.displayBackward();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
