#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MainWindow::operandMap['/'] = 0;
    MainWindow::operandMap['*'] = 1;
    MainWindow::operandMap['-'] = 2;
    MainWindow::operandMap['+'] = 3;

    ui->setupUi(this);

    connect(ui->keyNum0, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('0');});
    connect(ui->keyNum1, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('1');});
    connect(ui->keyNum2, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('2');});
    connect(ui->keyNum3, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('3');});
    connect(ui->keyNum4, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('4');});
    connect(ui->keyNum5, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('5');});
    connect(ui->keyNum6, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('6');});
    connect(ui->keyNum7, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('7');});
    connect(ui->keyNum8, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('8');});
    connect(ui->keyNum9, &QPushButton::clicked, this, [this]{MainWindow::handleNumKey('9');});

    connect(ui->keyDiv, &QPushButton::clicked, this, [this]{MainWindow::handleOperandKey('/');});
    connect(ui->keyMul, &QPushButton::clicked, this, [this]{MainWindow::handleOperandKey('*');});
    connect(ui->keySub, &QPushButton::clicked, this, [this]{MainWindow::handleOperandKey('-');});
    connect(ui->keySum, &QPushButton::clicked, this, [this]{MainWindow::handleOperandKey('+');});

    connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::handleClearButton);

    connect(ui->buttonCalculate, &QPushButton::clicked, this, &MainWindow::handleCalculateButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNumKey(char num)
{
    MainWindow::numStrings[MainWindow::numSetState] += num;

    if(MainWindow::numSetState == 0)
        ui->textNum1->setText(MainWindow::numStrings[MainWindow::numSetState]);
    else
        ui->textNum2->setText(MainWindow::numStrings[MainWindow::numSetState]);
}

void MainWindow::handleOperandKey(char operand)
{
    if(operand == '-' &&
        MainWindow::numStrings[MainWindow::numSetState].isEmpty())
    {
        MainWindow::numStrings[MainWindow::numSetState] += QString(operand);

        if(MainWindow::numSetState == 0)
            ui->textNum1->setText(QString(operand));
        else
            ui->textNum2->setText(QString(operand));
    }
    else if(MainWindow::operand == ' ' && !MainWindow::numStrings[0].isEmpty() && MainWindow::numStrings[0] != "-")
    {
        MainWindow::operand = operand;
        ui->textOperand->setText(QString(operand));

        MainWindow::numSetState = 1;
    }
}

void MainWindow::handleClearButton()
{
    MainWindow::numStrings[0].clear();
    MainWindow::numStrings[1].clear();
    ui->textNum1->clear();
    ui->textNum2->clear();

    MainWindow::operand = ' ';
    ui->textOperand->clear();

    ui->textResultNum->clear();

    MainWindow::numSetState = 0;
}

void MainWindow::handleCalculateButton()
{
    if(
        !MainWindow::numStrings[0].isEmpty() &&
        MainWindow::numSetState != 0 &&
        !MainWindow::numStrings[1].isEmpty() &&
        MainWindow::numStrings[1] != '-' &&
        !QString(MainWindow::operand).isEmpty()
        )
    {
        float num1 = MainWindow::numStrings[0].toFloat();
        float num2 = MainWindow::numStrings[1].toFloat();
        float result;

        switch(MainWindow::operandMap[MainWindow::operand])
        {
        case 0:
            result = num1 / num2;
            break;

        case 1:
            result = num1 * num2;
            break;

        case 2:
            result = num1 - num2;
            break;

        case 3:
            result = num1 + num2;
            break;
        }

        MainWindow::handleClearButton();

        ui->textResultNum->setText(QString::number(result));
    }
}
