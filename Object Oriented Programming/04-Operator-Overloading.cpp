#include <iostream>

class Complex {
private:
    double real;
    double imag; // Imaginary part

public:
    // Constructors
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    // Addition operator (+) overload
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Multiplication operator (*) overload
    friend Complex operator*(const Complex& c1, const Complex& c2) {
        return Complex(
            c1.real * c2.real - c1.imag * c2.imag,
            c1.real * c2.imag + c1.imag * c2.real
        );
    }

    // Stream output operator (<<) overload
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return out;
    }

    // Stream input operator (>>) overload
    friend std::istream& operator>>(std::istream& in, Complex& c) {
        std::cout << "Enter real and imaginary parts (e.g., 3 4): ";
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2;

    std::cout << "--- Complex Number 1 ---\n";
    std::cin >> c1;

    std::cout << "\n--- Complex Number 2 ---\n";
    std::cin >> c2;

    Complex sum = c1 + c2;
    Complex prod = c1 * c2;

    std::cout << "\n --- Results ---               \n";
    std::cout << "Complex Number 1 = " << c1 << "\n";
    std::cout << "Complex Number 2 = " << c2 << "\n";
    std::cout << "Sum = " << sum << "\n";
    std::cout << "Product = " << prod << "\n";

    return 0;
}

