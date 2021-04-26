//
// Created by oka on 4/15/2021.
//

#ifndef PSS_HW_4_MAINGATEWAY_H
#define PSS_HW_4_MAINGATEWAY_H

#include <string>

#include "MainGateway.h"
using namespace std;
class PassengerGateway;
class MainGateway {
public:
    vector<string>b;
    vector<string>c;
    vector<string>d;
    int a=0;

    static void enter();
    static void GetAndReplace(string & data, const std::string& toSearch, const std::string& toReplace);
    static void succed();

//scan for driver history
    void Scan(const string& str);
    MainGateway()=default;

    void scanOrder(string &car, string &Status, const string& File, int i);

    void NewOrder(string &Pass, string &Status, const string& File);
};


#endif //PSS_HW_4_MAINGATEWAY_H
