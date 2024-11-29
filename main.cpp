// #include "include/Terminal/terminal.hpp"

// #include <iostream>

// int main()
// {
//     Terminal terminal;
// }

#include <QApplication>
#include "graphic_interface/include/mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
