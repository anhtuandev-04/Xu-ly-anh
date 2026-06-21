/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *bt_ClickMe;
    QLabel *lb_FileName;
    QLineEdit *ln_filename;
    QPushButton *bt_Browse;
    QGroupBox *gBox_HisSlide;
    QPushButton *bt_HisSlide_Color;
    QPushButton *bt_HisSlide_Gray;
    QLabel *lb_Bta;
    QLineEdit *ln_c;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(861, 553);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bt_ClickMe = new QPushButton(centralWidget);
        bt_ClickMe->setObjectName(QStringLiteral("bt_ClickMe"));
        bt_ClickMe->setGeometry(QRect(630, 70, 91, 31));
        lb_FileName = new QLabel(centralWidget);
        lb_FileName->setObjectName(QStringLiteral("lb_FileName"));
        lb_FileName->setGeometry(QRect(80, 115, 81, 21));
        ln_filename = new QLineEdit(centralWidget);
        ln_filename->setObjectName(QStringLiteral("ln_filename"));
        ln_filename->setGeometry(QRect(200, 109, 421, 31));
        bt_Browse = new QPushButton(centralWidget);
        bt_Browse->setObjectName(QStringLiteral("bt_Browse"));
        bt_Browse->setGeometry(QRect(630, 110, 91, 31));
        gBox_HisSlide = new QGroupBox(centralWidget);
        gBox_HisSlide->setObjectName(QStringLiteral("gBox_HisSlide"));
        gBox_HisSlide->setGeometry(QRect(70, 220, 651, 80));
        bt_HisSlide_Color = new QPushButton(gBox_HisSlide);
        bt_HisSlide_Color->setObjectName(QStringLiteral("bt_HisSlide_Color"));
        bt_HisSlide_Color->setGeometry(QRect(400, 30, 151, 31));
        bt_HisSlide_Gray = new QPushButton(gBox_HisSlide);
        bt_HisSlide_Gray->setObjectName(QStringLiteral("bt_HisSlide_Gray"));
        bt_HisSlide_Gray->setGeometry(QRect(130, 30, 171, 31));
        lb_Bta = new QLabel(centralWidget);
        lb_Bta->setObjectName(QStringLiteral("lb_Bta"));
        lb_Bta->setGeometry(QRect(80, 170, 111, 21));
        ln_c = new QLineEdit(centralWidget);
        ln_c->setObjectName(QStringLiteral("ln_c"));
        ln_c->setGeometry(QRect(200, 170, 421, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        bt_ClickMe->setText(QApplication::translate("MainWindow", "Click me!", 0));
        lb_FileName->setText(QApplication::translate("MainWindow", "File Name", 0));
        bt_Browse->setText(QApplication::translate("MainWindow", "Browse", 0));
        gBox_HisSlide->setTitle(QApplication::translate("MainWindow", "Histogram Silde", 0));
        bt_HisSlide_Color->setText(QApplication::translate("MainWindow", "Apply(Color Image)", 0));
        bt_HisSlide_Gray->setText(QApplication::translate("MainWindow", "Apply(Gray Image)", 0));
        lb_Bta->setText(QApplication::translate("MainWindow", "By the amount", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
