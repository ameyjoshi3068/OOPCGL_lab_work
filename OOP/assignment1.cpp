#include<iostream>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>

using namespace std;

/*Implement a class Complex which represents the Complex Number data type.
Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >>to print and read Complex Numbers.*/

class ComplexNumber
{
	int realPart;
	int imaginaryPart;
public:

	friend ostream &operator<<(ostream &out,ComplexNumber c);
	friend istream &operator>>(istream &in,ComplexNumber &c);

    ComplexNumber(){
        realPart=0;
        imaginaryPart=0;
    }

    ComplexNumber(int r,int i){
        realPart=r;
        imaginaryPart=i;
    }

// Complex Addition
    ComplexNumber operator+(ComplexNumber num2){
        ComplexNumber answer;
        answer.realPart=realPart+num2.realPart;
        answer.imaginaryPart=imaginaryPart+num2.imaginaryPart;
        return answer;
    }

//Complex Multiplication
    ComplexNumber operator*(ComplexNumber num2){
        ComplexNumber answer;
        answer.realPart=(realPart*num2.realPart)-(imaginaryPart*num2.imaginaryPart);
        answer.imaginaryPart=(realPart*num2.imaginaryPart)-(imaginaryPart*num2.realPart);
        return answer;
    }

};

//operator overloading
    ostream &operator<<(ostream &out,ComplexNumber c){
    	if (c.imaginaryPart>=0){
    		out<< c.realPart << '+' << c.imaginaryPart << "i";
    	}
    	else{
    		out<< c.realPart<< c.imaginaryPart << "i";
    	}
        return out;
    }

    istream &operator>>(istream &in,ComplexNumber &c){
    	cout << "Enter real part: ";
        in >> c.realPart;
    	cout << "Enter imaginary part: ";
    	in >> c.imaginaryPart;
            return in;
        }

int main(int argc, char const *argv[])
{

	ComplexNumber num1;
	ComplexNumber num2;

    cout<<"Default Constructor values"<<endl;
    cout<<" a = "<<num1<<endl;
    cout<<" b = "<<num2<<endl;

	cout << "For Object a:"<<endl;
    cin >> num1 ;
    
    cout << "For Object b:"<<endl;
    cin >> num2 ;
    
    cout << "Addition of a and b : " << num1+num2 <<endl;
    cout << "Multiplication of a and b : " << num1*num2<<endl;
    return 0;
}
