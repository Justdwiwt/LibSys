#ifndef LIBSYS_STUDENT_H
#define LIBSYS_STUDENT_H

#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <ctime>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "DB.h"
#include "User.h"
#include "BorrowRecord.h"

using namespace std;

class Student : public User {
public:
    Student();

    ~Student() override;

    static void ShowMenu();

    bool QueryBook(const string &strBookName);

    bool BorrowBook(int nBookId);

    bool ReturnBook();

    bool ShowMyBorrowRecord();

    bool RenewBook();

    TimeUtil m_timeUtil;
    DB m_dbUtil;
};

#endif //LIBSYS_STUDENT_H
