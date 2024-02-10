#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        int size=q.size()-1;

        while(size>0){
            int front=q.front();
            q.pop();
            q.push(front);
            size--;
        }
    }
    
    int pop() {

        int temp=q.front();
        q.pop();
        return temp;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }
};
int main(){
  

  return 0;
}