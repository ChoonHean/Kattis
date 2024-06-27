import java.io.*;
import java.util.*;

class Solution {
    static PrintStream p = System.out;

    public static void main(String[] args) throws IOException {
        class BST {
            class TreeNode {
                final int value;
                TreeNode left;
                TreeNode right;
                final int height;
                TreeNode(int value, int height) {
                    this.value = value;
                    this.height = height;
                }
            }
            final TreeNode root;
            TreeMap<Integer,TreeNode> map = new TreeMap<>();
            BST(int value) {
                this.root = new TreeNode(value, 0);
                map.put(value, root);
            }
            int insert(int value) {
                Map.Entry<Integer,TreeNode> left = map.floorEntry(value);
                Map.Entry<Integer,TreeNode> right = map.ceilingEntry(value);
                if (left == null) {
                    TreeNode curr = right.getValue();
                    curr.left = new TreeNode(value, curr.height + 1);
                    map.put(value, curr.left);
                    return curr.height + 1;
                } else if (right == null) {
                    TreeNode curr = left.getValue();
                    curr.right = new TreeNode(value, curr.height + 1);
                    map.put(value, curr.right);
                    return curr.height + 1;
                } else {
                    TreeNode curr = left.getValue();
                    if (curr.right == null) {
                        curr.right = new TreeNode(value, curr.height + 1);
                        map.put(value, curr.right);
                        return curr.height + 1;
                    } else {
                        curr = right.getValue();
                        curr.left = new TreeNode(value, curr.height + 1);
                        map.put(value, curr.left);
                        return curr.height + 1;
                    }
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        BST tree = new BST(Integer.parseInt(br.readLine()));
        long c = 0;
        pw.println(c);
        for (int i = 1; i < n; i++) {
            c += tree.insert(Integer.parseInt(br.readLine()));
            pw.println(c);
        }
        pw.close();
    }
}