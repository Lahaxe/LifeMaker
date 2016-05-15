#include "gui/MainWindow.h"
#include <QApplication>

#include "lifemaker/core/Logger.h"

int main(int argc, char *argv[])
{
#ifdef USE_LOG4CPP
    lifemaker::initialize_logger("DEBUG");
#else
    qSetMessagePattern("%{file}(%{line}): %{message}");
#endif

    LOGGER_INFO << "***** Start LifeMaker *****";

    QApplication a(argc, argv);
    MainWindow w;
    w.initialize();
    w.show();

    return a.exec();
}
