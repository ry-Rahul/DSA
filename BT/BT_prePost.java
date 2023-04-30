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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return solve(preorder, 0, preorder.length - 1, postorder, 0, postorder.length - 1);
    }

    TreeNode solve(int[] pre, int preStart, int preEnd, int[] post, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return null;
        }
        TreeNode root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int postIndex = postStart;
        while (pre[preStart + 1] != post[postIndex])
            postIndex++;

        int len = postIndex - postStart + 1;

        root.left = solve(pre, preStart + 1, preStart + len, post, postStart, postIndex);
        root.right = solve(pre, preStart + len + 1, preEnd, post, postIndex + 1, postEnd);

        return root;
    }
};

/**
 * BT_prePost
 */
public class BT_prePost {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] pre = { 1, 2, 4, 5, 3, 6, 7 };
        int[] post = { 4, 5, 2, 6, 7, 3, 1 };
        /*
         * 1
         * / \
         * 2 3
         * / \ / \
         * 4 5 6 7
         * 
         */
        TreeNode root = sol.constructFromPrePost(pre, post);

    }
}