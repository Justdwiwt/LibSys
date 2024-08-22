#ifndef LIBSYS_BORROWRECORD_H
#define LIBSYS_BORROWRECORD_H

#include <iostream>
#include <string>

using namespace std;

#pragma once

class BorrowRecord {
public:
    BorrowRecord();

    virtual ~BorrowRecord();

    int m_nBorrowId{};
    int m_nBookId{};
    int m_nUserId{};
    string m_tBorrowDate;
    string m_tShouldReturnDate;
    string m_tReturnDate;
    int m_nContinue{};
};

#endif //LIBSYS_BORROWRECORD_H
