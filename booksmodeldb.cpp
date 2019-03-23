#include "booksmodeldb.h"
#include <QDebug>

#include <QSqlRecord>

booksModelDb::booksModelDb() {
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName("/Users/MichaLeG/MyLib/MyLib.db");
}

QSqlTableModel* booksModelDb::getBooksModel(){
    myBooksModel = new QSqlTableModel;
    myBooksModel->setTable("myBooks");
    myBooksModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Title"));
    myBooksModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Author"));
    myBooksModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Year"));
    myBooksModel->select();
    return myBooksModel;
}

void booksModelDb::addBook(const QString &newTitle, const QString &newAuthor, const int &year){
        QSqlRecord newBook = myBooksModel->record();

        newBook.setValue(myBooksModel->fieldIndex("title"), newTitle);
        newBook.setValue(myBooksModel->fieldIndex("author"), newAuthor);
        newBook.setValue(myBooksModel->fieldIndex("year"), year);

        myBooksModel->insertRecord(-1, newBook); //Insert into table, nagative pos -> insert at the end of table.
}

void booksModelDb::deleteBooks(QModelIndex idx){
    myBooksModel->removeRow(idx.row());
}

void booksModelDb::refresh(){
    myBooksModel->select();
}

booksModelDb::~booksModelDb()
{
    delete myBooksModel;
    conn.close();
}
