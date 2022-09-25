#include<iostream>
#include<string.h>
#include<fstream>
int acroom=3000;
int nonacroom=2000;
using namespace std;

class reserver
{
protected:

    char name[100];
    char phoneNo[20];
    char roomNo[10];
    char date[15];
    string type;
    char checkindate[15];
    char checkoutdate[15];
    int spendingdays;
    int bills;
    char rname[100];
    char id[50];


    int opt_for_roomtype;

public:

    void getdata()
    {
        fstream customer;

        customer.open("Reserver Info.txt",ios::app);

        cin.ignore();

        cout<<"\n\n\t\tEnter name: ";
        cin.getline(name,100);

        cout<<"\t\tEnter phone number: ";
        cin.getline(phoneNo,20);

        cout<<"\t\tEnter room number: ";
        cin.getline(roomNo,10);

        cout<<"\t\tEnter date: ";
        cin.getline(date,15);

        cout<<"\t\tEnter room type \n\t\t1.AC 2.Non-AC: ";
        cin>>opt_for_roomtype;
        switch(opt_for_roomtype)
        {
        case 1:
        {
            type="AC";
            break;
        }
        case 2:
        {
            type="Non-AC";
            break;
        }

        }
        cin.ignore();

        cout<<"\t\tEnter check in date: ";
        cin.getline(checkindate,15);

        cout<<"\t\tEnter checkout date: ";
        cin.getline(checkoutdate,15);

        cout<<"\t\tEnter spending days: ";
        cin>>spendingdays;

        cin.ignore();
        cout<<"\t\tEnter receiver name: ";
        cin.getline(rname,100);
        cout<<"\t\tEnter receiver ID: ";
        cin.getline(id,50);

        if(type == "AC" || type == "ac")
        {
            bills=acroom*spendingdays;
        }
        else
        {
            bills=nonacroom*spendingdays;
        }



        customer<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;
        customer.close();

    }

    void display_msg()
    {
        cout<<"\n\t\tYour records have been added successfully!"<<endl;
    }



};



class searchReserver:public reserver
{
public:
    void Search()
    {
        fstream searchR;
        searchR.open("Reserver Info.txt",ios::in);
        cin.ignore();
        char a[10];
        cout<<"\n\n\t\tEnter room no. to search: ";
        cin.getline(a,10);
        int flag=0;
        while(!searchR.eof())
        {

            searchR>>name;
            searchR>>phoneNo;
            searchR>>roomNo;
            searchR>>date;
            searchR>>type;
            searchR>>checkindate;
            searchR>>checkoutdate;
            searchR>>spendingdays;
            searchR>>bills;
            searchR>>rname;
            searchR>>id;


            if(strcmp(roomNo,a)==0)

            {
                cout<<"\n\t\tReserver name: "<<name<<endl;
                cout<<"\t\tReserver phone no: "<<phoneNo<<endl;
                cout<<"\t\tRoom no: "<<roomNo<<endl;
                cout<<"\t\tDate: "<<date<<endl;
                cout<<"\t\tRoom type: "<<type<<endl;
                cout<<"\t\tCheck in date: "<<checkindate<<endl;
                cout<<"\t\tCheck out date: "<<checkoutdate<<endl;
                cout<<"\t\tSpending days: "<<spendingdays<<endl;

                cout<<"\t\tBills: "<<bills<<endl;


                flag=1;
                break;
            }


        }
        if(flag==0)
        {
            cout<<"\n\n\t\tRecords not found!"<<endl;
        }

        searchR.close();
    }
};



