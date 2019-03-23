#include "bookfilter.h"
#include <QDebug>

BookFilter::BookFilter(QObject* parent) : QSortFilterProxyModel(parent)
{
}

bool BookFilter::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex titleIdx = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex authorIdx = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex yearIdx = sourceModel()->index(sourceRow, 3, sourceParent);

    QString author = sourceModel()->data(authorIdx).toString();
    QString title = sourceModel()->data(titleIdx).toString();
    int year = sourceModel()->data(yearIdx).toInt();

    if(yearFilterVal > 2100 || yearFilterVal < 1)
        return author.contains(authorRegex) && title.contains(titleRegex);

    return author.contains(authorRegex) && title.contains(titleRegex) && year == yearFilterVal;

}

void BookFilter::setAuthorFilter(const QString& regExp)
{
    authorRegex.setPattern(regExp);
    authorRegex.setCaseSensitivity(Qt::CaseInsensitive);
    invalidateFilter();
}

void BookFilter::setTitleFilter(const QString& regExp)
{
    titleRegex.setPattern(regExp);
    titleRegex.setCaseSensitivity(Qt::CaseInsensitive);
    invalidateFilter();
}

void BookFilter::setYearFilter(const int& regExp)
{
    yearFilterVal = regExp;
    invalidateFilter();
}
