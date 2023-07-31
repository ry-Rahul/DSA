package stackJava;

import java.util.Stack;

class Solution {
    public int longestValidParentheses(String s) {
        int max = 0;
        Stack<Integer> index = new Stack<>();
        Stack<Character> c = new Stack<>();
        index.push(-1);

        char ch;

        for (int i = 0; i < s.length(); i++) {
            ch = s.charAt(i);
            if (ch == '(') {
                c.push(ch);
                index.push(i);
            } else {
                if (!c.isEmpty() && c.peek() == '(') {
                    c.pop();
                    index.pop();
                    max = Math.max(max, i - index.peek());
                } else {
                    index.push(i);
                }
            }
        }
        return max;
    }
}

//
public class longestValidParanthesis {

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "((())";
        System.out.println(sol.longestValidParentheses(s));
    }
}