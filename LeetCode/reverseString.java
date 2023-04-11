// package LeetCode;

import java.util.concurrent.CountDownLatch;

public class reverseString {

    public static String reverseString(String str,int k) {
        int st = 0;
       int en = str.length() - 1;
        for(int j = 0 ; j< str.length(); j+=k) {
            for (int i = 0; i < k; i++) {
                char temp = str.charAt(st);
                str.charAt(st) = str.charAt(en);
                str.charAt(en) = temp;
                st++;
                en--;
              }
        }
       }
   
   }
    public static void main(String[] args) {
        String str = "abcdefg";
       String str1 =  reverseString(str,2);


    }
}
