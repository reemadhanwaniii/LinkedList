#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    
   
        Node(int data) {
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
};

class doubleLinkedList {
    Node *head;
    public: 
        doubleLinkedList() {
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
            node->prev = temp;
            temp->next = node;
        }
        
        void addAtHead(int data) {
            Node *node = new Node(data);
            if(head == nullptr) {
                head = node;
                return;
            }
            
            head->prev = node;
            node->next = head;
            head = node;
        }
        
        void addAtTail(int data) {
            addNode(data);
        }
        
        void printDLL() {
            Node *temp = head;
            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        
        int lengthOfDLL() {
            Node *temp = head;
            int count = 0;
            
            while(temp != nullptr) {
                count++;
                temp = temp->next;
            }
            return count;
        }
        
        void printHead() {
            cout<<head->data<<"\n";
        }
        
        void addAtNthPos(int n,int data) {
            int count = 0;
            Node *node = new Node(data);
            Node *temp=head,*prevv;
            while(count != (n-1)) {
                prevv = temp;
                temp=temp->next;
                count++;
            }
            node->prev = prevv;
            node->next = temp;
            prevv->next = node;
            temp->prev=node;
        }
        
        void removeAtHead() {
            Node *temp = head;
            head->next->prev = nullptr;
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
            Node *temp = head->next;
            Node *prevv = head;
            
            while(true) {
                if(temp->data == data) {
                    prevv->next = temp->next;
                    temp->next->prev = prevv;
                    delete(temp);
                    return;
                }    
                prevv = temp;
                temp = temp->next;
            }
        }
        
        void removeAtNthPos(int n) {
            int count = 0;
            Node *temp=head,*prevv;
            while(count != (n-1)) {
                prevv = temp;
                temp=temp->next;
                count++;
            }
            prevv->next = temp->next;
            temp->next->prev = prevv;
            delete(temp);
        }
};

int main() {
    doubleLinkedList *obj = new doubleLinkedList();
    obj->addNode(12);
    obj->addNode(13);
    obj->addNode(14);
    obj->addNode(15);
    obj->addNode(16);
    obj->printDLL();
    obj->printHead();
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtTail(7);
    obj->addAtTail(8);
    obj->addAtTail(9);
    obj->printDLL();
    cout<<"length of DLL : "<<obj->lengthOfDLL()<<endl;
    obj->addAtNthPos(5,1555);
    obj->printDLL();
    obj->removeAtHead();
    obj->removeAtTail();
    obj->removeData(13);
    obj->removeAtNthPos(4);
    obj->printDLL();
    return 0;
}
