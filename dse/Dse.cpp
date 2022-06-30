#include<iostream>//INPUT AND OUTPUTS
#include<string>//string
#include<fstream>//file handling
#include<conio.h>//use for getch()
#include<windows.h>//sleep
#include<iomanip>//setw

using namespace std;

class Queue1{
private:
    string *queuearray;//pointer to create the dynamic arry
    int maxsize;//the size of the array
    int rear;//the index of the rear
    int front;//the index of the front
    int nitems;//the number of items in the queue
    string bookname,checkName,tempBookName,bookName;


public:
    Queue1();//constructor
    void create(string userName,string bookName);
    ~Queue1();//destructor
    void enqueue(string userName);//insert item at the rear of queue
    string dequeue();//remove item at the front of queue
    string peekfront();//peek at front of queue
    bool isEmpty();//true if queue is empty
    bool isFull();//true if queue is full
    int size();//number of items in the queue

    };
class Admin:public Queue1{
private:
    int type,bookId,age,mnum;
    string bookName,bookIsbn,bookType,tempName, fname,lname,email,adminpassword,username,password;

public:
     Admin();
     void addBook();
     void changrSizeOfWaitingList();
     void deleteBook();
     void editBook();
     void addStudent();
     void deleteStudent();
     void editStudent();
     void issuungBooks();
};
class Student:public Queue1{
private:
    int type,rNo;
     string bookName,bookIsbn,bookType,tempbookName,username;

public:
     Student();
     void bookList();
     void reserventbook();
};
class Account{
private:
        int type,age,mnum;
        string fname,lname,email,adminpassword,username,password,tempusername,temppassword,acctype;
public:

friend void pass_value(Account user);

Account();

};
class Stackx{

private:
    int maxsize;
    int *stackArray;
    int top,sizeOfArray,countx;


    bool isEmpty();
    bool isfull();


public:



    Stackx(int s);
    ~Stackx();
    void push(double x);
    double pop();
    double peek();


};

Queue1::Queue1(){//constructor




}
void Queue1::create(string userName,string tempbookName){
bookname=tempbookName;
    tempBookName=tempbookName;
    bookname+=".txt";
    fstream book;
    book.open(bookname.c_str(),ios::in);
    if(!book){
        book.open(bookname.c_str(),ios::app | ios::in);
        cout<<"Your Book is availble"<<endl;
        queuearray=new string[32];
        maxsize=32;
        rear= -1;
        front=0;
        nitems=0;

        fstream appdata;
        appdata.open("appdata.txt",ios::app | ios::in);
        appdata<<bookname<<" "<<maxsize<<" "<<rear<<" "<<front<<" "<<nitems<<endl;

    }

};
Queue1::~Queue1(){
//       delete[]queuearray;
    }
