#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>

#include "ElementUI.h"
#include "Controller.h"

#include "lifemaker/objects/Relation.h"
#include "lifemaker/core/LMController.h"

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

void MainWindow::initialize()
{
    this->_ui->widget_2->initialize("feu");
    this->_ui->widget_3->initialize("terre");

    this->connect(this->_ui->widget_2, SIGNAL(endmove()), SLOT(check()));
}

void MainWindow::check() const
{
    QVector<ElementUI*> elements;
    if (lifemaker::gui::check_proximity(this->_ui->frame, this->_ui->widget_2, elements))
    {
        std::vector<int> parents = {3}; // widget_2.id
        // for (auto element : elements)
        // parents.push_back(element.get_id);
        parents.push_back(4);
        std::sort(parents.begin(), parents.end());
        lifemaker::Relation relation(0, parents, {});

        if (lifemaker::LMController::get_instance().merge_elements(&relation))
        {
            ElementUI* newelement = new ElementUI(this->_ui->frame);
            newelement->setGeometry(this->_ui->widget_2->geometry());

            newelement->initialize("lave"); // relation.enfants[0].get_name
            newelement->show();

            delete this->_ui->widget_2;
            delete this->_ui->widget_3;
        }
    }
}
