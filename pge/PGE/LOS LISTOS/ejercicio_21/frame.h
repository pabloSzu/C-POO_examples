#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class Frame;
}

class Frame : public QWidget {
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();
    void setFrame(QImage imagen);

private:
    Ui::Frame *ui;
    QImage image;
    void paintEvent(QPaintEvent *);
};

#endif // FRAME_H
