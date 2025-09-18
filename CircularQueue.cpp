#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int front,rear,capacity,count;
    
public:
    CircularQueue(int size) {
        arr = new int[size];
        front = 0;
        rear = -1;
        capacity = size;
        count = 0;
    }    
    
    ~CircularQueue() {
        delete[] arr;
    }
    
    void enqueue(int ele) {
        if(count == capacity) {
            cout<<"Queue Overflow";
            return;
        }
        
        rear = (rear+1)%capacity;
        arr[rear] = ele;
        count++;
        return;
    }
    
    int dequeue() {
        if(count == 0) {
            cout<<"Queue underflow";
            return -1;
        }
        int val = arr[front];
        count--;
        front = (front+1)%capacity;
        return val;
    }
    
    int size() {
        return count;
    }
    
    int peek() {
        if(count == 0) return -1;
        return arr[front];
    }
    
    int empty() {
        return count==0;
    }
    
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20

    q.enqueue(60);
    q.enqueue(70); // Works because circular

    while (!q.empty()) {
        cout << q.dequeue() << " ";
    }
    // Output: 30 40 50 60 70

    return 0;
}
