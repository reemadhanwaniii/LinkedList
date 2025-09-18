#include<bits/stdc++.h>
using namespace std;

class Queue {
  int front,rear,capacity;
  int *arr;
  
 public:
    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = -1;
        capacity = size;
    }
    ~Queue() {
        delete[] arr;
    }
    
    void enqueue(int ele) {
        if(rear == capacity) {
            cout<<"Queue Overflow";
            return;
        }
        arr[++rear] = ele;
    }
    
    int dequeue() {
        if(front > rear) {
            cout<<"Queue underflow";
            return -1;
        }
        return arr[front++];
    }
    
    int peek() {
        if(front > rear) {
            cout<<"Queue Empty";
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return front > rear;
    }
    
    int size() {
        return rear-front+1;
    }
};


int main() {
    
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;   // 10
    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Underflow

    return 0;
    return 0;
}
