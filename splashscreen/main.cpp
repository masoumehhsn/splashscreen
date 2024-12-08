#include "mainwindow.h"

#include <QApplication>
#include <splashscreen.h>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SplashScreen *splash = new SplashScreen(&a);
    splash->setPixmap(QPixmap(":/rec/background.PNG"));  // splash picture
    splash->show();
    QObject::connect(splash,&SplashScreen::LoadingFinished,[&](){splash->close();w.show();});
    return a.exec();
}
