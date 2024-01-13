class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return solve(preorder,inorder,0,inorder.length-1,0);
    }

    TreeNode solve(int[] pre,int inor[],int start,int end ,int index){
        if(start>end){
            return null;
        }
        TreeNode root = new TreeNode(pre[index]);

        int inIndex = start;
        while(pre[index]!=inor[inIndex]) inIndex++;

        root.left = solve(pre,inor, start, inIndex - 1,index+1);
        root.right = solve(pre,inor,inIndex+1,end,index+1 + inIndex-start);

        return root;
    }
}
public class BTpreInord {
    public static void main(String[] args) {
        int pre[] = { 1, 2, 4, 5, 3, 6, 7 };
        int inor[] = { 4, 2, 5, 1, 6, 3, 7 };
        Solution sol = new Solution();
        TreeNode root = sol.buildTree(pre, inor);
        System.out.println(root.val);

    }
}
