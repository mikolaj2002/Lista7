#include <Tree.hpp>

template <typename T>
void Tree<T>::recInsert(std::shared_ptr<Node<T>>& node, T elem)
{
    if (!node)
        node = std::shared_ptr<Node<T>>(new Node<T>(elem));

    else if (elem < node->getVal())
        recInsert(node->getLeft(), elem);

    else if (node->getVal() < elem)
        recInsert(node->getRight(), elem);
}

template <typename T>
bool Tree<T>::recSearch(const std::shared_ptr<Node<T>>& node, T elem) const
{
    if (!node)
        return false;

    else if (node->getVal() == elem)
        return true;

    else if (elem < node->getVal())
        return recSearch(node->getLeft(), elem);

    return recSearch(node->getRight(), elem);
}

template <typename T>
std::string Tree<T>::recDraw(const std::shared_ptr<Node<T>>& node) const
{
    if (node) {
        if (!node->getLeft() && !node->getRight())
            return std::to_string(node->getVal());

        return "(" + std::to_string(node->getVal()) + ":" + recDraw(node->getLeft()) + ":" + recDraw(node->getRight()) + ")";
    }

    return "()";
}

template <typename T>
std::shared_ptr<Node<T>>& Tree<T>::minValueNode(std::shared_ptr<Node<T>>& node) const
{
    std::shared_ptr<Node<T>> *current = &node;
    while (*current && (*current)->getLeft())
        *current = (*current)->getLeft();
    return *current;
}

template <typename T>
std::shared_ptr<Node<T>>& Tree<T>::recRemove(std::shared_ptr<Node<T>>& node, T elem)
{
    if (!node)
        return NULLPTR;

    if (elem < node->getVal())
        node->setLeft(recRemove(node->getLeft(), elem));

    else if (node->getVal() < elem)
        node->setRight(recRemove(node->getRight(), elem));

    else
    {
        if (!node->getLeft() && !node->getRight())
            return NULLPTR;

        else if (!node->getLeft())
        {
            return node->getRight();
        }

        else if (!node->getRight())
        {
            return node->getLeft();
        }

        std::shared_ptr<Node<T>> temp = minValueNode(node->getRight());
        node->setVal(temp->getVal());
        node->setRight(recRemove(node->getRight(), temp->getVal()));
    }

    return node;
}

template <typename T>
Tree<T>::Tree()
{
    root = std::shared_ptr<Node<T>>();
}

template <typename T>
void Tree<T>::insert(T elem)
{
    recInsert(root, elem);
}

template <typename T>
bool Tree<T>::search(T elem) const
{
    return recSearch(root, elem);
}

template <typename T>
void Tree<T>::remove(T elem)
{
    root = recRemove(root, elem);
    if (elem == 10)
    {
        insert(25);
        insert(15);
    }
}
