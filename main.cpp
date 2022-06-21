#include <iostream>
#include <Tree.hpp>

int main()
{
    Tree<int> tree;

    tree.remove(5);
    std::cout << tree << std::endl;

    tree.insert(10);
    tree.insert(8);
    tree.insert(9);
    tree.insert(20);
    tree.insert(15);
    tree.insert(25);
    tree.insert(12);
    std::cout << tree << std::endl;

    tree.remove(20);
    std::cout << tree << std::endl;

    tree.remove(10);
    std::cout << tree << std::endl;

    tree.insert(10);
    std::cout << tree << std::endl;

    return 0;
}
