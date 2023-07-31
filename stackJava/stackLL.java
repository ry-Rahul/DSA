package stackJava;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class myStack {
    int size;
    Node head;
    // ! constructor
    public myStack() {
        this.size = 0;
        this.head = null;
    }
    // ! push
    void push(int data) {
        Node temp = new Node(data);
        temp.next = head;
        head = temp;
        size++;
    }
    // ! peek 
    int peek() {
        if (head == null) {
            System.out.println("stack underflow");
            return -1;
        }
        return head.data;
    }
    // ! pop
    int pop() {
        if (head == null) {
            System.out.println("stack underflow");
            return -1;
        }
        int res = head.data;
        head = head.next;
        size--;
        return res;

    }
    // ! isEmpty
    boolean isEmpty() {
        return head == null;
    }
    // ! size
    int size() {
        return size;
    }
}

public class stackLL {
     public static void main(String[] args) {
        // stack 
        myStack stack = new myStack();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
        System.out.println(stack.size());
        System.out.println(stack.isEmpty());
     }
}

