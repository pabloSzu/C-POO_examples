#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mouseReleaseEvent(QMouseEvent * event) override;
private:
    Ui::Widget *ui;


private slots:
void slotGuardar();
};

#endif // WIDGET_H
