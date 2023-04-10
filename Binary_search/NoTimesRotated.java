
public class NoTimesRotated {

    static public int NoOfTimesRotated(int arr[]) {
        int start = 0;
        int end = arr.length - 1;
        int size = arr.length, next, prev;
        int mid;

        while (start < end) {
            mid = start + (end - start) / 2;

            if (arr[mid] > arr[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }

        }

        return arr[start];
    }
    
    static public int NoOfTimesRotated2(int arr[]) {
        int start = 0;
        int end = arr.length - 1;
        int size = arr.length, next, prev;
        int mid;

        while (start < end) {
            mid = start + (end - start) / 2;
            
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }

        }

        return arr[start];
    }

    public static void main(String[] args) {
      
        // int arr[] = { 12,15,18,22,25,30,45,55,62,75,2,5,8,9,11};
        // int ans = NoOfTimesRotated(arr);
        // System.out.println("Minimum Element in rotated Sorted Array is " + ans);

        int arr[] = { 3,3,1,3 };
        int ans2 = NoOfTimesRotated2(arr);
        System.out.println("Minimum Element in rotated Sorted Array is " + ans2);

    }
}
