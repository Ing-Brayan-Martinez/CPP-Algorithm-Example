//
// Created by brayan on 17/9/20.
//

#include <iostream>

#ifndef LISTA_LIST_H
#define LISTA_LIST_H

using namespace std;


/**
 * Nodo de la lista.
 *
 * @tparam T Tipo generico.
 */
template<typename T> class Node {

    private:
        Node<T> *next;
        T value;
        int index{};

    public:

        explicit Node(T value, Node<T> *next = NULL, int index = 0)
        {
            this->value = value;
            this->next = next;
            this->index = index;
        }

        T getValue()
        {
            return this->value;
        }

        Node<T> * getNext()
        {
            return this->next;
        }

        int getIndex()
        {
            return this->index;
        }

        void finish()
        {
            this->next = NULL;
        }

        bool operator==(const Node<T>& b)
        {
            return (b != NULL) && (this->index == b.getIndex())
                    && (this->value == b.getValue());
        }

        bool operator!=(const Node<T>& b)
        {
            return (b != NULL) && (this->index != b.getIndex())
                   && (this->value != b.getValue());
        }

};










/**
 * Lista simple de tipo generico.
 *
 * @tparam T Tipo generico.
 */
template<typename T> class List {

    private:
        Node<T> *chain;
        int length;

    public:

        explicit List()
        {
            chain = NULL;
            length = 0;
        }

        void add(T value)
        {
            Node<T> *newNode = NULL;

            if (chain == NULL) {
                chain = new Node(value);

            } else  {
                newNode = new Node(value, chain, length);
                chain = newNode;

            }

            length++;
        }

        T get(int index)
        {
            Node<T> *last = NULL;
            T value;

            last = chain;

            if (last == NULL) {
                throw exception();

            } else if (last->getIndex() == index) {
                value = last->getValue();

            } else {
                while (last->getNext() != NULL) {
                    last = last->getNext();
                    if (last->getIndex() == index) {
                        value = last->getValue();
                        break;
                    }
                }

            }

            return value;
        }

        int getLength()
        {
            return this->length;
        }

        void remove(int index);
        string toString();

};





template<typename T>
void List<T>::remove(int index)
{
    Node<T> *last = NULL;
    T value;
    int position;

    last = chain;

    if (last == NULL) {
        throw exception();

    } else if (last->getIndex() == index) {
        value = last->getValue();

    } else {
        while (last->getNext() != NULL) {
            last = last->getNext();
            if (last->getIndex() == index) {
                value = last->getValue();
                break;
            }
        }

    }

//    Node<T> *anterior;
//    Node<T> *actual;
//
//    anterior = chain;
//    actual = chain; //
//    if (chain->value==v) {
//        actual = chain;
//        chain = actual->getNext();
//        delete actual;
//        actual = chain;
//        length--;
//
//    } else {
//        actual = actual->next;
//        while (actual!=NULL) {
//            if (actual->value==v) {
//                anterior->next = actual->next;
//                actual = anterior->next;
//            } else {
//                anterior = actual;
//                actual = actual->next;
//            }
//        }
//    }
}


template<typename T>
string List<T>::toString() {
    cout << "La lista es: " << endl;
    string str = "";
    return str;
}



#endif // LISTA_LIST_H
