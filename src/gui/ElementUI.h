#ifndef ELEMENTUI_H
#define ELEMENTUI_H

#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class ElementUI;
}

class ElementUI : public QWidget
{
    Q_OBJECT

public:
    explicit ElementUI(QWidget *parent = 0);

    virtual ~ElementUI();

    void initialize(QString const & name);

    QString get_name() const;

signals:
    void endmove();

protected:
    virtual void mousePressEvent(QMouseEvent* event);

    virtual void mouseMoveEvent(QMouseEvent* event);

    virtual void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::ElementUI * _ui;

    QPoint _start_position;

};

#endif // ELEMENTUI_H
