#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};


class CircularLL {
    Node *head,*tail;
    
    public:
        CircularLL() {
            head = nullptr;
            tail = nullptr;
        }
        
        void addAtHead(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                head->next=node;
                tail = head;
                return;
            }
            node->next = head;
            tail->next = node;
            head = node;
        }
        
        void addAtTail(int data) {
            if(tail == nullptr) {
                addAtHead(data);
            }
            
            Node *node = new Node(data);
            tail->next = node;
            node->next = head;
            tail = node;
        }
        
        void printCLL() {
            Node *temp = head;
            while(temp->next != head) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
        
        void displayCLL() {
            Node *temp = head;
            while(temp != tail) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
        
        int lengthOfCLL() {
            int count = 1;
            Node *temp = head;
            while(temp != tail) {
                count++;
                temp = temp->next;
            }
            return count;
        }
        
        void removeAtHead() {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete(temp);
        }
        
        void removeAtTail() {
            Node *temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            delete(tail);
            temp->next = head;
            tail = temp;
        }
        
        void addAtNthPos(int n,int data) {
            Node *node = new Node(data);
            Node *temp = head;
            int count = 0;
            Node *prev;
            while(count!=(n-1)) {
                count++;
                prev = temp;
                temp=temp->next;
            }
            prev->next = node;
            node->next = temp;
        }
        
        void removeAtNthPos(int n) {
            
            Node *temp = head;
            int count = 0;
            Node *prev;
            while(count!=(n-1)) {
                count++;
                prev = temp;
                temp=temp->next;
            }
            prev->next = temp->next;
            delete(temp);
        }
};

int main() {
    CircularLL *obj = new CircularLL();
    obj->addAtHead(12);
    obj->addAtHead(11);
    obj->addAtHead(10);
    obj->addAtHead(9);
    obj->addAtTail(13);
    obj->addAtTail(14);
    obj->addAtTail(15);
    cout<<"length of CLL "<<obj->lengthOfCLL()<<endl;
    obj->printCLL();
    obj->displayCLL();
    obj->removeAtTail();
    obj->removeAtHead();
    obj->addAtNthPos(4,5555);
    obj->removeAtNthPos(4);
    obj->printCLL();
    return 0;
}
