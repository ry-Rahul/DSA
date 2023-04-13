// package LeetCode.BSearch;

/**
 * ProductOfArryExceptItSelf
 */
import java.util.Arrays;

public class ProductOfArryExceptItSelf {

    public static int[] productOfArray(int[] arr) {
        int n = arr.length;
        int left[] = new int[n];
        int right[] = new int[n];
        int ans[] = new int[n];

        left[0] = 1;
        right[n - 1] = 1;
        for (int i = 1; i < n; i++)
            left[i] = left[i - 1] * arr[i - 1];

        for (int j = n - 2; j >= 0; j--)
            right[j] = right[j + 1] * arr[j + 1];

        for (int k = 0; k < n; k++)
            ans[k] = left[k] * right[k];

        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4 };
        System.out.println("The product of array is: " + Arrays.toString(productOfArray(arr)));
    }
}