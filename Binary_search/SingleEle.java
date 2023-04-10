public class SingleEle {

    public static int searchSingleElement(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int mid;
        while (start <= end){
            mid = start + (end - start) / 2;
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }
            else if (arr[mid] != arr[mid + 1] && arr[mid] == arr[mid - 1]) {
                
            }
        }

        return -1;
    }
    public static void main(String[] args) {
        int arr[] = { 1, 2, 2, 3, 3, 4, 4, 8, 8 };

        int ans = searchSingleElement(arr);
        System.out.println(ans);
    }
}
