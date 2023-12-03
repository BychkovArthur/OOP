#include <vector>

#include "../include/Pentagon.hpp"
#include "../include/Rhombus.hpp"
#include "../include/Trapezoid.hpp"

using namespace std;
// TODO конструктор по умолчанию
int main() {
    Figure* figures[3];
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(0, 0);
    Point p4(3, 0);
    Trapezoid t1(p1, p2, p4, p3);
    Point pp1(1, 0);
    Point pp2(-1, 0);
    Point pp3(0, 1);
    Point pp4(0, -1);
    Rhombus r1(pp1, pp3, pp2, pp4);

    Point a1(0, 100);
    Point a2(95.10565, 30.9017);
    Point a3(58.7788, -80.9017);
    Point a4(-58.778, -80.9017);
    Point a5(-95.10565, 30.9017);
    Pentagon pent(a1, a2, a3, a4, a5);

    figures[0] = &t1;
    figures[1] = &r1;
    figures[2] = &pent;
    for (int i = 0; i < 3; ++i) {
        cout << figures[i]->getGeometricCenter() << endl;
        cout << static_cast<double>(*figures[i]) << endl;
        cout << *figures[i] << endl;
    }

    // for (int i = 0; i < 2; ++i) {
    //     cin >> *figures[i];
    // }

    //     for (int i = 0; i < 2; ++i) {
    //     cout << figures[i]->getGeometricCenter() << endl;
    //     cout << static_cast<double> (*figures[i]) << endl;
    //     cout << *figures[i] << endl;
    // }
}