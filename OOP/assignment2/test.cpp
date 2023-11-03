//
//#include <iostream>
//using namespace std;
//class B;
//class student
//{
//private:
//
//string driving_license_no;
//
//public:
//string name;
//int Roll_No;
//int Class;
//string Division;
//string DOB;
//string blood_group;
//string contact_address;
//long telephone_no;
//
//friend class B;
//
//void getdetails(){
//        cout<<"enter name: ";
//        cin.ignore();
//        getline(cin,name);
//        cout<<"enter roll no: ";
//        cin>>Roll_No;
//        cout<<"enter class: ";
//        cin>>Class;
//        cout<<"enter division: ";
//        cin>>Division;
//        cout<<"enter your date of birth: ";
//        cin>>DOB;
//        cout<<"enter blood group: ";
//        cin>>blood_group;
//        cout<<"enter contact address: ";
//        cin.ignore();
//        getline(cin,contact_address);
//        cout<<"enter telephone number: ";
//        cin>>telephone_no;
//        cout<<"enter driving license number: ";
//        cin.ignore();
//        getline(cin,driving_license_no);
//}
//void display(){
//		cout<<"name: "<<name<<endl;
//		cout<<"roll no: "<<Roll_No<<endl;
//		cout<<"class: "<<Class<<endl;
//		cout<<"Division: "<<Division<<endl;
//		cout<<"Date of BIrth: "<<DOB<<endl;
//		cout<<"blood group: "<<blood_group<<endl;
//		cout<<"contact address: "<<contact_address<<endl;
//		cout<<"telephone number: "<<telephone_no<<endl;}
//students(string name , int Roll_No , int Class , string Division , string DOP , string blood_group , string contact_address, int telephone_no , int driving_license_no )
//{
//    this->name = name;
//    this->Roll_No = Roll_No;
//    this->Class = Class;
//    this->Division = Division;
//    this->DOP = DOP;
//    this->blood_group = blood_group;
//    this->contact_address = contact_address;
//    this->telephone_no = telephone_no;
//    this->driving_license_no = telephone_no;
//}
//vo
//};
//
//class B{
//    public:
//	void display(student& t){
//		cout<<"driving license number: "<<t.driving_license_no<<endl;
//	}
//};
//
//int main()
//
//{
//student s;
//B obj;
//s.getdetails();
//
//cout<<endl;
//
//obj.display(s);
//return 0;
//}
