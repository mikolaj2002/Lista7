public class Node<T extends Comparable<T>>
{
    private T value;
    private Node<T> left;
    private Node<T> right;

    Node(T v)
    {
        value = v;
        left = right = null;
    }

    T getVal() { return value; }

    Node<T> getLeft() { return left; }

    Node<T> getRight() { return right; }

    void setVal(T v) { value = v; }

    void setLeft(Node<T> l) { left = l; }

    void setRight(Node<T> r) { right = r; }
}
