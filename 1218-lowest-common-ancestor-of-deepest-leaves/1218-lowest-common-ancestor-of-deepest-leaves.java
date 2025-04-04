/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int findHeight(TreeNode root,Map<Integer, Integer> mp){
        if(root == null)
            return 0;
        int l = findHeight(root.left, mp);
        int r = findHeight(root.right, mp);
        mp.put(root.val ,Math.max(l,r) + 1);
        return mp.get(root.val);
    }
    TreeNode solve(TreeNode root, Map<Integer, Integer> mp){
        if(root.left == null && root.right == null)
            return root;
        if(root.left == null)
            return solve(root.right, mp);
        if(root.right == null)
            return solve(root.left, mp);
        if(mp.get(root.left.val) < mp.get(root.right.val)) 
            return solve(root.right, mp);
        if(mp.get(root.left.val) > mp.get(root.right.val))
            return solve(root.left, mp);
        return root;
    }
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        Map<Integer, Integer> mp = new HashMap<>();
        findHeight(root, mp);
        // System.out.println(mp);
        // return root;
        return solve(root, mp);
    }
}