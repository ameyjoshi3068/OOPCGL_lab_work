#include <iostream>
#include <string>
using namespace std;

class Publications
{
protected:
    string title;
    float price;

public:
    Publications() : title(""), price(0.0) {}

    void getdata()
    {
        cout << "Enter Title : ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price : ";
        cin >> price;
    }

    void displaydata()
    {
        cout << "Title : " << title << endl;
        cout << "Price : Rs." << price << endl;
    }
};

class Book : public Publications
{
private:
    int pagecount;

public:
    Book() : pagecount(0) {}

    void getdata()
    {
        Publications::getdata();
        cout << "Enter the pagecount : ";
        cin >> pagecount;
        try
        {
            if (pagecount <= 0 && price <= 0)
            {
                pagecount = 0;
                price = 0;
                throw "Price & Pages Can't Be Zero or Negative\n";
            }
            else if (price <= 0)
            {
                price = 0;
                throw "Price Can't Be Negative\n";
            }
            else if (pagecount <= 0)
            {
                pagecount = 0;
                throw "Pages Can't Be Zero or Negative\n";
            }
        }
        catch (const char *ex)
        {
            cout << ex;
        }
    }

    void displaydata()
    {
        Publications::displaydata();
        cout << "Pagecount : " << pagecount << endl;
    }
};

class Tape : public Publications
{
private:
    float playtime;

public:
    Tape() : playtime(0.0) {}

    void getdata()
    {
        Publications::getdata();
        cout << "Enter the Streaming Time (in Minutes) : ";
        cin >> playtime;
        try
        {
            if (playtime <= 0 && price <= 0)
            {
                playtime = 0;
                price = 0;
                throw "Price & Pages Can't Be Zero or Negative\n";
            }
            else if (price <= 0)
            {
                price = 0;
                throw "Price Can't Be Negative\n";
            }
            else if (playtime <= 0)
            {
                playtime = 0;
                throw "Reading Time Can't Be Zero or Negative\n";
            }
        }
        catch (const char *ex)
        {
            cout << ex;
        }
    }

    void displaydata()
    {
        Publications::displaydata();
        cout << "Streaming time of Audio Tape is : " << playtime << endl;
    }
};

int main()
{
    int choice;
    Book book;
    Tape tape;
    do
    {
        cout << "\n";
        cout << "---------------------Menu----------------------" << '\n'
             << endl;
        cout << "1. Enter Book Information." << endl;
        cout << "2. Enter Audio Tape Information." << endl;
        cout << "3. Display Book Information.";
        cout << "\n4. Display Audio Tape Information.";
        cout << "\n5. Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        cout << '\n';
        cout << "------------------------------------------------" << endl;
        cout << '\n';

        switch (choice)
        {
        case 1:
            book.getdata();
            break;
        case 2:
            tape.getdata();
            break;
        case 3:
            book.displaydata();
            break;
        case 4:
            tape.displaydata();
        case 5:
            cout << "Thank You!" << endl;
            break;
        default:
            cout << "Select valid option" << endl;
        }
    } while (choice != 5);
    return 0;
}
