//
// Created by oka on 4/8/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include "PassengerGateway.h"
#include "Admin.h"

string username1, stat1, nama1, addr1, payment1, OPorder1, history1, CarT1, PassengerName1, price1;
vector<string>a1;
vector<string>b1;
vector<string>c1;
vector<string>d1;

void PassengerGateway::SetAll(string Status, string Name, string Address, string To , string payMethod, string Car) {
    this->status=move(Status);
    this->name=move(Name);
    this->To=move(To);
    this->Car=move(Car);
    this->method=move(payMethod);
    this->address=move(Address);
}

void PassengerGateway::printData(){
    ofstream out("User Database/"+username1 + ".txt");
    string updated= OPorder1+"\n"+stat1+"\n"+ nama1+ "\n"+addr1+"\n"+ payment1;
    out<<updated<<"\n";
    vector<string>::iterator H;
    for(H=a1.begin();H<a1.end();H++){
        out<<*H<<"\n";
    }
    a1.clear();
}

string PassengerGateway::GetAddress() {
    return address;
}
string PassengerGateway::GetName() {
    return name;
}
string PassengerGateway::GetCar() {
    return Car;
}
string PassengerGateway::GetPay() {
    return method;
}
string PassengerGateway::GetStatus() {
    return status;
}
string PassengerGateway::GetTo() {
    return To;
}

PassengerGateway::PassengerGateway(string name, string To, string Car, string method, string address, string status) {
    this->name=move(name);
    this->To=move(To);
    this->Car=move(Car);
    this->method=move(method);
    this->address=move(address);
    this->status= move(status);
}

void PassengerGateway::printOrder(PassengerGateway& passengerGateway, MainGateway& mainGateway){
    string allOrder;
    ifstream in("order.txt");
    while (getline(in, allOrder)){
        b1.push_back(allOrder);
    }
    ofstream Order("order.txt");
    vector<string>::iterator H;
    for(H=b1.begin();H<b1.end();H++){
        Order<<*H<<"\n";
    }
    b1.clear();
    Order<<passengerGateway.GetStatus()<<","<<passengerGateway.GetName()<<","
         <<passengerGateway.GetAddress()<<","<<passengerGateway.GetTo()<<","
         <<passengerGateway.GetCar()<<","<<passengerGateway.GetPay()<<",";
}
void PassengerGateway::setPaymentandAddress(){

    cout << "Enter address:";
    cin >> addr1;

    cout << "\tChoose payment method:\n1. Cash\n2. Card\n";
    int pay;cout << "Enter your choice:"; cin >> pay;
    switch (pay) {
        case 1:
            payment1 = "Cash";
            cout << "\n\tYour Account has been successfully registered\n";
            break;
        case 2:
            payment1 = "Card";
            cout << "\n\tYour Account has been successfully registered\n";
            break;
        default:
            std::cout << "\n\n Invalid Value... Please try again\n";
    }

}


