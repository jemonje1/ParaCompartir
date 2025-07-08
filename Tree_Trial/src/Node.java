public class Node <T extends Comparable<T>>{
    private T element;
    private Node<T> root;
    private Node<T> right;
    private Node<T> left;

    public Node(T element) {
        this.element = element;
    }

    public Node(T element, Node<T> root, Node<T> left, Node<T> right) {
        this.element = element;
        this.root = root;
        this.left = left;
        this.right = right;
    }

    public T getElement() {
        return element;
    }
    public void setElement(T element) {
        this.element = element;
    }
    public Node<T> getRoot() {
        return root;
    }
    public void setRoot(Node<T> root) {
        this.root = root;
    }
    public Node<T> getRight() {
        return right;
    }
    public void setRight(Node<T> right) {
        this.right = right;
    }
    public Node<T> getLeft() {
        return left;
    }
    public void setLeft(Node<T> left) {
        this.left = left;
    }
}
