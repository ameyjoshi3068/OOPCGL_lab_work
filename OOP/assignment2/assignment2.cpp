
#include <iostream>
using namespace std;

class StudData;

class Student
{
private:
	string name;
	int roll_no;
	string class_;
	string division;
	string DOB;
	string blood_group;

public:
	static int count;
	Student()
	{
		name = "Amey Joshi";
		roll_no = 21330;
		class_ = "SE";
		division = "3";
		DOB = "0/0/2004";
		blood_group = "A";
	}
	static inline int getcount()
	{
		return count;
	}
	static inline void incCount()
	{
		count++;
	}
	void displayData(StudData *data);
	void setData(StudData *data);

	Student(StudData* sData, Student *s, StudData* secData);

	~Student(){
		cout<<"Destroying data for a student"<<endl;
		count--;
	}
};

class StudData
{
	string address;
	long long tele;
	long long dlNo;

	friend class Student;

public:
	StudData()
	{
		tele = 1234567890;
		dlNo = 12368;
		address = "PICT, Pune";
	}
	void setStudData()
	{
		cout << "enter contact address: ";
		cin.ignore();
		getline(cin, address);
		cin.clear();
		cout << "enter telephone number: ";
		cin >> tele;
		cout << "enter driving license number: ";
		cin >> dlNo;
		cin.clear();
	}
	void displayData()
	{
		cout << "contact address: " << address << endl;
		cout << "Telephone number: " << tele << endl;
		cout << "Driving license number: " << dlNo << endl;
	}
};

void Student::setData(StudData *data)
{
	cout << "enter name: ";
	cin.get();
	getline(cin, name);
	cin.clear();
	cout << "enter roll no: ";
	cin >> roll_no;
	cout << "enter class: ";
	cin >> class_;
	cout << "enter division: ";
	cin >> division;
	cout << "enter date of birth: ";
	cin >> DOB;
	cout << "enter blood group: ";
	cin >> blood_group;
	data->setStudData();
	cin.clear();
	cout<<"\n\n";
}

void Student::displayData(StudData *data)
{
	cout << "name: " << name << endl;
	cout << "roll no: " << roll_no << endl;
	cout << "class: " << class_ << endl;
	cout << "Division: " << division << endl;
	cout << "Date of Birth: " << DOB << endl;
	cout << "Blood Group: " << blood_group << endl;
	data->displayData();
}

Student::Student(StudData* sData, Student *sec, StudData* secData) // Copy Constructor
	{
		name = sec->name;
		roll_no = sec->roll_no;
		class_ = sec->class_;
		division = sec->division;
		DOB = sec->DOB;
		blood_group = sec->blood_group;
		sData->tele = secData->tele;
		sData->dlNo = secData->dlNo;
		sData->address = secData->address;
	}

int Student::count = 0;

int main()

{
	cout << "How many enteries do you want to store: ";
	int n;
	cin >> n;
	pair<Student *, StudData *> studentDatabase[n];

	while (1)
	{
		int ch;
		printf("-----------------------------------------\n");
		printf("☺☺☺☺☺------Main Menu------☺☺☺☺☺\n");
		printf("-----------------------------------------");
		printf("\n 1:Initiate with default data");
		printf("\n 2:Enter the data inside database");
		printf("\n 3:Create copy of ith entery to jth position");
		printf("\n 4:Display the data for all students");
		printf("\n 5:Show number of entries in database");
		printf("\n 6:Use destructor");
		printf("\n 7:Exit");
		printf("\n----------------------------------------\n");
		printf("Enter Your Choice : ");
		cin >> ch;
		cout<<"\n\n";
		switch (ch)
		{
		case 1:
		{
			cout << "Initializing default data for "<<n<<" students: "<<"\n\n";
			for (int i = 0; i < n; i++)
			{
				Student *stdPtr = new Student;
				StudData *dataPtr = new StudData;
				studentDatabase[i] = {stdPtr, dataPtr};
				Student::incCount();
			}
		}
		break;
		case 2:
		{
			int choice;
			for (int i = 0; i < n; i++)
			{
				cout << "Enter the data for " << "student no " << i+1<<endl;
				Student *stdPtr = new Student;
				StudData *dataPtr = new StudData;
				stdPtr->setData(dataPtr);
				studentDatabase[i] = {stdPtr, dataPtr};
				Student::incCount();
				
				cout<< "\n\nPress 1 to enter next data and 0 to exit\n";
				cin>> choice;
				if (choice==0)
				{
					break;
				}
				
			}
		}
		break;
		case 3:
		{
			int i,j;
			cout<<"\nWhich data do you want to copy"<<endl;
			cin>>i;
			cout<<"\nWhere to paste the data"<<endl;
			cin>>j;

			StudData *dataPtr = new StudData;
			Student *stdPtr = new Student(dataPtr,studentDatabase[i-1].first,studentDatabase[i-1].second);
			studentDatabase[j-1] = {stdPtr, dataPtr};
			Student::incCount();

		}
		break;
		case 4:
		{
			cout << "Displaying complete database: "<<"\n\n";
			for (int i = 0; i < n; i++)
			{
				cout << "Showing the data for "<< "Student no " << i+1 <<endl;
				studentDatabase[i].first->displayData(studentDatabase[i].second);
				cout<<"\n\n";
			}
		}
		break;
		case 5:
			cout<<"The count of students is: "<<Student::count;
			break;

		case 6:
			cout<<"XXXX Destroying complete database XXXX"<<"\n\n";
			Student::count=0;
			for (size_t i = 0; i < n; i++){
			
				delete studentDatabase[i].second;
				delete studentDatabase[i].first;
			}
			
			break;
		case 7:
			exit(0);
			break;
		}
		cout<<endl;
	}

	return 0;
}
