#ifndef SEARCHMODEL_H
#define SEARCHMODEL_H

#include <QAbstractListModel>

namespace google_images
{
    class SearchModel : public QAbstractListModel
    {
        Q_OBJECT

        Q_CLASSINFO("author", "Dmitry Smirnov")

    public:
        enum Roles
        {
            ImageUrlRole = Qt::UserRole + 1
        };

        QHash<int, QByteArray> roleNames() const override
        {
            QHash<int, QByteArray> roles;
            roles[ImageUrlRole] = "imageUrl";
            return roles;
        }

        explicit SearchModel(QObject* parent = nullptr);

        int rowCount(const QModelIndex &) const override;
        QVariant data(const QModelIndex &index, int role = ImageUrlRole) const override;

    public slots:
        void setImageUrls(QStringList imageUrls);

    private:
        QStringList _imageUrls;
    };
}

#endif // SEARCHMODEL_H
