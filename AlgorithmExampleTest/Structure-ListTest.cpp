//
// Created by Qard Group CA on 12/15/22.
//
#include <gtest/gtest.h>
#include <Structure-List.h>

using namespace std;
using namespace Structure;

TEST(ListTest, BasicAssertions) {
    List<int> list;

    list.Add(3);
    list.Add(8);
    list.Add(4);
    list.Add(6);
    list.Add(10);
    list.Add(22);
    list.Add(35);

    cout << "La longitud de la lista es: " << list.Length() << endl;

    for (int i = 0; i < list.Length(); ++i) {
        cout << "El valor es: " << list.Get(i) << endl;

    }

    //cout << "ToString(); " << list.ToString() << endl;


    List<string> words;

    words.Add("brayan");
    words.Add("maria");
    words.Add("rosa");
    words.Add("jose");
    words.Add("benito");
    words.Add("adela");
    words.Add("pedro");

    cout << "La longitud de la lista es: " << words.Length() << endl;


    for (int i = 0; i < words.Length(); ++i) {
        cout << "El valor es: " << words.Get(i) << endl;

    }

    words.Remove(0);

    cout << "La longitud de la lista es: " << words.Length() << endl;


    for (int i = 0; i < words.Length(); ++i) {
        cout << "El valor es: " << words.Get(i) << endl;

    }

    //cout << "ToString(); " << words.ToString() << endl;

    std::cout << std::endl << "Test Passed!" << std::endl;
}