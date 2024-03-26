#include <iostream>
#include <string>
using namespace std;

class Mammal {
public:
	virtual void Speak() {
		cout << "¶¯Îï½Ð" << endl;
	}
};

class Dog : public Mammal {
public:
	void Speak() {
		cout << "¹·½Ð" << endl;
	}
};

int main() {
	Dog myDog;
	myDog.Speak();
	return 0;
}