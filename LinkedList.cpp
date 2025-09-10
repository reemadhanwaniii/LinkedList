#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int data) {
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {
    Node *head;
    
    public:
        LinkedList(){
            head = nullptr;
        }
        
        void addNode(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                return;
            }
            
            Node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
        
        void printLinkedList() {
            Node *temp = head;
            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        
        
        void addAtTail(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                return;
            }
            Node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
        
        void addAtHead(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                return;
            } 
            node->next=head;
            head = node;
        }
        
        void removeAtHead() {
            Node *temp = head;
            head = head->next;
            delete(temp);
        }
        
        
        void removeAtTail() {
            Node *temp = head;
            while(temp->next->next != nullptr) {
                temp = temp->next;
            }
            Node *tail = temp->next;
            temp->next = nullptr;
            delete(tail);
        }
        
        void removeData(int data) {
            Node *prev = head;
            Node *temp = head->next;
            while(true) {
                if(temp->data == data) {
                    prev->next = temp->next;
                    delete(temp);
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }
};

int main() {
    LinkedList *obj = new LinkedList();
    obj->addNode(78);
    obj->addNode(65);
    obj->addNode(12);
    obj->addNode(43);
    obj->addNode(54);
    obj->addNode(32);
    obj->addNode(49);
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtTail(4);
    obj->addAtTail(5);
    obj->addAtTail(6);
    obj->printLinkedList();
    obj->removeAtHead();
    obj->removeAtTail();
    obj->removeData(49);
    
    obj->printLinkedList();
    return 0;
}
