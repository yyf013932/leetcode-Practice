import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by Daniel on 2017/4/10.
 */
public class SymmetricTree_101 {

    public static void main(String[] args) {
        TreeNode node = new TreeNode(1);
        TreeNode node1 = new TreeNode(2);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(4);
        TreeNode node6 = new TreeNode(3);
        node.left=node1;
        node.right=node2;
        node1.left=node3;
        node1.right=node4;
        node2.left=node5;
        node2.right=node6;
        SymmetricTree_101 symmetricTree_101=new SymmetricTree_101();
        System.out.println(symmetricTree_101.isSymmetric(node));

    }


    Queue<TreeNode> leftQueue = new ArrayDeque<>();
    Queue<TreeNode> rightQueue = new ArrayDeque<>();

    public boolean isSymmetric(TreeNode root) {
        TreeNode placeHolder = new TreeNode(-1);
        if (root == null)
            return true;
        TreeNode left = root.left;
        TreeNode right = root.right;
        put(leftQueue, left, placeHolder);
        put(rightQueue, right, placeHolder);
        while (leftQueue.size() != 0 || rightQueue.size() != 0) {
            TreeNode temLeft = leftQueue.poll();
            TreeNode temRight = rightQueue.poll();

            if (temLeft == placeHolder) {
                if (temRight == placeHolder) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (temRight == placeHolder) {
                    return false;
                } else {
                    if (temLeft.val != temRight.val)
                        return false;
                    put(leftQueue, temLeft.left, placeHolder);
                    put(leftQueue, temLeft.right, placeHolder);
                    put(rightQueue, temRight.right, placeHolder);
                    put(rightQueue, temRight.left, placeHolder);
                }
            }

        }
        return true;
    }

    void put(Queue<TreeNode> queue, TreeNode node, TreeNode placeHolder) {
        if (node == placeHolder || node == null)
            queue.add(placeHolder);
        else
            queue.add(node);
    }

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}