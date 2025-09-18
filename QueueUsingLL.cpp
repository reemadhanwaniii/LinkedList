#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    Node *start,*end;
    int count;
    
    
public:
    Queue() {
        this->start = nullptr;
        this->end = nullptr;
        count = 0;
    }
    
    void enqueue(int data) {
        Node *node = new Node(data);
        count++;
        if(end == nullptr) {
           start = node;   
           end = node; 
           return;
        }
        end->next = node;
        end = node;
    }
    
    int dequeue() {
        if(start == nullptr) {
            cout<<"Queue underflow";
            return 0;
        }
        count--;
        Node *node = start;
        start = start->next;
        int val = node->data;
        if (start == nullptr) end = nullptr;
        delete(node);
        return val;
    }
    
    int peek() {
        if(start == nullptr) {
            cout<<"Queue Underflow";
            return 0;
        }
        return start->data;
    }
    
    int size() {
        return count;
    }
    
    bool empty() {
        return (count == 0);
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl;   // 10
    cout << "Size: " << q.size() << endl;    // 3

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    cout << "Dequeued: " << q.dequeue() << endl; // 30
    cout << "Dequeued: " << q.dequeue() << endl; // Underflow

    return 0;
}
