#include <iostream>
#include <string>
using namespace std;

class Mammal {
public:
	virtual void Speak() {
		cout << "�����" << endl;
	}
};

class Dog : public Mammal {
public:
	void Speak() {
		cout << "����" << endl;
	}
};

int main() {
	Dog myDog;
	myDog.Speak();
	return 0;
}