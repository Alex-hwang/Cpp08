#include <iostream>
using namespace std;

class Shape {
public:
	Shape() {}
	virtual float GetArea() = 0;
	virtual float GetPerim() = 0;
};

class Rectangle : public Shape {
private:
	float m_Length;
	float m_Width;

public:
	Rectangle(float length, float width) : m_Length(length), m_Width(width) {}

	virtual float GetArea() {
		return m_Length * m_Width;
	}

	virtual float GetPerim() {
		return 2 * (m_Length + m_Width);
	}
};

class Circle : public Shape {
private:
	float m_Radius;

public:
	Circle(float radius) : m_Radius(radius) {}

	virtual float GetArea() {
		return 3.14 * m_Radius * m_Radius;
	}

	virtual float GetPerim() {
		return 2 * 3.14 * m_Radius;
	}
};

int main() {
	Rectangle rect(3, 4);
	Circle circle(5);

	cout << "Rectangle Area: " << rect.GetArea() << endl;
	cout << "Rectangle Perimeter: " << rect.GetPerim() << endl;

	cout << "Circle Area: " << circle.GetArea() << endl;
	cout << "Circle Perimeter: " << circle.GetPerim() << endl;

	return 0;
}