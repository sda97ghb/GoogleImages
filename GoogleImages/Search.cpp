#include "Extractor.h"
#include "Search.h"

namespace google_images
{
    Search::Search(QObject* parent) :
        QObject(parent)
    {
        _searchModel = new SearchModel(this);

        connect(this, &Search::gotNewImages,
                _searchModel, &SearchModel::setImageUrls);

        connect(&_networkAccessManager, &QNetworkAccessManager::finished,
                this, &Search::onReply);

        connect(this, &Search::gotReplyError, [](QString cause)
        {
            qDebug() << "Got error " << cause;
        });
    }

    void Search::search(QString request)
    {
        static const QString SEARCH_URL_TEMPLATE =
                "http://www.google.ru/search?site=imghp&tbm=isch&q=";
        qDebug() << "Request " << (SEARCH_URL_TEMPLATE + request);
        _networkAccessManager.get(QNetworkRequest(QUrl(SEARCH_URL_TEMPLATE + request)));
    }

    SearchModel* Search::model() const
    {
        return _searchModel;
    }

    void Search::onReply(QNetworkReply* reply)
    {
        qDebug() << "Got reply.";
        if (reply->error() != QNetworkReply::NoError)
            emit gotReplyError(reply->errorString());
        else
            emit gotNewImages(extractImageUrls(reply->readAll()));

        reply->deleteLater();
    }
}
