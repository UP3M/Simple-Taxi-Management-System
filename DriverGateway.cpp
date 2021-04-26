//
// Created by oka on 4/8/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "DriverGateway.h"
#include "Admin.h"

using namespace std;
static string username, stat, nama, OPorder, history, CarT, PassengerName;
vector<string>a;
void DriverGateway::AdmitNewDriver(MainGateway& mainGateway) {
    int PickDriver;
    string ClassTo, ORDER, Wait="Waiting";
    mainGateway.scanOrder(ORDER, Wait, "CarList", 1);//scan: status,name,model,color,etc
    cout<<"Set Class for Driver no:";cin>>PickDriver;
    cout<<"Set Class To:";cin>>ClassTo;
    string statAndclass= ClassTo+",Pending";
    MainGateway::GetAndReplace(mainGateway.d.at(PickDriver-1), "Waiting", statAndclass);//set that line
    mainGateway.Scan(mainGateway.d.at(PickDriver-1));//scan for pick all data
    stat="Pending";
    nama=mainGateway.c.at(2);
    CarT=mainGateway.c.at(0);
    username= nama;
    printDriverData();//update drivername.txt
    mainGateway.c.clear();
    mainGateway.b.push_back(mainGateway.d.at(PickDriver-1));
    mainGateway.d.clear();
    mainGateway.NewOrder(nama,Wait,"CarList");
    cout<<"Validation process for "<<nama<<" success";
}

void DriverGateway::printDriverData(){
    ofstream out("Driver Database/"+username+".txt");
    string updated= OPorder+"\n"+stat+"\n"+ nama+ "\n"+CarT+"\n"+PassengerName;
    out<<updated<<"\n";
    vector<string>::iterator H;
    for(H=a.begin();H<a.end();H++){
        out<<*H<<"\n";
    }
    a.clear();
}

void DriverGateway::byAdmin(MainGateway& mainGateway){
    string acc="Booked";
    string empty=",";
    int Pick;
    mainGateway.scanOrder(empty, acc, "CarList", 1);
    cout<<"which driver you want to force accept order:";cin>>Pick;
    MainGateway::GetAndReplace(mainGateway.d.at(Pick-1), "Booked", "Accepted");
    mainGateway.Scan(mainGateway.d.at(Pick-1));
    nama = mainGateway.c.at(2);
    mainGateway.b.push_back(mainGateway.d.at(0));
    mainGateway.d.clear();
    mainGateway.c.clear();
    mainGateway.NewOrder(nama,acc,"CarList");
    mainGateway.scanOrder(nama, stat, "order", 0);
        MainGateway::GetAndReplace(mainGateway.d.at(0), "Pending", "Accepted");
        mainGateway.Scan(mainGateway.d.at(0));
        stat="Accepted";
        username=nama;
        OPorder="Passenger Name: "+mainGateway.c.at(1)+",From: "+mainGateway.c.at(2) +" To: "+mainGateway.c.at(3) +", Car Type: "+mainGateway.c.at(4)+", Paid: "+mainGateway.c.at(5);
        PassengerName=mainGateway.c.at(1);
        printDriverData();
        mainGateway.c.clear();
        string Pend="Pending";
        mainGateway.b.push_back(mainGateway.d.at(0));
        mainGateway.d.clear();
        mainGateway.NewOrder(PassengerName,Pend,"order");
        cout<<"You Success Pick an Order from "<<PassengerName;
}

