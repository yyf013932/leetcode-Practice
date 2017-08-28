package daily_notes;

import sun.text.normalizer.Trie;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by daniel.yyf on 2017/8/1.
 */
public class TrieTree {
    Node rootNode = new Node();

    public void insert(String word) {
        Node last = rootNode, tem;
        for (char c : word.toCharArray()) {
            last.count++;
            tem = nextNode(last, c);
            if (tem == null) {
                tem = new Node();
                last.nodeMap.put(c, tem);
                last = tem;
            } else {
                last = tem;
            }
        }
        last.count++;
        last.isWord = true;
    }

    public int search(String word) {
        Node last = rootNode;
        for (int i = 0; i < word.length(); i++) {
            last = nextNode(last, word.charAt(i));
            if (last == null)
                return 0;
        }
        return last.count;
    }

    public int delete(String word) {
        Node last = rootNode;
        int count = search(word);
        if (count == 0)
            return count;
        for (int i = 0; i < word.length(); i++) {
            last.count -= count;
            if (i == word.length() - 1) {
                last.nodeMap.remove(word.charAt(i));
            } else {
                last = nextNode(last, word.charAt(i));
            }
        }
        return count;

    }

    class Node {
        int count;
        boolean isWord;
        Map<Character, Node> nodeMap = new HashMap<>(10);
    }

    static Node nextNode(Node node, char c) {
        return node.nodeMap.get(c);
    }

    public static void main(String[] args) {
        TrieTree trieTree = new TrieTree();
        trieTree.insert("hello");
        trieTree.insert("hehe");
        System.out.println(trieTree.search("h"));
        trieTree.delete("he");
        System.out.println(trieTree.search("hello"));
        trieTree.insert("cad");
        trieTree.insert("ca");

        System.out.println(trieTree.search("c"));
        System.out.println(trieTree.search("ac"));
        System.out.println(trieTree.search("ad"));
    }

}
