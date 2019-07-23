#ifndef LIBSYS_MANAGER_H
#define LIBSYS_MANAGER_H

#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <time.h>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "DB.h"

#pragma once

class Manager : public User {
public:
    Manager();

    virtual ~Manager();

    void ShowMenu();

    bool AddBook();

    bool DisplayAllBook();

    bool QueryBook(string strBookName);

    bool DeleteBook(int nBookId);

    bool DiaplayAllBorrowRecord();

    bool AddUser();

    bool DisplayAllUser();

    TimeUtil m_timeUtil;

    DB m_dbUtil;
};

#endif //LIBSYS_MANAGER_H
