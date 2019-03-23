#ifndef LIBCLIENT_H
#define LIBCLIENT_H

#include <QMainWindow>

#include "booksmodel.h"
#include "booksmodeldb.h"
#include "bookfilter.h"
#include "funwindow.h"
#include "spinboxdelegate.h"

namespace Ui {
class LibClient;
}

class LibClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibClient(QWidget *parent = nullptr);
    ~LibClient();

private slots:
    void on_bDelete_clicked();

    void on_bAdd_clicked();

    void on_bClear_clicked();

private:
    Ui::LibClient *ui;

    AbstractBooksModel *myModel; //Database Table Model
    BookFilter *myProxyFilter; //Proxy Model used to filter shown data
    SpinBoxDelegate *delegate;



    //Load Table View
    void getBooksFromModel(QAbstractTableModel *booksModel);
    void addBook(const QString &newTitle, const QString &newAuthor, const int &year);
    void removeBook();





};

#endif // LIBCLIENT_H
