package stackJava;

public class prevSmllEle {

    public static void main(String[] args) {

        int arr[] = { 4, 10, 5, 8, 20, 15, 3, 12 };
        int n = arr.length;
        int res[] = new int[n], k = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= -1; j--) {
                if(j<0){
                    res[k] = -1;
                    k++;
                    break;
                }
                else if (arr[j] < arr[i]) {
                    res[k++] = arr[j];
                    break;
                }
               
            }
        }

        for (int i : res)
           System.out.print(i + " ");

    }
}
