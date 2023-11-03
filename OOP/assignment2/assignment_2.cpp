/*Develop a program in C++ to create a database of student’s
information system containing the following information:
Name, Roll number, Class, Division, Date of Birth, Blood
group, contact address, Telephone number, Driving license no.
and other. Construct the database with suitable member
functions. Make use of constructor, default constructor, copy
constructor, destructor, static member functions, friend class,
this pointer, inline code and dynamic memory allocation
operators-new and delete as well as exception handling.*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll_no;
    string cls;
    char div;
    string dob;
    string blood_group;
    string address;
    int tel_no;
    string dl_no;
    static int count;

public:
    // Copy constructor
    Student(const Student& other);

    Student();
    void getdata();
    friend void displayStudent(const Student& student); 
    static int getcount();

    ~Student() {
        count--;
    }
};

Student::Student() {
    name = "";
    roll_no = 0;
    cls = "";
    div = '/';
    dob = "dd/mm/yyyy";
    blood_group = "";
    address = "";
    tel_no = 0;
    dl_no = "";
    count++;
}

Student::Student(const Student& other) {
    name = other.name;
    roll_no = other.roll_no;
    cls = other.cls;
    div = other.div;
    dob = other.dob;
    blood_group = other.blood_group;
    address = other.address;
    tel_no = other.tel_no;
    dl_no = other.dl_no;
    count++;
}

inline void Student::getdata() {
    cout << "Enter student name: ";
    cin >> name;
    cout << endl;

    cout << "Enter roll_no of student: ";
    cin >> roll_no;
    cout << endl;

    cout << "Enter Class: ";
    cin >> cls;
    cout << endl;

    cout << "Enter division: ";
    cin >> div;
    cout << endl;

    cout << "Enter DOB: ";
    cin >> dob;
    cout << endl;

    cout << "Enter Blood group: ";
    cin >> blood_group;
    cout << endl;

    cout << "Enter Address: ";
    cin >> address;
    cout << endl;

    cout << "Enter telephone no: ";
    cin >> tel_no;
    cout << endl;

    cout << "Enter driving license no: ";
    cin >> dl_no;
    cout << endl;
}


void displayStudent(const Student& student) {
    cout << "Student Name : " << student.name << endl;
    cout << "Roll Number : " << student.roll_no << endl;
    cout << "Class : " << student.cls << endl;
    cout << "Division : " << student.div << endl;
    cout << "Date of Birth : " << student.dob << endl;
    cout << "Blood Group : " << student.blood_group << endl;
    cout << "Address: " << student.address << endl;
    cout << "Telephone No: " << student.tel_no << endl;
    cout << "Driving License: " << student.dl_no << endl;
}

int Student::getcount() {
    return count;
}

int Student::count = 0;

int main() {
    Student* stds[100];
    int n = 0;
    char ch;

    do {
        stds[n] = new Student;
        stds[n]->getdata();
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << endl;
        displayStudent(*stds[i]); 
    }

    for (int i = 0; i < n; i++) {
        delete stds[i];
    }

    return 0;
}
