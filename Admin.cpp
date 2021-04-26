//
// Created by oka on 4/17/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Admin.h"
using namespace std;

string Name, Method, Aline, Blocked;

void Admin::AccOrder() {

}

void Admin::BlockMethod(int BOO) {
    vector<string> a;
    vector<string>::iterator A;
    int PickMethod;
    string Acc="Access order history\n";
    string Order="Pick/Make an Order\n";
    cout<<"\nEnter username of User:";cin>>Name;
    string can;
    if (BOO==2) can= "can ";
    else can ="cannot";
    string Success="\nUser "+ Name +" now "+can;
    cout<<"\nChoose which access you want to block/open for this user:"
          "\n1. See Order History\n2. Order\nYour choice:";cin>>PickMethod;
    switch (PickMethod) {
        case 1:Method="History";
            cout<<Success<<" "<<Acc;
            MainGateway::enter();
            goto here;
        case 2:Method="Order";
            cout<<Success<<" "<<Order;
            MainGateway::enter();
            goto here;
        default: cout<<"Invalid Input... Please Try Again";
    }here:
    ifstream Ch("Admin.txt");
    while (getline(Ch, Aline)){
        if (Aline.find(Name)!=string::npos){
            if (Aline.find(Method)!=string::npos){
                if (BOO==2){
                    continue;
                }
                else{
                a.push_back(Aline);
                Blocked="";
                }
            }
            else{
                //assume switch: 1 for block, 2 for open block, 3 for as Driver, 4 for Admit new driver
                if (BOO==1){Blocked=Name+","+Method+"\n";}
                else if (BOO==2){Blocked="";}
                a.push_back(Aline);
            }
        }else {
            if (BOO==1){Blocked=Name+","+Method+"\n";}
            else if (BOO==2){Blocked="";}
            a.push_back(Aline);
        }
    }

    ofstream Out("Admin.txt");
    for (A=a.begin();A<a.end();A++){
        Out<<*A<<"\n";
    }
    Out<<Blocked;
}

bool Admin::CheckMthd(string& user, string& method){
    ifstream getAll("Admin.txt");
    string DOU;
    bool is;
    while (getline(getAll, DOU)){
        if (DOU.find(user)!=string::npos){
            if (DOU.find(method)!=string::npos){
                is= true;
            }else is= false;
        } else is= false;
    }
    return is;
}
