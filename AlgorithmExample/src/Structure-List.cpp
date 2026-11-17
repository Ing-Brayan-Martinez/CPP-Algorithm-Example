//
// Created by brayan on 17/9/20.
//
module;

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

import util.object;

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
     * Concepto para identificar si un tipo es una cadena de texto.
     */
    template <typename T>
    concept IsString = std::same_as<std::decay_t<T>, std::string> ||
                       std::same_as<std::decay_t<T>, std::string_view> ||
                       std::same_as<std::decay_t<T>, const char*> ||
                       std::same_as<std::decay_t<T>, char*>;
    /**
     * Concepto de C++20 que verifica si T hereda de la clase Object.
     */
    template <typename T>
    concept IsDerivedFromObject = std::derived_from<T, Object>;

    /**
     * Lista simple de tipo generico.
     *
     * @tparam T Tipo generico.
     */
    export template<typename T>
    class List {
    private:
        Node<T> *chain{};
        int length;

    public:
        explicit List()
        {
            chain = nullptr;
            length = 0;
        }

        void Add(T value)
        {
            if (chain == nullptr) {
                chain = new Node(value, length);

            } else  {
                auto newNode = new Node(value, length, chain);
                chain = newNode;

            }
            length++;
        }

        T Get(int index)
        {
            if (index < 0 || index >= length) {
                throw std::out_of_range("Indice fuera de rango");
            }

            T value;

            Node<T> *last = chain;

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
            Node<T> *last = nullptr;
            Node<T> *del = nullptr;

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

            for (int i = 0; i < this->Length(); i++) {
                T tmp = this->Get(i) ;

                // Caso 1: Es un número (int, float, etc.) -> Usamos std::to_string
                if constexpr (std::is_arithmetic_v<T>) {
                    str.append(std::to_string(tmp));
                }
                // Caso 2: Es una cadena -> Usamos directamente
                else if constexpr (IsString<T>) {
                    str.append(tmp);
                }
                // Caso 3: Es un objeto que hereda de la clase Object -> Invocamos su ToString()
                else if constexpr (IsDerivedFromObject<T>) {
                    return str.append(tmp.ToString());
                }
                // Caso 4: Tipo desconocido u objeto que no hereda de Object, es un error
                else {
                    throw std::exception();
                }

                if (i < this->Length()-1) {
                    str.append(", ");
                }
            }

            str.append("];");

            return str;
        }

        ~List() {
            Node<T> *current = chain;
            while (current != nullptr) {
                Node<T> *next = current->GetNext();
                delete current;
                current = next;
            }
        }
    };

    /**
     * Lista simple de tipo int.
     *
     */
    export class ListInteger {
    private:
        Node<int> *chain;
        int length;

    public:
        explicit ListInteger()
        {
            chain = nullptr;
            length = 0;
        }

        void Add(int value)
        {
            if (chain == nullptr) {
                chain = new Node(value, length);

            } else  {
                auto newNode = new Node(value, length, chain);
                chain = newNode;

            }
            length++;
        }

        int Get(int index)
        {
            if (index < 0 || index >= length) {
                throw std::out_of_range("Indice fuera de rango");
            }

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

        void Remove(int index) {
            if (index < 0 || index >= length || chain == nullptr) {
                throw std::out_of_range("Índice fuera de rango");
            }

            Node<int>* toDelete = nullptr;

            // Caso 1: Eliminar el primer nodo (la cabeza)
            if (index == length - 1) {
                // Nota: En tu implementación de Add, el último agregado es el primero en la cadena
                toDelete = chain;
                chain = chain->GetNext();
            }
            // Caso 2: Eliminar un nodo intermedio o el final
            else {
                Node<int>* prev = chain;

                // Buscamos el nodo anterior al que queremos borrar
                // Basándonos en tu lógica de índices descendentes
                while (prev->GetNext() != nullptr && prev->GetNext()->GetIndex() != index) {
                    prev = prev->GetNext();
                }

                toDelete = prev->GetNext();
                if (toDelete != nullptr) {
                    prev->SetNext(toDelete->GetNext());
                }
            }

            if (toDelete) {
                delete toDelete;
                length--;
                // Importante: Si guardas el índice dentro del nodo,
                // aquí deberías recorrer el resto para actualizarlos,
                // pero es mejor calcular el índice al vuelo.
            }
        }

        std::string ToString()
        {
            std::string str = "List [";

            for (int i = 0; i < this->Length(); i++) {
                int tmp = this->Get(i) ;

                str.append(std::to_string(tmp));

                if (i < this->Length()-1) {
                    str.append(", ");
                }
            }

            str.append("];");

            return str;
        }

        ~ListInteger() {
            Node<int> *current = chain;
            while (current != nullptr) {
                Node<int> *next = current->GetNext();
                delete current;
                current = next;
            }
        }
    };

    /**
    * Lista simple de tipo string.
    *
    */
    export class ListString {
    private:
        Node<std::string> *chain;
        int length;

    public:
        explicit ListString() {
            chain = nullptr;
            length = 0;
        }

        void Add(const std::string& value) {

            if (chain == nullptr) {
                chain = new Node(value, length);

            } else  {
                auto newNode = new Node(value, length, chain);
                chain = newNode;

            }
            length++;
        }

        std::string Get(int index) {
            if (index < 0 || index >= length) {
                throw std::out_of_range("Indice fuera de rango");
            }

            std::string value;

            Node<std::string> *last = chain;

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

        int Length() {
            return this->length;
        }

        void Remove(int index) {
            if (index < 0 || index >= length) {
                throw std::out_of_range("Indice fuera de rango");
            }

            Node<std::string> *toDelete = nullptr;

            // Caso 1: Eliminar la cabeza (primer elemento)
            if (index == 0) {
                toDelete = chain;
                chain = chain->GetNext();
            }
            // Caso 2: Eliminar cualquier otro elemento (medio o final)
            else {
                Node<std::string> *prev = chain;
                for (int i = 0; i < index - 1; i++) {
                    prev = prev->GetNext();
                }
                toDelete = prev->GetNext();
                prev->SetNext(toDelete->GetNext());
            }

            delete toDelete;
            length--;
        }

        std::string ToString() {
            std::string str = "List [";

            for (int i = 0; i < this->Length(); i++) {
                std::string tmp = this->Get(i) ;

                str.append(tmp);

                if (i < this->Length()-1) {
                    str.append(", ");
                }
            }

            str.append("];");
            return str;
        }

        ~ListString() {
            Node<std::string> *current = chain;
            while (current != nullptr) {
                Node<std::string> *next = current->GetNext();
                delete current;
                current = next;
            }
        }
    };
}

