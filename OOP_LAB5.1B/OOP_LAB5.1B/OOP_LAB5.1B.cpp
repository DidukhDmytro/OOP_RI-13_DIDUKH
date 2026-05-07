#include <iostream>
#include "Point.h"

#pragma pack(push, 1)
struct PointPacked {
    double x, y;
};
#pragma pack(pop)

struct PointNormal {
    double x, y;
};

int main() {
    try {
        std::cout << "--- Object Creation ---" << std::endl;
        Point p1;                 
        Point p2(3.0, 4.0);       
        Point p3 = p2;            

        std::cout << "p1: " << p1 << std::endl;
        std::cout << "p2: " << p2 << std::endl;
        std::cout << "p3 (copy of p2): " << p3 << std::endl;

        std::cout << "\n--- Moving and Distance ---" << std::endl;
        p2.moveX(2.0);
        p2.moveY(-1.0);
        std::cout << "p2 moved: " << p2 << std::endl;
        std::cout << "Distance between p1 and p2: " << (p1 - p2) << std::endl;

        std::cout << "\n--- Increment/Decrement ---" << std::endl;
        std::cout << "p2++: " << p2++ << " Result: " << p2 << std::endl;
        std::cout << "++p2: " << ++p2 << std::endl;

        std::cout << "\n--- Array of Objects ---" << std::endl;
        Point arr[3] = { Point(1,1), Point(2,2), Point() };
        for (int i = 0; i < 3; ++i) std::cout << "arr[" << i << "] = " << arr[i] << " ";
        std::cout << std::endl;

        std::cout << "\n--- Sizes ---" << std::endl;
        std::cout << "Size of Point (normal): " << sizeof(PointNormal) << " bytes" << std::endl;
        std::cout << "Size of Point (packed): " << sizeof(PointPacked) << " bytes" << std::endl;

        std::cout << "\n--- Exception Handling (Testing Init) ---" << std::endl;
        Point pError(20000, 0); 

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}