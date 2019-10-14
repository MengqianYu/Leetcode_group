/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer> res;
    Set<Integer> visited;
    int distance;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        res = new ArrayList<>();
        distance = K;
        visited = new HashSet<>();
        popdown(target, K);
        dfs(root, target);
        return res;
    }
    
    public int dfs(TreeNode root, TreeNode target){
        if (root == null) return -1;
        if (root == target){
            return 0;
        }
        int left = dfs(root.left, target);
        int right = dfs(root.right, target);
        int ans = -1;
        if (left != -1){
            ans = left+1;
            visited.add(root.left.val);
        }
        else if (right != -1){
            ans = right+1;
            visited.add(root.right.val);
        }
        else{
            return -1;
        }
        //System.out.println(root.val + " " + ans);
        popdown(root, distance-ans);
        return ans;
    }
    
    public void popdown(TreeNode target, int k){
        if (target == null) return;
        if (visited.contains(target.val)) return;
        if (k == 0){
            res.add(target.val);
            return;
        }
        popdown(target.left, k-1);
        popdown(target.right, k-1);
    }
}