#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QObject>
#include <QProgressBar>
#include <QSplashScreen>
#include <QTimer>
#include <QLabel>
#include <QBoxLayout>

class SplashScreen final: public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(QApplication *app_, QWidget *parent = 0);
    ~SplashScreen();
    QProgressBar progress_;
    QTimer timer_;
    int progressValue_ = 0;
    QLabel textLabel;
    QLabel logoLabel;
    QVBoxLayout *mainLayout;
    void setupProgressBar();
    void setupText();
    void setupLogo();
    QHBoxLayout *topLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *bottomLayout;
public slots:
    void UpdateProgress();

signals:
    void LoadingFinished();
};

#endif // SPLASHSCREEN_H
