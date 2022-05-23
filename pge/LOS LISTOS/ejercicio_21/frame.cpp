#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) : QWidget(parent), ui(new Ui::Frame) {
    ui->setupUi(this);
}

Frame::~Frame() {
    delete ui;
}

void Frame::setFrame(QImage imagen) {
    image = imagen;
    repaint();
}

void Frame::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}
