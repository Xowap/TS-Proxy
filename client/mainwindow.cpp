#include <QDebug>
#include <QTcpSocket>
#include <QMessageBox>
#include <QRegExp>
#include <QTime>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settings = new QSettings("Maiznet", "TSProxy");

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataReady()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(connected()), this, SLOT(connectionReady()));

    connect(this, SIGNAL(newConnectionStatus(bool)), this, SLOT(connectionStatusChanged(bool)));

    ui->ts_proxy_host->setText(getFavoriteProxyHost());
    ui->ts_proxy_port->setValue(getFavoriteProxyPort());
    ui->ts_server_host->setText(getFavoriteTSHost());
    ui->ts_server_port->setValue(getFavoriteTSPort());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString MainWindow::getFavoriteTSHost() {
   return settings->value("pref/ts/host", "").toString();
}

QString MainWindow::getFavoriteProxyHost() {
    return settings->value("pref/proxy/host", "kate.maiznet.fr").toString();
}

int MainWindow::getFavoriteTSPort() {
    return settings->value("pref/ts/port", 1024).toInt();
}

int MainWindow::getFavoriteProxyPort() {
    return settings->value("pref/proxy/port", 7412).toInt();
}

void MainWindow::setFavoriteTSHost(QString host) {
    settings->setValue("pref/ts/host", host);
}

void MainWindow::setFavoriteProxyHost(QString host) {
    settings->setValue("pref/proxy/host", host);
}

void MainWindow::setFavoriteTSPort(int port) {
    settings->setValue("pref/ts/port", port);
}

void MainWindow::setFavoriteProxyPort(int port) {
    settings->setValue("pref/proxy/port", port);
}

int MainWindow::getFavoriteFwPort() {
    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    return settings->value("pref/fw/port", qrand() % 917).toInt();
}

void MainWindow::setFavoriteFwPort(int fw) {
    settings->setValue("pref/fw/port", fw);
}

void MainWindow::checkData() {
    int pos = 0;
    QRegExp dom_rx("[a-zA-Z1-9_.\\-]+");
    QRegExpValidator v(dom_rx, 0);
    QString proxy = ui->ts_proxy_host->text();
    QString server = ui->ts_server_host->text();

    if(v.validate(proxy, pos) == QValidator::Acceptable && v.validate(server, pos) == QValidator::Acceptable) {
        ui->connect_button->setEnabled(true);
    } else {
        ui->connect_button->setEnabled(false);
    }
}

void MainWindow::connectionReady() {
    QByteArray block;
    QTextStream out(&block);

    out << QString::number(getFavoriteFwPort())
                   .append(":")
                   .append(ui->ts_server_host->text())
                   .append(":")
                   .append(ui->ts_server_port->text())
                   .append("\r\n");

    out.flush();

    socket->write(block);
}

void MainWindow::dataReady() {
    if(socket->canReadLine()) {
        fw_port = QString(socket->readLine()).toInt();
        qDebug() << "Using forward port " << fw_port;
        emit newConnectionStatus(true);
    }
}

void MainWindow::setConnectionStatus(bool status) {
    qDebug() << "Changing connection status (" << status << ")";
    socket->abort();
    if(status) {
        ui->ts_proxy_host->setEnabled(false);
        ui->ts_proxy_port->setEnabled(false);
        ui->ts_server_host->setEnabled(false);
        ui->ts_server_port->setEnabled(false);
        socket->connectToHost(ui->ts_proxy_host->text(), ui->ts_proxy_port->text().toInt());
    } else {
        emit connectionStatusChanged(false);
    }
}

void MainWindow::connectionStatusChanged(bool status) {
    if(status) {
        qDebug() << "connected...";
        ui->ts_settings->setText(ui->ts_proxy_host->text() + ":" + QString::number(fw_port));
        ui->connect_button->setText("Disconnect");
        ui->connect_button->setChecked(true);

        setFavoriteProxyHost(ui->ts_proxy_host->text());
        setFavoriteProxyPort(ui->ts_proxy_port->text().toInt());
        setFavoriteTSHost(ui->ts_server_host->text());
        setFavoriteTSPort(ui->ts_server_port->text().toInt());
        setFavoriteFwPort(fw_port);
    } else {
        qDebug() << "disconnected...";
        ui->ts_settings->setText("");
        ui->connect_button->setText("Connect");
        ui->connect_button->setChecked(false);
        ui->ts_proxy_host->setEnabled(true);
        ui->ts_proxy_port->setEnabled(true);
        ui->ts_server_host->setEnabled(true);
        ui->ts_server_port->setEnabled(true);
    }
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError) {
    switch(socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("TS Proxy"), tr("The proxy host could not be found."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("TS Proxy"), tr("The proxy refused the connection."));
        break;
    default:
        QMessageBox::information(this, tr("TS Proxy"), tr("An error occured: %1.").arg(socket->errorString()));
    }

    emit connectionStatusChanged(false);
}

void MainWindow::on_actionQuitter_triggered()
{
    qApp->quit();
}
