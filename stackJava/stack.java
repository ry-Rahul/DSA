package stackJava;

/**
 * stack
 */
class myStack {
    int arr[];
    int top;
    int capacity;
    // ! constructor
    public myStack(int capacity) {
        this.capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    // ! push
    void push(int data) {
        if (top == capacity - 1) {
            System.out.println("stack overflow");
            return;
        }
        arr[++top] = data;
    }
    // ! pop
    int pop() {
        if (top == -1) {
            System.out.println("stack underflow");
            return -1;
        }
        int res = arr[top--];
        return res;

    }
    // ! peek
    int peek() {
        if (top == -1) {
            System.out.println("stack underflow");
            return -1;
        }
        return arr[top];
    }
    // ! isEmpty
    boolean isEmpty() {
        return top == -1;
    }

    // ! size
    int size() {
        return top + 1;
    }

}
public class stack {

    public static void main(String[] args) {
        // stack 
        myStack stack = new myStack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);
        System.out.println("size: " + stack.size());
        System.out.println("peek: " + stack.peek());
        stack.pop();
        System.out.println("peek: " + stack.peek());

    }
}