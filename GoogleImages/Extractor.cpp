#include <htmlcxx/html/ParserDom.h>

#include "Extractor.h"

QStringList google_images::extractImageUrls(QString html)
{
    QStringList imageUrls;

    using std::pair;
    using std::string;
    using htmlcxx::HTML::Node;
    using htmlcxx::HTML::ParserDom;

    ParserDom parser;
    tree<Node> dom = parser.parseTree(html.toStdString());

    for (tree<Node>::iterator i = dom.begin(); i != dom.end(); ++ i)
    {
        Node& node = *i;
        if (!node.isTag())
            continue;
        if (node.tagName() != "img")
            continue;
        node.parseAttributes();
        if (QString::fromStdString(node.attribute("width").second).toInt() < 75)
            continue;
        pair<bool, string> srcAttribute = node.attribute("src");
        if (!srcAttribute.first)
            continue;
        imageUrls.append(QString::fromStdString(srcAttribute.second));
    }

    return imageUrls;
}
