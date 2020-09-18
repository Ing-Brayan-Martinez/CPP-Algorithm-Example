#include <iostream>
#include "list.h"

using namespace std;

int main() {

    List<int> list;

    list.add(3);
    list.add(8);
    list.add(4);
    list.add(6);
    list.add(10);
    list.add(22);
    list.add(35);

    cout << "La longitud de la lista es: " << list.getLength() << endl;

    for (int i = 0; i < list.getLength(); ++i) {
        cout << "El valor es: " << list.get(i) << endl;

    }


    List<string> words;

    words.add("brayan");
    words.add("maria");
    words.add("rosa");
    words.add("jose");
    words.add("benito");
    words.add("adela");
    words.add("pedro");

    cout << "La longitud de la lista es: " << words.getLength() << endl;


    for (int i = 0; i < words.getLength(); ++i) {
        cout << "El valor es: " << words.get(i) << endl;

    }

    words.remove(0);

    cout << "La longitud de la lista es: " << words.getLength() << endl;


    for (int i = 0; i < words.getLength(); ++i) {
        cout << "El valor es: " << words.get(i) << endl;

    }


    return 0;
}
