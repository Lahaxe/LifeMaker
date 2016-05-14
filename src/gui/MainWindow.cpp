#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

MainWindow
::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    this->_ui->setupUi(this);

    // Resize to screen
    this->resize(QDesktopWidget().screenGeometry().width(),
                 QDesktopWidget().screenGeometry().height());
}

MainWindow
::~MainWindow()
{
    delete this->_ui;
}
