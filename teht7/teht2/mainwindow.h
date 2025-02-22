#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString numStrings[2];
    char operand = ' ';
    std::map<char, int> operandMap;
    bool numSetState = 0;

private slots:
    void handleNumKey(char);
    void handleOperandKey(char operand);
    void handleClearButton();
    void handleCalculateButton();
};
#endif // MAINWINDOW_H
