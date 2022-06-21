#include <iostream>
#include <Node.hpp>

#ifndef TREE_HPP
#define TREE_HPP

/**
 * Klasa reprezentuje drzewo binarne zadanego typu.
 * @tparam T Typ drzewa.
 */
template <typename T>
class Tree
{
private:
    std::shared_ptr<Node<T>> NULLPTR = std::shared_ptr<Node<T>>(nullptr);
    std::shared_ptr<Node<T>> root;

    void recInsert(std::shared_ptr<Node<T>> &node, T elem);
    bool recSearch(const std::shared_ptr<Node<T>> &node, T elem) const;
    std::string recDraw(const std::shared_ptr<Node<T>> &node) const;
    std::shared_ptr<Node<T>>& minValueNode(std::shared_ptr<Node<T>> &node) const;
    std::shared_ptr<Node<T>>& recRemove(std::shared_ptr<Node<T>> &node, T elem);

public:
    /**
     * Konstruktor klasy Tree.
     */
    Tree();

    /**
     * Funkcja wsadza element do drzewa.
     * Wartości w drzewie się nie powtarzają.
     * @param elem Wsadzany element.
     */
    void insert(T elem);

    /**
     * Funkcja szuka zadanego elementu w drzewie.
     * @param elem Zadany element.
     * @return true Element został znaleziony.
     * @return false Element nie został znaleziony.
     */
    bool search(T elem) const;

    /**
     * Funkcja usuwa zadany element z drzewa, o ile w nim jest.
     * @param elem Wartość elementu do usunięcia.
     */
    void remove(T elem);

    /**
     * Funkcja rysuje drzewo na standardowe wyjście.
     */
    friend std::ostream& operator<<(std::ostream& out, Tree<T> tree)
    {
        out << tree.recDraw(tree.root);
        return out;
    }
};

#include <Tree.cpp>

#endif
