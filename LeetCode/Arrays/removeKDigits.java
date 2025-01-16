import java.util.Stack;

class Solution {
    public String removeKdigits(String num, int k) {

        if (num.length() == k)
            return "0";
        
        Stack<Character> stack = new Stack<>();
        int i = 0;
        
        while (i < num.length()) {
            while (k > 0 && !stack.isEmpty() && stack.peek() > num.charAt(i)) {
                stack.pop();
                k--;
            }
            stack.push(num.charAt(i));
            i++;
        }

        // if k is not zero, then pop the remaining elements from the stack
    //    eg = 12345, k = 2
        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }
        
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        sb.reverse();
        
        // remove the leading zeros
        while (sb.length() > 1 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        return sb.toString();
    }
}
public class removeKDigits {
    public static void main(String[] args) {
        String num = "001";
        int k = 3;
        Solution obj = new Solution();
        String ans = obj.removeKdigits(num, k);
        System.out.println(ans);
    }
}
