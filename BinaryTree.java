public class BinaryTree<T extends Comparable<T>>
{
    private Node<T> root;

    private Node<T> recInsert(Node<T> node, T elem)
    {
        if (node == null)
            return new Node<T>(elem);

        else if (elem.compareTo(node.getVal()) < 0)
            node.setLeft(recInsert(node.getLeft(), elem));
        
        else if (node.getVal().compareTo(elem) < 0)
            node.setRight(recInsert(node.getRight(), elem));

        return node;
    }
    
    private boolean recSearch(Node<T> node, T elem)
    {
        if (node == null)
            return false;

        else if (node.getVal() == elem)
            return true;

        else if (elem.compareTo(node.getVal()) < 0)
            return recSearch(node.getLeft(), elem);
        
        return recSearch(node.getRight(), elem);
    }

    private StringBuilder recDraw(Node<T> node)
    {
        if (node != null)
        {
            if (node.getLeft() != null || node.getRight() != null)
                return new StringBuilder("(" + node.getVal() + ":" +
                    recDraw(node.getLeft())+ ":" + recDraw(node.getRight()) + ")");
            
            return new StringBuilder(node.getVal().toString());
        }
        
        return new StringBuilder("()");
    }

    private Node<T> minValueNode(Node<T> node)
    {
        Node<T> current = node;
        while (current != null && current.getLeft() != null)
            current = current.getLeft();
        return current;
    }

    private Node<T> recRemove(Node<T> node, T elem)
    {
        if (node == null)
            return null;

        if (elem.compareTo(node.getVal()) < 0)
            node.setLeft(recRemove(node.getLeft(), elem));
        
        else if (node.getVal().compareTo(elem) < 0)
            node.setRight(recRemove(node.getRight(), elem));

        else
        {
            if (node.getLeft() == null && node.getRight() == null)
                return null;
            
            else if (node.getRight() == null)
            {
                Node<T> temp = node.getRight();
                return temp;
            }

            else if (node.getRight() == null)
            {
                Node<T> temp = node.getLeft();
                return temp;
            }

            Node<T> temp = minValueNode(node.getRight());
            node.setVal(temp.getVal());
            node.setRight(recRemove(node.getRight(), temp.getVal()));
        }

        return node;
    }

    public void insert(T elem)
    {
        root = recInsert(root, elem);
    }

    public boolean search(T elem)
    {
        return recSearch(root, elem);
    }

    public void draw()
    {
        System.out.println(recDraw(root));
    }

    void remove(T elem)
    {
        recRemove(root, elem);
    }
}
