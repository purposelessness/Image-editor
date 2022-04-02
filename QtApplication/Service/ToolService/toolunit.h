#ifndef IMAGEEDITOR_TOOLUNIT_H
#define IMAGEEDITOR_TOOLUNIT_H

#include <QObject>
#include <QAction>
#include <QWidget>

#include "Tool/itoolmodel.h"

class ToolUnit : public QObject {
Q_OBJECT

public:
    explicit ToolUnit(QString name);

signals:
    void triggered(const QString &name);
    void updateView();

public:
    virtual QAction *getAction() = 0;
    virtual IToolModel *getModel() = 0;
    virtual QWidget *getWidget() = 0;
    virtual QWidget *getAlternativeWidget();

    [[nodiscard]] QString toString() const;

private:
    QString name;
};

inline bool operator==(const ToolUnit &s1, const ToolUnit &s2)
{
    return s1.toString() == s2.toString();
}

inline uint qHash(const ToolUnit &key, uint seed)
{
    return qHash(key.toString(), seed);
}

#endif //IMAGEEDITOR_TOOLUNIT_H
