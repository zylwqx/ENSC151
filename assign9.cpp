#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

double rate = 16.50;
double com = 0.03;

struct Sale {
    int ID;
    double saleAmt;
};

struct timeSheet{
    int ID;
    double hours;
    string name;
};

int main(){
    list<timeSheet> timesheets;
    list<Sale> sales;

    ifstream tfile("timesheets.txt"); // open the file
    string line;
    while(getline(tfile, line)){ // read the file and takes each line
        stringstream ss(line);
        timeSheet ts;

        ss >> ts.ID; // employee ID
        ss >> ts.hours; // hours
        getline(ss, ts.name); // full name with the space
        if (!ts.name.empty() && ts.name[0] == ' '){ // deletes leading space
            ts.name.erase(0, 1);
        }

        timesheets.push_back(ts); // add to list
    }
    tfile.close(); // close the file

    ifstream sfile("sales.txt"); // open the file
    while(getline(sfile, line)){ // read the file and takes each line
        stringstream ss(line);
        Sale sl;

        ss >> sl.ID; // employee ID
        ss >> sl.saleAmt; // $$ amount of sales

        sales.push_back(sl); // add to list
    }
    sfile.close(); // close the file


    for (const timeSheet& t : timesheets) {
        double salesMon = 0.0;

        for(const Sale& s : sales){
            if(s.ID == t.ID){ // match ID's
                salesMon = s.saleAmt;
                break;
            }  
        }

        double pay = t.hours * rate;
        double commission = salesMon * com;
        double totalPay = pay + commission;

        cout << "Name: " << t.name << "\n";
        cout << "Number: " << t.ID << "\n";
        cout << "Hours: " << t.hours << "\n";
        cout << "Pay: " << pay << "\n";
        cout << "Commission: " << commission << "\n";
        cout << "Total: " << totalPay << "\n\n";

    } 

    return 0;
}