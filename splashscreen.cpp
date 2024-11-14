#include "splashscreen.h"
#include <QTimer>
#include <QPalette>
SplashScreen::SplashScreen(QApplication *app_, QWidget *parent)
{

    setupProgressBar();
    setupText();
    setupLogo();

    mainLayout = new QVBoxLayout(this);

    topLayout = new QHBoxLayout();
    leftLayout = new QVBoxLayout();
    rightLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();

    mainLayout->addStretch(); // Add a stretchable space to push the progress bar to the bottom
    rightLayout->addWidget(&logoLabel,Qt::AlignVCenter);
    leftLayout->addWidget(&textLabel,Qt::AlignVCenter);
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);

    bottomLayout->addWidget(&progress_);
    mainLayout->addLayout(topLayout,Qt::AlignTop); // Add the horizontal layout to the vertical one

    mainLayout->addLayout(bottomLayout); // Add the horizontal layout to the vertical one

    mainLayout->setContentsMargins(20, 0, 20, 40);

    setLayout(mainLayout);

    connect(&timer_, &QTimer::timeout, this, &SplashScreen::UpdateProgress);
    timer_.start(50);
}

SplashScreen::~SplashScreen()
{
    delete mainLayout;
    delete topLayout;
    delete bottomLayout;
    delete rightLayout;
    delete leftLayout;
}

void SplashScreen::setupProgressBar()
{
    progress_.setRange(0,100);
    progress_.setEnabled(true);
    progress_.setTextVisible(false);
    QString danger = "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #ef4f7f,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-bottom-right-radius: 5px;border-bottom-left-radius: 5px;border: .px solid black;}";
    progress_.setStyleSheet(danger);

}

void SplashScreen::setupText()
{
    textLabel.setText("© 2024 DemoCorp. All rights reserved. This software and its contents are protected by copyright law and international treaties. Unauthorized reproduction, distribution, or modification of this software is strictly prohibited and may result in severe civil and criminal penalties. For licensing inquiries or permissions, please contact support@democorp.com."
                      );
    textLabel.setWordWrap(true);

    QFont font = textLabel.font();
    font.setPixelSize(15);

    font.setFamily("Arial");  // Change to the font family you want
    font.setBold(true);
    textLabel.setFont(font);

}

void SplashScreen::setupLogo()
{
    QPixmap logoPixmap("logo.png"); // Use your logo's resource path or file path
    logoLabel.setPixmap(logoPixmap.scaled(300, 300, Qt::KeepAspectRatio));
}

void SplashScreen::UpdateProgress()
{
    progressValue_ += 1;
    progress_.setValue(progressValue_);

    if (progressValue_ >= 100) {
        timer_.stop();
        emit LoadingFinished();
    }

}
