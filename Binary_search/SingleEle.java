public class SingleEle {

    public static int searchSingleElement(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        int mid;
        // boundary check
        if(end ==0){
            return arr[0];
        }
        if (arr[start] != arr[start + 1]) {
            return arr[start];
        }
        if (arr[end] != arr[end - 1]) {
            return arr[end];
        }
        while (start <= end){
            mid = start + (end - start) / 2;
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }
            if(((mid%2)==0 && arr[mid]==arr[mid+1]) || ((mid%2)==1 && arr[mid]==arr[mid-1])){
                start = mid + 1;
            }
            else{
                end = mid - 1;
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
