#include <iostream>
#include <vector>
#include <sstream>
#include "PassengerGateway.h"
#include "DriverGateway.h"
#include "MainGateway.h"
#include "Admin.h"

using namespace std;

int main() {
    string userType;
    cout<<"\tWelcome To Wendex App\nYou Want to Login as:";
    cin>>userType;
    MainGateway mainGateway;
    if (userType=="User"){
    PassengerGateway::AllUserNeed(mainGateway);
    }

    else if (userType=="Driver") {
        DriverGateway::AllDriverNeed(mainGateway);
    }
    else if (userType=="Admin"){
        tryagain:
        string username, password;
        cout<<"enter username:";cin>>username;
        if(username=="oka"){
            cout<<"enter password:";cin>> password;
            if (password=="oka123"){
                cout<<"\tWhat you want to do:\n1. Block Access\n2. Open Access\n3. Accept Order\n4. Admit Driver\nYour choice:";
                int pick;
                cin>>pick;
                switch (pick) {
                    case 1: Admin::BlockMethod(pick);
                        break;
                    case 2: Admin::BlockMethod(pick);
                        break;
                    case 3: DriverGateway::byAdmin(mainGateway);
                        break;
                    case 4: DriverGateway::AdmitNewDriver(mainGateway);
                        break;
                    default:cout<<"Invalid Input.. please try again";
                }
            } else{
                cout<<"wrong password/n";goto tryagain;
            }
        }else {
            cout<<"wrong username/n";goto tryagain;
        }

    }
}