#include "ElementUI.h"
#include "ui_ElementUI.h"

#include "lifemaker/core/Logger.h"

ElementUI::ElementUI(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::ElementUI)
{
    this->_ui->setupUi(this);

#ifdef ANDROID
    this->setMaximumSize(300,300);
    this->resize(300,300);
    this->setMinimumSize(300,300);
#endif
}

ElementUI::~ElementUI()
{
    delete this->_ui;
}

void ElementUI::initialize(const QString &name)
{
    this->_ui->label->setText(name);
}

QString ElementUI::get_name() const
{
    return this->_ui->label->text();
}

void ElementUI::mousePressEvent(QMouseEvent *event)
{
    _start_position = event->pos();
}

void ElementUI::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        this->move(mapToParent(event->pos() - _start_position));
    }
}

void ElementUI::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit this->endmove();
}
