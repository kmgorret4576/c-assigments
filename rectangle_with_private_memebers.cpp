#include <iostream>
#include <stdexcept>
using namespace std;

class Rectangle {
private:
    double width = 1;
    double length = 1;

    // error checking Rejects zero and negative values
    static void validate(double value, const string& name) {
        if (value <= 0)
            throw invalid_argument(name + " must be greater than 0");
    }

public:
    void setWidth(double w) {
        validate(w, "Width");
        width = w;
    }

    void setLength(double l) {
        validate(l, "Length");
        length = l;
    }

    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getArea() const { return width * length; }
    double getPerimeter() const { return 2 * (width + length); }
};

void show(const string& label, const Rectangle& r) {
    cout << label << endl;
    cout << "Width: " << r.getWidth() << endl;
    cout << "Length: " << r.getLength() << endl;
    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << "\n" << endl;
}

int main() {
    Rectangle rectangle1;
    rectangle1.setWidth(5);
    rectangle1.setLength(10);
    show("Rectangle 1", rectangle1);

    Rectangle rectangle2;
    rectangle2.setWidth(4);
    rectangle2.setLength(6);
    show("Rectangle 2", rectangle2);

    // Invalid inputs
    try {
        rectangle1.setWidth(0);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        rectangle2.setLength(-3);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Values stay unchanged after failed updates
    cout << "\nAfter invalid inputs:" << endl;
    cout << "Rectangle 1 width: " << rectangle1.getWidth() << endl;
    cout << "Rectangle 2 length: " << rectangle2.getLength() << endl;

    return 0;
