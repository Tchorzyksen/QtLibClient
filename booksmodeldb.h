#ifndef BOOKSMODELDB_H
#define BOOKSMODELDB_H

#include "booksmodel.h"

#include <QSqlDatabase>
#include <QSqlTableModel>

class booksModelDb : public AbstractBooksModel{

    QSqlDatabase conn;
    QSqlTableModel *myBooksModel;


public:
    booksModelDb();
    QSqlTableModel* getBooksModel();

    void addBook(const QString &newTitle, const QString &newAuthor, const int &year);
    void deleteBooks(QModelIndex idx);
    void refresh();

    QString reportDataBaseErrors();

    ~booksModelDb();

};

#endif // BOOKSMODELDB_H
