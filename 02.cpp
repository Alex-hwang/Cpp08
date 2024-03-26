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
		cout << "Age: " << (m_Age == 1 ? "男" : "女") << " ";
		cout << "Number: " << m_Number << " ";
	}
	Person() {
		cout << "Person构造函数" << endl;
	}
	~Person() {
		cout << "Person析构函数" << endl;
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
		cout << "Teacher构造函数" << endl;
	}
	~Teacher() {
		cout << "Teacher析构函数" << endl;
	}
	void getPay() {
		cout << "Pay: " << m_Pay << " ";
	}
};

class Professor :private Teacher {
public:
	//构造函数
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
	//构造函数
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
		cout << "Student构造函数" << endl;
	}
	~Student() {
		cout << "Student析构函数" << endl;
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
		cout << "Graduate构造函数" << endl;
	}
	~Graduate() {
		cout << "Graduate析构函数" << endl;
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
		cout << "TeacherAssistant构造函数" << endl;
	}
	~TeacherAssistant() {
		cout << "TeacherAssistant析构函数" << endl;
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
		cout << "请输入年龄：";
		cin >> age;
		cout << "请输入学号：";
		cin >> num;
		cout << "请输入性别：(1-男，2-女）";
		cin >> sex;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入班级：";
		cin >> classno;
		stu[i].setInformation(age, num, sex, name, classno);
		stu[i].getInformation();
		cout << endl;
	}

	//同样的操作，为了方便测试，就不重复输入了
	for (int i = 0; i < TEA; i++) {
		tea[i].setInformation(30, 10002, 2, "王二麻子", "电子工程系", "教授");
		tea[i].getInformation();
		cout << endl;
	}
	for (int i = 0; i < GRA; i++) {
		gra[i].setInformation(25, 10003, 1, "赵六", "无25", "电子工程系", "王二麻子");
		gra[i].getInformation();
		cout << endl;
	}
	for (int i = 0; i < TA; i++) {
		ta[i].setInformation(26, 10004, 2, "老六", "无01", "交叉信息研究院", "李大眼", "电子工程系", "研究员");
		ta[i].getInformation();
		cout << endl;
	}

	Professor pro[1];
	pro[0].setInformation(30, 10004, 2, "王麻子", "电子工程系", "教授");

	FemaleProfessor fpro[1];
	fpro[0].setInformation(30, 10005, 2, "李狗", "电子工程系", "教授");

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