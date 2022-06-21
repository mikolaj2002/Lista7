#include <memory>

#ifndef NODE_HPP
#define NODE_HPP

/**
 * Klasa reprezentuje element drzewa binarnego.
 * @tparam T Typ drzewa binarnego.
 */
template <typename T>
class Node
{
private:
    T value;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;

public:
    /**
     * Domyślny konstruktor klasy Node.
     */
    Node();

    /**
     * Konstruktor klasy Node.
     * @param v Wartość elementu drzewa.
     */
    Node(T v);

    /**
     * Zwraca wartość elementu drzewa.
     * @return T Wartość elementu drzewa.
     */
    T getVal() const;

    /**
     * Zwraca referencję na element drzewa po lewej.
     * @return std::shared_ptr<Node<T>>& Referencja na element drzewa po lewej.
     */
    std::shared_ptr<Node<T>>& getLeft();

    /**
     * Zwraca referencję na element drzewa po prawej.
     * @return std::shared_ptr<Node<T>>& Referencja na element drzewa po prawej.
     */
    std::shared_ptr<Node<T>>& getRight();

    /**
     * Funkcja ustawia wartość elementu drzewa.
     * @param v Nowa wartość.
     */
    void setVal(T v);

    /**
     * Funkcja ustawia element drzewa po lewej.
     * @param l Nowy element drzewa po lewej.
     */
    void setLeft(std::shared_ptr<Node<T>> l);

    /**
     * Funkcja ustawia element drzewa po prawej.
     * @param l Nowy element drzewa po prawej.
     */
    void setRight(std::shared_ptr<Node<T>> r);
};

#include <Node.cpp>

#endif