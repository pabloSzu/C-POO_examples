#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVector>
#include <QStringList>
#include <QCloseEvent>

namespace Ui {
    class Login;
}

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget * parent = 0);
    ~Login();
    static Login *getInstancia();

    void setBaseUsuarios(QVector< QStringList > usuarios);

private:
    Ui::Login *ui;
    static Login *instancia;

    QVector< QStringList > usuarios;

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void slot_validarUsuario();
    void slot_agregarUsuario(QStringList usuario);

signals:
    void signal_usuarioValidado(bool valido, QStringList usuario);
    void signal_cierreLogin();
};

#endif // LOGIN_H
