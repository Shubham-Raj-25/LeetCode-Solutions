public class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        
        q.add(root);
        
        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            list.add(curr.val);
            
            if (curr.left != null) {
                q.add(curr.left);
                q.add(curr.right);
            }
        }
        
        Collections.sort(list);
        
        int firstMin = list.get(0);
        int secondMin = -1;
        
        for (int val : list) {
            if (val != firstMin) {
                secondMin = val;
                break;
            }
        }
        
        return secondMin;
    }
}
