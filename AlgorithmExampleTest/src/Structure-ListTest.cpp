//
// Created by Qard Group CA on 12/15/22.
//
#include <iostream>
#include <gtest/gtest.h>

import structure.list;

using namespace std;
using namespace Structure;

TEST(ListTest, ListAssertions)
{
    //----------------- Integer -----------------------

    List<int> list1;

    list1.Add(3);
    list1.Add(8);
    list1.Add(4);
    list1.Add(6);
    list1.Add(10);
    list1.Add(22);
    list1.Add(35);

    cout << endl;
    cout << "La longitud de la lista es: " << list1.Length() << endl;
    cout << endl;

    for (int i = 0; i < list1.Length(); i++) {
        cout << "El valor es: " << list1.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << list1.ToString() << endl;

    //----------------- String -----------------------

    List<std::string> list2;

    list2.Add("brayan");
    list2.Add("maria");
    list2.Add("rosa");
    list2.Add("jose");
    list2.Add("jesus");
    list2.Add("adela");
    list2.Add("pedro");

    cout << endl;
    cout << "La longitud de la lista es: " << list2.Length() << endl;
    cout << endl;

    for (int i = 0; i < list2.Length(); i++) {
        cout << "El valor es: " << list2.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << list2.ToString() << endl;

    //----------------- Final -----------------------

    cout << endl;
    cout << "Test Passed!" << std::endl;
}

TEST(ListTest, ListIntegerAssertions) {

    ListInteger numbers;

    numbers.Add(3);
    numbers.Add(8);
    numbers.Add(4);
    numbers.Add(6);
    numbers.Add(10);
    numbers.Add(22);
    numbers.Add(35);

    cout << endl;
    cout << "La longitud de la lista es: " << numbers.Length() << endl;
    cout << endl;

    for (int i = 0; i < numbers.Length(); i++) {
        cout << "El valor es: " << numbers.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << numbers.ToString() << endl;

    //----------------- Remove -----------------------

    numbers.Remove(2);
    numbers.Remove(4);
    numbers.Remove(3);

    cout << endl;
    cout << "La longitud de la lista es: " << numbers.Length() << endl;
    cout << endl;

    for (int i = 0; i < numbers.Length(); i++) {
        cout << "El valor es: " << numbers.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << numbers.ToString() << endl;

    cout << endl;
    cout << "Test Passed!" << std::endl;
}

TEST(ListTest, ListStringAssertions) {

    ListString words;

    words.Add("brayan");
    words.Add("maria");
    words.Add("rosa");
    words.Add("jose");
    words.Add("jesus");
    words.Add("adela");
    words.Add("pedro");

    cout << endl;
    cout << "La longitud de la lista es: " << words.Length() << endl;
    cout << endl;

    for (int i = 0; i < words.Length(); i++) {
        cout << "El valor es: " << words.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << words.ToString() << endl;

    //----------------- Remove -----------------------

    words.Remove(2);
    words.Remove(4);
    words.Remove(3);

    cout << endl;
    cout << "La longitud de la lista es: " << words.Length() << endl;
    cout << endl;

    for (int i = 0; i < words.Length(); i++) {
        cout << "El valor es: " << words.Get(i) << endl;
    }

    cout << endl;
    cout << "ToString(); " << words.ToString() << endl;

    cout << endl;
    cout << "Test Passed!" << std::endl;
}
