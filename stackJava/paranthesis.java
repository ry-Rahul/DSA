package stackJava;

import java.util.Stack;
public class paranthesis {
    public static void main(String[] args) {
       paranthesis p = new paranthesis();
        System.out.println(p.isParanthesIsMatching("()"));
        System.out.println(p.isParanthesIsMatching("()[]{}"));
        System.out.println(p.isParanthesIsMatching("(]"));
        System.out.println(p.isParanthesIsMatching("([)]"));
        System.out.println(p.isParanthesIsMatching("{[]}"));
    }
    
    boolean isParanthesIsMatching(String str) {
        Stack<Character> s = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char curr = str.charAt(i);
            if (isOpening(curr)) {
                s.push(curr);
            } else {
                if (s.isEmpty()) {
                    return false;
                } else if (!isMatching(s.peek(), curr)) {
                    return false;
                } else {
                    s.pop();
                }
            }
        }
        return s.isEmpty();
    }

    boolean isOpening(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    boolean isMatching(char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') ||( a == '{'&& b == '}');
    }
}
