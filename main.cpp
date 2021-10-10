#include <iostream>
#include <unistd.h>
#include "queue.h"

using namespace std;


int main()
{
    string n, c;
    int s;
    int y;
    if (!s)
    {
        cout<<"W E L C O M E   T O   R E S E R V A T I O N   P A G E"<<endl<<endl<<endl;
        cout<<"List how many people you want to reserve in the program: ";
        cin>>s;
        cout<<"Loading .";
        sleep(1);
        cout<<" .";
        sleep(1);
        cout<<" .";
        sleep(1);
    }

    iqueue<string> name(s);
    iqueue<int> year(s);
    iqueue<string> course(s);
    iqueue<string> section(s);

    int choice;

    do
    {   choice = 0;
        system("cls");
        cout<<"W E L C O M E   T O   R E S E R V A T I O N   P A G E"<<endl<<endl<<endl;
        cout<<"[1] Add reservation"<<endl;
        cout<<"[2] Print transcript"<<endl<<endl<<endl;
        cout<<"Input your choice here: ";
        cin>>choice;
        cout<<"Loading .";
        sleep(1);
        cout<<" .";
        sleep(1);
        cout<<" .";
        sleep(1);

        switch(choice){
            case 1:
                if(name.isfull())
                {
                    system("cls");
                    cout<<"NO MORE SLOTS!\n";
                    cout<<"Returning to main menu .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                }
                else
                {
                    system("cls");
                    cout<<"R E S E R V I N G"<<endl<<endl;
                    cout<<"Input full name here: ";
                    cin.ignore();
                    getline(cin, n);
                    name.enqueue(n);
                    cout<<"Input your year here: ";
                    cin>>y;
                    year.enqueue(y);
                    cout<<"Input your course here: ";
                    cin.ignore();
                    getline(cin,c);
                    course.enqueue(c);
                    cout<<"Saving .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                }
                break;
            case 2:
                if (name.isempty())
                {
                    system("cls");
                    cout<<"EMPTY!\n";
                    cout<<"Returning to main menu .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                    cout<<" .";
                    sleep(1);
                }
                else
                {
                    system("cls");
                    cout<<"T R A N S C R I P T"<<endl<<endl;
                    for(int i = 0; i<s; i++)
                    {
                        cout<<"Name: "<<name.dequeue(n)<<endl;
                        cout<<"Year: "<<year.dequeue(y)<<endl;
                        cout<<"Course: "<<course.dequeue(c)<<endl<<endl;
                    }
                    cout<<"Finishing up .";
                    sleep(2);
                    cout<<" .";
                    sleep(1);
                    cout<<" .";
                    sleep(2);
                }
                break;
        }

    }while(choice>0);
    return 0;
}
