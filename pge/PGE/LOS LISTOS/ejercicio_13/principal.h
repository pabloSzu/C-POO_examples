#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class principal;
}

class principal : public QMainWindow {
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private:
    Ui::principal *ui;
    QFile f;

private slots:
    void slot_cerrar();
//    void slot_nuevo();
    void slot_abrir();
//    void slot_guardar();

};

#endif // PRINCIPAL_H