class editReserver:public reserver
{
public:
    void edit()
    {
        fstream editreserver;
        fstream temp;
        editreserver.open("Reserver Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);

        char a[10];
        cin.ignore();
        cout<<"\n\n\t\tEnter room no to edit info: ";
        cin.getline(a,10);

        while(!editreserver.eof())

        {

            editreserver>>name;
            editreserver>>phoneNo;
            editreserver>>roomNo;
            editreserver>>date;
            editreserver>>type;
            editreserver>>checkindate;
            editreserver>>checkoutdate;
            editreserver>>spendingdays;
            editreserver>>bills;
            editreserver>>rname;
            editreserver>>id;
            if(strcmp(roomNo,a)==0)
            {
                cout<<"\n\t\tEnter new info: "<<endl;
                cout<<"\n\t\tEnter name: ";
                cin.getline(name,100);

                cout<<"\t\tEnter phone number: ";
                cin.getline(phoneNo,20);

                cout<<"\t\tEnter room number: ";
                cin.getline(roomNo,10);

                cout<<"\t\tEnter date: ";
                cin.getline(date,15);

                cout<<"\t\tEnter room type: \n\t\t1.AC 2.Non-AC"<<endl;
                cin>>opt_for_roomtype;
                switch(opt_for_roomtype)
                {
                case 1:
                {
                    type="AC";
                    break;
                }
                case 2:
                {
                    type="Non-AC";
                    break;
                }

                }
                cin.ignore();

                cout<<"\t\tEnter check in date: ";
                cin.getline(checkindate,15);

                cout<<"\t\tEnter checkout date: ";
                cin.getline(checkoutdate,15);

                cout<<"\t\tEnter spending days: ";
                cin>>spendingdays;

                cin.ignore();
                cout<<"\t\tEnter receiver name: ";
                cin.getline(rname,100);
                cout<<"\t\tEnter receiver ID: ";
                cin.getline(id,50);

                if(type == "AC" || type == "ac")
                {
                    bills=acroom*spendingdays;
                }
                else
                {
                    bills=nonacroom*spendingdays;
                }


                temp<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;


            }

            else
            {

                temp<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;
            }
        }

        temp.close();
        editreserver.close();

        editreserver.open("Reserver Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);
        while(!temp.eof())
        {

            temp>>name;
            temp>>phoneNo;
            temp>>roomNo;
            temp>>date;
            temp>>type;
            temp>>checkindate;
            temp>>checkoutdate;
            temp>>spendingdays;
            temp>>bills;
            temp>>rname;
            temp>>id;

            editreserver<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;


        }

        temp.close();
        editreserver.close();

        remove("Temp.txt");



    }

    void display_msg()
    {
        cout<<"\n\t\tYour info have been edited!"<<endl;
    }
};

class deleteReserver:public reserver
{
public:
    void Delete()
    {
        fstream deletereserver;
        fstream temp;

        deletereserver.open("Reserver Info.txt",ios::in);
        temp.open("Temp.txt",ios::out);

        char a[10];
        cin.ignore();
        cout<<"\n\n\t\tEnter room no to delete info: ";
        cin.getline(a,10);

        while(!deletereserver.eof())
        {
            deletereserver>>name;
            deletereserver>>phoneNo;
            deletereserver>>roomNo;
            deletereserver>>date;
            deletereserver>>type;
            deletereserver>>checkindate;
            deletereserver>>checkoutdate;
            deletereserver>>spendingdays;
            deletereserver>>bills;
            deletereserver>>rname;
            deletereserver>>id;
            if(strcmp(roomNo,a)==0)
            {
                continue;
            }
            else
            {
                temp<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;
            }

        }

        temp.close();
        deletereserver.close();


        deletereserver.open("Reserver Info.txt",ios::out);
        temp.open("Temp.txt",ios::in);

        while(!temp.eof())
        {

            temp>>name;
            temp>>phoneNo;
            temp>>roomNo;
            temp>>date;
            temp>>type;
            temp>>checkindate;
            temp>>checkoutdate;
            temp>>spendingdays;
            temp>>bills;
            temp>>rname;
            temp>>id;

            deletereserver<<name<<" "<<phoneNo<<" "<<roomNo<<" "<<date<<" "<<type<<" "<<checkindate<<" "<<checkoutdate<<" "<<spendingdays<<" "<<bills<<" "<<rname<<" "<<id<<endl;
        }

        temp.close();
        deletereserver.close();

        remove("Temp.txt");




    }
    void display_msg()
    {
        cout<<"\n\n\t\tYour records have been deleted!"<<endl;
    }


};




class searchReceiver: public reserver
{
public:
    void searchR()
    {
        fstream searchreceiver;

        searchreceiver.open("Reserver Info.txt",ios::in);
        cin.ignore();

        char a[50];
        cout<<"\n\n\t\tEnter receiver's id to search: ";
        cin.getline(a,50);

        int flag=0;
        while(!searchreceiver.eof())
        {
            searchreceiver>>name;
            searchreceiver>>phoneNo;
            searchreceiver>>roomNo;
            searchreceiver>>date;
            searchreceiver>>type;
            searchreceiver>>checkindate;
            searchreceiver>>checkoutdate;
            searchreceiver>>spendingdays;
            searchreceiver>>bills;
            searchreceiver>>rname;
            searchreceiver>>id;


            if(strcmp(id,a)==0)
            {
                cout<<"\n\t\tReceiver name: "<<rname<<endl;
                cout<<"\t\tReceiver id: "<<id<<endl;
                cout<<"\t\tInformation under "<<rname<<" is:"<<endl;

                cout<<"\t\tReserver name: "<<name<<endl;
                cout<<"\t\tReserver phone no: "<<phoneNo<<endl;
                cout<<"\t\tRoom no: "<<roomNo<<endl;
                cout<<"\t\tDate: "<<date<<endl;

                flag=1;
                break;

            }


        }




        if(flag==0)
        {
            cout<<"\n\t\tNo records found!"<<endl;
        }

        searchreceiver.close();



    }



};




int main()
{

    cout<<"\n\n\t\t\t\t\t\tHotel Reservation System"<<endl;
    int password;
    int pass=28;
    cout<<"\n\n\n\t\tEnter password to continue: ";
    cin>>password;

    if(password==pass)
    {
        int second_option;

        do
        {
            cout<<"\n\n\t\t1. Add new reservation"<<endl;
            cout<<"\t\t2. Search of information"<<endl;
            cout<<"\t\t3. Edit information"<<endl;
            cout<<"\t\t4. Delete information"<<endl;
            cout<<"\t\tEnter your choice: ";
            int third_option;
            cin>>third_option;
            switch(third_option)
            {
            case 1:
            {
                reserver r;
                r.getdata();
                r.display_msg();
                break;
            }
            case 2:
            {
                int fourth_option;
                do
                {
                    cout<<"\n\n\t\t1. Reserver Information"<<endl;
                    cout<<"\t\t2. Receiver information"<<endl;
                    cout<<"\t\tEnter your choice: ";

                    int optS;
                    cin>>optS;

                    switch(optS)
                    {
                    case 1:
                    {
                        searchReserver s;
                        s.Search();
                        break;
                    }
                    case 2:
                    {
                        searchReceiver s;
                        s.searchR();
                        break;
                    }
                    default:
                    {
                        cout<<"\t\tWrong input!"<<endl;
                        fourth_option=0;
                    }

                    }

                    cout<<"\t\tPress 0 to search again"<<endl;
                    cout<<"\t\tPress 1 to return to menu"<<endl;
                    cout<<"\t\tEnter your choice: ";
                    cin>>fourth_option;

                }
                while(fourth_option!=1);
                break;
            }

            case 3:
            {
                editReserver e;
                e.edit();
                e.display_msg();
                break;
            }
            case 4:
            {
                deleteReserver d;
                d.Delete();
                d.display_msg();
                break;
            }
            default:
            {
                cout<<"\t\tWrong input"<<endl;
                second_option=0;
            }

            }

            cout<<"\t\tPress 0 to go to the main menu"<<endl;
            cout<<"\t\tPress 1 to exit"<<endl;
            cout<<"\t\tEnter your choice: ";
            cin>>second_option;

        }
        while (second_option!=1);
        return 0;
    }

    else
    {
        cout<<"\t\tPassword error"<<endl;
        return 0;
    }
}







