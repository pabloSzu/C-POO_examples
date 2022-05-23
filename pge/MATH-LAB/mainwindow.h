#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void MousePressEvent(QMouseEvent * event) override;

private slots:
    void click_lugar();


private:
    Ui::MainWindow *ui;
};





#endif // MAINWINDOW_H
