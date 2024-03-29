public class floorOfElem {
    public static int ceilOfElement(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;
        int mid = -1;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                return arr[mid];
            } else if (arr[mid] > target) {
                ans = arr[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
    public static int floorOfElement(int[] arr, int tareget) {
        int start = 0;
        int end = arr.length - 1;
        int mid = -1;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (arr[mid] == tareget) {
                return arr[mid];
            } else if (arr[mid] > tareget) {
                end = mid - 1;
            } else {
                ans = arr[mid];
                start = mid + 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int arr[] = { 1, 2,8, 10, 10, 12, 19 };
        int target = 5;
        int ans = floorOfElement(arr, target);
        System.out.println("Floor of element is: "+ans);
        System.out.println("Ceil of element is: " + ceilOfElement(arr, target));
    }
}
