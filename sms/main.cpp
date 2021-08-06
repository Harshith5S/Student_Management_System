#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>

using namespace std;

class student
{
    private:
        string usn, std_name, dob, gender, mother_name, father_name, address, std_phno, std_email_id, branch, semester, tenth, puc, cgpa, total_fee, paid_fee, due_fee;

    public:
        void login();
        void menu();
        void insert();
        void display();
        void modify();
        void search();
        void deleted();
};

void student::login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";

    do
    {
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|      LOGIN TO ACCESS      |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| ENTER USERNAME: ";
        cin >> uname;
        cout << "\t\t\t| ENTER PASSWORD: ";

        while (i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        i=0;

        if (strcmp(uname,"admin")==0 && strcmp(pword,"pass123")==0)
        {
            cout << "\n\t\t\tLOGIN IS SUCCESSFUL";
            getch();
            menu();
            system("cls");
        }

        else
        {
            cout << "\n\t\t\tLOGIN IS UNSUCESSFUL";
            a++;
            getch();
            system("cls");
        }
    } while (a<=2);

	if (a>2)
	{
		cout << "\n\t\t\tSorry you have entered the wrong credentials";
		getch();
    }
    system("cls");
}

void student::menu()
{
    menustart:
        int choice;
        char x;
        system("cls");
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t| ADMINISTRATIVE DETAILS OF STUDENT |" << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Exit" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                do
                {
                    insert();
                    cout << "\n\t\t\t Add Another Student Record (Y,N): ";
                    cin >> x;
                } while (x == 'y' || x == 'Y');
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleted();
                break;
            case 6:
                exit(0);
            default:
                cout << "\n\t\t\t Invalid Choice, please try again";
        }
        getch();
        goto menustart;
}

void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
    cout << "\n--------------------------------------- Add Student Details -----------------------------------------" << endl;
    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tEnter USN: ";
    cin >> usn;
    cout << "\t\t\tEnter Student Name: ";
    cin >> std_name;
    cout << "\t\t\tEnter DOB: ";
    cin >> dob;
    cout << "\t\t\tEnter Gender: ";
    cin >> gender;
    cout << "\t\t\tEnter Mother Name: ";
    cin >> mother_name;
    cout << "\t\t\tEnter Father Name: ";
    cin >> father_name;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    cout << "\t\t\tEnter Student Phone Number: ";
    cin >> std_phno;
    cout << "\t\t\tEnter Student Email ID: ";
    cin >> std_email_id;
    cout << "\t\t\tEnter Branch: ";
    cin >> branch;
    cout << "\t\t\tEnter Semester: ";
    cin >> semester;
    cout << "\t\t\tEnter 10th Marks: ";
    cin >> tenth;
    cout << "\t\t\tEnter 2nd PUC Marks: ";
    cin >> puc;
    cout << "\t\t\tEnter CGPA: ";
    cin >> cgpa;
    cout << "\t\t\tEnter Total Fee: ";
    cin >> total_fee;
    cout << "\t\t\tEnter Paid Fee: ";
    cin >> paid_fee;
    cout << "\t\t\tEnter Due Fee: ";
    cin >> due_fee;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << usn << " " << std_name << " " << dob << " " << gender << " " << mother_name << " " << father_name << " " << address << " "  << std_phno << " " << std_email_id << " " << branch << " " << semester << " " << tenth << " " << puc << " " << cgpa << " " << total_fee << " " << paid_fee << " " << due_fee <<"\n";
    file.close();
}

void student::display()
{
    system("cls");
    fstream file;
    int total =1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------- Student Records ------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Record Available";
        file.close();
    }

    else
    {
        file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;

        while (!file.eof())
        {
            cout << "\n\t\t Student Number: " << total++ << endl;
            cout << "\t\t\t USN: " << usn << endl;
            cout << "\t\t\t Student Name: " << std_name << endl;
            cout << "\t\t\t DOB: " << dob << endl;
            cout << "\t\t\t Gender: " << gender << endl;
            cout << "\t\t\t Mother Name: " << mother_name << endl;
            cout << "\t\t\t Father Name: " << father_name << endl;
            cout << "\t\t\t Address: " << address << endl;
            cout << "\t\t\t Student Phone Number: " << std_phno << endl;
            cout << "\t\t\t Student Email ID: " << std_email_id << endl;
            cout << "\t\t\t Branch: " << branch << endl;
            cout << "\t\t\t Semester: " << semester << endl;
            cout << "\t\t\t 10th Marks: " << tenth << endl;
            cout << "\t\t\t 2nd PUC Marks: " << puc << endl;
            cout << "\t\t\t CGPA: " << cgpa << endl;
            cout << "\t\t\t Total Fee: " << total_fee << endl;
            cout << "\t\t\t Paid Fee: " << paid_fee << endl;
            cout << "\t\t\t Due Fee: " << due_fee << endl;
            file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;
        }

        if (total == 1)
        {
            cout << "\n\t\t\tNo Record Available";
        }
    }
    file.close();
}

