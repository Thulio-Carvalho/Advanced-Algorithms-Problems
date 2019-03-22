import java.util.Scanner;

public class game_with {

    static Node root;
    static String word;
    static int count;
    static boolean flag;
    static boolean has_dupes;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        word = sc.nextLine();

        build_nodes();
        has_dupes = true;
        flag = false;
        
        while(has_dupes && root != null) {
            Node next = root;
            has_dupes = false;
            
            while (next != null) {
                next = search_dupes(next);
            }
            
            if (has_dupes) {
                count++;
            }
        }

        if (count % 2 == 0) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }

    public static void build_nodes() {
        root = new Node(word.charAt(0));
        
        Node old = root;
        for (int i = 1; i < word.length(); i++){
            Node tmp = new Node(word.charAt(i));
            tmp.before = old;
            old.after = tmp;

            old = tmp;
        }
    }

    public static Node search_dupes(Node curr){
        if (curr.after == null) {
            return null;
        }
        if (curr.after.equals(curr)) {
            has_dupes = true;
            if (curr.before != null && curr.after.after != null) {
                curr.before.after = curr.after.after;
                curr.after.after.before = curr.before;
            } else if (curr.before == null){
                root = curr.after.after;
                if (root != null) root.before = null;
            } else if (curr.after.after == null){
                curr.before.after = null;
            }
            return null; 
        }
        return curr.after;
    }
}

class Node {
    public Node before;
    public Node after;
    public char letter;

    public Node(char letter){
        this.letter = letter;
    }

    @Override
    public boolean equals(Object o){
        if (o == this) { 
            return true; 
        } 
        if (!(o instanceof Node)) { 
            return false; 
        } 
        return this.letter == ((Node) o).letter;
    }
}