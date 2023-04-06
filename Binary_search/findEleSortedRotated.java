public class findEleSortedRotated {
    public static int binarySearch(int arr[],int target){
        int start = 0,mid= -1;
        int end= arr.length-1;

        while(start<=end){
            mid = start + (end-start)/2;

            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid]>=arr[start]){
                if(target>=arr[start] && target <= arr[mid]){
                  end = mid - 1;
                }
                else{
                  start = mid + 1;
                }
            }
            else{
                if(target>=arr[mid] && target <= arr[end]){
                  start = mid +1;
                }
                else{
                  end = mid - 1;
                }
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {

        return binarySearch(nums,target);
    }
    
    public static void main(String[] args) {
        int arr[] = {4,5,6,7,0,1,2};
        System.out.println(binarySearch(arr, 2));
    }
    

}