// package LeetCode;

import java.util.concurrent.CountDownLatch;

public class reverseString {

    public static String reverseString(String str,int k) {
        int st = 0;
        int en;
       for (int j = 0; j < str.length(); j += k) {
           st = j;
           en = j + k - 1;
           while (st < en) {
               char temp = str.charAt(st);
               str.charAt(en) = str.charAt(st);
               str.charAt(st) = temp;
            st++;
            en--;
           }
        }
       }
   
   
    public static void main(String[] args) {
        String str = "abcdefg";
       String str1 =  reverseString(str,2);


    }
}
