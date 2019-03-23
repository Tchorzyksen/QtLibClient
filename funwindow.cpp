#include "funwindow.h"

FunWindow::FunWindow(const QString &windowTitle) : QDialog(){

    FunWindow::setWindowTitle(windowTitle);
    setLayout();

    connect(&funButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(&cancel, SIGNAL(clicked()), this, SLOT(reject()));

    connect(&clear, SIGNAL(clicked()), &insertTitle, SLOT(clear()));
    connect(&clear, SIGNAL(clicked()), &insertAuthor, SLOT(clear()));
    connect(&clear, &QPushButton::clicked, [=](){ insertYear.setValue(0);});
}

void FunWindow::setFunButtonName(const QString &funButtonName){
    funButton.setText(funButtonName);
}

void FunWindow::setLayout(){

    labelTitle.setText("Title:");
    windowLayout.addWidget(&labelTitle);
    windowLayout.addWidget(&insertTitle);


    labelAuthor.setText("Author:");
    windowLayout.addWidget(&labelAuthor);
    windowLayout.addWidget(&insertAuthor);


    labelYear.setText("Year:");
    windowLayout.addWidget(&labelYear);
    windowLayout.addWidget(&insertYear);

    insertYear.setMinimum(0);
    insertYear.setMaximum(QDate::currentDate().year());
    insertYear.setSpecialValueText("Year");


    buttons.addWidget(&funButton);
    clear.setText("Clear");
    buttons.addWidget(&clear);
    cancel.setText("Cancel");
    buttons.addWidget(&cancel);

    windowLayout.addLayout(&buttons);

    QDialog::setLayout(&windowLayout);
}

QString FunWindow::getTitle() const{
    return insertTitle.text();
}

QString FunWindow::getAuthor() const{
    return insertAuthor.text();
}

int FunWindow::getYear() const{

    if(insertYear.text().toInt() > 0)
        return insertYear.text().toInt();
    else
        return QDate::currentDate().year();
}
