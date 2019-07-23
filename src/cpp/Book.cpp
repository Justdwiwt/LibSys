//
// Created by 段泽宇 on 2019/7/23.
//

#include "../h/Book.h"

int Book::getMNBookId() const {
    return m_nBookId;
}

void Book::setMNBookId(int mNBookId) {
    m_nBookId = mNBookId;
}

const std::basic_string<char> &Book::getMStrBookName() const {
    return m_strBookName;
}

void Book::setMStrBookName(const std::basic_string<char> &mStrBookName) {
    m_strBookName = mStrBookName;
}

const std::basic_string<char> &Book::getMStrAuthor() const {
    return m_strAuthor;
}

void Book::setMStrAuthor(const std::basic_string<char> &mStrAuthor) {
    m_strAuthor = mStrAuthor;
}

const std::basic_string<char> &Book::getMStrIsbn() const {
    return m_strISBN;
}

void Book::setMStrIsbn(const std::basic_string<char> &mStrIsbn) {
    m_strISBN = mStrIsbn;
}

const std::basic_string<char> &Book::getMStrPub() const {
    return m_strPub;
}

void Book::setMStrPub(const std::basic_string<char> &mStrPub) {
    m_strPub = mStrPub;
}

const std::basic_string<char> &Book::getMInDate() const {
    return m_inDate;
}

void Book::setMInDate(const std::basic_string<char> &mInDate) {
    m_inDate = mInDate;
}

int Book::getMNTotalNum() const {
    return m_nTotalNum;
}

void Book::setMNTotalNum(int mNTotalNum) {
    m_nTotalNum = mNTotalNum;
}

int Book::getMNLeftNum() const {
    return m_nLeftNum;
}

void Book::setMNLeftNum(int mNLeftNum) {
    m_nLeftNum = mNLeftNum;
}

Book::Book(int mNBookId, const string &mStrBookName, const string &mStrAuthor, const string &mStrIsbn,
           const string &mStrPub, const string &mInDate, int mNTotalNum, int mNLeftNum) : m_nBookId(mNBookId),
                                                                                          m_strBookName(mStrBookName),
                                                                                          m_strAuthor(mStrAuthor),
                                                                                          m_strISBN(mStrIsbn),
                                                                                          m_strPub(mStrPub),
                                                                                          m_inDate(mInDate),
                                                                                          m_nTotalNum(mNTotalNum),
                                                                                          m_nLeftNum(mNLeftNum) {}

Book::~Book() {

}

Book::Book() {}
