#include<iostream>
#include<string>
using namespace std;
#define STU 1
#define TEA 1
#define GRA 1
#define TA 1

class Person {
private:
	int m_Age;
	int m_Number;
	int m_Sex;
	string m_Name;

public:
	void setInformation(int age, int num, int sex, string name) {
		m_Age = age;
		m_Number = num;
		m_Sex = sex;
		m_Name = name;
	}
	void getInformation() {
		cout << "Name: " << m_Name << " ";
		cout << "Sex: " << m_Sex << " ";
		cout << "Age: " << (m_Age == 1 ? "��" : "Ů") << " ";
		cout << "Number: " << m_Number << " ";
	}
	Person() {
		cout << "Person���캯��" << endl;
	}
	~Person() {
		cout << "Person��������" << endl;
	}
};

class Teacher :virtual private Person {
private:
	string m_Department;
	string m_Personel;
	int m_Pay = rand() % 1000 + 12000;
public:
	void setInformation(int age, int num, int sex, string name, string dep, string per) {
		Person::setInformation(age, num, sex, name);
		m_Department = dep;
		m_Personel = per;
	}
	void getInformation() {
		Person::getInformation();
		cout << "Department: " << m_Department << " ";
		cout << "Personel: " << m_Personel << " ";
	}
	void getInformation(int) {
		cout << "Department: " << m_Department << " ";
		cout << "Personel: " << m_Personel << " ";
	}
	Teacher() {
		cout << "Teacher���캯��" << endl;
	}
	~Teacher() {
		cout << "Teacher��������" << endl;
	}
	void getPay() {
		cout << "Pay: " << m_Pay << " ";
	}
};

class Professor :private Teacher {
public:
	//���캯��
	Professor() {
	}

	~Professor() {
	}
	void setInformation(int age, int num, int sex, string name, string dep, string per) {
		Teacher::setInformation(age, num, sex, name, dep, per);
	}

	void getInformation() {
		Teacher::getInformation();
	}

	void getPay() {
		Teacher::getPay();
	}
};

class FemaleProfessor :private Professor {
public:
	//���캯��
	FemaleProfessor() {
	}

	~FemaleProfessor() {
	}

	void setInformation(int age, int num, int sex, string name, string dep, string per) {
		Professor::setInformation(age, num, sex, name, dep, per);
	}

	void getInformation() {
		Professor::getInformation();
	}

	void getPay() {
		Professor::getPay();
	}
};

class Student :private Person {
private:
	string m_ClassNo;
public:
	void setInformation(int age, int num, int sex, string name, string classno) {
		Person::setInformation(age, num, sex, name);
		m_ClassNo = classno;
	}
	void getInformation() {
		Person::getInformation();
		cout << "ClassNo: " << m_ClassNo << " ";
	}
	Student() {
		cout << "Student���캯��" << endl;
	}
	~Student() {
		cout << "Student��������" << endl;
	}
};

class Graduate : virtual private Student {
public:
	string m_Subject;
	string m_Tutor;
public:
	void setInformation(int age, int num, int sex, string name, string classno, string sub, string tut) {
		Student::setInformation(age, num, sex, name, classno);
		m_Subject = sub;
		m_Tutor = tut;
	}
	void getInformation() {
		Student::getInformation();
		cout << "Subject: " << m_Subject << " ";
		cout << "Tutor: " << m_Tutor << " ";
	}
	Graduate() {
		cout << "Graduate���캯��" << endl;
	}
	~Graduate() {
		cout << "Graduate��������" << endl;
	}
};

class TeacherAssistant :private Graduate, private Teacher {
private:
	string m_RA;
public:
	void setInformation(int age, int num, int sex, string name, string classno, string sub, string tut, string dep, string per) {
		Graduate::setInformation(age, num, sex, name, classno, sub, tut);
		Teacher::setInformation(age, num, sex, name, dep, per);
	}
	void getInformation() {
		Graduate::getInformation();
		Teacher::getInformation(1);
	}
	TeacherAssistant() {
		cout << "TeacherAssistant���캯��" << endl;
	}
	~TeacherAssistant() {
		cout << "TeacherAssistant��������" << endl;
	}
};

int main() {
	Student stu[STU];
	Teacher tea[TEA];
	Graduate gra[GRA];
	TeacherAssistant ta[TA];

	for (int i = 0; i < STU; i++) {
		int age, num, sex;
		string name, classno;
		cout << "���������䣺";
		cin >> age;
		cout << "������ѧ�ţ�";
		cin >> num;
		cout << "�������Ա�(1-�У�2-Ů��";
		cin >> sex;
		cout << "������������";
		cin >> name;
		cout << "������༶��";
		cin >> classno;
		stu[i].setInformation(age, num, sex, name, classno);
		stu[i].getInformation();
		cout << endl;
	}

	//ͬ���Ĳ�����Ϊ�˷�����ԣ��Ͳ��ظ�������
	for (int i = 0; i < TEA; i++) {
		tea[i].setInformation(30, 10002, 2, "��������", "���ӹ���ϵ", "����");
		tea[i].getInformation();
		cout << endl;
	}
	for (int i = 0; i < GRA; i++) {
		gra[i].setInformation(25, 10003, 1, "����", "��25", "���ӹ���ϵ", "��������");
		gra[i].getInformation();
		cout << endl;
	}
	for (int i = 0; i < TA; i++) {
		ta[i].setInformation(26, 10004, 2, "����", "��01", "������Ϣ�о�Ժ", "�����", "���ӹ���ϵ", "�о�Ա");
		ta[i].getInformation();
		cout << endl;
	}

	Professor pro[1];
	pro[0].setInformation(30, 10004, 2, "������", "���ӹ���ϵ", "����");

	FemaleProfessor fpro[1];
	fpro[0].setInformation(30, 10005, 2, "�", "���ӹ���ϵ", "����");

	Teacher* pt = tea;
	pt->getInformation();
	pt->getPay();
	cout << endl;

	Professor* pp = pro;
	pp->getInformation();
	pp->getPay();
	cout << endl;

	FemaleProfessor* pf = fpro;
	pf->getInformation();
	pf->getPay();
	cout << endl;

	return 0;
}