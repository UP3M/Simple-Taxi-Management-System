//
// Created by oka on 4/15/2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include "PassengerGateway.h"


void MainGateway::enter(){
    std::cout<<"Press Enter to continue";
    std::cin.ignore();
    while (std::cin.get()!='\n');
}

void MainGateway::GetAndReplace(string & data, const std::string& toSearch, const std::string& toReplace)
{
    size_t pos = data.find(toSearch);
    while( pos != std::string::npos)
    {
        data.replace(pos, toSearch.size(), toReplace);
        pos =data.find(toSearch, pos + toReplace.size());
    }
}
void MainGateway::NewOrder(string& Pass, string& Status, const string& File)
{
    ifstream in(File+".txt");
    string str;

    while (getline(in, str)) {

        if (str.find(Status) != std::string::npos){
            if (str.find(Pass) != std::string::npos){
                str.erase();
            }
            else
                b.push_back(str);
        }
        else{
            b.push_back(str);
        }
    }
    ofstream Order(File+".txt");
    vector<string>::iterator H;
    for(H=b.begin();H<b.end();H++){
        Order<<*H<<"\n";
    }
    b.clear();
}


void MainGateway::scanOrder(string& car, string& Status, const string& File, int p)
{
    ifstream file_in(File+".txt");
    string str1;
    int i=1;
    while (getline(file_in, str1)) {

        if (str1.find(Status) != std::string::npos){
            if (str1.find(car) != std::string::npos){
                d.push_back(str1);
                if (p==1)
                cout<<i<<". "<<str1<<"\n";
                i++;
                a++;
            }
            else{
                str1.erase();
            }
        }
        else{
            str1.erase();
        }
    }
    a=0;
}
void MainGateway::Scan(const string& str){
    string word;
    for (auto x:str) {
        if (x==',') {
            c.push_back(word);
            word.erase();
        }
        else
            word += x;
    }
}

void MainGateway::succed(){
    cout << "\n\tYour Order has been successfully registered\n";
}


