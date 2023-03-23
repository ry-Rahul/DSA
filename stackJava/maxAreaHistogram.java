package stackJava;

import java.util.Stack;

public class maxAreaHistogram {
    public static void main(String[] args) {
        int arr[] = { 4, 2, 1, 5, 6, 3, 2, 4, 2 };
        printArr(arr);
        System.out.println();
        System.out.println("Maximum area is " + maxArea(arr));
      
    
    }

    static int maxArea(int a[]) {
        int maxAns = 0;
        int ps[] = prevSmallElem(a);
        int ns[] = nxtSmallElem(a);
        for (int i = 0; i < ps.length; i++) {
            int curr = (ns[i] - ps[i] - 1) * a[i];
            maxAns = Math.max(maxAns, curr);
        }
        return maxAns;
    }

    static int[] prevSmallElem(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int prev[] = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            while (!stack.isEmpty() && arr[i] <= arr[stack.peek()]) {
                stack.pop();

            }
            if (stack.isEmpty()) {
                prev[i] = -1;
            } else {
                prev[i] = stack.peek();
            }
            stack.push(i);
        }
        return prev;
    }

    static int[] nxtSmallElem(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int nxt[] = new int[arr.length];
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[i] <= arr[stack.peek()]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                nxt[i] = arr.length;
            } else {
                nxt[i] = stack.peek();
            }
            stack.push(i);
        }
        return nxt;
    }

    static void printArr(int[] arr) {
        for (int a : arr) {
            System.out.print(a + " ");
        }
    }
}