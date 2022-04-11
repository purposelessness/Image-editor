#include "shape.h"

#include <utility>

Shape::Shape(QString name, ToolUnitView *view, ShapeModel *model) : Figure(std::move(name), view, model), model(model) {}

void Shape::setData(FigureData *figureData) {
    model->setFillColor(figureData->fillColor);
    model->setLineColor(figureData->lineColor);
    model->setThickness(figureData->thickness);
}

FigureType Shape::getType() {
    return shape;
}
