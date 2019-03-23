#include "libclient.h"
#include "ui_libclient.h"

#include <QVector>
#include <QSpinBox>
#include <QDate>
#include <QDebug>

LibClient::LibClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibClient)
{
    ui->setupUi(this);
    ui->fYear->setMaximum(QDate::currentDate().year());

    myModel = new booksModelDb;
    getBooksFromModel(myModel->getBooksModel());

    myProxyFilter = new BookFilter(this);
    myProxyFilter->setSourceModel(myModel->getBooksModel());
    ui->tableBooks->setModel(myProxyFilter);

    connect(ui->fTitle, &QLineEdit::textChanged, myProxyFilter, &BookFilter::setTitleFilter);
    connect(ui->fAuthor, &QLineEdit::textChanged, myProxyFilter, &BookFilter::setAuthorFilter);
    connect(ui->fYear, QOverload<int>::of(&QSpinBox::valueChanged), [=](int i){ myProxyFilter->setYearFilter(i); });

    //ui->statusBar->showMessage(conn.lastError().text());


}

void LibClient::getBooksFromModel(QAbstractTableModel* booksModel)
{
    ui->tableBooks->setModel(booksModel);
    //Handle Display Properties
    //---Here---
    ui->tableBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableBooks->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableBooks->setColumnHidden(0, true);

    delegate = new SpinBoxDelegate(ui->tableBooks);
    ui->tableBooks->setItemDelegateForColumn(3, delegate);

    ui->tableBooks->setSelectionBehavior(QAbstractItemView::SelectRows);
    //--Display Properties--end
    ui->tableBooks->show();
}

void LibClient::removeBook(){

    QModelIndexList list = ui->tableBooks->selectionModel()->selectedRows();
    std::vector<int> toDelete;

    foreach (QModelIndex temp, list){
        toDelete.push_back(temp.row());
    }

    std::sort(toDelete.begin(), toDelete.end(), std::greater<int>());

    foreach (int deleteRow, toDelete) {
        myProxyFilter->removeRow(deleteRow);
    }

    myModel->refresh();
}

void LibClient::addBook(const QString &newTitle, const QString &newAuthor, const int &year){
    myModel->addBook(newTitle.isEmpty() ? "Unknown": newTitle, newAuthor.isEmpty() ? "Unknown" : newAuthor ,
                     year == 0 ? QDate::currentDate().year() : year);
    myModel->refresh();
}

LibClient::~LibClient()
{
    delete ui;
    delete myModel;
    delete myProxyFilter;
    delete delegate;
}

void LibClient::on_bDelete_clicked()
{
    removeBook();
}



void LibClient::on_bAdd_clicked()
{
    FunWindow addWindow("Add New Book");
    addWindow.setFunButtonName("Add");

    if (addWindow.exec()){
        //add new element.
        addBook(addWindow.getTitle(), addWindow.getAuthor(), addWindow.getYear());
    } //otherwise window is closed
}

void LibClient::on_bClear_clicked()
{
    ui->fTitle->clear();
    ui->fAuthor->clear();
    ui->fYear->setValue(0);
}
