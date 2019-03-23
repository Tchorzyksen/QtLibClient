#ifndef FUNWINDOW_H
#define FUNWINDOW_H

#include <QDialog>
#include <QFormLayout>

#include <QDate>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

// |-Edit/Add--Window-|
// |                  |
// |title    LineEdit |
// |author   ComboBox | -> ComboBox should display conntent of table authrs, if possible adding new elements enable.
// |year     SpinBox  |
// |                  |
// |b1      b2      b3| -> b1 - function button edit/add, b2 - clear, b3 - cancel
// |------------------|

class FunWindow : public QDialog{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(int year READ getYear WRITE setYear NOTIFY yearChanged)
public:
    FunWindow(const QString &windowTitle);

    void setFunButtonName(const QString &funButtonName);

    QString getTitle() const;
    QString getAuthor() const;
    int getYear() const;

public slots:
    void setTitle(QString title)
    {
        if (insertTitle.text() == title)
            return;

        insertTitle.setText(title);
        emit titleChanged(title);
    }

    void setAuthor(QString author)
    {
        if (insertAuthor.text() == author)
            return;

        insertAuthor.setText(author);
        emit authorChanged(author);
    }

    void setYear(int year)
    {
        if (insertYear.value() == year || year == 0)
            return;

        insertYear.setValue(year);
        emit yearChanged(year);
    }

signals:
    void titleChanged(QString title);

    void authorChanged(QString author);

    void yearChanged(int year);

private:

    QVBoxLayout windowLayout;
    QHBoxLayout buttons;

    QLabel labelTitle;
    QLabel labelAuthor;
    QLabel labelYear;

    QLineEdit insertTitle;
    QLineEdit insertAuthor;
    QSpinBox insertYear;

    QPushButton funButton;
    QPushButton clear;
    QPushButton cancel;

    void setLayout();


};

#endif // FUNWINDOW_H
