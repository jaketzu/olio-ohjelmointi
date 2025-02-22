#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::handleCount);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::handleReset);

    ui->countText->setText(QString::number(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCount()
{
    MainWindow::count++;
    ui->countText->setText(QString::number(count));
}

void MainWindow::handleReset()
{
    MainWindow::count = 0;
    ui->countText->setText(QString::number(0));
}