void DriverGateway::AllDriverNeed(MainGateway& mainGateway) {
    cout << "Enter username:";
    cin >> username;
    ifstream read("Driver Database/"+username + ".txt");
    if (!read.good()) {
        regisDriv:
        cout << "\n\tYour Account is not registered\nYou want to register?(yes/no):";
        string reg, model, color, number, setCar;
        CarT="Waiting";
        cin>>reg;
        if (reg=="yes") {
            OPorder="";
            stat = "Waiting";
            cout << "Enter username:";
            cin >> nama;
            cout << "Enter Car model:";
            cin >> model;
            cout << "Enter Car color:";
            cin >> color;
            cout << "Enter Car number:";
            cin >> number;
            ofstream out("Driver Database/"+username + ".txt");
            string updated = OPorder+"\n"+stat + "\n" + nama + "\n" + CarT;
            out << updated << "\n";
            ifstream in("CarList.txt");
            string ln;
            vector<string>::iterator H;
            while (getline(in, ln)){
                a.push_back(ln);
            }
            ofstream SetCar("CarList.txt");
            for (H=a.begin();H<a.end();H++){
                SetCar<<*H<<"\n";
            }
            setCar=stat+","+nama+","+model+","+color+","+number+",";
            SetCar<<setCar<<"\n";
            cout<<"Request sended.Please Wait\nAdmin will review your request\n";
            MainGateway::enter();
            return;
        }
        else if(reg=="no"){
            MainGateway::enter();
            exit(0);
        }
        else{
            cout<<"Invalid input... please try again";
            goto regisDriv;
        }
    }
    getline(read, OPorder);
    getline(read, stat);
    getline(read, nama);
    getline(read, CarT);
    getline(read, PassengerName);
    while (getline(read, history)){
        a.push_back(history);
    }
    if (stat=="Pending"){
        here:
        pickPass: cout<<"\n\tWhat you want to do:\n1. See Order History\n2. See Available Order\n";
        int DriverDo;
        string PickOrder;
        string To, ORDER, Pend,Method;
        ifstream SeeOrder("order.txt");
        vector<string>::iterator H;
        cout << "\nEnter your choice:";cin>>DriverDo;
        switch (DriverDo) {
            case 1:
                Method="History";
                if ( Admin::CheckMthd(nama,Method)){
                    cout<<"Your Access to See History was Blocked by Admin";
                }
                cout<<"\n\tOrder History\n";
                for(H=a.begin();H<a.end();H++){
                    cout<<*H<<"\n";
                }MainGateway::enter();
                goto pickPass;
            case 2:
                Method="Order";
                if ( Admin::CheckMthd(nama,Method)){
                    cout<<"Your Access to Pick an Order was Blocked by Admin";
                }else{
                mainGateway.scanOrder(nama, stat, "order", 1);
                back:
                cout<<"Do you want to pick this order(yes/no):";cin>>PickOrder;
                if(PickOrder=="yes"){
                MainGateway::GetAndReplace(mainGateway.d.at(0), "Pending", "Accepted");
                mainGateway.Scan(mainGateway.d.at(0));
                stat="Accepted";
                OPorder="Passenger Name: "+mainGateway.c.at(1)+",From: "+mainGateway.c.at(2) +" To: "+mainGateway.c.at(3) +", Car Type: "+mainGateway.c.at(4)+", Paid: "+mainGateway.c.at(5);
                PassengerName=mainGateway.c.at(1);
                username=nama;
                printDriverData();
                mainGateway.c.clear();
                Pend="Pending";
                mainGateway.b.push_back(mainGateway.d.at(0));
                mainGateway.d.clear();
                mainGateway.NewOrder(PassengerName,Pend,"order");
                cout<<"You Success Pick an Order from "<<PassengerName;
                string booked= "Booked";
                mainGateway.scanOrder(nama, booked, "CarList",0);
                MainGateway::GetAndReplace(mainGateway.d.at(0), "Booked", "Accepted");
                mainGateway.b.push_back(mainGateway.d.at(0));
                mainGateway.d.clear();
                mainGateway.NewOrder(nama, booked, "CarList");
                return;}
                else if(PickOrder=="no"){
                    Pend="Pending";
                    MainGateway::GetAndReplace(mainGateway.d.at(0), "Pending", "Rejected");
                    mainGateway.b.push_back(mainGateway.d.at(0));
                    mainGateway.d.clear();
                    mainGateway.NewOrder(PassengerName,Pend,"order");
                    string acc="Booked";
                    mainGateway.scanOrder(nama, acc, "CarList", 0);
                    MainGateway::GetAndReplace(mainGateway.d.at(0), "Booked", "Pending");
                    mainGateway.b.push_back(mainGateway.d.at(0));
                    mainGateway.d.clear();
                    mainGateway.NewOrder(nama,acc,"CarList");
                    cout<<"You Reject an Order from "<<PassengerName;
                    return;
                }
                else{
                    cout<<"Invalid input... please try again";
                    goto back;
                }
                }
            default:
                std::cout << "\n\n Invalid Value... Please try again\n";
        }
    }
    ifstream file_in("order.txt");
    string str,Finish, wait="Waiting";
    while (getline(file_in, str)) {
        if (str.find(PassengerName) != std::string::npos){
            if (str.find(stat) != std::string::npos){
                cout<<"\n\tYou are still on Ride";
            }
            else if(str.find(wait)!=string::npos){
                cout<<"Please wait...Your car still on validation process by admin";
                return;
            }
            else{
                Finish="Finished";
                mainGateway.Scan(str);
                string acc="Accepted";
                mainGateway.scanOrder(nama, acc, "CarList", 0);
                MainGateway::GetAndReplace(mainGateway.d.at(0), "Accepted", "Pending");
                mainGateway.b.push_back(mainGateway.d.at(0));
                mainGateway.d.clear();
                mainGateway.NewOrder(nama,acc,"CarList");
                mainGateway.NewOrder(PassengerName, Finish,"order");
                a.push_back(OPorder+" Given Rating: "+ mainGateway.c.at(8));
                OPorder="";
                stat="Pending";
                printDriverData();
                cout<<"Your Job is Done and "<<PassengerName<<" Give Rating:"<<mainGateway.c.at(8)<<"\nPlease Re-Run App to Check Available Order";
                break;
            }
        }
        else{
            str.erase();
        }
    }
}



