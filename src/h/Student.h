#ifndef LIBSYS_STUDENT_H
#define LIBSYS_STUDENT_H

#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctype.h>
#include <time.h>
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

    virtual ~Student();

    void ShowMenu();

    bool QueryBook(string strBookName);

    bool BorrowBook(int nBookId);

    bool ReturnBook();

    bool ShowMyBorrowRecord();

    bool RenewBook();

    TimeUtil m_timeUtil;
    DB m_dbUtil;
};

#endif //LIBSYS_STUDENT_H