bool Queue1::isEmpty(){//true if queue is empty

     return(nitems==0);
}
bool Queue1::isFull(){//true if queues is full

    return(rear==maxsize-1);

}
int Queue1::size(){//number of items in queue
    return nitems;
}
void Queue1::enqueue(string userName){
if(isFull())//check if queue is full
    {
    cout << "queue is full for this year...";
    }
else
{

    fstream book;
    book.open(bookname.c_str(),ios::app | ios::in);
    book<<userName<<" "<<tempBookName<<endl;
    fstream appdata;
    appdata.open("appdata.txt",ios::app | ios::in);
    fstream temp;
    temp.open("temp.txt",ios::app|ios::in);

    appdata>>checkName>>maxsize>>rear>>front>>nitems;

    while(!appdata.eof()){
        if(bookname==checkName){
            queuearray[++rear]=userName;//insert and increment rear
            nitems++;//one more item
            temp<<bookname<<" "<<maxsize<<" "<<rear<<" "<<front<<" "<<nitems<<endl;

        }else{
            appdata<<bookname<<" "<<maxsize<<" "<<rear<<" "<<front<<" "<<nitems<<endl;
            }
         appdata>>checkName>>maxsize>>rear>>front>>nitems;
    }
    appdata.close();
    temp.close();
    remove("appdata.txt");
    rename("temp.txt","appdata.txt");
}
}
string Queue1::dequeue(){

    if (isEmpty())
{
    cout << "Queue is empty";
    return "no";
}
else
{
   cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER BOOK NAME :";
        cin>>bookName;
        fstream appdata;
        appdata.open("appdata.txt",ios::app | ios::in);
        appdata>>checkName>>maxsize>>rear>>front>>nitems;
        fstream temp;
        temp.open("temp.txt",ios::app |ios::in);
        while(!appdata.eof()){
          if(checkName==bookName){
             nitems--;
            return queuearray[front++];//post fixed notation
            appdata<<checkName<<" "<<maxsize<<" "<<rear<<" "<<front<<" "<<nitems<<endl;
          }else{
            appdata<<checkName<<" "<<maxsize<<" "<<rear<<" "<<front<<" "<<nitems<<endl;
          }

          appdata>>checkName>>maxsize>>rear>>front>>nitems;
        }
        temp.close();
        appdata.close();
        return "000";
}
}
string Queue1::peekfront(){
     if(isEmpty())
    {
        cout<<"Queue is Empty :(";
        return "no";
    }
    else
    {
        return queuearray[front];
    }

}

Stackx::Stackx(int s){

     stackArray=new int[s];
     maxsize=s;
     top=-1;
}
Stackx::~Stackx(){

}
void Stackx::push(double x){

//cout<<isfull()<<endl;
//    cout<<isfull()<<endl;
//top++;
    if(isfull()){

         cout<<"SO SAD!! YOUR ARRAY IS FULL XC"<<endl;
//         ++top;
    }
    else
    {

                stackArray[++top]=x;
                cout<<x<<endl;
    }

     cout<<"this is top"<<top<<endl;
}
double Stackx::pop(){

    return 0;
}
double Stackx::peek(){

cout<<stackArray[2]<<endl;

    for(int i=0;maxsize>i;i++){

        cout<<"index :- "<<i<<"  value is :- "<<stackArray[i]<<endl;
    }

    return 0;
}
bool Stackx::isEmpty(){
    //return(top==-1);
    if(top==-1)
        return true;
    else
        return false;

}
bool Stackx::isfull(){

    return (maxsize==--top);

}

Student::Student(){

    system("color 5");
     lable:
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    WELCOME OUR Student POTRAL"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   MENU...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t01.Book List\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t02.Resarvent Book\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t03.Borrow history\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t04.GOTO MAIN MENU\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t05.EXIT PROGRAM\n"<<endl;

    cin>>type;
        if(type==1){
        bookList();
        }else if(type==2){
        reserventbook();
        }else if(type==3){
        }else if(type==4){
            Account obj2;
        }else if(type==5){
        exit;
        }else
        {   system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
        goto lable;
        }

    cout<<"END PROGRAM....";
}
void Student::bookList(){
    lable5:
    system("cls");
    fstream book;
        book.open("bookList.txt",ios::app | ios::in);
        book>>bookName>>bookIsbn>>bookType;
        if(!book)
        {
            cout<<"\n\n\n\n\n\t\tNO DATA ENTERD YET...."<<endl;
            cout<<"\n\n\t\t\t\t\tPRESS ANY KEY TO MENU::"<<endl;
            getch();
        }else
        {
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\tBOOK LIST\n\n\n"<<endl;
            cout<<"\n\t\t\t\t\t\t BOOK NAME \t\t BOOK ISBN \t\t  BOOk TYPE\n\n"<<endl;

            while(!book.eof())
            {
                cout<<"\t\t\t"<<setw(34)<<bookName<<setw(22)<<bookIsbn<<setw(28)<<bookType<<endl;
                cout<<"\n";
                book>>bookName>>bookIsbn>>bookType;

            }
        }
        getch();
        goto lable5;
}
void Student::reserventbook(){
    system("color 6");
     lable2:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tRESERVENT BOOK"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tBOOK NAME:-";
            cin>>tempbookName;
            cout<<"\n\n\n\t\t\t\t\t\tUSERNAME:-";
            cin>>username;

            fstream book1;
            book1.open("bookList.txt",ios::app | ios::in);
            book1>>bookName>>bookIsbn>>bookType;
            while(!book1.eof())
                {
                if(tempbookName==bookName){

                    Queue1 obj1();
                    fstream book;
                    tempbookName+=".tet";
                    book.open(bookName.c_str(),ios::in);
                    if(!book){
                            create(username,bookName);
                    }
                    enqueue(username);
                }
                book1>>bookName>>bookIsbn>>bookType;
            }
}

