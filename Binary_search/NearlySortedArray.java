public class NearlySortedArray {

    public static int NearlySortedArray(int[] A,int target) {
        
        int start = 0;
        int end = A.length - 1;
        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (A[mid] == target) {
                return mid;
            } else if (mid >= start && A[mid - 1] == target) {
                return mid - 1;
            } else if (mid < end && A[mid + 1] == target) {
                return mid + 1;
            } else if (A[mid] > target) {
                end = mid - 2;
            } else {
                start = mid + 2;
            }
        }
        return -1;

    }
    public static void main(String[] args) {
        int arr[] = { 10, 3, 40, 20, 50, 80, 70 };
        int target = 80;
        System.out.println(NearlySortedArray(arr, target));
        
    }
}
