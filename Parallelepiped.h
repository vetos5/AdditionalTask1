#ifndef CUSTOM_CONTAINER_PARALLELEPIPED_H
#define CUSTOM_CONTAINER_PARALLELEPIPED_H
#pragma once

#include "Figure.h"
#include <fstream>
#include <sstream>
#include <string>

class Parallelepiped : public Figure {
protected:
    double edgeA;
    double edgeB;
    double height;
public:
    Parallelepiped() : Figure(""), edgeA(0), edgeB(0), height(0) {}

    Parallelepiped(string name, double edgeA, double edgeB, double height) : Figure(name), edgeA(edgeA), edgeB(edgeB),
                                                                             height(height) {}

    void setParameters(const string &name, double edgeA, double edgeB, double height) {
        this->name = name;
        this->edgeA = edgeA;
        this->edgeB = edgeB;
        this->height = height;
    }

    double volume() override {
        double baseArea = edgeA * edgeB;
        return baseArea * height;
    }

    void print() override {
        cout << "Name: " << name << endl;
        cout << "Edge A: " << edgeA << endl;
        cout << "Edge B: " << edgeB << endl;
        cout << "Height: " << height << endl;
        cout << "Volume " << volume() << endl;
    }

    friend istream &operator>>(istream is, Parallelepiped &p) {
        return is >> p.name >> p.edgeA >> p.edgeB >> p.height;
    }

    static void fileInput(const string &filename, LinkedList<Figure *> &container) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Unable to open file " << filename << endl;
            return;
        }

        string name;
        double edgeA, edgeB, height;

        while (file >> name >> edgeA >> edgeB >> height) {
            Parallelepiped *sphere = new Parallelepiped(name, edgeA, edgeB, height);;
            container.push_back(dynamic_cast<Figure *>(sphere));
        }

        file.close();

    }
};


#endif //CUSTOM_CONTAINER_PARALLELEPIPED_H
