#include <iostream>
#include <Tree.hpp>

int main()
{
    Tree<int> test;

    test.insert(10);
    test.insert(5);
    test.insert(8);
    test.insert(3);
    test.insert(14);
    test.insert(22);
    test.insert(11);

    test.draw();

    test.remove(5);

    test.search(5);

    test.draw();

    return 0;
}
