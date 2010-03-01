#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QSettings *settings;

    int getFavoriteTSPort();
    void setFavoriteTSPort(int);
    QString getFavoriteTSHost();
    void setFavoriteTSHost(QString);

    int getFavoriteProxyPort();
    void setFavoriteProxyPort(int);
    QString getFavoriteProxyHost();
    void setFavoriteProxyHost(QString);

    void setFavoriteFwPort(int);
    int getFavoriteFwPort();

    int fw_port;

public slots:
    void connectionReady();
    void dataReady();
    void setConnectionStatus(bool);
    void connectionStatusChanged(bool);
    void displayError(QAbstractSocket::SocketError socketError);
    void checkData();

signals:
    void newConnectionStatus(bool);

private slots:
    void on_actionQuitter_triggered();
};

#endif // MAINWINDOW_H
