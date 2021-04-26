//
// Created by oka on 4/17/2021.
//

#ifndef PSS_HW_4_ADMIN_H
#define PSS_HW_4_ADMIN_H


#include "MainGateway.h"

class Admin {
public:

    static void AccOrder();

    Admin()=default;

    static void BlockMethod(int BOO);

    static bool CheckMthd(string &Name, string &Method);
};


#endif //PSS_HW_4_ADMIN_H
