public class SpiralMatrix {

    public static void generateMatrix(int n) {
        // int arr[] = new int[n * n];

        int count = 1;
        // for (int i = 0; i < n * n; i++) {
        //     arr[i] = count++;
        // }

        int matrix[][] = new int[n][n];
        int m = matrix.length;
        int N = matrix[0].length;
        int left = 0, right = N - 1, top = 0, bottom = m - 1;
        int dir = 0;
        int k = 0;

        while (top <= bottom && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    // matrix[top][i] = arr[k++];
                    matrix[top][i] = count++;
                }
                top += 1;
            } else if (dir == 1) {
                for (int i = top; i <= bottom; i++) {
                    // matrix[i][right] = arr[k++];
                    matrix[i][right] = count++;
                }
                right -= 1;

            } else if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    // matrix[bottom][i] = arr[k++];
                    matrix[bottom][i] = count++;
                }
                bottom -= 1;

            } else if (dir == 3) {
                for (int i = bottom; i >= top; i--) {
                    // matrix[i][left] = arr[k++];
                    matrix[i][left] = count++;
                }
                left += 1;

            }

            dir = (dir + 1) % n;
        }
        
        printMatrix(matrix);
    }
    
    // printing 2D matrix
    public static void printMatrix(int arr[][]) {
        for (int[] row : arr) {
            for (int col : row) {
                System.out.printf("%3d ", col);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int n = 4;
        generateMatrix(n);
        
    }
}
