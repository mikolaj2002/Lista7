#include <iostream>
#include <Node.hpp>

#ifndef TREE_HPP
#define TREE_HPP

static bool operator<(std::string s1, std::string s2)
{
    if (s1 == "" && s2 == "")
        return false;
    else if (s1 == "" && s2 != "")
        return true;
    else if (s1 != "" && s2 == "")
        return false;

    if (s1[0] < s2[0])
        return true;
    else if (s2[0] < s1[0])
        return false;
    
    s1 = (std::string)((char*)(s1.c_str()) + 1);
    s2 = (std::string)((char*)(s2.c_str()) + 1);
    
    return s1 < s2;
}

template <typename T> class Tree
{
private:
    Node<T> *root;

    void recInsert(Node<T> **node, T elem)
    {
        if (*node == nullptr)
            *node = new Node<T>(elem);

        else if (elem < (*node)->getVal())
            recInsert((*node)->getLeftPointer(), elem);
        
        else if ((*node)->getVal() < elem)
            recInsert((*node)->getRightPointer(), elem);
    }
    
    bool recSearch(Node<T> *node, T elem)
    {
        if (node == nullptr)
            return false;

        else if (node->getVal() == elem)
            return true;

        else if (elem < node->getVal())
            return recSearch(node->getLeft(), elem);
        
        return recSearch(node->getRight(), elem);
    }

    void recDraw(Node<T> *node)
    {
        if (node != nullptr)
        {
            recDraw(node->getLeft());
            std::cout << node->getVal() << " ";
            recDraw(node->getRight());
        }
    }

    Node<T>* minValueNode(Node<T> *node)
    {
        Node<T> *current = node;
        while (current != nullptr && current->getLeft() != nullptr)
            current = current->getLeft();
        return current;
    }

    Node<T>* recRemove(Node<T> *node, T elem)
    {
        if (node == nullptr)
            return nullptr;

        if (elem < node->getVal())
            node->setLeft(recRemove(node->getLeft(), elem));
        
        else if (node->getVal() < elem)
            node->setRight(recRemove(node->getRight(), elem));

        else
        {
            if (node->getLeft() == nullptr && node->getRight() == nullptr)
                return nullptr;
            
            else if (node->getRight() == nullptr)
            {
                Node<T> *temp = node->getRight();
                delete node;
                return temp;
            }

            else if (node->getRight() == nullptr)
            {
                Node<T> *temp = node->getLeft();
                delete node;
                return temp;
            }

            Node<T> *temp = minValueNode(node->getRight());
            node->setVal(temp->getVal());
            node->setRight(recRemove(node->getRight(), temp->getVal()));
        }

        return node;
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void insert(T elem)
    {
        recInsert(&root, elem);
    }

    bool search(T elem)
    {
        return recSearch(root, elem);
    }

    void draw()
    {
        recDraw(root);
        std::cout << std::endl;
    }

    void remove(T elem)
    {
        recRemove(root, elem);
    }
};

#endif
