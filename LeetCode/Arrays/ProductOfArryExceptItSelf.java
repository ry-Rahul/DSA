
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

    // method 2
    public static int[] productOfArray2(int[] arr) {
        int n = arr.length;
        int ans[] = new int[n];

        int right = 1;
        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * arr[i - 1];

        for (int j = n - 1; j >= 0; j--)
        {
            ans[j] = ans[j] * right;
            right = right * arr[j];
        }

        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 4,5,1,8,2 };
        System.out.println("The product of array is: " + Arrays.toString(productOfArray(arr)));
    }
}