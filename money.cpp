#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

//hello my name is safi
//hello my name is friend
using namespace std;


class currency
{

  string money;
  float num;

public:

  currency(string name,float y)
  {
    num=y;
    money=name;
  }

  string getmoney()
  {
    return money;
  }
  float getnum()
  {
    return num;
  }





};

class office
{
  vector<string> areas;//holds locations such as west south east north
  string name;//this is the office names like is it abc or def
  vector<currency> types;// this is the conversions and currency that can be done
  string manager;

public:

  currency getcurrency(int m)
  {
  return types[m-1];
  }
  string getname()
  {
    return name;
  }
  office(string o,string i, string p, string w,string m)
  {
    string v=o+" "+i;
    name=v;
    manager=m;
    areas.push_back(p);
    areas.push_back(w);
  }
  string getarea(string z)
  {
    string p;
    if(z==areas[1])
    {
      p=areas[1];
    }
    else if(z==areas[0])
    {
       p= areas[0];
    }
    return p;
  }
  string getmanager()
  {
    return manager;
  }

  office addmanager(office e,string p)
  {
    manager=p;
    return e;
  }

  office(currency e)
  {
    types.push_back(e);
  }

  void info()
  {
    string x="yen";
    string y="peso";
    string z="dinar";
                      // basically these are the conversions that can be made to dollars
    string e="riyal";
    currency yen(x,.0091);
    currency peso(y,.054);
    currency dinar(z,.00084);

    currency riyal(e,.27);
    types.push_back(yen);
    types.push_back(peso);
    types.push_back(dinar);

    types.push_back(riyal);

  }







};
class airport
{

  vector<office> offices;

public:

  void addoffice(office u)
  {
    offices.push_back(u);
  }

  airport()
  {

  }
  office getoffice(int n)
  {
    return offices[n-1];
  }


  int ask(airport v)// function that will create the offices and ask for the office info
  {
    int i=1;
    int q=0;
    while(q<2)
    {
      vector<string> x;

      string line;

      string y;
    cout<<"Enter name of exchange office and manager: "<<endl;

    getline(cin,line);

    stringstream ss(line);

    while(ss>>y)
    {
      x.push_back(y);
    }
    if(x[0]=="ABC"||x[0]=="abc")
    {
      office t(x[0],x[1],"north","east",x[2]);

      t.info();
      addoffice(t);
       //v=v.y(v,t);
    }
    else if(x[0]=="def"||x[0]=="DEF")
    {
      office w(x[0],x[1],"west","south",x[2]);

      w.info();
      addoffice(w);
       //v=v.y(v,t);
    }
    else if(x[0]=="exit"||x[0]=="Exit")
    {
      cout<<"Exiting...";
      q=2;
      i=0;
    }

     q++;
    }
    return i;

  }


};



int main(int argc, char ** argv)
{
  airport dfw;
  int lel=dfw.ask(dfw);
  if(lel==0)
  {
    lel=5;
  }
  else
  {
    int i=1;
    while(i)
    {
      string z;
      cout<<"********\nHello traveler! Where are you in the airport? ";
      getline(cin,z);
      cout<<"********\n\n";

      if(z==dfw.getoffice(2).getarea(z))
      {
        cout<<"Welcome to "<<dfw.getoffice(2).getname()<<". Please contact the manager "<<dfw.getoffice(2).getmanager()<<" if you have any complaints.\nWhat currency are you converting to dollars and how much? ";
        string p;
        string t;
        vector <string> x;
        getline(cin,p);
        stringstream ss(p);
        while(ss>>t)
        {
          x.push_back(t);
        }
        if(x[0]=="exit")
        {
          cout<<"Exiting...";
          break;
          i=0;
        }
        float o=stof(x[0]);
        for( int m=4;m>0;m--)
        {
          if(x[1]==dfw.getoffice(2).getcurrency(m).getmoney())
          {
            o=o*dfw.getoffice(2).getcurrency(m).getnum();
          }

        }
          cout<<"Here you go: $"<<setprecision(2)<<fixed<<o<<endl;
        }
        else if(z==dfw.getoffice(1).getarea(z))
        {
          cout<<"Welcome to "<<dfw.getoffice(1).getname()<<". Please contact the manager "<<dfw.getoffice(1).getmanager()<<" if you have any complaints.\nWhat currency are you converting to dollars and how much? ";
          string p;
          string t;
          vector <string> x;
          getline(cin,p);
          stringstream ss(p);
          while(ss>>t)
          {
            x.push_back(t);
          }
          if(x[0]=="exit")
          {
            cout<<"Exiting...";
            break;
            i=0;
          }
          float o=stof(x[0]);
          for( int m=4;m>0;m--)
          {
            if(x[1]==dfw.getoffice(1).getcurrency(m).getmoney())
            {
              o=o*dfw.getoffice(1).getcurrency(m).getnum();
            }

          }
          cout<<"Here you go: $"<<setprecision(2)<<fixed<<o<<endl;
        }
        else if(z=="exit"||z=="Exit")
        {
          cout<<"Exiting...";
          i=0;
        }








      }
  }
}
