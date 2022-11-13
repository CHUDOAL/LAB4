#include <string>
//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ostringstream;

int st;



class magazin
{

public:

    class user;

    void FD(user& user);
    
        
    

    void setUser()
    {
        //cout << magazin::GetQuantityUsers();
        ifstream Id3;
        Id3.open("Id.txt");
        string str;
        getline(Id3, str);
        st = atoi(str.c_str()) + 1;
        Id3.close();
        
        cout << "Введите свое имя: "; cin >> user_name;
        cout << "Введите свою фамилию: "; cin >> user_surname;
        user User(user_name, user_surname);
        
        FD(User);

        QuantityUsers = st;
       // cout << st;
    }

    void getUser()
    {
        user User(user_name, user_surname);
        User.getUser();
    }

    void setTovars()
    {

        cout << "Сколько вещей вы хотите заказать?" << endl;
        cin >> size;

        tovar tvr;
        tovar_zakaz = tvr.setTovar(size);

    }

    void getTovars()
    {
        tovar tvr;
        tvr.getTovar(tovar_zakaz, size);
    }


    void setAdres()
    {
        adres adr;
        Adr = adr.setAdres();
    }

    void getAdres()
    {
        adres adr;
        adr.getAdres(Adr);

    }

    void setDate()
    {
        date dt;
        data = dt.setData();
    }

    void getDate()
    {
        date dt;
        dt.getData(data);

    }

    static int& GetQuantityUsers()
    {
        return QuantityUsers;
    }

private:

    // User
    string user_name;
    string user_surname;
    static int QuantityUsers;
    // Tovar
    string* tovar_zakaz;
    int size;
    // Adres
    string Adr;
    // Data
    string data;
    // Class
    

    

    class user
    {
    private:
        string name;
        string surname;
        ofstream User;
        friend void magazin::FD(user &user);

    public:
        user(string name, string surname) :name(name), surname(surname) {}

        void getUser()
        {
            User.open("UserInf.txt", ofstream::app);
            User << name << " " << surname << "\n";
            User.close();

        }

    };

    class tovar
    {
    private:
        string name;
        int kolich;
        string* zakaz;
        int size;
        ofstream User;
        
    public:
        
        

        string* setTovar(int size)
        {

            zakaz = new string[size];
            for (int i = 0; i < size; i++) {
                cout << "Название товара: ";  cin >> name;
                cout << "Сколько вы хотите товара: "; cin >> kolich;
                ostringstream ost;
                ost << kolich;
                zakaz[i] = name + " " + ost.str() + " штук, ";
                
            }

            return (zakaz);
        }


        void getTovar(string* zakaz, int size)
        {
            User.open("UserInf.txt", ofstream::app);
            
            for (int i = 0; i < size; i++) {
                User << zakaz[i];
            }
            User << "\n";
            User.close();


        }

       
    };

    class adres
    {
    private:
        string country;
        string city;
        ofstream User;
        string adrs;
    public:

        

        string setAdres()
        {
            string adrees;
            cout << "Введите свою страну: ";  cin >> country;
            cout << "Введите свой город: "; cin >> city;
            adrees = country + " " + city;

            return(adrees);
        }

        void getAdres(string adrees)
        {
            User.open("UserInf.txt", ofstream::app);
            this->adrs = adrees;
            User << adrs << "\n";
            User.close();
        }

    };

    class date
    {
    private:
        string data;
        ofstream User;
    public:

        string setData()
        {

            cout << "Введите дату доставки: ";  cin >> data;

            return(data);
        }

        void getData(string data)
        {
            User.open("UserInf.txt", ofstream::app); 
            User << data << "\n";
            User.close();
        }
    };
};



class Count
{
    private:
        int numb;
    public:
        Count(int i) : numb(i)
        {}
        friend const Count& operator++(Count& i);
        friend const Count operator++(Count& i, int);
};


const Count& operator++(Count& i) {
    i.numb++;
    return i;
}

const Count operator++(Count& i, int) {
    Count oldnumb(i.numb);
    i.numb++;
    return oldnumb;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");

    magazin mag;

    ofstream Id;

  

   // Id.open("Id.txt");

    //Id << magazin::GetQuantityUsers();
    
    //Id.close();

    ofstream User;

    string s;

    s = "";

    string id;

    id = "";

    int gg;
    gg = 0;

    string tovar;

    cout << "Выберите действие (NewUser - для оформления заказа, UserInf = для получения информации о заказах)" << endl;
    cin >> s;
    
   if (s == "NewUser") 
   {
        
        User.open("UserInf.txt", ofstream::app);
        
        mag.setUser();
        mag.setTovars();
        mag.setAdres();
        mag.setDate();
        
        

        ostringstream ost;
        ost << magazin::GetQuantityUsers();

        Id.open("Id.txt");
     
        Id << magazin::GetQuantityUsers();


        User << ost.str() << "\n";

        mag.getUser(); mag.getAdres(); mag.getTovars(); mag.getDate();
        User.close();
   }



   if (s == "UserInf")
   {

       cout << "Введите id пользовтеля" << endl;
       cin >> id;
       ifstream User;
       User.open("UserInf.txt");
       string str;
       string str2;
       int count;
       count = 1;

       while (!User.eof()) 
       {
           str = "";
            
           getline(User,str);
           if (count % 5 == 0 and str == id)
           {
               for (int i = 4; i > 0; i--)
               {   
                   User.close();
                   User.open("UserInf.txt");
                   int count2 = 1;
                   while (!User.eof())
                   {
                       str2 = "";
                       getline(User, str2);
                       
                       if (count2 == (atoi(id.c_str())*5) - i)
                       {
                           
                           cout << str2 << endl;
                       }
                       count2++;
                   }
               }
           }
           count ++;

        }
   }
   User.close();
   Id.close();




  
    

 //   cout << magazin::GetQuantityUsers();
    
    return 0;
}

void magazin::FD(user& user)
{
    cout << "Name: " << user.name << endl << "Surname: " << user.surname << endl;
}

int magazin::QuantityUsers = 5;