void PassengerGateway::AllUserNeed(MainGateway& mainGateway) {
    cout << "Enter username:";
    cin >> username1;
    ifstream read("User Database/"+username1 + ".txt");
    if (!read.good()) {
        regis:
        cout << "\n\tYour Account is not registered\nYou want to register?(yes/no):";
        string reg;
        cin>>reg;
        if (reg=="yes") {
            OPorder1="";
            stat1 = "None";
            cout << "Enter username:";
            cin >> nama1;
            setPaymentandAddress();
            ofstream out("User Database/"+username1 + ".txt");
            string updated = OPorder1+"\n"+stat1 + "\n" + nama1 + "\n" + addr1 + "\n" + payment1;
            out << updated << "\n";
            MainGateway::enter();
            return;
        }
        else if(reg=="no"){
            MainGateway::enter();
            return;
        }
        else{
            cout<<"Invalid input... please try again";
            goto regis;
        }
    }
    getline(read, OPorder1);
    getline(read, stat1);
    getline(read, nama1);
    getline(read, addr1);
    getline(read, payment1);
    while (getline(read, history1)){
        a1.push_back(history1);
    }
    if (stat1=="None"){
        PassengerGateway passengerGateway;
        pick: cout<<"\n\tWhat you want to do:\n1. See Order History\n2. Order Car\n3. Set Payment method and Address";
        int UserDo;
        string To, Method;
        vector<string>::iterator H;
        cout << "\nEnter your choice:";cin>>UserDo;
        switch (UserDo) {
            case 1:
                Method="History";
                if ( Admin::CheckMthd(nama1,Method)){
                    cout<<"Your Access to See History was Blocked by Admin\n";
                    MainGateway::enter();
                    goto pick;
                }
                else{
                cout<<"\n\tOrder History\n";
                for(H=a1.begin();H<a1.end();H++){
                    cout<<*H<<"\n";
                }
                MainGateway::enter();
                goto pick;
                }
            case 2:
                Method="Order";
                if ( Admin::CheckMthd(nama1,Method)){
                    cout<<"Your Access to Make an Order was Blocked by Admin\n";
                    MainGateway::enter();
                    goto pick;
                }else{
                cout<<"From :"<<addr1<<", To (Enter Destination):";
                getline(cin>>ws, To);
                cout << "\tChoose your Car:\n1. Economy\n(no feature) => price: 200 Rubel\n2. Comfort\n(Free 2 Bottles Water)=> price: 250 Rub\n3. ComfortPlus\n(Free 4 Bottles Water)=> price: 300 Rub\n4. Business\n(Park Right In Front Of The Entrance + 3 Bottles Juice)=> price: 400 Rub\n";
                int pickCar;cout << "Enter your choice:"; cin >> pickCar;
                switch (pickCar) {
                    case 1:
                        CarT1 = "Economy";
                        price1="200 Rub";
                        int PickDriver;

                        break;
                    case 2:
                        CarT1 = "Comfort";
                        price1="250 Rub";
                        MainGateway::succed();
                        break;
                    case 3:
                        CarT1 = "ComfortPlus";
                        price1="300 Rub";
                        MainGateway::succed();
                        break;
                    case 4:
                        CarT1 = "Business";
                        price1="400 Rub";
                        MainGateway::succed();
                        break;
                    default:
                        std::cout << "\n\n Invalid Value... Please try again\n";
                }
                    int PickDriver;
                    string ClassTo, Wait="Pending";
                    mainGateway.scanOrder(CarT1, Wait, "CarList", 1);//scan: status,name,model,color,etc
                    if (mainGateway.a==0){
                        cout<<"Sorry there are no free " +CarT1+" class Driver right now\nTry again later";
                        return;
                    }
                    cout<<"Choose Driver and Car model no:";cin>>PickDriver;
                    MainGateway::GetAndReplace(mainGateway.d.at(PickDriver-1), "Pending", "Booked");//set that line
                    mainGateway.Scan(mainGateway.d.at(PickDriver-1));//scan for pick all data
                    string nama=mainGateway.c.at(2);
                    string carmodel=mainGateway.c.at(3);
                    mainGateway.c.clear();
                    mainGateway.b.push_back(mainGateway.d.at(PickDriver-1));
                    mainGateway.d.clear();
                    mainGateway.NewOrder(nama,Wait,"CarList");
                stat1="Pending";
                string picked= CarT1+","+nama+","+carmodel;
                passengerGateway.SetAll(stat1, nama1, addr1, To, payment1, picked);
                printOrder(passengerGateway,mainGateway);
                OPorder1="From: "+ addr1+"=> To: "+To+", Car model: "+carmodel+" Class: "+CarT1+" Driver: "+nama+", Cost: "+ price1 +", Paid "+payment1;
                printData();
                a1.clear();
                cout<<"Please wait your order to picked by your Driver accept\n";
                MainGateway::enter();
                return;
                }
            case 3:
                setPaymentandAddress();
                goto pick;
            default:
                std::cout << "\n\n Invalid Value... Please try again\n";
        }
    }
    ifstream file_in("order.txt");
    string str;
    while (getline(file_in, str)) {
        if (str.find(nama1) != std::string::npos){
            if (str.find(stat1) != std::string::npos){
                cout<<"\n\tPlease wait for your order to be accepted";
            }else if (str.find("Rejected")!=string::npos){
                stat1="Rejected";
                string pend="Pending";
                cout<<"Your Request rejected by driver\n";
                mainGateway.NewOrder(nama1,stat1,"order");
                mainGateway.NewOrder(nama1,pend,"order");
                OPorder1="";
                stat1="None";
                printData();
                MainGateway::enter();
                return;
            }
            else {
                PDo:
                int pick;
                string Rating, PickOrder;
                double Coordinatex, Coordinatey;
                srand(time(nullptr));
                Coordinatex =-90.0000+(double)rand()/RAND_MAX*90.000000-(-90.00000);
                Coordinatey =0.0000+(double)rand()/RAND_MAX*180.000000-0.00000;
                cout<<"\n    Your Order is on progress"
                      "\n\tEnjoy your Trip\n\nWhat you want to do:"
                      "\n1.You Arrived(Finish Order)\n2.Check Current Location"
                      "\nEnter your choice:";cin>>pick;
                switch (pick) {
                    case 1:cout<<"\n\tDid you enjoy our service?\nGive Rating(1.0 to 5.0):";cin>>Rating;
                        stat1="Accepted";
                        mainGateway.scanOrder(nama1, stat1, "order", 0);
                        MainGateway::GetAndReplace(mainGateway.d.at(0), "Accepted", "Finished");
                        mainGateway.b.push_back(mainGateway.d.at(0)+Rating+',');
                        mainGateway.NewOrder(nama1,stat1,"order");
                        a1.push_back(OPorder1);
                        OPorder1="";
                        stat1="None";
                        printData();
                        d1.clear();
                        cout<<"\n\tThank You For Using Wandex App";
                        return;
                    case 2: cout<<"\nCurrent Coordinate:"<<Coordinatex<<", "<<Coordinatey<<"\n";
                        MainGateway::enter();goto PDo;
                    default: cout<<"\nInvalid Value... Please Try Again:";

                }
                str.erase();
            }
        }
        else{
            str.erase();
        }
    }
}



