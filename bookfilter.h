#ifndef BOOKFILTER_H
#define BOOKFILTER_H

#include <QSortFilterProxyModel>

class BookFilter : public QSortFilterProxyModel
{
public:
    explicit BookFilter(QObject* parent = nullptr);

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

public slots:
    void setTitleFilter(const QString& regExp);
    void setAuthorFilter(const QString& regExp);
    void setYearFilter(const int& regExp);


private:
    QRegExp titleRegex;
    QRegExp authorRegex;
    int yearFilterVal;

};

#endif // BOOKFILTER_H
