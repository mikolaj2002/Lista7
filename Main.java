public class Main
{
    public static void main(String[] args)
    {
        BinaryTree<Integer> tree = new BinaryTree<Integer>();

        tree.insert(10);
        tree.insert(12);
        tree.insert(11);
        tree.insert(8);
        tree.insert(9);
        tree.insert(6);
        tree.insert(7);
        tree.insert(4);
        tree.insert(3);
        tree.insert(5);
        tree.insert(25);

        tree.draw();

        tree.remove(10);
        tree.remove(11);

        tree.draw();
    }
}
