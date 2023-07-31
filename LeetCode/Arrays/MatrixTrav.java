/**
 * 2DMatrix
 */

import java.util.ArrayList;
import java.util.List;

public class MatrixTrav {
    
    public static List<Integer> spiralOrderTraversal(int[][] arr) {
        List<Integer> ans = new ArrayList<>();
        int m = arr.length;
        int n = arr[0].length;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int dir = 0;

        while (top <= bottom && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++)
                    ans.add(arr[top][i]);
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= bottom; i++)
                    ans.add(arr[i][right]);
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--)
                    ans.add(arr[bottom][i]);
                bottom--;
            } else if (dir == 3) {
                for (int i = bottom; i >= top; i--)
                    ans.add(arr[i][left]);
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }

    public static void main(String[] args) {
        int arr[][] = { { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 10,11,12},
                        { 13,14,15,16} };
        // array list
        List<Integer> arr1 = new ArrayList<>();
        arr1 = spiralOrderTraversal(arr);

        for(int i = 0; i < arr1.size(); i++)
            System.out.print(arr1.get(i) + " ");
    }
}