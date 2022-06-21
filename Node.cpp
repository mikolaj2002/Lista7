#include <Node.hpp>

template <typename T>
Node<T>::Node()
{
    left = right = std::shared_ptr<Node<T>>();
}

template <typename T>
Node<T>::Node(T v) : value(v)
{
    left = right = std::shared_ptr<Node<T>>();
}

template <typename T>
T Node<T>::getVal() const
{
    return value;
}

template <typename T>
std::shared_ptr<Node<T>>& Node<T>::getLeft()
{
    return left;
}

template <typename T>
std::shared_ptr<Node<T>>& Node<T>::getRight()
{
    return right;
}

template <typename T>
void Node<T>::setVal(T v)
{
    value = v;
}

template <typename T>
void Node<T>::setLeft(std::shared_ptr<Node<T>> l)
{
    left = l;
}

template <typename T>
void Node<T>::setRight(std::shared_ptr<Node<T>> r)
{
    right = r;
}
