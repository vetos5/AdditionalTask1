#include "List.h"
#include "Parallelepiped.h"
#include "Sphere.h"

using namespace std;

int main() {

    LinkedList<Figure *> f;

    /*Parallelepiped P1("P1",3,4,5);
    Sphere S1("S1",4.5);

    f.push_back(&S1);
    f.push_front(&P1);
    */

    Parallelepiped::fileInput("E:\\Custom_Container\\parallelepiped.txt", f);

    Sphere::fileInput("E:\\Custom_Container\\sphere.txt", f);

    Parallelepiped P432("P432", 3, 4, 5);

    f.insert(2, &P432);

    cout << "Every name in container:\n";
    f.foreach([](Figure *figure) {
        cout << figure->getName() << " ";
    });

    cout << "\n";

    f.print();

    f.clear();

    f.print();


    return 0;
}