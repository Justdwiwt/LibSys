#ifndef LIBSYS_USER_H
#define LIBSYS_USER_H

#pragma once

#include <string>

using namespace std;

class User {
public:
    User();

    virtual ~User();

    int m_nID;
    string m_strName;
    string m_strPassword;
    int m_nRole;
};

#endif //LIBSYS_USER_H
