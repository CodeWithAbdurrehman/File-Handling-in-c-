//This code is just simple example of file handling in c++ so dont expect more from this code :) 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class student
{
protected:
    int rollno, age;
    char name[30];
    student()
    {
        rollno = 0;
        for (int i = 0; i < 30; i++)
        {
            name[i] = ' ';
        }
    }
    void setdata();
    void upload_data();
    void editdata();
    void deletedata();
    void searchdata();
    friend void menu();         //declaring this because I want my main in one line
};
void student::setdata()
{
    cout << "\n\nEnter roll no: ";
    cin >> rollno;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}
void student::upload_data()
{
    //uploading data inputted data to file
    ofstream file("Record.txt", ios::app);
    if (file.is_open())
    {
        file << rollno << endl
             << name << endl
             << age << endl;
        cout << "\n_________________________________\n";
        cout << "DATA UPLOADED SUCCSESFULLY :)\n";
        cout << "_________________________________\n\n";
    }
    else
    {
        cout << "ERROR OPENING FILE!!\n";
    }
    file.close();
    //your data is stored in txt file named as record
    //this file will be saved along with your cpp file 
}
void student::editdata()
{

    ofstream outFile("replaced.txt");   //temporary file
    ifstream readFile("record.txt");    //actual file
    int choice;
    string readout;
    string search;
    string replace;
    cout << "What do you want to replace\n1.Rollno\n2.Name\nChoice: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter Which Roll no you want to replace : ";
        cin >> readout;
        while (readFile.good())
        {
            getline(readFile, search);
            if (readout == search)
            {
                cout << "\nEnter new roll no: ";
                cin >> replace;
                outFile << replace<<endl;
            }
            else
            {

                outFile << search << endl;
            }
        }
        outFile.close();
        readFile.close();
        remove("record.txt");   //deleting record file
        rename("replaced.txt", "record.txt");   //renaming file to your actual file so that your overall file count will be 1
    }
    else if (choice == 2)
    {
        cout << "\nEnter which name you want to replace: ";
        cin >> readout;
        while (readFile.good())
        {
            getline(readFile, search);
            if (readout == search)
            {
                cout << "\nEnter new name: ";
                cin >> replace;
                outFile << replace<<endl;
            }
            else
            {
                outFile << search << endl;
            }
        }
        outFile.close();
        readFile.close();
        remove("record.txt");
        rename("replaced.txt", "record.txt");
    }
    // I dont know how to replace record by only taking single word(roll no in this case) so you ca change record word by word 
    //or digit by digit 
}
void student::deletedata()
{
    int flag = 1;
    char c;
    int d;
    string search;
    string read;
    ifstream in("record.txt");
    ofstream out("replaced.txt", ios::trunc);
    cout << "\nEnter roll no to delete data: ";
    cin >> search;
    while (in.good())
    {
        getline(in, read);
        if (read == search)
        {
            cout << "\n|___RECORD FOUND__|\n";
            for (int i = 0; i < 3; i++)
            {
                getline(in, read);
                cout << read << endl;
            }
            cout << "\n|__CONFIRM DELETE__|\nchoice(y/n): ";
            cin >> c;
            if (c == 'Y' || c == 'y')
            {   
                
                    out << "                        " << endl;      //this will delete your desired record
                    out << "                        " << endl;
                    out << "                        " << endl;
                
            }
            else if (c == 'N' || c == 'n')
            {
                out << read << endl;
            }
            
        }

        flag++;
    }
    out.close();
    in.close();
    remove("record.txt");
    rename("replaced.txt","record.txt");

}
void student::searchdata()
{
    int flag = 1;
    string rol;
    string search;
    string read;
    ifstream obj("record.txt");
    if (obj.is_open())
    {
        cout << "\nEnter roll no you want to search: " << endl;
        cin >> rol;
        while (!obj.eof())
        {
            getline(obj, search);
            if (search == rol)
            {
                cout << "\n|__RECORD FOUND__|\n";
                for (int i = 0; i < 3; i++)
                {
                    getline(obj, read);
                    cout << read << endl;
                }
            }

            ++flag;
        }
    }
    else
    {
        cout << "|__ERROR OPENING FILE!__|" << endl;
    }
    obj.close();
}
void menu()
{
    int choice;
    student s1;

    cout << "\n _________________________\n";
    cout << "|        WELCOME          |";
    cout << "\n|_________________________|\n";

    for (int i = 1; i < 2; i--)
    {
        cout << "\n\n*********************************\n";
        cout << "\nChoose from the following";
        cout << "\n*********************************\n";
        cout << "\n1.Set data\n2.Mofify data\n3.Delete data\n4.Search data\n5.Exit\nchoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            s1.setdata();
            s1.upload_data();
            break;

        case 2:
            s1.editdata();
            break;
        case 3:
            s1.deletedata();
            break;
        case 4:
            s1.searchdata();
            break;
        case 5:
            cout << "\n _________________________\n";
            cout << "|         THANK YOU       |";
            cout << "\n|_________________________|\n";
            break;
        default:
            cout << "\n|___INVALID INPUT___|\n";
            break;
        }
        if (choice == 5)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
int main()
{
    menu();     //friend function called which we declared in line 24
}