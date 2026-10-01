#include <iostream>

using namespace std;

// Abstract Base Class
class Shape {
protected:
    double val1, val2; // Dimensions: radius/length/base, width/height

public:
    // Virtual destructor for proper cleanup
    virtual ~Shape() {
        cout << "\nShape Destructor" << endl;
    }

    // Pure Virtual Functions
    virtual void getData() = 0;
    virtual void calculateArea() = 0;
};

// Derived Class: Circle
class Circle : public Shape {
public:
    void getData() override {
        cout << "\nEnter radius: ";
        cin >> val1;
    }

    void calculateArea() override {
        double area = 3.14 * val1 * val1;
        cout << "Area of Circle: " << area << endl;
    }

    ~Circle() override {
        cout << "\nCircle Destructor" << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
public:
    void getData() override {
        cout << "\nEnter length: ";
        cin >> val1;
        cout << "Enter width: ";
        cin >> val2;
    }

    void calculateArea() override {
        double area = val1 * val2;
        cout << "\nArea of Rectangle: " << area << endl;
    }

    ~Rectangle() override {
        cout << "\nRectangle Destructor" << endl;
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
public:
    void getData() override {
        cout << "\nEnter base: ";
        cin >> val1;
        cout << "Enter height: ";
        cin >> val2;
    }

    void calculateArea() override {
        double area = 0.5 * val1 * val2;
        cout << "\nArea of Triangle: " << area << endl;
    }

    ~Triangle() override {
        cout << "\nTriangle Destructor" << endl;
    }
};

int main() {
    Shape* s = nullptr; // Base class pointer
    int choice;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s = new Circle();
                break;
            case 2:
                s = new Rectangle();
                break;
            case 3:
                s = new Triangle();
                break;
            case 4:
                cout << "Exiting..." << endl;
                continue;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }

        // Polymorphic function calls
        s->getData();
        s->calculateArea();

        // Free allocated memory
        delete s;

    } while (choice != 4);

    return 0;
}
