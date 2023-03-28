import java.util.Stack;

class Solution {
    public int maximalRectangle(int[][] a) {
        int max = 0;
     int currRow[]= a[0];
        max = maxArea(currRow);
        for(int i = 1 ; i<a.length; i++){
            for(int j= 0 ; j<a[0].length; j++){
                if(a[i][j]==1){
                    currRow[j]+=1;
                }
                else{
                    currRow[j]=0;
                }
                int currAns = maxArea(currRow);
                max = Math.max(max,currAns);
            }
        }
        return max;
    }


    public int maxArea(int []arr){
        int ps[]=prevSmallest(arr);
        int ns[]=nxtSmallest(arr);

        int max = 0;
        for(int i = 0; i<arr.length; i++){
            int ans = (ns[i]-ps[i]-1)*arr[i];

            max = Math.max(ans,max);
        }
        return max;
    }

    public int[] prevSmallest(int arr[]){
        int ps[]=new int[arr.length];
        
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i<arr.length; i++){
            while(!st.isEmpty() && arr[i]<=arr[st.peek()]){
                st.pop();
            }
            if(st.isEmpty()){
                ps[i]=-1;
            }
            else{
                ps[i]=st.peek();
            }

            st.push(i);
        }
        return ps;
    }

    public int[] nxtSmallest(int arr[]){
        int ns[]=new int[arr.length];
        
        Stack<Integer> st = new Stack<>();

        for(int i = arr.length-1; i>=0; i--){
            while(!st.isEmpty() && arr[i]<=arr[st.peek()]){
                st.pop();
            }
            if(st.isEmpty()){
                ns[i]=arr.length;
            }
            else{
                ns[i]=st.peek();
            }

            st.push(i);
        }
        return ns;
    }
}


public class largestAreaSubmatrix {

     public static void main(String[] args) {
        Solution sol = new Solution();
        int a[][] = {{1,0,1,0,0},
                    {1,0,1,1,1},
                    {1,1,1,1,1},
                    {1,0,0,1,0}};
        System.out.println(sol.maximalRectangle(a));
     }
}