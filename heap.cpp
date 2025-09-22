#include <iostream>
using namespace std;

class Heap {
    int *arr;      
    int capacity;  
    int size;      
    bool isMax;    
public:
    Heap(int cap, bool maxHeap = true) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
        isMax = maxHeap;
    }

 
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    
    bool compare(int a, int b) {
        return isMax ? (a > b) : (a < b);
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full!\n";
            return;
        }
        arr[size] = key;
        int i = size;
        size++;

        
        while (i != 0 && compare(arr[i], arr[parent(i)])) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int best = i;

        if (l < size && compare(arr[l], arr[best])) best = l;
        if (r < size && compare(arr[r], arr[best])) best = r;

        if (best != i) {
            swap(arr[i], arr[best]);
            heapify(best);
        }
    }

   
    int extractRoot() {
        if (size <= 0) return -1;
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }

   
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Max Heap Implementation:\n";
    Heap maxHeap(10, true);

    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Heap elements: ";
    maxHeap.display();

    cout << "Extracted Root: " << maxHeap.extractRoot() << endl;

    cout << "Heap after extraction: ";
    maxHeap.display();

    cout << "\nMin Heap Implementation:\n";
    Heap minHeap(10, false);

    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Heap elements: ";
    minHeap.display();

    cout << "Extracted Root: " << minHeap.extractRoot() << endl;

    cout << "Heap after extraction: ";
    minHeap.display();

    return 0;
}
