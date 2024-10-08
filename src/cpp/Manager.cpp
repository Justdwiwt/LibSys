
#include "../h/Manager.h"

Manager::Manager() = default;

Manager::~Manager() = default;

void Manager::ShowMenu() {
    system("cls");
    cout << "==========================欢迎使用图书馆后台管理系统：==========================" << endl;
    cout << "                              1.新书录入" << endl;
    cout << "                              2.图书查询" << endl;
    cout << "                              3.删除图书" << endl;
    cout << "                              4.图书列表" << endl;
    cout << "                              5.借阅记录" << endl;
    cout << "                              6.新增用户" << endl;
    cout << "                              7.用户列表" << endl;
    cout << "                              0.退出登录" << endl;
}

bool Manager::AddBook() {
    string bookName;
    string author;
    string isbn;
    string pub;
    int total;
    char szTime[32] = {0};
    time_t lt;
    lt = time(nullptr);
    m_timeUtil.TimeToString(lt, szTime);

    cout << "你选择的是新增图书功能，请依次输入图书信息" << endl;
    cout << "图书名称 作者 ISBN 出版社 总册数" << endl;
    cin >> bookName;
    cin >> author;
    cin >> isbn;
    cin >> pub;
    cin >> total;

    Book book;
    book.setMStrBookName(bookName);
    book.setMStrAuthor(author);
    book.setMStrIsbn(isbn);
    book.setMStrPub(pub);
    book.setMNTotalNum(total);
    book.setMNLeftNum(0);
    book.setMInDate(szTime);

    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }
    m_dbUtil.AddBook(book);
    cout << "新增图书成功" << endl;
    return true;
}

bool Manager::DisplayAllBook() {
    vector<Book> books;
    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }

    m_dbUtil.SelectAllBook(books);
    vector<Book>::iterator vecIter;
    cout << "ID     书名            作者           出版社       入库日期     馆藏数量   余量" << endl;
    for (vecIter = books.begin(); vecIter != books.end(); vecIter++) {

        cout << setiosflags(ios::left) << setw(4) << vecIter->getMNBookId() << "  " << setw(14)
             << vecIter->getMStrBookName()
             << "  " << setw(10) << vecIter->getMStrAuthor() << "  " << setw(14) << vecIter->getMStrPub() << "  "
             << setw(14)
             << vecIter->getMInDate() << "  " << setw(8) << vecIter->getMNTotalNum() << "  " << setw(3)
             << vecIter->getMNLeftNum() << endl;
    }
    cin.get();
    cin.get();
    return true;
}

bool Manager::QueryBook(const string &strBookName) {
    vector<Book> books;
    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }

    m_dbUtil.SelectBookByName(strBookName, books);
    vector<Book>::iterator vecIter;
    cout << "ID     书名            作者           出版社       入库日期     馆藏数量   余量" << endl;
    for (vecIter = books.begin(); vecIter != books.end(); vecIter++) {

        cout << setiosflags(ios::left) << setw(4) << vecIter->getMNBookId() << "  " << setw(14)
             << vecIter->getMStrBookName()
             << "  " << setw(10) << vecIter->getMStrAuthor() << "  " << setw(14) << vecIter->getMStrPub() << "  "
             << setw(14)
             << vecIter->getMInDate() << "  " << setw(8) << vecIter->getMNTotalNum() << "  " << setw(3)
             << vecIter->getMNLeftNum() << endl;
    }
    cin.get();
    cin.get();
    return true;
}

bool Manager::DeleteBook(int nBookId) {
    Book book;
    book.setMNBookId(-1);
    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }
    m_dbUtil.SelectBookById(nBookId, book);
    if (book.getMNBookId() != -1) {
        cout << "ID     书名            作者           出版社       入库日期     馆藏数量   余量" << endl;
        cout << setiosflags(ios::left) << setw(4) << book.getMNBookId() << "  " << setw(14) << book.getMStrBookName()
             << "  "
             << setw(10) << book.getMStrAuthor() << "  " << setw(14) << book.getMStrPub() << "  " << setw(14)
             << book.getMInDate() << "  " << setw(8) << book.getMNTotalNum() << "  " << setw(3) << book.getMNLeftNum()
             << endl;

        //询问是否删除
        char chIsDelete = 'a';
        cout << "删除这本书吗?n/y" << endl;
        cin.get();
        cin >> chIsDelete;
        while (true) {
            if (chIsDelete == 'y' || chIsDelete == 'Y') {
                m_dbUtil.DeleteBookById(nBookId);
                break;
            } else if (chIsDelete == 'n' || chIsDelete == 'N') {
                cout << "已取消删除！";
                break;
            } else {
                cout << "输入有误,请重新输入:";
                cin.get();
                cin >> chIsDelete;
            }
        }
    } else {
        cout << "没有找到ID为" << nBookId << "的书籍" << endl;
    }
    cin.get();
    cin.get();
    return true;
}

bool Manager::DiaplayAllBorrowRecord() {
    vector<BorrowRecord> borrowRecords;
    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }

    m_dbUtil.SelectAllBorrowRecord(borrowRecords);
    User user;
    Book book;
    vector<BorrowRecord>::iterator vecIter;
    cout << "ID       书名        借阅人    借阅日期       应还日期     还书日期   续借次数" << endl;
    for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++) {
        user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
        m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
        cout << setiosflags(ios::left) << setw(4) << vecIter->m_nBorrowId << "  " << setw(14) << book.getMStrBookName()
             << "  " << setw(6) << user.m_strName << "  " << setw(13) << vecIter->m_tBorrowDate << "  " << setw(13)
             << vecIter->m_tShouldReturnDate << "  " << setw(13) << vecIter->m_tReturnDate << "  " << setw(3)
             << vecIter->m_nContinue << endl;
    }
    cin.get();
    cin.get();
    return true;
}

bool Manager::AddUser() {
    cout << "请输入一下用户信息:" << endl;
    cout << "用户名   密码   用户类型" << endl;
    User user;

    cin >> user.m_strName;
    cin >> user.m_strPassword;
    cin >> user.m_nRole;

    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }

    m_dbUtil.AddUser(user);
    cout << "新增用户成功" << endl;
    cin.get();
    cin.get();
    return true;
}

bool Manager::DisplayAllUser() {
    vector<User> users;
    if (!m_dbUtil.isOpen) {
        m_dbUtil.OpenDB();
    }

    m_dbUtil.SelectAllUser(users);
    User user;
    Book book;
    vector<User>::iterator vecIter;
    cout << "ID     用户名      身份" << endl;
    for (vecIter = users.begin(); vecIter != users.end(); vecIter++) {
        cout << setiosflags(ios::left) << setw(6) << vecIter->m_nID << "  " << setw(8) << vecIter->m_strName << "  "
             << (vecIter->m_nRole == 1 ? "管理员" : "学生") << endl;
    }
    cin.get();
    cin.get();
    return true;
}
