//
// Created by Qard Group CA on 12/28/22.
//
module;

#include <iostream>
#include <string>

export module util.object;

export class Object {
public:
    virtual ~Object() = default;

    virtual std::string ToString() {
        return "";
    };
};

