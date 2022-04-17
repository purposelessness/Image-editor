#include "marqueeitem.h"

#include <QPainter>
#include <QPen>

QPen MarqueeItem::whiteSolidPen{};
QPen MarqueeItem::blackDashPen{};

MarqueeItem::MarqueeItem() {
    whiteSolidPen.setStyle(Qt::SolidLine);
    whiteSolidPen.setColor(Qt::white);
    whiteSolidPen.setWidth(0);

    blackDashPen.setStyle(Qt::DashLine);
    blackDashPen.setColor(Qt::black);
    blackDashPen.setWidth(0);
}

void MarqueeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::NoBrush);
    painter->setPen(whiteSolidPen);
    drawItem(painter, rect);

    painter->setPen(blackDashPen);
    drawItem(painter, rect);
}

QRectF MarqueeItem::boundingRect() const {
    return rect;
}

void MarqueeItem::setRect(const QRectF &newRect) {
    rect = newRect;
    update(boundingRect());
}
