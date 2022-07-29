#include <cmath>
#include <iostream>
using namespace std;

class Point {
   public:
    int p_x;
    int p_y;
};
class Circle {
   private:
    Point c_Centre;
    int c_Radius;

   public:
    Circle(const Point &C, int R) {
        c_Radius = R;
        c_Centre = C;
    }
    void position(Point C) {
        int d2 = (C.p_x - c_Centre.p_x) * (C.p_x - c_Centre.p_x) +
                 (C.p_y - c_Centre.p_y) * (C.p_y - c_Centre.p_y);
        int r2 = c_Radius * c_Radius;
        if (d2 == r2) {
            cout << "The point is on the circle" << endl;
        } else if (d2 > r2) {
            cout << "The point is outside the circle" << endl;
        } else {
            cout << "Inside the circle" << endl;
        }
    }
};

int main() {
    Point p1;
    p1.p_y = 0;
    p1.p_x = 0;
    Circle c1(p1, 5);
    Point p2;
    p2.p_x = 0;
    p2.p_y = 10;
    c1.position(p2);
    return 0;
}
