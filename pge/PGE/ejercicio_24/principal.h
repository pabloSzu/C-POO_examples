#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Principal;
}

class Principal : public QWidget {
    Q_OBJECT

public:
    explicit Principal( QWidget *parent = 0 );
    ~Principal();
    static Principal *getInstancia();

private:
    Ui::Principal *ui;
    static Principal *instancia;

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void signal_ok();
    void signal_cerrarSesion();
    void signal_cierrePrincipal();

private slots:
    void slot_pbCerrarSesion();
    void slot_pbOk();

};

#endif // PRINCIPAL_H
