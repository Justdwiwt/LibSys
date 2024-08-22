#ifndef LIBSYS_MANAGER_H
#define LIBSYS_MANAGER_H

#include <cstdlib>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <ctime>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "DB.h"

#pragma once

class Manager : public User {
public:
    Manager();

    ~Manager() override;

    static void ShowMenu();

    bool AddBook();

    bool DisplayAllBook();

    bool QueryBook(const string &strBookName);

    bool DeleteBook(int nBookId);

    bool DiaplayAllBorrowRecord();

    bool AddUser();

    bool DisplayAllUser();

    TimeUtil m_timeUtil;

    DB m_dbUtil;
};

#endif //LIBSYS_MANAGER_H
