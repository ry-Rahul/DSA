#include <bits/stdc++.h>
using namespace std;

class twostack
{
    public:
        int top1 ;
        int top2 ;
        int size;
        int *arr;
    
    twostack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int data);
    void push2(int data);
    int pop1();
    int pop2();
    int peek1();
    int peek2();
};
void twostack::push1(int data)
{
      if(top2 - top1 >1)
      {
        top1++;
        arr[top1] = data;
      }
      else
          cout << "stack is overflow" << endl;
}

void twostack::push2(int data)
{
    if (top2 - top1 > 1)
    {
        top2--;
        arr[top2] = data;
    }
    else
        cout << "stack is overflow" << endl;
}

int twostack::pop1()
{
        int ans;
    if(top1>=0)
       { 
        ans = arr[top1];
        top1--;
        return ans;
        }
    else
        return -1;
}

int twostack::pop2()
{
    int ans;
    if (top2 < size)
    {
        ans = arr[top2];
        top2++;
        return ans;
    }
    else
        return -1;
}

int twostack::peek1()
{
    if (top2 >=0 )
        return arr[top1];
    else
        return -1;
}

int twostack::peek2() 
{
    if(top2<size)
        return arr[top2];
    else
        return -1;
}
int main()
{
    twostack st(10);

    st.push1(45);
    st.push1(89);
    st.push1(23);

    st.push2(5);
    st.push2(2);
    st.push2(3);
    st.push2(55);

    cout << st.peek1() << endl;
    cout << st.peek2() << endl;
    st.pop1();
    cout << st.peek1() << endl;
}