#include<bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyCircularLL {
    Node *head,*tail;
    
    public:
        DoublyCircularLL() {
            head = nullptr;
            tail = nullptr;
        }
        
        void addAtHead(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                head->next=node;
                tail = head;
                head->prev = tail;
                return;
            }
            head->prev = node;
            node->prev = tail;
            node->next = head;
            tail->next = node;
            head = node;
        }
        
        void addAtTail(int data) {
            if(tail == nullptr) {
                addAtHead(data);
            }
            
            Node *node = new Node(data);
            node->prev = tail;
            tail->next = node;
            node->next = head;
            head->prev = node;
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
            head->prev = tail;
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
            head->prev = tail;
        }
        
        void addAtNthPos(int n,int data) {
            Node *node = new Node(data);
            Node *temp = head;
            int count = 0;
            Node *prevv;
            while(count!=(n-1)) {
                count++;
                prevv = temp;
                temp=temp->next;
            }
            prevv->next = node;
            node->prev=prevv;
            node->next = temp;
            temp->prev = node;
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
            temp->next->prev = prev;
            delete(temp);
        }
};

int main() {
    DoublyCircularLL *obj = new DoublyCircularLL();
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