void student::modify()
{
    system("cls");
    fstream file, file1;
    string urn;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------- Modify Student Records -----------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Record Available";
    }

    else
    {
        cout << "\nEnter USN of student which you want to modify: ";
        cin >> urn;
        file1.open("record.txt", ios::app | ios::out);
        file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;

        while (!file.eof())
        {
            if (urn != usn)
            {
                file1 << " " << usn << " " << std_name << " " << dob << " " << gender << " " << mother_name << " " << " " << father_name << " " << address << " " << std_phno << " " << std_email_id << " " << branch << " " << semester << " " << tenth << " " << puc << " " << cgpa << " " << total_fee << " " << paid_fee << " " << due_fee << "\n";
            }

            else
            {
                cout << "\t\t\tEnter USN: ";
                cin >> usn;
                cout << "\t\t\tEnter Student Name: ";
                cin >> std_name;
                cout << "\t\t\tEnter DOB: ";
                cin >> dob;
                cout << "\t\t\tEnter Gender: ";
                cin >> gender;
                cout << "\t\t\tEnter Mother Name: ";
                cin >> mother_name;
                cout << "\t\t\tEnter Father Name: ";
                cin >> father_name;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                cout << "\t\t\tEnter Student Phone Number: ";
                cin >> std_phno;
                cout << "\t\t\tEnter Student Email ID: ";
                cin >> std_email_id;
                cout << "\t\t\tEnter Branch: ";
                cin >> branch;
                cout << "\t\t\tEnter Semester: ";
                cin >> semester;
                cout << "\t\t\tEnter 10th Marks: ";
                cin >> tenth;
                cout << "\t\t\tEnter 2nd PUC Marks: ";
                cin >> puc;
                cout << "\t\t\tEnter CGPA: ";
                cin >> cgpa;
                cout << "\t\t\tEnter Total Fee: ";
                cin >> total_fee;
                cout << "\t\t\tEnter Paid Fee: ";
                cin >> paid_fee;
                cout << "\t\t\tEnter Due Fee: ";
                cin >> due_fee;
                file1 << " " << usn << " " << std_name << " " << dob << " " << gender << " " << mother_name << " " << " " << father_name << " " << address << " " << std_phno << " " << std_email_id << " " << branch << " " << semester << " " << tenth << " " << puc << " " << cgpa << " " << total_fee << " " << paid_fee << " " << due_fee << "\n";
                found++;
            }
            file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;
        }

        if (found == 0)
        {
            cout << "\n\n\t\t\tStudent USN not valid";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n---------------------------------------- Search Student Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t No Record Available";
    }

    else
    {
        string urn;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n---------------------------------------- Search Student Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n Enter USN of student which you want to search: ";
        cin >> urn;
        file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;

        while (!file.eof())
        {
            if (urn == usn)
            {
                cout << "\t\t\t USN: " << usn << endl;
                cout << "\t\t\t Student Name: " << std_name << endl;
                cout << "\t\t\t DOB: " << dob << endl;
                cout << "\t\t\t Gender: " << gender << endl;
                cout << "\t\t\t Mother Name: " << mother_name << endl;
                cout << "\t\t\t Father Name: " << father_name << endl;
                cout << "\t\t\t Address: " << address << endl;
                cout << "\t\t\t Student Phone Number: " << std_phno << endl;
                cout << "\t\t\t Student Email ID: " << std_email_id << endl;
                cout << "\t\t\t Branch: " << branch << endl;
                cout << "\t\t\t Semester: " << semester << endl;
                cout << "\t\t\t 10th Marks: " << tenth << endl;
                cout << "\t\t\t 2nd PUC Marks: " << puc << endl;
                cout << "\t\t\t CGPA: " << cgpa << endl;
                cout << "\t\t\t Total Fee: " << total_fee << endl;
                cout << "\t\t\t Paid Fee: " << paid_fee << endl;
                cout << "\t\t\t Due Fee: " << due_fee << endl;
                found++;
            }
            file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;
        }

        if (found == 0)
        {
            cout << "\n\t\t\tStudent USN not found";
        }
        file.close();
    }
}

void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string drn;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------- Delete Student Record ------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Record Available";
        file.close();
    }

    else
    {
        cout << "\nEnter USN of Student which you want delete the record: ";
        cin >> drn;
        file1.open("record.txt", ios::app | ios::out);
        file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;

        while (!file.eof())
        {
            if (drn != usn)
            {
                file1 << " " << usn << " " << std_name << " " << dob << " " << gender << " " << mother_name << " " << father_name << " " << address << " " << std_phno << " " << std_email_id << " " << branch << " " << semester << " " << tenth << " " << puc << " " << cgpa << " " << total_fee << " " << paid_fee << " " << due_fee << "\n";
            }

            else
            {
                found++;
                cout << "\n\t\t\tStudent Record Deleted Successfully";
            }
            file >> usn >> std_name >> dob >> gender >> mother_name >> father_name >> address >> std_phno >> std_email_id >> branch >> semester >> tenth >> puc >> cgpa >> total_fee >> paid_fee >> due_fee;
        }

        if (found == 0)
        {
            cout << "\n\t\t\t Student USN not found";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

main()
{
    student project;
    project.login();
    return 0;
}
