#include "SearchModel.h"

namespace google_images
{
    SearchModel::SearchModel(QObject* parent) :
        QAbstractListModel(parent)
    {
        // Designed as empty
    }

    int SearchModel::rowCount(const QModelIndex&) const
    {
        return _imageUrls.size();
    }

    QVariant SearchModel::data(const QModelIndex& index, int role) const
    {
        if (!index.isValid())
            return QVariant();

        switch (role)
        {
        case ImageUrlRole: return _imageUrls.at(index.row());
        default: return QVariant();
        }
    }

    void SearchModel::setImageUrls(QStringList imageUrls)
    {
        beginResetModel();
        _imageUrls = imageUrls;
        endResetModel();
    }
}
