#ifndef NODE_HPP
#define NODE_HPP

template <typename T> class Node
{
private:
    T value;
    Node<T> *left;
    Node<T> *right;

public:
    Node()
    { left = right = nullptr; }

    Node(T v) : value(v)
    { left = right = nullptr; }

    Node(T v, Node<T> *l, Node<T> *r) : value(v), left(l), right(r) {}

    ~Node()
    {
        delete left;
        delete right;
    }

    T getVal() { return value; }

    Node<T>* getLeft() { return left; }

    Node<T>* getRight() { return right; }

    Node<T>** getLeftPointer() { return &left; }

    Node<T>** getRightPointer() { return &right; }

    void setVal(T v) { value = v; }

    void setLeft(Node<T> *l) { left = l; }

    void setRight(Node<T> *r) { right = r; }
};

#endif