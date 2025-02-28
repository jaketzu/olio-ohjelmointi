#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

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

    bool playing = false;
    bool currentPlayer = 0;

    QTimer *timer;
    int playerTimesRemaining[2] = {0, 0};

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void startGame();
    void stopGame();
    void setTime();

    void timerTimeout();

    void switchPlayer(bool);
};
#endif // MAINWINDOW_H
