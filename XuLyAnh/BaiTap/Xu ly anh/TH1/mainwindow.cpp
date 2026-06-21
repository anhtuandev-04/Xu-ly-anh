#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QPixmap"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_ClickMe_clicked()
{
   QMessageBox::information(this, "Thông báo!", "Bạn ổn hok dạ");
}

void MainWindow::on_bt_Browse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "C:/CVIPtools/images", "*.* All Files;;*.bmp;;*.ppm;;*.png;;*.jpg");
    if(filename.isEmpty())
        return;
    ui -> ln_filename -> setText(filename);

    QPixmap pixmap(filename);
    QLabel *label = new QLabel();
    label -> setPixmap(pixmap);
    label -> setWindowTitle(QFileInfo(filename).fileName());
    label -> show();
}
void MainWindow::DisplayImage(QImage &img, QString title){
    QLabel *label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(img));
    label -> setWindowTitle(title);
    label -> show();
}

void MainWindow::on_bt_HisSlide_Gray_clicked()
{
    QString filename = ui -> ln_filename -> text();
    QImage image_in(filename);
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    int c = ui -> ln_c -> text().toInt();
    for(int x = 0; x < image_in.width(); x++)
        for(int y = 0; y < image_in.height(); y++){
            QRgb color = image_in.pixel(x, y);
            int gray_in = qGray(color);
            int gray_out = gray_in + c;
            if(gray_out > 255)
                gray_out = 255;
            else if(gray_out < 0)
                gray_out = 0;
            QRgb color_out = qRgb(gray_out, gray_out, gray_out);
            image_out.setPixel(x, y, color_out);
        }
    DisplayImage(image_in, QFileInfo(filename).fileName());
    DisplayImage(image_out, QFileInfo(filename).fileName() + "_His_Silde");
}


void MainWindow::on_bt_HisSlide_Color_clicked()
{
    QString filename = ui -> ln_filename -> text();
    QImage image_in(filename);
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    int c = ui -> ln_c -> text().toInt();
    for(int x = 0; x < image_in.width(); x++)
        for(int y = 0; y < image_in.height(); y++){
            QRgb rgb = image_in.pixel(x, y);
            QColor color_in(rgb);
            int h, s, v;
            color_in.getHsv(&h, &s, &v);
            int v_out = v + c;
            if(v_out > 255)
                v_out = 255;
            else if(v_out < 0)
                v_out = 0;
            QColor color_out = QColor::fromHsv(h, s, v_out);
            image_out.setPixel(x, y, color_out.rgb());
        }
    DisplayImage(image_in, QFileInfo(filename).fileName());
    DisplayImage(image_out, QFileInfo(filename).fileName() + "_His_Silde");
}
