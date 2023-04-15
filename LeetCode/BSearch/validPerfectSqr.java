class Solution {
    public boolean isPerfectSquare(int num) {
       int low = 1;
       int high = num;

     while (low <= high) {
        long mid = (low + high) / 2;
        if (mid * mid == num) return true;
        else if (mid * mid < num)
             low = (int) mid + 1;
         else
             high = (int) mid - 1;
    }
        return false;
    }
    
}

public class validPerfectSqr {
    
    public static void main(String[] args) {
        int num = 16;
        Solution obj = new Solution();
        boolean ans = obj.isPerfectSquare(num);
        System.out.println(ans);
    }
}
