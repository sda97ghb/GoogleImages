#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <QString>
#include <QStringList>

namespace google_images
{
    /// Extract image urls from response html page.
    QStringList extractImageUrls(QString html);
}

#endif // EXTRACTOR_H
