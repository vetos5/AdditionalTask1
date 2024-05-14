#ifndef CUSTOM_CONTAINER_FIGURE_H
#define CUSTOM_CONTAINER_FIGURE_H
#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Figure {

protected:
    string name;

public:
    Figure(string name) : name(name) {};

    virtual ~Figure() {};

    virtual double volume() = 0;

    virtual void print() = 0;

    string getName() {
        return name;
    }

    friend ostream &operator<<(ostream &os, Figure &f) {
        f.print();
        return os;
    }

    friend istream &operator>>(istream &is, Figure &f) {
        return is >> f.name;
    }


};


#endif //CUSTOM_CONTAINER_FIGURE_H
