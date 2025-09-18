#include<bits/stdc++.h>
using namespace std;


class stImpl {
  vector<int> st;
  int top;
 public:
  stImpl(int size) {
      st.resize(size);
      top = -1;
  }
  
  void push(int ele) {
      if(top == st.size()) {
          cout<<"Stack overflow";
          return;
      }
      st[++top] = ele;
      return;
  }
  
  int top_() {
      if(top == -1) {
          cout<<"Empty";
          return -1;
      }
      return st[top];
  }
  
  int size() {
      if(top == -1) {
          cout<<"Stack Empty";
          return -1;
      }
      return top+1;
  }
  int pop() {
      if(top == -1) {
          cout<<"Empty";
          return -1;
      }
      return st[top--];
  }
};

int main() {
stImpl obj(10);
obj.push(10);
obj.push(20);
obj.push(30);

std::cout<<obj.size()<<endl;
std::cout<<obj.top_()<<endl;
std::cout<<obj.pop()<<endl;
std::cout<<obj.pop()<<endl;
std::cout<<obj.pop()<<endl;
std::cout<<obj.pop()<<endl;
return 0;
}
