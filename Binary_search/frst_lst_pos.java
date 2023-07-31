/**
 * frst_lst_pos
 */
public class frst_lst_pos {

    static int firstOccur(int a[], int key) {
        int size = a.length;
        int mid, ans = -1;
        int end = size - 1;
        int start = 0;
        mid = start + (end - start) / 2;
        while (start <= end) {
            if (a[mid] == key) {
                ans = mid;
                end = mid - 1;
            } else if (key > a[mid])
                start = mid + 1;
            else if (key < a[mid])
                end = mid - 1;

            mid = start + (end - start) / 2;
        }
        return ans;
    }

    static public int lastOccur(int a[], int key) {
        int size = a.length;
        int mid, ans = -1;
        int end = size - 1;
        int start = 0;
        mid = start + (end - start) / 2;
        while (start <= end) {
            if (a[mid] == key) {
                ans = mid;
                start = mid + 1;
            } else if (key > a[mid])
                start = mid + 1;
            else if (key < a[mid])
                end = mid - 1;

            mid = start + (end - start) / 2;
        }
        return ans;
    }

    static int countElement(int arr[], int key) {
        int first = firstOccur(arr, key);
        int last = lastOccur(arr, key);

        if (first == -1 || last == -1) {
            return -1;
        }
        else {
            return last - first + 1;
        }
    }
    
     
    /**
     * @param args
     */
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 3, 3,3,3,5 };
        System.out.println(firstOccur(arr, 3));
        System.out.println(lastOccur(arr, 3));

        System.out.println(countElement(arr, 3));
    }

}
