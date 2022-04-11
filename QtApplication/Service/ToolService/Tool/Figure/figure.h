#ifndef IMAGEEDITOR_FIGURE_H
#define IMAGEEDITOR_FIGURE_H


#include "../tool.h"
#include "figuremodel.h"

#include <QColor>

enum FigureType {
    line,
    shape,
    none
};

struct FigureData {
    QColor fillColor {QColor(Qt::green)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
    FigureType type {none};
};

class QGraphicsItem;

class Figure : public Tool {
Q_OBJECT

public:
    explicit Figure(QString name, ToolUnitView *view, FigureModel *model);

    virtual void setData(FigureData *figureData) {
        qDebug() << "setting data";
    }
    virtual FigureType getType() = 0;
    FigureData getData();

    void onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) override;
    void onMouseMoved(const QPoint &mousePos) override;
    void onMouseReleased(const QPoint &mousePos) override;

signals:
    void update(Figure *figure);
    void selected(Figure *figure);
    void deselected();

protected slots:
    void onItemSelected();
    void onItemDeselected();

private:
    FigureModel *model;

    bool isSelected = false;
};

#endif //IMAGEEDITOR_FIGURE_H
