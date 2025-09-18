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

class StackLL {
  Node *top;
  int count;
  public:
    StackLL() {
        this->top = nullptr;
        count = 0;
    }
    
    void push(int data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        count++;
    }  
    
    int size() {
        return count;
    }
    
    bool empty() {
        return (count == 0);
    }
    
    int top_() {
        if(top == nullptr) {
            cout<<"Empty";
            return -1;
        }
        return top->data;
    }
    
    int pop() {
        if(top == nullptr) {
            cout<<"Empty";
            return -1;
        }
        Node *node = top;
        int val = node->data;
        top = top->next;
        count--;
        delete(node);
        return val;
    }
    
};

int main() {
    StackLL st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top_() << endl;   // 30
    cout << "Size: " << st.size() << endl; // 3

    cout << "Popped: " << st.pop() << endl; // 30
    cout << "Popped: " << st.pop() << endl; // 20
    cout << "Popped: " << st.pop() << endl; // 10
    cout << "Popped: " << st.pop() << endl; // Underflow
    cout << "Is Empty : "<<st.empty() << endl;
    return 0;
}
