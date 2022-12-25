// Practical 1 of OOP lab : 
// Implement a class Complex which represents the Complex Number data type.
// Implement the following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include <iostream>

using namespace std;

class complex
{
    float x, y;

public:
    // step 1 :
    complex()
    {
        x = 0;
        y = 0;
    }

    // step 2:
    complex operator+(complex);
    complex operator*(complex);

    // step 3:
    friend istream &operator>>(istream &input, complex &t)
    {
        cout << "\nEnter the real number : ";
        input >> t.x;
        cout << "\nEnter the Emaginary Part : ";
        input >> t.y;
    }

    friend ostream &operator<<(ostream &output, complex &t)
    {
        // printing the statement
        output << t.x << "+" << t.y << "i\n";
    }
};

// step 4:
complex complex::operator+(complex c)
{
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return (temp);
}

complex complex::operator*(complex c)
{
    complex temp;
    temp.x = (x * c.x) - (y * c.y);
    temp.y = (y * c.x) + (x * c.y);
    return (temp);
}

// step 5:
int main()
{
    complex c1, c2, c3, c4;
    cout << "\nDefault constructor value : ";
    cout << c1;
    cout << "\nEnter the 1st number\n";
    cin >> c1;
    cout << "\nEnter the 2st number\n";
    cin >> c2;

    c3 = c1 + c2;
    c4 = c1 * c2;

    cout << "\n\nThe first number is : ";
    cout << c1;
    cout << "\nThe second number is : ";
    cout << c2;
    cout << "\nThe Addition number is : ";
    cout << c3;
    cout << "\n\nThe Multiplication number is : ";
    cout << c4;
    cout << "\n";
    return 0;
}
