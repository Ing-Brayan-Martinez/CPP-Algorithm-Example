//
// Created by brayan on 17/9/20.
//

#include <iostream>
#include <string>

#include "Util-Object.h"


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

                explicit Node(T value, int index, Node<T> *next = nullptr)
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

    }

    /**
     * Lista simple de tipo generico.
     *
     * @tparam T Tipo generico.
     */
    template<typename T>
    class List: Object {

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

            std::string ToString() override
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
    class ListInteger: Object {

    private:
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
            Node<int> *last;
            int value = 0;

            last = chain;

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

        std::string ToString() override
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
    class ListString: Object {

    private:
        Node<std::string> *chain;
        int length;

    public:

        explicit ListString()
        {
            chain = nullptr;
            length = -1;
        }

        void Add(const std::string& value)
        {
            length++;

            if (chain == nullptr) {
                chain = new Node(value, length);

            } else  {
                auto *newNode = new Node(value, length, chain);
                chain = newNode;

            }
        }

        std::string Get(int index)
        {
            Node<std::string> *last;
            std::string value;

            last = chain;

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

        void Remove(int index) {

            //eliminar el utltimo elemento, de una lista de 1 elemento
            if (index == 0 && length == 0) {
                //guardar referencia al elemento a eliminar
                Node<std::string> *eliminar = chain;

                //recortar la cadena omitiendo el ultimo elemento
                chain = eliminar->GetNext();

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //eliminar el utltimo elemento, de una lista de 2 elemento
            } else if (index == 0 && length == 1) {
                //guardar referencia al elemento a eliminar
                Node<std::string> *eliminar = chain;

                //recortar la cadena omitiendo el ultimo elemento
                chain = eliminar->GetNext();

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //eliminar el utltimo elemento, de una lista de 3 elemento o mas
            } else if (index == 0 && length > 1 && index <= length) {
                //guardar referencia al elemento a eliminar
                Node<std::string> *eliminar = chain;

                //recortar la cadena omitiendo el ultimo elemento
                chain = eliminar->GetNext();

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //eliminar el penutltimo elemento, de una lista de 2 elemento
            } else if (index == 1 && length == 1) {
                //guardar referencia al elemento a eliminar
                Node<std::string> *eliminar = chain;

                //recortar la cadena omitiendo el ultimo elemento
                chain = eliminar->GetNext();

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //eliminar el penutltimo elemento, de una lista de 3 elemento o mas
            } else if (index > 0 && index < length) {
                Node<std::string> *eliminar = nullptr;
                Node<std::string> *anterior = chain;

                //recorer hasta encontrar el elemento anterior
                while (anterior != nullptr) {
                    if (anterior->GetIndex() == index + 1) {
                        break;
                    }
                    anterior = anterior->GetNext();
                }

                //guardar referencia al elemento a eliminar que es el siguiente
                eliminar = anterior->GetNext();

                //saltar la referencia al siguiente nodo para omitir
                anterior->SetNext(eliminar->GetNext());

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //eliminar el primer elementos de la lista
            } else if (index == length) {
                Node<std::string> *eliminar = nullptr;
                Node<std::string> *anterior = chain;

                //recorer hasta encontrar el elemento anterior
                while (anterior != nullptr) {
                    if (anterior->GetIndex() == index + 1) {
                        break;
                    }
                    anterior = anterior->GetNext();
                }

                //guardar referencia al elemento a eliminar que es el siguiente
                eliminar = anterior->GetNext();

                //eliminar referencia
                anterior->SetNext(nullptr);

                //eliminar de la memoria
                delete eliminar;

                //decrementar el contador
                length--;

            //si no coincide el parametro
            } else {
                throw std::exception();

            }
        }

        std::string ToString() override
        {

            std::string str = "List [";

            if (length == 0) {
                std::string tmp = this->Get(0);
                if (!tmp.empty()) {
                    str.append(tmp);
                }

            } else if (length == 1) {
                for (int i = 0; i <= length; i++) {
                    std::string tmp = this->Get(i);

                    if (!tmp.empty()) {
                        str.append(tmp);

                        if (i == 0) {
                            str.append(", ");
                        }
                    }

                }
            } else {
                for (int i = 0; i < length; i++) {
                    std::string tmp = this->Get(i);

                    if (!tmp.empty()) {
                        str.append(tmp);

                        if (i < length-1) {
                            str.append(", ");
                        }
                    }

                }
            }

            str.append("];");

            return str;
        }

    };
}













