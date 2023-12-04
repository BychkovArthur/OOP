#include <vector>

#include "../include/Pentagon.hpp"
#include "../include/PentagonFactory.hpp"
#include "../include/PentagonValidator.hpp"
#include "../include/Rhombus.hpp"
#include "../include/RhombusFactory.hpp"
#include "../include/RhombusValidator.hpp"
#include "../include/Trapezoid.hpp"
#include "../include/TrapezoidFactory.hpp"
#include "../include/TrapezoidValidator.hpp"

using namespace std;
// TODO конструктор по умолчанию
int main() {
    RhombusFactory rFact;
    PentagonFactory pFact;
    TrapezoidFactory tFact;

    Figure* figures[6];

    vector<Point> tpoints;
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(0, 0);
    Point p4(3, 0);
    tpoints.push_back(p1);
    tpoints.push_back(p2);
    tpoints.push_back(p4);
    tpoints.push_back(p3);
    figures[0] = tFact.createFigure(tpoints);

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

    vector<Point> rpoints1;
    vector<Point> rpoints2;
    vector<Point> rpoints3;
    vector<Point> rpoints4;
    rpoints1.push_back(pp1);
    rpoints1.push_back(pp3);
    rpoints1.push_back(pp2);
    rpoints1.push_back(pp4);

    rpoints2.push_back(pp5);
    rpoints2.push_back(pp6);
    rpoints2.push_back(pp7);
    rpoints2.push_back(pp8);

    rpoints3.push_back(pp10);
    rpoints3.push_back(pp11);
    rpoints3.push_back(pp12);
    rpoints3.push_back(pp9);

    rpoints4.push_back(pp13);
    rpoints4.push_back(pp14);
    rpoints4.push_back(pp15);
    rpoints4.push_back(pp16);

    figures[1] = rFact.createFigure(rpoints4);
    figures[2] = rFact.createFigure(rpoints4);
    figures[3] = rFact.createFigure(rpoints3);
    figures[4] = rFact.createFigure(rpoints4);

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

    figures[5] = pFact.createFigure(vpoints);

    for (int i = 0; i < 6; ++i) {
        cout << figures[i]->getGeometricCenter() << endl;
        cout << static_cast<double>(*figures[i]) << endl;
        cout << *figures[i] << endl;
    }
}