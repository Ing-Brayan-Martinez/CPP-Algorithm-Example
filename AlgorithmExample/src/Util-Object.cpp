//
// Created by Qard Group CA on 12/28/22.
//
module;

#include <iostream>
#include <string>

export module util.object;

/**
 * Clase base que define la interfaz para objetos que pueden convertirse a string.
 */
export class Object {
public:
    virtual std::string ToString() const = 0;
    virtual ~Object() = default;
};