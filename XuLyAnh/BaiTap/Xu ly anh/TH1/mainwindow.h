#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DisplayImage(QImage &img, QString title);
    
private slots:

    void on_bt_Browse_clicked();

    void on_bt_ClickMe_clicked();

    void on_bt_HisSlide_Gray_clicked();

    void on_bt_HisSlide_Color_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
