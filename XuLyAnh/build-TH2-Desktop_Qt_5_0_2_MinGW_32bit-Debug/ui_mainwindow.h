/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
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
    QGroupBox *gBox_1;
    QLabel *lb_1;
    QLabel *lb_2;
    QLabel *lb_3;
    QLabel *lb_4;
    QLabel *lb_5;
    QLabel *lb_6;
    QLabel *lb_7;
    QLabel *lb_8;
    QLineEdit *ln_filename;
    QLineEdit *ln_mucsang;
    QLineEdit *ln_dotuongphan;
    QLineEdit *ln_phannguong;
    QPushButton *bt_Chon;
    QPushButton *btn_amban_xam;
    QPushButton *btn_amban_mau;
    QPushButton *btn_mucsang_xam;
    QPushButton *btn_mucsang_mau;
    QPushButton *btn_dotuongphan_xam;
    QPushButton *btn_dotuongphan_mau;
    QPushButton *btn_phannguong;
    QPushButton *btn_gaithuat_tuantumau;
    QPushButton *btn_giaithuat_tosu;
    QPushButton *btn_histogram_xam;
    QPushButton *btn_histogram_mau;
    QPushButton *btn_biendoituyentinh_histogram;
    QPushButton *btn_canbang_histogram;
    QLabel *lb_kichthuocmatna;
    QLabel *lb_tilenhieu;
    QLineEdit *ln_SizeMask;
    QLineEdit *ln_tylenhieu;
    QPushButton *btn_AnMon;
    QPushButton *btn_GianNo;
    QPushButton *btn_Open;
    QPushButton *btn_Close;
    QPushButton *btn_loctrungbinh;
    QPushButton *btn_loctrungvi;
    QPushButton *bt_gauss_laplace;
    QPushButton *btn_nhieumuoitieu;
    QPushButton *btn_nhieuanhmau;
    QPushButton *btn_G_L_anhmau;
    QPushButton *btn_locGradient;
    QPushButton *btn_Gra_anhmau;
    QPushButton *btn_locRobert;
    QPushButton *btn_locRobert_anhmau;
    QPushButton *btn_locSobel;
    QPushButton *btn_locSobel_anhmau;
    QPushButton *btn_locPrewitt;
    QPushButton *btn_locPrewitt_anhmau;
    QPushButton *btn_locLaplace;
    QPushButton *btn_locLaplace_anhmau;
    QGroupBox *gBox_2;
    QLineEdit *ln_anh1;
    QLineEdit *ln_anh2;
    QLineEdit *ln_Opacity1;
    QLineEdit *ln_Opacity1_2;
    QPushButton *btn_ChonAnh1;
    QPushButton *btn_ChonAnh2;
    QPushButton *bt_Cong2Anh;
    QPushButton *bt_Tru2Anh;
    QLabel *lb_Opacity1;
    QLabel *lb_Opacity1_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1087, 881);
        MainWindow->setMinimumSize(QSize(1087, 881));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gBox_1 = new QGroupBox(centralWidget);
        gBox_1->setObjectName(QStringLiteral("gBox_1"));
        gBox_1->setGeometry(QRect(20, 0, 1041, 681));
        lb_1 = new QLabel(gBox_1);
        lb_1->setObjectName(QStringLiteral("lb_1"));
        lb_1->setGeometry(QRect(20, 36, 111, 31));
        lb_2 = new QLabel(gBox_1);
        lb_2->setObjectName(QStringLiteral("lb_2"));
        lb_2->setGeometry(QRect(20, 85, 121, 31));
        lb_3 = new QLabel(gBox_1);
        lb_3->setObjectName(QStringLiteral("lb_3"));
        lb_3->setGeometry(QRect(20, 140, 101, 31));
        lb_4 = new QLabel(gBox_1);
        lb_4->setObjectName(QStringLiteral("lb_4"));
        lb_4->setGeometry(QRect(20, 200, 141, 31));
        lb_5 = new QLabel(gBox_1);
        lb_5->setObjectName(QStringLiteral("lb_5"));
        lb_5->setGeometry(QRect(20, 260, 121, 31));
        lb_6 = new QLabel(gBox_1);
        lb_6->setObjectName(QStringLiteral("lb_6"));
        lb_6->setGeometry(QRect(400, 140, 171, 31));
        lb_7 = new QLabel(gBox_1);
        lb_7->setObjectName(QStringLiteral("lb_7"));
        lb_7->setGeometry(QRect(400, 200, 221, 31));
        lb_8 = new QLabel(gBox_1);
        lb_8->setObjectName(QStringLiteral("lb_8"));
        lb_8->setGeometry(QRect(400, 250, 171, 31));
        ln_filename = new QLineEdit(gBox_1);
        ln_filename->setObjectName(QStringLiteral("ln_filename"));
        ln_filename->setGeometry(QRect(170, 30, 631, 41));
        ln_mucsang = new QLineEdit(gBox_1);
        ln_mucsang->setObjectName(QStringLiteral("ln_mucsang"));
        ln_mucsang->setGeometry(QRect(170, 130, 221, 41));
        ln_dotuongphan = new QLineEdit(gBox_1);
        ln_dotuongphan->setObjectName(QStringLiteral("ln_dotuongphan"));
        ln_dotuongphan->setGeometry(QRect(170, 190, 221, 41));
        ln_phannguong = new QLineEdit(gBox_1);
        ln_phannguong->setObjectName(QStringLiteral("ln_phannguong"));
        ln_phannguong->setGeometry(QRect(170, 250, 221, 41));
        bt_Chon = new QPushButton(gBox_1);
        bt_Chon->setObjectName(QStringLiteral("bt_Chon"));
        bt_Chon->setGeometry(QRect(880, 30, 141, 41));
        btn_amban_xam = new QPushButton(gBox_1);
        btn_amban_xam->setObjectName(QStringLiteral("btn_amban_xam"));
        btn_amban_xam->setGeometry(QRect(630, 80, 171, 41));
        btn_amban_mau = new QPushButton(gBox_1);
        btn_amban_mau->setObjectName(QStringLiteral("btn_amban_mau"));
        btn_amban_mau->setGeometry(QRect(880, 80, 141, 41));
        btn_mucsang_xam = new QPushButton(gBox_1);
        btn_mucsang_xam->setObjectName(QStringLiteral("btn_mucsang_xam"));
        btn_mucsang_xam->setGeometry(QRect(630, 130, 171, 41));
        btn_mucsang_mau = new QPushButton(gBox_1);
        btn_mucsang_mau->setObjectName(QStringLiteral("btn_mucsang_mau"));
        btn_mucsang_mau->setGeometry(QRect(880, 130, 141, 41));
        btn_dotuongphan_xam = new QPushButton(gBox_1);
        btn_dotuongphan_xam->setObjectName(QStringLiteral("btn_dotuongphan_xam"));
        btn_dotuongphan_xam->setGeometry(QRect(630, 190, 171, 41));
        btn_dotuongphan_mau = new QPushButton(gBox_1);
        btn_dotuongphan_mau->setObjectName(QStringLiteral("btn_dotuongphan_mau"));
        btn_dotuongphan_mau->setGeometry(QRect(880, 180, 141, 41));
        btn_phannguong = new QPushButton(gBox_1);
        btn_phannguong->setObjectName(QStringLiteral("btn_phannguong"));
        btn_phannguong->setGeometry(QRect(620, 250, 181, 41));
        btn_gaithuat_tuantumau = new QPushButton(gBox_1);
        btn_gaithuat_tuantumau->setObjectName(QStringLiteral("btn_gaithuat_tuantumau"));
        btn_gaithuat_tuantumau->setGeometry(QRect(850, 230, 171, 41));
        btn_giaithuat_tosu = new QPushButton(gBox_1);
        btn_giaithuat_tosu->setObjectName(QStringLiteral("btn_giaithuat_tosu"));
        btn_giaithuat_tosu->setGeometry(QRect(850, 280, 171, 41));
        btn_histogram_xam = new QPushButton(gBox_1);
        btn_histogram_xam->setObjectName(QStringLiteral("btn_histogram_xam"));
        btn_histogram_xam->setGeometry(QRect(160, 310, 231, 41));
        btn_histogram_mau = new QPushButton(gBox_1);
        btn_histogram_mau->setObjectName(QStringLiteral("btn_histogram_mau"));
        btn_histogram_mau->setGeometry(QRect(580, 310, 221, 41));
        btn_biendoituyentinh_histogram = new QPushButton(gBox_1);
        btn_biendoituyentinh_histogram->setObjectName(QStringLiteral("btn_biendoituyentinh_histogram"));
        btn_biendoituyentinh_histogram->setGeometry(QRect(140, 360, 271, 41));
        btn_canbang_histogram = new QPushButton(gBox_1);
        btn_canbang_histogram->setObjectName(QStringLiteral("btn_canbang_histogram"));
        btn_canbang_histogram->setGeometry(QRect(560, 360, 261, 41));
        lb_kichthuocmatna = new QLabel(gBox_1);
        lb_kichthuocmatna->setObjectName(QStringLiteral("lb_kichthuocmatna"));
        lb_kichthuocmatna->setGeometry(QRect(20, 420, 161, 31));
        lb_tilenhieu = new QLabel(gBox_1);
        lb_tilenhieu->setObjectName(QStringLiteral("lb_tilenhieu"));
        lb_tilenhieu->setGeometry(QRect(30, 470, 151, 31));
        ln_SizeMask = new QLineEdit(gBox_1);
        ln_SizeMask->setObjectName(QStringLiteral("ln_SizeMask"));
        ln_SizeMask->setGeometry(QRect(190, 420, 113, 41));
        ln_tylenhieu = new QLineEdit(gBox_1);
        ln_tylenhieu->setObjectName(QStringLiteral("ln_tylenhieu"));
        ln_tylenhieu->setGeometry(QRect(190, 470, 113, 41));
        btn_AnMon = new QPushButton(gBox_1);
        btn_AnMon->setObjectName(QStringLiteral("btn_AnMon"));
        btn_AnMon->setGeometry(QRect(110, 620, 131, 41));
        btn_GianNo = new QPushButton(gBox_1);
        btn_GianNo->setObjectName(QStringLiteral("btn_GianNo"));
        btn_GianNo->setGeometry(QRect(300, 620, 131, 41));
        btn_Open = new QPushButton(gBox_1);
        btn_Open->setObjectName(QStringLiteral("btn_Open"));
        btn_Open->setGeometry(QRect(490, 620, 131, 41));
        btn_Close = new QPushButton(gBox_1);
        btn_Close->setObjectName(QStringLiteral("btn_Close"));
        btn_Close->setGeometry(QRect(670, 620, 131, 41));
        btn_loctrungbinh = new QPushButton(gBox_1);
        btn_loctrungbinh->setObjectName(QStringLiteral("btn_loctrungbinh"));
        btn_loctrungbinh->setGeometry(QRect(320, 420, 171, 41));
        btn_loctrungvi = new QPushButton(gBox_1);
        btn_loctrungvi->setObjectName(QStringLiteral("btn_loctrungvi"));
        btn_loctrungvi->setGeometry(QRect(520, 420, 161, 41));
        bt_gauss_laplace = new QPushButton(gBox_1);
        bt_gauss_laplace->setObjectName(QStringLiteral("bt_gauss_laplace"));
        bt_gauss_laplace->setGeometry(QRect(690, 420, 161, 41));
        btn_nhieumuoitieu = new QPushButton(gBox_1);
        btn_nhieumuoitieu->setObjectName(QStringLiteral("btn_nhieumuoitieu"));
        btn_nhieumuoitieu->setGeometry(QRect(320, 470, 171, 41));
        btn_nhieuanhmau = new QPushButton(gBox_1);
        btn_nhieuanhmau->setObjectName(QStringLiteral("btn_nhieuanhmau"));
        btn_nhieuanhmau->setGeometry(QRect(520, 470, 161, 41));
        btn_G_L_anhmau = new QPushButton(gBox_1);
        btn_G_L_anhmau->setObjectName(QStringLiteral("btn_G_L_anhmau"));
        btn_G_L_anhmau->setGeometry(QRect(690, 470, 161, 41));
        btn_locGradient = new QPushButton(gBox_1);
        btn_locGradient->setObjectName(QStringLiteral("btn_locGradient"));
        btn_locGradient->setGeometry(QRect(20, 520, 151, 41));
        btn_Gra_anhmau = new QPushButton(gBox_1);
        btn_Gra_anhmau->setObjectName(QStringLiteral("btn_Gra_anhmau"));
        btn_Gra_anhmau->setGeometry(QRect(20, 570, 151, 41));
        btn_locRobert = new QPushButton(gBox_1);
        btn_locRobert->setObjectName(QStringLiteral("btn_locRobert"));
        btn_locRobert->setGeometry(QRect(190, 520, 161, 41));
        btn_locRobert_anhmau = new QPushButton(gBox_1);
        btn_locRobert_anhmau->setObjectName(QStringLiteral("btn_locRobert_anhmau"));
        btn_locRobert_anhmau->setGeometry(QRect(190, 570, 161, 41));
        btn_locSobel = new QPushButton(gBox_1);
        btn_locSobel->setObjectName(QStringLiteral("btn_locSobel"));
        btn_locSobel->setGeometry(QRect(370, 520, 171, 41));
        btn_locSobel_anhmau = new QPushButton(gBox_1);
        btn_locSobel_anhmau->setObjectName(QStringLiteral("btn_locSobel_anhmau"));
        btn_locSobel_anhmau->setGeometry(QRect(370, 570, 171, 41));
        btn_locPrewitt = new QPushButton(gBox_1);
        btn_locPrewitt->setObjectName(QStringLiteral("btn_locPrewitt"));
        btn_locPrewitt->setGeometry(QRect(560, 520, 161, 41));
        btn_locPrewitt_anhmau = new QPushButton(gBox_1);
        btn_locPrewitt_anhmau->setObjectName(QStringLiteral("btn_locPrewitt_anhmau"));
        btn_locPrewitt_anhmau->setGeometry(QRect(560, 570, 161, 41));
        btn_locLaplace = new QPushButton(gBox_1);
        btn_locLaplace->setObjectName(QStringLiteral("btn_locLaplace"));
        btn_locLaplace->setGeometry(QRect(740, 520, 161, 41));
        btn_locLaplace_anhmau = new QPushButton(gBox_1);
        btn_locLaplace_anhmau->setObjectName(QStringLiteral("btn_locLaplace_anhmau"));
        btn_locLaplace_anhmau->setGeometry(QRect(740, 570, 161, 41));
        gBox_2 = new QGroupBox(centralWidget);
        gBox_2->setObjectName(QStringLiteral("gBox_2"));
        gBox_2->setGeometry(QRect(20, 690, 1051, 261));
        ln_anh1 = new QLineEdit(gBox_2);
        ln_anh1->setObjectName(QStringLiteral("ln_anh1"));
        ln_anh1->setGeometry(QRect(150, 30, 601, 41));
        ln_anh2 = new QLineEdit(gBox_2);
        ln_anh2->setObjectName(QStringLiteral("ln_anh2"));
        ln_anh2->setGeometry(QRect(150, 90, 601, 41));
        ln_Opacity1 = new QLineEdit(gBox_2);
        ln_Opacity1->setObjectName(QStringLiteral("ln_Opacity1"));
        ln_Opacity1->setGeometry(QRect(150, 150, 241, 41));
        ln_Opacity1_2 = new QLineEdit(gBox_2);
        ln_Opacity1_2->setObjectName(QStringLiteral("ln_Opacity1_2"));
        ln_Opacity1_2->setGeometry(QRect(150, 210, 241, 41));
        btn_ChonAnh1 = new QPushButton(gBox_2);
        btn_ChonAnh1->setObjectName(QStringLiteral("btn_ChonAnh1"));
        btn_ChonAnh1->setGeometry(QRect(780, 30, 141, 41));
        btn_ChonAnh2 = new QPushButton(gBox_2);
        btn_ChonAnh2->setObjectName(QStringLiteral("btn_ChonAnh2"));
        btn_ChonAnh2->setGeometry(QRect(780, 90, 141, 41));
        bt_Cong2Anh = new QPushButton(gBox_2);
        bt_Cong2Anh->setObjectName(QStringLiteral("bt_Cong2Anh"));
        bt_Cong2Anh->setGeometry(QRect(420, 180, 161, 41));
        bt_Tru2Anh = new QPushButton(gBox_2);
        bt_Tru2Anh->setObjectName(QStringLiteral("bt_Tru2Anh"));
        bt_Tru2Anh->setGeometry(QRect(610, 180, 141, 41));
        lb_Opacity1 = new QLabel(gBox_2);
        lb_Opacity1->setObjectName(QStringLiteral("lb_Opacity1"));
        lb_Opacity1->setGeometry(QRect(20, 150, 111, 31));
        lb_Opacity1_2 = new QLabel(gBox_2);
        lb_Opacity1_2->setObjectName(QStringLiteral("lb_Opacity1_2"));
        lb_Opacity1_2->setGeometry(QRect(20, 210, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1087, 21));
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
        gBox_1->setTitle(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 1 \341\272\243nh", 0));
        lb_1->setText(QApplication::translate("MainWindow", "T\303\252n file \341\272\243nh", 0));
        lb_2->setText(QApplication::translate("MainWindow", "\303\202nh \303\242m b\341\272\243n", 0));
        lb_3->setText(QApplication::translate("MainWindow", "M\341\273\251c s\303\241ng", 0));
        lb_4->setText(QApplication::translate("MainWindow", "\304\220\341\273\231 t\306\260\306\241ng ph\341\272\243n", 0));
        lb_5->setText(QApplication::translate("MainWindow", "Ch\341\273\215n ng\306\260\341\273\241ng", 0));
        lb_6->setText(QApplication::translate("MainWindow", "> 0 t\304\203ng, < 0 gi\341\272\243m", 0));
        lb_7->setText(QApplication::translate("MainWindow", "> 1 t\304\203ng 0 < c < 1 gi\341\272\243m", 0));
        lb_8->setText(QApplication::translate("MainWindow", "> n tr\341\272\257ng < n \304\221en", 0));
        bt_Chon->setText(QApplication::translate("MainWindow", "Ch\341\273\215n", 0));
        btn_amban_xam->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_amban_mau->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        btn_mucsang_xam->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_mucsang_mau->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        btn_dotuongphan_xam->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_dotuongphan_mau->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        btn_phannguong->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 ph\303\242n ng\306\260\341\273\241ng", 0));
        btn_gaithuat_tuantumau->setText(QApplication::translate("MainWindow", "Gi\341\272\243i thu\341\272\255t tu\341\272\247n t\341\273\261", 0));
        btn_giaithuat_tosu->setText(QApplication::translate("MainWindow", "Gi\341\272\243i thu\341\272\255t Otsu", 0));
        btn_histogram_xam->setText(QApplication::translate("MainWindow", "V\341\272\275 Histogram \341\272\243nh x\303\241m", 0));
        btn_histogram_mau->setText(QApplication::translate("MainWindow", "V\341\272\275 Histogram \341\272\243nh m\303\240u", 0));
        btn_biendoituyentinh_histogram->setText(QApplication::translate("MainWindow", "Bi\341\272\277n \304\221\341\273\225i tuy\341\272\277n t\303\255nh Histogram", 0));
        btn_canbang_histogram->setText(QApplication::translate("MainWindow", "C\303\242n b\341\272\261ng Histogram", 0));
        lb_kichthuocmatna->setText(QApplication::translate("MainWindow", "K\303\255ch th\306\260\341\273\233c m\341\272\267t n\341\272\241", 0));
        lb_tilenhieu->setText(QApplication::translate("MainWindow", "T\341\273\267 l\341\273\207 nhi\341\273\205u (%)", 0));
        btn_AnMon->setText(QApplication::translate("MainWindow", "\304\202n m\303\262n", 0));
        btn_GianNo->setText(QApplication::translate("MainWindow", "Gi\303\243n n\341\273\237", 0));
        btn_Open->setText(QApplication::translate("MainWindow", "Open", 0));
        btn_Close->setText(QApplication::translate("MainWindow", "Close", 0));
        btn_loctrungbinh->setText(QApplication::translate("MainWindow", "L\341\273\215c trung b\303\254nh", 0));
        btn_loctrungvi->setText(QApplication::translate("MainWindow", "L\341\273\215c trung v\341\273\213", 0));
        bt_gauss_laplace->setText(QApplication::translate("MainWindow", "Gauss + Laplace", 0));
        btn_nhieumuoitieu->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u mu\341\273\221i ti\303\252u", 0));
        btn_nhieuanhmau->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u \341\272\243nh m\303\240u", 0));
        btn_G_L_anhmau->setText(QApplication::translate("MainWindow", "G + L \341\272\242nh M\303\240u", 0));
        btn_locGradient->setText(QApplication::translate("MainWindow", "L\341\273\215c Gradient", 0));
        btn_Gra_anhmau->setText(QApplication::translate("MainWindow", "Gradient \341\272\243nh m\303\240u", 0));
        btn_locRobert->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert", 0));
        btn_locRobert_anhmau->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert \341\272\243nh m\303\240u", 0));
        btn_locSobel->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel", 0));
        btn_locSobel_anhmau->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel \341\272\243nh m\303\240u", 0));
        btn_locPrewitt->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt", 0));
        btn_locPrewitt_anhmau->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt \341\272\243nh m\303\240u", 0));
        btn_locLaplace->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace", 0));
        btn_locLaplace_anhmau->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace \341\272\243nh m\303\240u", 0));
        gBox_2->setTitle(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 2 \341\272\243nh", 0));
        btn_ChonAnh1->setText(QApplication::translate("MainWindow", "Ch\341\273\215n \341\272\243nh 1", 0));
        btn_ChonAnh2->setText(QApplication::translate("MainWindow", "Ch\341\273\215n \341\272\243nh 2", 0));
        bt_Cong2Anh->setText(QApplication::translate("MainWindow", "C\341\273\231ng 2 \341\272\243nh", 0));
        bt_Tru2Anh->setText(QApplication::translate("MainWindow", "Tr\341\273\253 2 \341\272\243nh", 0));
        lb_Opacity1->setText(QApplication::translate("MainWindow", "Opacity \341\272\243nh 1", 0));
        lb_Opacity1_2->setText(QApplication::translate("MainWindow", "Opacity \341\272\243nh 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
