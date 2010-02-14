/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jan 13 01:16:03 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ts_proxy_host;
    QLabel *label_2;
    QSpinBox *ts_proxy_port;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *ts_server_host;
    QLabel *label_3;
    QSpinBox *ts_server_port;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *ts_settings;
    QPushButton *connect_button;
    QMenuBar *menuBar;
    QMenu *menuFichier;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(503, 263);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ts_proxy_host = new QLineEdit(groupBox);
        ts_proxy_host->setObjectName(QString::fromUtf8("ts_proxy_host"));

        gridLayout->addWidget(ts_proxy_host, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(26, 16777215));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        ts_proxy_port = new QSpinBox(groupBox);
        ts_proxy_port->setObjectName(QString::fromUtf8("ts_proxy_port"));
        ts_proxy_port->setMaximumSize(QSize(70, 16777215));
        ts_proxy_port->setMinimum(1024);
        ts_proxy_port->setMaximum(65535);
        ts_proxy_port->setValue(7412);

        gridLayout->addWidget(ts_proxy_port, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        ts_server_host = new QLineEdit(groupBox_2);
        ts_server_host->setObjectName(QString::fromUtf8("ts_server_host"));

        gridLayout_2->addWidget(ts_server_host, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(26, 16777215));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        ts_server_port = new QSpinBox(groupBox_2);
        ts_server_port->setObjectName(QString::fromUtf8("ts_server_port"));
        ts_server_port->setMaximumSize(QSize(70, 16777215));
        ts_server_port->setMinimum(1024);
        ts_server_port->setMaximum(65535);
        ts_server_port->setValue(1024);

        gridLayout_2->addWidget(ts_server_port, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(98, 16777215));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        ts_settings = new QLineEdit(groupBox_3);
        ts_settings->setObjectName(QString::fromUtf8("ts_settings"));
        ts_settings->setReadOnly(true);

        gridLayout_3->addWidget(ts_settings, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        connect_button = new QPushButton(centralWidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setEnabled(false);
        connect_button->setCheckable(true);

        gridLayout_4->addWidget(connect_button, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 503, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(connect_button, SIGNAL(clicked(bool)), MainWindow, SLOT(setConnectionStatus(bool)));
        QObject::connect(ts_proxy_host, SIGNAL(textChanged(QString)), MainWindow, SLOT(checkData()));
        QObject::connect(ts_server_host, SIGNAL(textChanged(QString)), MainWindow, SLOT(checkData()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "TeamSpeak Proxy", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "TeamSpeak Proxy", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ts_proxy_host->setToolTip(QApplication::translate("MainWindow", "Address of the proxy server. This is the server on your local network that will relay TeamSpeak for you. Contact your network administrator to get more informations about this server.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ts_proxy_host->setText(QApplication::translate("MainWindow", "localhost", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ts_proxy_port->setToolTip(QApplication::translate("MainWindow", "Port to connect the proxy on.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TeamSpeak Server", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Host", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ts_server_host->setToolTip(QApplication::translate("MainWindow", "Enter here the name of the TeamSpeak server that you want to join.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ts_server_host->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ts_server_port->setToolTip(QApplication::translate("MainWindow", "Here goes the port of the TeamSpeak server that you want to join.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("MainWindow", "TeamSpeak Settings", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Server Address", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ts_settings->setToolTip(QApplication::translate("MainWindow", "Copy this address to TeamSpeak and connect it, you will be on the TeamSpeak server that you asked above.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        connect_button->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
