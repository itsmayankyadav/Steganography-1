#ifndef __STEG__SETUP
#define __STEG__SETUP
#include "mainwindow.h"
#include <QHBoxLayout>


void MainWindow::_setupProgressBar()
{
    QHBoxLayout * progressBarLayout = new QHBoxLayout;

    _progressBar->setTextVisible(false);

    progressBarLayout->addWidget(_progressBar);

    _mainLayout->addLayout(progressBarLayout);
}

void MainWindow::_setupButtons()
{
    connect(_openCoverImageButton, SIGNAL(clicked()), this, SLOT(_openCoverImageButtonIsPressed()));
    connect(_openPayloadButton, SIGNAL(clicked()), this, SLOT(_openPayloadButtonIsPressed()));
    connect(_hidePayloadButton, SIGNAL(clicked()), this, SLOT(_hidePayloadButtonIsPressed()));
    connect(_openStegImageButton,SIGNAL(clicked()),this,SLOT(_openStegImageButtonIsPressed()));
    connect(_recoverFilesButton,SIGNAL(clicked()),this,SLOT(_recoverFilesButtonIsPressed()));

    QHBoxLayout * hideButtons = new QHBoxLayout;
    QHBoxLayout * recoverButtons = new QHBoxLayout;

    hideButtons->addWidget(_openCoverImageButton);
    hideButtons->addWidget(_openPayloadButton);
    hideButtons->addWidget(_hidePayloadButton);

    recoverButtons->addWidget(_openStegImageButton);
    recoverButtons->addWidget(_recoverFilesButton);

    _mainLayout->addLayout(hideButtons);
    _mainLayout->addLayout(recoverButtons);
}

void MainWindow::_setupLabels()
{
    QHBoxLayout * imageLabels = new QHBoxLayout;
    QHBoxLayout * images = new QHBoxLayout;

    _coverLabel->setMaximumHeight(15);
    _stegLabel->setMaximumHeight(15);

    _coverLabel->setAlignment(Qt::AlignCenter);
    _stegLabel->setAlignment(Qt::AlignCenter);

    imageLabels->addWidget(_coverLabel);
    imageLabels->addWidget(_stegLabel);

    images->addWidget(_coverImageDisplay);
    images->addWidget(_stegImageDisplay);

    _mainLayout->addLayout(imageLabels);
    _mainLayout->addLayout(images);
}

void MainWindow::_setup()
{
    _setupLabels();
    _setupProgressBar();
    _setupButtons();

    _centralWidget->setLayout(_mainLayout);
}

#endif
