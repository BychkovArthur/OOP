#include <vector>

#include "../include/Pentagon.hpp"
#include "../include/PentagonValidator.hpp"
#include "../include/Rhombus.hpp"
#include "../include/RhombusValidator.hpp"
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

    Point pp1(0, 0);
    Point pp2(2, 5);
    Point pp3(0, 3);
    Point pp4(2, 2);

    Point pp5(0, 0);
    Point pp6(1, 1);
    Point pp7(4, 1);
    Point pp8(3, 0);

    Point pp9(0, 0);
    Point pp10(0, 1);
    Point pp11(1, 1);
    Point pp12(1, 0);

    Point pp13(-1, 0);
    Point pp14(0, 1);
    Point pp15(1, 0);
    Point pp16(0, -1);
    Rhombus r1(pp1, pp3, pp2, pp4);
    vector<Point> rpoints;
    // rpoints.push_back(pp1);
    // rpoints.push_back(pp3);
    // rpoints.push_back(pp2);
    // rpoints.push_back(pp4);

    // rpoints.push_back(pp5);
    // rpoints.push_back(pp6);
    // rpoints.push_back(pp7);
    // rpoints.push_back(pp8);

    // rpoints.push_back(pp10);
    // rpoints.push_back(pp11);
    // rpoints.push_back(pp12);
    // rpoints.push_back(pp9);

    rpoints.push_back(pp13);
    rpoints.push_back(pp14);
    rpoints.push_back(pp15);
    rpoints.push_back(pp16);
    RhombusValidator* rval = new RhombusValidator;
    rval->validate(rpoints);

    Point a1(0, 100);
    Point a2(95.10565, 30.9017);
    Point a3(58.7788, -80.9017);
    Point a4(-58.778, -80.9017);
    Point a5(-95.10565, 30.9017);
    vector<Point> vpoints;
    vpoints.push_back(a1);
    vpoints.push_back(a2);
    vpoints.push_back(a3);
    vpoints.push_back(a4);
    vpoints.push_back(a5);

    PentagonValidator* pval = new PentagonValidator;
    pval->validate(vpoints);
    Pentagon pent(a1, a2, a3, a4, a5);

    figures[0] = &t1;
    figures[1] = &r1;
    figures[2] = &pent;
    for (int i = 0; i < 3; ++i) {
        cout << figures[i]->getGeometricCenter() << endl;
        cout << static_cast<double>(*figures[i]) << endl;
        cout << *figures[i] << endl;
    }

    // cout << "Types are equal: " << (typeid(figures) == typeid(t1)) << endl;

    // for (int i = 0; i < 2; ++i) {
    //     cin >> *figures[i];
    // }

    //     for (int i = 0; i < 2; ++i) {
    //     cout << figures[i]->getGeometricCenter() << endl;
    //     cout << static_cast<double> (*figures[i]) << endl;
    //     cout << *figures[i] << endl;
    // }
}