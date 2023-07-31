package stackJava;
// question Previous Smaller Element 

import java.util.Stack;

public class prevSmllEle {

    public static void main(String[] args) {
        int arr[] = { 4, 10, 5, 18, 3, 12, 7 };
        // previousSmallerElement(arr);

        int arr2[] = { 3, 10, 5, 1, 15, 10, 7, 6 };
        nextSmallerElement(arr2);

    }

    // ! Previous smaller Element
    static void previousSmallerElement(int a[]) {
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < a.length; i++) {
            while (!s.isEmpty() && s.peek() >= a[i]) {
                s.pop();
            }

            if (s.isEmpty()) {
                System.out.print(-1 + " ");
            } else {
                System.out.print(s.peek() + " ");

            }
            s.push(a[i]);
        }
    }

    // !Next smaller Element
    static void nextSmallerElement(int a[]) {
        // todo 3 10 5 1 15 10 7 6
        // todo 1 5 1 -1 10 7 6 -1

        int res[] = new int[a.length];
        int k = a.length - 1;
        Stack<Integer> s = new Stack<>();

        for (int i = a.length - 1; i >= 0; i--) {
            while (!s.isEmpty() && s.peek() >= a[i]) {
                s.pop();
            }

            if (s.isEmpty()) {
                // System.out.print(-1 + " ");
                res[k--] = -1;
            } else {
                // System.out.print(s.peek()+" ");
                res[k--] = s.peek();
            }
            s.push(a[i]);
        }

        printArr(res);
    }

    // !print tha array
    static void printArr(int arr[]) {
        for (int a : arr) {
            System.out.print(a + " ");
        }
    }
}
