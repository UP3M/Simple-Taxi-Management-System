//
// Created by oka on 4/8/2021.
//

#ifndef PSS_HW_4_DRIVERGATEWAY_H
#define PSS_HW_4_DRIVERGATEWAY_H
using namespace std;

#include <string>
#include "MainGateway.h"

class DriverGateway {
public:

    DriverGateway()= default;

    static void AdmitNewDriver(MainGateway &mainGateway);
    static void AllDriverNeed(MainGateway &mainGateway);

    static void printDriverData();

    static void byAdmin(MainGateway &mainGateway);
};


#endif //PSS_HW_4_DRIVERGATEWAY_H
