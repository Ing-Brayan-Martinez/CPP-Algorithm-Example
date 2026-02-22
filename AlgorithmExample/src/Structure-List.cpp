//
// Created by brayan on 17/9/20.
//
module;

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

export module structure.list;

namespace Structure {

    /**
     * Nodo de la listas, es privado en este espacio de nombres.
     *
     * @tparam T Tipo generico.
     */
    template<typename T>
    class Node {

        private:
            Node<T> *next;
            T value;
            int index{};

        public:

            explicit Node(T value, int index, Node<T> *next = nullptr)
            {
                this->value = std::move(value);
                this->next = next;
                this->index = index;
            }

            T GetValue()
            {
                return this->value;
            }

            Node<T> * GetNext()
            {
                return this->next;
            }

            int GetIndex()
            {
                return this->index;
            }

            void SetNext(Node<T> * node)
            {
                this->next = node;
            }

            void Finish()
            {
                this->next = NULL;
            }

            bool operator==(const Node<T>& b)
            {
                return (b != NULL) && (this->index == b.GetIndex())
                       && (this->value == b.GetValue());
            }

            bool operator!=(const Node<T>& b)
            {
                return (b != NULL) && (this->index != b.GetIndex())
                       && (this->value != b.GetValue());
            }

    };


    /**
     * Lista simple de tipo generico.
     *
     * @tparam T Tipo generico.
     */
    export template<typename T>
    class List {
        Node<T> *chain{};
        int length;

        public:

            explicit List()
            {
                chain = NULL;
                length = 0;
            }

            void Add(T value)
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

            T Get(int index)
            {
                Node<T> *last = NULL;
                T value;

                last = chain;

                if (last == NULL) {
                    throw std::exception();

                } else if (last->GetIndex() == index) {
                    value = last->GetValue();

                } else {
                    while (last->GetNext() != NULL) {
                        last = last->GetNext();
                        if (last->GetIndex() == index) {
                            value = last->GetValue();
                            break;
                        }
                    }

                }

                return value;
            }

           int Length()
            {
                return this->length;
            }

            void Remove(int index)
            {
                Node<T> *last = NULL;
                Node<T> *del = NULL;

                last = chain;

                if (last == NULL) {
                    throw std::exception();


                } else if (index == length) {
                    chain = last->GetNext();
                    length--;

                } else {
                    while (last->GetNext() != NULL) {
                        if (last->GetIndex() == index + 1) {
                            break;
                        }
                        last = last->GetNext();
                    }

                    del = last->GetNext();
                    last->SetNext(del->GetNext());
                    chain = last;
                    length--;

                }

            }

            std::string ToString()
            {

                std::string str = "List [";

                for (int i = 0; i < length; i++) {
                    T tmp = this->Get(i) ;




                    if (i < length-1) {
                        //str = str + ", ";
                        str.append(", ");
                    }
                }

                //str + "];";
                str.append("];");

                return str;
            }

    };

    /**
     * Lista simple de tipo int.
     *
     */
    export class ListInteger {
        Node<int> *chain;
        int length;

        public:

            explicit ListInteger()
            {
                chain = nullptr;
                length = -1;
            }

            void Add(int value)
            {
                length++;

                if (chain == nullptr) {
                    chain = new Node(value, length);

                } else  {
                    auto newNode = new Node(value, length, chain);
                    chain = newNode;

                }
            }

            int Get(int index)
            {
                int value = 0;

                Node<int> *last = chain;

                if (last == nullptr) {
                    throw std::exception();

                } else if (last->GetIndex() == index) {
                    value = last->GetValue();

                } else {
                    while (last->GetNext() != nullptr) {
                        last = last->GetNext();
                        if (last->GetIndex() == index) {
                            value = last->GetValue();
                            break;
                        }
                    }

                }

                return value;
            }

            int Length()
            {
                return this->length;
            }

            void Remove(int index)
            {
                Node<int> *last;
                Node<int> *del;

                last = chain;

                if (last == nullptr) {
                    throw std::exception();


                } else if (index == length) {
                    chain = last->GetNext();
                    length--;

                } else {
                    while (last->GetNext() != nullptr) {
                        if (last->GetIndex() == index + 1) {
                            break;
                        }
                        last = last->GetNext();
                    }

                    del = last->GetNext();
                    last->SetNext(del->GetNext());
                    chain = last;
                    length--;

                }

            }

            std::string ToString()
            {

                std::string str = "List [";

                for (int i = 0; i < length; i++) {
                    int tmp = this->Get(i) ;

                    str.append(std::to_string(tmp));

                    if (i < length-1) {
                        str.append(", ");
                    }
                }

                str.append("];");

                return str;
            }

    };

    /**
    * Lista simple de tipo string.
    *
    */
    export class ListString {
    private:
        Node<std::string> *head;
        int count; // Renombrado a 'count' para que represente la cantidad REAL de elementos

    public:
        // Constructor
        explicit ListString() {
            head = nullptr;
            count = 0;
        }

        // DESTRUCTOR: Obligatorio en C++ para evitar Fugas de Memoria (Memory Leaks)
        ~ListString() {
            Node<std::string> *current = head;
            while (current != nullptr) {
                Node<std::string> *next = current->GetNext();
                delete current;
                current = next;
            }
        }

        // Agrega un elemento AL FINAL de la lista para mantener el orden natural (FIFO)
        void Add(const std::string& value) {
            // Se añade 'count' como segundo parámetro para que coincida con tu constructor original de Node(value, index)
            Node<std::string> *newNode = new Node(value, count);

            if (head == nullptr) {
                head = newNode;
            } else {
                Node<std::string> *current = head;
                while (current->GetNext() != nullptr) {
                    current = current->GetNext();
                }
                current->SetNext(newNode);
            }
            count++;
        }

        // Obtener un elemento por su índice real
        std::string Get(int index) {
            if (index < 0 || index >= count) {
                throw std::out_of_range("Indice fuera de rango");
            }

            Node<std::string> *current = head;
            for (int i = 0; i < index; i++) {
                current = current->GetNext();
            }
            return current->GetValue();
        }

        // Devuelve la longitud de la lista
        int Length() {
            return this->count;
        }

        // Remueve un elemento de la lista por índice
        void Remove(int index) {
            if (index < 0 || index >= count) {
                throw std::out_of_range("Indice fuera de rango");
            }

            Node<std::string> *toDelete = nullptr;

            // Caso 1: Eliminar la cabeza (primer elemento)
            if (index == 0) {
                toDelete = head;
                head = head->GetNext();
            }
            // Caso 2: Eliminar cualquier otro elemento (medio o final)
            else {
                Node<std::string> *prev = head;
                for (int i = 0; i < index - 1; i++) {
                    prev = prev->GetNext();
                }
                toDelete = prev->GetNext();
                prev->SetNext(toDelete->GetNext());
            }

            delete toDelete;
            count--;
        }

        // Imprimir la lista iterando una sola vez O(N) usando un ciclo for
        std::string ToString() {
            std::string str = "List [";
            Node<std::string> *current = head;

            for (int i = 0; i < count; i++) {
                str.append(current->GetValue());

                // Agrega la coma solo si no estamos en el último elemento
                if (i < count - 1) {
                    str.append(", ");
                }

                // Avanzamos al siguiente nodo
                current = current->GetNext();
            }

            str.append("];");
            return str;
        }
    };
}

