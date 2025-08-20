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
        Node* newNode = new Node(coeff, power);
        if (head == nullptr || head->power < power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->power >= power) {
                temp = temp->next;
            }
            if (temp->power == power) {
                temp->coeff += coeff;
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
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

    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* t1 = p1.head;
        Node* t2 = p2.head;

        while (t1 != nullptr && t2 != nullptr) {
            if (t1->power == t2->power) {
                result.insertTerm(t1->coeff + t2->coeff, t1->power);
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->power > t2->power) {
                result.insertTerm(t1->coeff, t1->power);
                t1 = t1->next;
            } else {
                result.insertTerm(t2->coeff, t2->power);
                t2 = t2->next;
            }
        }
        while (t1 != nullptr) {
            result.insertTerm(t1->coeff, t1->power);
            t1 = t1->next;
        }
        while (t2 != nullptr) {
            result.insertTerm(t2->coeff, t2->power);
            t2 = t2->next;
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2, sum;
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

    sum = Polynomial::add(p1, p2);

    cout << "Sum of Polynomials: ";
    sum.display();
    cout << endl;

    return 0;
}