Admin::Admin(){

    system("color 3");
     lable2:
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    WELCOME OUR ADMIN POTRAL"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   MENU...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t01.Add Book\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t02.Delete Book\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t03.Edit Book\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t04.Add  Student\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t05.Delete  Student\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t06.Edit Student\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t07.giving books\n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t08.Goto main menu \n"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t09.EXIT PROGRAM \n"<<endl;
    cin>>type;

    if(type==1){
        addBook();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    }else if(type==2){
        deleteBook();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    }else if(type==3){
        editBook();
        goto lable2;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
    }else if(type==4){
        addStudent();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    }else if(type==5){
        deleteStudent();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    }else if(type==6){
        editStudent();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    } else if(type==7){
        Account obj2;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    } else if(type==8){
        issuungBooks();
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
        goto lable2;
    }else if(type==9){
       exit;
    }else{
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   PLEASE ENTER VALIDE NUMBER"<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   ENTER ANYKEY FOR COUNTENU...."<<endl;
        getch();
    goto lable2;
    }
}
void Admin::addBook(){
system("color 6");
     lable2:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tADD BOOK"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tBOOK NAME:-";
            cin>>bookName;
            cout<<"\n\t\t\t\t\t\tENTER BOOK ISBM:-";
            cin>>bookIsbn;
            cout<<"\n\t\t\t\t\t\tENTER BOOK TYPE:-";
            cin>>bookType;


            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream book;
                book.open("bookList.txt",ios::app );
                book<<bookName<<" "<<bookIsbn<<" "<<bookType<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable2;
            }

}
void Admin::changrSizeOfWaitingList(){
    system("color 5");
    system("cls");
    fstream appdata;
    appdata.open("appdata.txt",ios::app | ios::in);
    if(!appdata){
        cout<<"not Data enter Yet";
        getch();
    }else{
     lable:
//    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t    Change Maximum Size of Waiting List"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tYour current maximum value :- ...."<<endl;
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tADD BOOK"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\tBOOK NAME:-";
    cin>>bookName;
    }
}
void Admin::deleteBook(){
  system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER BOOK NAME FOR DELETE:";
        cin>>tempName;
        fstream book;
        book.open("bookList.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!book)
        {
            cout<<"no data yet";
        }else
        {
            book>>bookName>>bookIsbn>>bookType;
            while(!book.eof())
            {
                if(tempName==bookName)
                {
                    book>>bookName>>bookIsbn>>bookType;
                }else
                {
                    temp<<bookName<<" "<<bookIsbn<<" "<<bookType<<endl;
                    book>>bookName>>bookIsbn>>bookType;

                }

            }
            temp.close();
            book.close();

            remove("bookList.txt");
            rename("temp.txt","bookList.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();

        }
}
void Admin::editBook(){
            system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER BOOK NAME FOR EDIT:";
        cin>>tempName;
        fstream book;
        book.open("bookList.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!book)
        {
            cout<<"no data yet";
        }else
        {
            book>>bookName>>bookIsbn>>bookType;
            while(!book.eof())
            {
                if(tempName==bookName)
                {
                    cout<<"\n\n\n\t\t\t\t\t\t\tENTER BOOK NAME:";
                    cin>>bookName;
                    cout<<"\n\n\t\t\t\t\t\t\tENTER ISBN:";
                    cin>>bookIsbn;
                    cout<<"\n\n\t\t\t\t\t\t\tENTER BOOK TYPE:";
                    cin>>bookType;
                    temp<<bookName<<" "<<bookIsbn<<" "<<bookType<<endl;

                    book>>bookName>>bookIsbn>>bookType;
                }else
                {
                    temp<<bookName<<" "<<bookIsbn<<" "<<bookType<<endl;
                    book>>bookName>>bookIsbn>>bookType;

                }

            }
            temp.close();
            book.close();

            remove("bookList.txt");
            rename("temp.txt","bookList.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();

        }
}
void Admin::addStudent(){
//  signup as a STUDENT
            lable1:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO STUDENT PORTAL"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
            cin>>fname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
            cin>>lname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
            cin>>age;
            cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
            cin>>mnum;
            cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
            cin>>email;
            cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
            cin>>username;
            cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
            cin>>password;

            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream signup;
                signup.open("guest.txt",ios::app );
                signup<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable1;
            }
}
void Admin::deleteStudent(){
     system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER STUDENT USER NAME FOR DELETE:";
        cin>>tempName;
        fstream student;
        student.open("guest.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!student)
        {
            cout<<"no data yet";
        }else
        {
//
            student>>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!student.eof())
            {
                if(tempName==username)
                {
                    student>>username>>password>>fname>>lname>>age>>mnum>>email;
                }else
                {
                    temp<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;
                    student>>username>>password>>fname>>lname>>age>>mnum>>email;
                }

            }
            temp.close();
            student.close();

            remove("guest.txt");
            rename("temp.txt","guest.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();

        }
}
void Admin::editStudent(){
    system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tENTER STUDENT USER NAME FOR EDIT:";
        cin>>tempName;
        fstream student;
        student.open("guest.txt",ios::app | ios::in);
        fstream temp;
        temp.open("temp.txt",ios::app | ios::in);
        if(!student)
        {
            cout<<"no data yet";
        }else
        {
//
            student>>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!student.eof())
            {
                if(tempName==username)
                {
                     cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
                    cin>>fname;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
                    cin>>lname;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
                    cin>>age;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
                    cin>>mnum;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
                    cin>>email;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
                    cin>>username;
                    cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
                    cin>>password;
                    temp<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;
                    student>>username>>password>>fname>>lname>>age>>mnum>>email;
                }else
                {
                    temp<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;
                    student>>username>>password>>fname>>lname>>age>>mnum>>email;
                }

            }
            temp.close();
            student.close();

            remove("guest.txt");
            rename("temp.txt","guest.txt");
            cout<<"ENTER ANY KEY TO CONTINU:";
            getch();

        }
}
void Admin::issuungBooks(){
        dequeue();
        getch();
}
Account::Account(){
    lable:
    system("color 2");
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR LIBRARY SYSTEM"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tSIGN IN...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t01.AS ADMIN"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t02.AS STUDENT"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tSIGN UP...."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t03.AS ADMIN"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t04.AS STUDENT"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\tEXIT...."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t05.EXIT PROGRAM"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE_";
    cin>>type;

    if(type==1)
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR RAILWAY SYSTEM"<<endl;
        cout<<"\n\n\t\t\t\t\t ADMIN PORTAL..."<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR USER NAME:-";
        cin>>tempusername;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR PASSWORD:-";
        cin>>temppassword;

        fstream signup;
        signup.open("admin.txt",ios::in);
        if(!signup)
        {
            cout<<"\n\n\n\t\t\t\tNO ANY ADMIN LOGIN YET"<<endl;
            signup.close();
            goto lable;
        }else
        {
            signup>>acctype >>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!signup.eof())
            {
                if(username==tempusername || password==temppassword)
                {

                    cout<<"\n\n\n\t\t\t\tACCOUNT LOGIN SUCCESS.......";
                    cout<<"\n\n\n\t\t\t\t............................"<<endl;
                    Sleep(3000);
                    system("cls");
                    Admin obj2;
                    int x;
                    cin>>x;
                    goto lable;
                }else
                {
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tINVALID LOGIN PLEASE TRY AGAIN...."<<endl;
                    Sleep(3000);
                    goto lable;

                }
                signup>>acctype >>username>>password>>fname>>lname>>age>>mnum>>email;
            }
        }

    }
    else if(type==2)
    {
        system("cls");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO OUR RAILWAY SYSTEM"<<endl;
        cout<<"\n\n\t\t\t\t\t PASSENGER PORTAL..."<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR USER NAME:-";
        cin>>tempusername;
        cout<<"\n\n\n\t\t\t\t\t\t\tPLEASE ENTER YOUR PASSWORD:-";
        cin>>temppassword;
        fstream signup;
        signup.open("guest.txt",ios::in);
        if(!signup)
        {
            cout<<"\n\n\n\t\t\t\tNO ANY USER LOGIN YET"<<endl;
            signup.close();
            goto lable;
        }else
        {
            signup >>username>>password>>fname>>lname>>age>>mnum>>email;
            while(!signup.eof())
            {
                if(username==tempusername || password==temppassword)
                {
                    cout<<"\n\n\n\t\t\t\tACCOUNT LOGIN SUCCESS";
                    Sleep(2500);
                    Student obj2;
                    goto lable;
                }
                signup>>username>>password>>fname>>lname>>age>>mnum>>email;
            }
        }
    }else if(type==3)
    {
//        signup as admin
        cout<<"\n\t\t\t\t\t\tPLEASE ENTER PASSWORD::";
        cin>>adminpassword;
        if("lahirusuwahas"==adminpassword)
        {

            lable2:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO PASSWENGER PORTAL"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
            cin>>fname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
            cin>>lname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
            cin>>age;
            cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
            cin>>mnum;
            cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
            cin>>email;
            cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
            cin>>username;
            cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
            cin>>password;

            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream signup;
                signup.open("admin.txt",ios::app );
                signup<<"admin "<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable2;
            }
        }else{
                cout<<"_INVALID PASSWORD_"<<endl;
                cout<<"PLEASE ENTER CORRECT PASSWORD OR TRY AS A STUDENT"<<endl;
                cout<<"PLEASE ENTER ANY KEY FOR LOGIN MENU"<<endl;
                getch();
                system("cls");
                goto lable;
             }



    }
    else if(type==4)
    {
//        signup as a STUDENT
            lable1:
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO STUDENT PORTAL"<<endl;
            cout<<"\n\n\n\t\t\t\t\t\tENTER YOUR FIRST NAME:-";
            cin>>fname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR LAST NAME:-";
            cin>>lname;
            cout<<"\n\t\t\t\t\t\tENTER YOUR AGE:-";
            cin>>age;
            cout<<"\n\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:-";
            cin>>mnum;
            cout<<"\n\t\t\t\t\t\tENTER YOUR EMAIL ADDRESS:-";
            cin>>email;
            cout<<"\n\t\t\t\t\t\tENTER YOUR USERNAME:-";
            cin>>username;
            cout<<"\n\t\t\t\t\t\tENTER YOUR PASSWORD:-";
            cin>>password;

            cout<<"\n\n\t\t\t\t\tPLEASE CONFOIRM YOUR DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 1 FOR CONFIRM DETAILS"<<endl;
            cout<<"\t\t\t\t\t\nPRESS 2 FOR ENTER DETAILS AGAIN"<<endl;  //chek spells
            cin>>type;

            if(type==1)
            {
                fstream signup;
                signup.open("guest.txt",ios::app );
                signup<<username<<" "<<password<<" "<<fname<<" "<<lname<<" "<<age<<" "<<mnum<<" "<<email<<endl;


            }else
            {   system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\t\tPLEASE ENTER YOUR DETAILS AGAIN"<<endl;
                goto lable1;
            }
    }else if(type==5)
    {
        exit(0);
    }

    goto lable;


}


int main(){

    Account obj1;
//    Student obj1;
//    Admin obj1;

    return 0;
}


