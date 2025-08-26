#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = nullptr;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    void insertTerm(int coeff, int power) {
        if (coeff == 0) return;
        Node* newNode = new Node(coeff, power);
        if (head == nullptr || head->power < power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp != nullptr && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != nullptr && temp->power == power) {
                temp->coeff += coeff;
                delete newNode;
            } else {
                newNode->next = temp;
                if (prev != nullptr) prev->next = newNode;
                else head = newNode;
            }
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "0";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next != nullptr && temp->next->coeff >= 0) cout << " + ";
            temp = temp->next;
        }
    }

    static Polynomial multiply(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        for (Node* t1 = p1.head; t1 != nullptr; t1 = t1->next) {
            for (Node* t2 = p2.head; t2 != nullptr; t2 = t2->next) {
                int coeffProduct = t1->coeff * t2->coeff;
                int powerSum = t1->power + t2->power;
                result.insertTerm(coeffProduct, powerSum);
            }
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2, product;
    int n, coeff, power;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> power;
        p1.insertTerm(coeff, power);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> power;
        p2.insertTerm(coeff, power);
    }

    cout << "First Polynomial: ";
    p1.display();
    cout << endl;

    cout << "Second Polynomial: ";
    p2.display();
    cout << endl;

    product = Polynomial::multiply(p1, p2);

    cout << "Product of Polynomials: ";
    product.display();
    cout << endl;

    return 0;
}
