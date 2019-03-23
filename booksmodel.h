#ifndef BOOKSMODEL_H
#define BOOKSMODEL_H

#include <QAbstractTableModel>

class AbstractBooksModel {
public:

    virtual QAbstractTableModel* getBooksModel() = 0;
    virtual void addBook(const QString &newTitle, const QString &newAuthor, const int &year) = 0;
    virtual void deleteBooks(QModelIndex idx) = 0;
    virtual void refresh() = 0;

    QString progName(){return "Books Model"; }

    virtual ~AbstractBooksModel() {}

};

#endif // BOOKSMODEL_H
