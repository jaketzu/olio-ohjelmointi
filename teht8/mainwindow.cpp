#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    timer->setTimerType(Qt::PreciseTimer);
    timer->setInterval(1);

    connect(timer, &QTimer::timeout, this, &MainWindow::timerTimeout);

    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::stopGame);

    connect(ui->pushButtonSetTime, &QPushButton::clicked, this, &MainWindow::setTime);
    connect(ui->pushButtonPlayer1, &QPushButton::clicked, this, [this]{MainWindow::switchPlayer(0);});
    connect(ui->pushButtonPlayer2, &QPushButton::clicked, this, [this]{MainWindow::switchPlayer(1);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_H)
        switchPlayer(currentPlayer);
}

void MainWindow::startGame()
{
    if(
        !playing
        && playerTimesRemaining[0] > 0
        && playerTimesRemaining[1] > 0
        && playerTimesRemaining[0] == playerTimesRemaining[1])
    {
        playing = true;

        currentPlayer = 0;
        timer->start();

        ui->progressBarGame->setFormat("Game ongoing");
    }
}

void MainWindow::stopGame()
{
    playing = false;

    timer->stop();

    playerTimesRemaining[0] = 0;
    playerTimesRemaining[1] = 0;

    ui->progressBarPlayer1->setValue(0);
    ui->progressBarPlayer2->setValue(0);
    ui->progressBarGame->setValue(0);

    ui->progressBarGame->setFormat("Select playtime and press \"Start\"");
}

void MainWindow::setTime()
{
    int time = ui->spinBoxGameTime->value();
    if(!playing && time > 0 && time < 99999)
    {

        playerTimesRemaining[0] = time * 1000;
        playerTimesRemaining[1] = time * 1000;

        ui->progressBarPlayer1->setRange(0, time);
        ui->progressBarPlayer2->setRange(0, time);
        ui->progressBarGame->setRange(0, time * 2);

        ui->progressBarPlayer1->setValue(time);
        ui->progressBarPlayer2->setValue(time);
        ui->progressBarGame->setValue(time * 2);

        ui->progressBarGame->setFormat("Ready to start!");
    }
}

void MainWindow::timerTimeout()
{
    if(playerTimesRemaining[currentPlayer] > 0)
    {
        playerTimesRemaining[currentPlayer]--;
        ui->progressBarGame->setValue(std::ceil((float)(playerTimesRemaining[0] + playerTimesRemaining[1])) / 1000);

        if(currentPlayer == 0)
        {
            ui->progressBarPlayer1->setValue(std::ceil((float)(playerTimesRemaining[0]) / 1000));
        }
        else
        {
            ui->progressBarPlayer2->setValue(std::ceil((float)(playerTimesRemaining[1]) / 1000));
        }
    }
    else
    {
        playing = false;
        timer->stop();

        if(currentPlayer == 0)
        {
            ui->progressBarGame->setFormat("Player 1 wins!");
        }
        else
        {
            ui->progressBarGame->setFormat("Player 2 wins!");
        }
    }
}

void MainWindow::switchPlayer(bool player)
{
    if(playing && player == currentPlayer)
    {
        timer->stop();
        currentPlayer = !currentPlayer;
        timer->start();
    }
}
