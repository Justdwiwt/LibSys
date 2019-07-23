#ifndef LIBSYS_DB_H
#define LIBSYS_DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include "../include/mysql.h"
#include <iostream>
#include <vector>
#include "User.h"
#include "Book.h"
#include "TimeUtil.h"
#include "BorrowRecord.h"

#pragma once

class DB {
public:
    DB();

    virtual ~DB();

    bool OpenDB();

    bool CloseDB();

    User ReadUser(string strUserName, string strUserPWD);

    bool AddBook(Book book);

    bool SelectAllBook(vector<Book> &books);

    bool SelectBookByName(string strBookName, vector<Book> &books);

    bool SelectBookById(int nBookId, Book &book);

    bool DeleteBookById(int nBookId);

    bool AddBorrowRecord(BorrowRecord borrowRecord);

    bool ExtendBorrowRecord(int nRecordId);

    bool SelectBorrowRecordByRecordId(BorrowRecord &borrowRecord, int nRecordId);

    bool FinishBorrowRecord(int nRecordId, int nBookId);

    bool SelectAllBorrowRecord(vector<BorrowRecord> &borrowRecords);

    bool SelectBorrowRecordByUserId(vector<BorrowRecord> &borrowRecords, int nUserId, int nType);

    User SelectUserById(int nUserId);

    bool AddUser(User user);

    bool SelectAllUser(vector<User> &users);

    string szUsername;
    string szPswd;
    string szHost;
    string szDatabase;
    int nPort;
    MYSQL myCont;
    MYSQL_RES *result;
    MYSQL_ROW sql_row;
    MYSQL_FIELD *fd;
    bool isOpen;
    TimeUtil timeUtil;
};

#endif //LIBSYS_DB_H{}
