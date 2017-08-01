#ifndef SEARCH_H
#define SEARCH_H

#include <QNetworkReply>
#include <QObject>
#include <QString>
#include <QStringList>

#include "SearchModel.h"

namespace google_images
{
    class Search : public QObject
    {
        Q_OBJECT

        Q_CLASSINFO("author", "Dmitry Smirnov")

        Q_PROPERTY(SearchModel* model READ model CONSTANT)
    public:
        Search(QObject* parent = nullptr);

        Q_INVOKABLE void search(QString request);

        SearchModel* model() const;

    signals:
        void gotReplyError(QString cause);
        void gotNewImages(QStringList imageUrls);

    protected slots:
        void onReply(QNetworkReply* reply);

    private:
        QNetworkAccessManager _networkAccessManager;

        SearchModel* _searchModel;
    };
}

#endif // SEARCH_H
