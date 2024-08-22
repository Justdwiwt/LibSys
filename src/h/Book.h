#ifndef LIBSYS_BOOK_H
#define LIBSYS_BOOK_H

#include <string>
#include <ctime>

using namespace std;

#pragma once

class Book {
public:
    Book();

    virtual ~Book();

    Book(int mNBookId, string mStrBookName, string mStrAuthor, string mStrIsbn,
         string mStrPub, string mInDate, int mNTotalNum, int mNLeftNum);

    int getMNBookId() const;

    void setMNBookId(int mNBookId);

    const string &getMStrBookName() const;

    void setMStrBookName(const string &mStrBookName);

    const string &getMStrAuthor() const;

    void setMStrAuthor(const string &mStrAuthor);

    const string &getMStrIsbn() const;

    void setMStrIsbn(const string &mStrIsbn);

    const string &getMStrPub() const;

    void setMStrPub(const string &mStrPub);

    const string &getMInDate() const;

    void setMInDate(const string &mInDate);

    int getMNTotalNum() const;

    void setMNTotalNum(int mNTotalNum);

    int getMNLeftNum() const;

    void setMNLeftNum(int mNLeftNum);

private:
    int m_nBookId{};
    string m_strBookName;
    string m_strAuthor;
    string m_strISBN;
    string m_strPub;
    string m_inDate;
    int m_nTotalNum{};
    int m_nLeftNum{};
};

#endif //LIBSYS_BOOK_H
