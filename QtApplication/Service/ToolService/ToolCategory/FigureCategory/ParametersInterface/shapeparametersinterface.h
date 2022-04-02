#ifndef IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H
#define IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H

#include "../../../toolunitview.h"
#include "parametersinterface.h"

#include <QSlider>
#include <QPushButton>
#include <QToolButton>

class ShapeParametersInterface : public ParametersInterface, public ToolUnitView {
Q_OBJECT

public:
    explicit ShapeParametersInterface(const QString &name, QObject *parent = nullptr, QWidget *widget = new QWidget());

    [[nodiscard]] QColor getFillColor() const;
    [[nodiscard]] QColor getLineColor() const;
    [[nodiscard]] int getThicknessValue() const;
    void resetParameters();

private slots:
    void onNoneFillAction();
    void onSolidFillAction();
    void onNoneLineAction();
    void onSolidLineAction();
    void onThicknessChanged(int value);
    void pickFillColor();
    void pickLineColor();

private:
    void createColorPicker(const QString &name, QPushButton *colorPickerButton, QToolButton *materialPickerButton);
    void setFillColor(const QColor &color);
    void setLineColor(const QColor &color);

    QSlider *thicknessSlider;
    QPushButton *fillColorPicker, *lineColorPicker;
    QToolButton *fillMaterialPicker, *lineMaterialPicker;
    QColor defaultFillColor = QColor(0, 168, 243), defaultLineColor = QColor(Qt::black);
    QColor prevFillColor = QColor();
    QColor prevLineColor = QColor();
};


#endif //IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H