//
// Created by brayan on 17/9/20.
//

#include <iostream>


namespace Structure {

    namespace {
        /**
         * Nodo de la lista.
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

                explicit Node(T value, Node<T> *next = NULL, int index = 0)
                {
                    this->value = value;
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

                void SetNext(Node<T> *next)
                {
                    this->next = next;
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

    }

    /**
     * Lista simple de tipo generico.
     *
     * @tparam T Tipo generico.
     */
    template<typename T>
    class List {

        private:
            Node<T> *chain;
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
                    auto tmp =  (char) this->Get(i);

                    str = str + tmp;


                    if (i < length-1) {
                        str = str + ", ";
                    }
                }

                str + "];";

                return str;
            }

    };

}













