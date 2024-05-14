//
// Created by Vitalii on 14.05.2024.
//

#ifndef CUSTOM_CONTAINER_SPHERE_H
#define CUSTOM_CONTAINER_SPHERE_H

#include "Figure.h"

const double Pi = 3.14;

class Sphere : public Figure {
protected:
    double radius;

public:

    Sphere() : Figure(""), radius(0) {}

    Sphere(string name, double radius) : Figure(name), radius(radius) {}

    void setParameters(const string &name, double radius) {
        this->name = name;
        this->radius = radius;
    }

    double volume() override {
        return ((4.0 / 3.0) * Pi * pow(radius, 3));
    }

    void print() override {
        cout << "Name: " << name << endl;
        cout << "Radius: " << radius << endl;
        cout << "Volume " << volume() << endl;
    }

    friend istream &operator>>(istream is, Sphere &s) {
        return is >> s.name >> s.radius;
    }

    static void fileInput(const string &filename, LinkedList<Figure *> &container) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Unable to open file " << filename << endl;
            return;
        }

        string name;
        double radius;

        while (file >> name >> radius) {
            Sphere *sphere = new Sphere(name, radius);
            container.push_back(dynamic_cast<Figure *>(sphere));
        }

        file.close();
    }
};


#endif //CUSTOM_CONTAINER_SPHERE_H
