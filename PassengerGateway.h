//
// Created by oka on 4/8/2021.
//

#ifndef PSS_HW_4_PASSENGERGATEWAY_H
#define PSS_HW_4_PASSENGERGATEWAY_H
using namespace std;


#include <string>
#include "MainGateway.h"

class PassengerGateway {
    string name;
    string To;
    string method;
    string address;
    string status;
    string Car;
public:
    void SetAll(string Status, string Name, string Address, string To , string payMethod, string Car);
    string GetName();
    string GetTo();
    string GetAddress();
    string GetPay();
    string GetStatus();
    string GetCar();
    static void AllUserNeed(MainGateway &mainGateway);
    PassengerGateway(string, string, string, string, string, string);
    PassengerGateway()= default;


    static void printOrder(PassengerGateway &passengerGateway, MainGateway &mainGateway);

    static void setPaymentandAddress();

    static void printData();
};


#endif //PSS_HW_4_PASSENGERGATEWAY_H
