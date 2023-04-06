// package QueueJava;

// class Node  
class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

// class queue 
class queue {
    Node front, rear;

    void enqueue(int data) {
        Node newNode = new Node(data);
        if (front == null) {
            front = rear = newNode;
            return;
        }
        rear.next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == null) {
            return -1;
        }
        int result = front.data;
        front = front.next;
        return result;
    }

    int frontData() {
        if (front == null) {
            return -1;
        }
        return front.data;
    }

    int rearData() {
        if (front == null) {
            return -1;
        }
        return rear.data;
    }
}

public class QueuLL {
    
    public static void main(String[] args) {
        queue q = new queue();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());

        System.out.println("rear data is " + q.rearData());
        System.out.println("front data is " + q.frontData());

    }
}
