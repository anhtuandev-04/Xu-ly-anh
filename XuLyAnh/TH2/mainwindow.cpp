#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QPixmap"
#include "QLabel"
#include "QDebug"
#include "QFileInfo"
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime> // Added for srand and time

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(static_cast<unsigned>(time(nullptr)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Helper function to convert image to grayscale
QImage MainWindow::toGrayscale(const QImage &imgin)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            QRgb rgb = imgin.pixel(x, y);
            int gray = qGray(rgb);
            image_out.setPixel(x, y, qRgb(gray, gray, gray));
        }
    }
    return image_out;
}

// Random function for noise addition
int MainWindow::Random(int n)
{
    return rand() % n;
}

// Add salt-and-pepper noise to grayscale image
QImage MainWindow::imNoise_Gray(QImage image_in, float level)
{
    QImage image_out = image_in;
    int noisePoint = image_in.width() * image_in.height() * level;
    for (int i = 0; i < noisePoint; i++) {
        int x = Random(image_in.width());
        int y = Random(image_in.height());
        int a = Random(2);
        if (a == 0)
            image_out.setPixel(x, y, qRgb(0, 0, 0));
        else
            image_out.setPixel(x, y, qRgb(255, 255, 255));
    }
    return image_out;
}

// Add salt-and-pepper noise to color image
QImage MainWindow::imNoise_Color(QImage image_in, float level)
{
    QImage image_out = image_in;
    int noisePoint = image_in.width() * image_in.height() * level;
    for (int i = 0; i < noisePoint; i++) {
        int x = Random(image_in.width());
        int y = Random(image_in.height());
        int a = Random(2);
        if (a == 0)
            image_out.setPixel(x, y, qRgb(0, 0, 0));
        else
            image_out.setPixel(x, y, qRgb(255, 255, 255));
    }
    return image_out;
}

// Apply mean filter to grayscale image
QImage MainWindow::applyMeanFilter(const QImage &imgin, int maskSize)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int offset = maskSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int sum = 0;
            int count = 0;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        sum += qGray(imgin.pixel(nx, ny));
                        count++;
                    }
                }
            }
            int avg = sum / count;
            image_out.setPixel(x, y, qRgb(avg, avg, avg));
        }
    }
    return image_out;
}

// Apply median filter to grayscale image
QImage MainWindow::applyMedianFilter(const QImage &imgin, int maskSize)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int offset = maskSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            std::vector<int> values;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        values.push_back(qGray(imgin.pixel(nx, ny)));
                    }
                }
            }
            std::sort(values.begin(), values.end());
            int median = values[values.size() / 2];
            image_out.setPixel(x, y, qRgb(median, median, median));
        }
    }
    return image_out;
}

// Apply Gaussian + Laplace filter (grayscale)
QImage MainWindow::applyGaussianLaplace(const QImage &imgin)
{
    std::vector<std::vector<int> > laplaceKernel = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };
    return applyConvolution(imgin, laplaceKernel);
}

// Apply Gaussian + Laplace filter (color)
QImage MainWindow::applyGaussianLaplaceColor(const QImage &imgin)
{
    std::vector<std::vector<int> > laplaceKernel = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };
    return applyConvolutionColor(imgin, laplaceKernel);
}

// Apply Gradient filter (grayscale)
QImage MainWindow::applyGradient(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    QImage gradX = applyConvolution(imgin, kernelX);
    QImage gradY = applyConvolution(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int gx = qGray(gradX.pixel(x, y));
            int gy = qGray(gradY.pixel(x, y));
            int grad = std::min(255, static_cast<int>(std::sqrt(gx * gx + gy * gy)));
            image_out.setPixel(x, y, qRgb(grad, grad, grad));
        }
    }
    return image_out;
}

// Apply Gradient filter (color)
QImage MainWindow::applyGradientColor(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    QImage gradX = applyConvolutionColor(imgin, kernelX);
    QImage gradY = applyConvolutionColor(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            QRgb px = gradX.pixel(x, y);
            QRgb py = gradY.pixel(x, y);
            int gradR = std::min(255, static_cast<int>(std::sqrt(qRed(px) * qRed(px) + qRed(py) * qRed(py))));
            int gradG = std::min(255, static_cast<int>(std::sqrt(qGreen(px) * qGreen(px) + qGreen(py) * qGreen(py))));
            int gradB = std::min(255, static_cast<int>(std::sqrt(qBlue(px) * qBlue(px) + qBlue(py) * qBlue(py))));
            image_out.setPixel(x, y, qRgb(gradR, gradG, gradB));
        }
    }
    return image_out;
}

// Apply Robert filter (grayscale)
QImage MainWindow::applyRobert(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {1, 0},
        {0, -1}
    };
    std::vector<std::vector<int> > kernelY = {
        {0, 1},
        {-1, 0}
    };
    QImage gradX = applyConvolution(imgin, kernelX);
    QImage gradY = applyConvolution(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int gx = qGray(gradX.pixel(x, y));
            int gy = qGray(gradY.pixel(x, y));
            int grad = std::min(255, static_cast<int>(std::sqrt(gx * gx + gy * gy)));
            image_out.setPixel(x, y, qRgb(grad, grad, grad));
        }
    }
    return image_out;
}

// Apply Robert filter (color)
QImage MainWindow::applyRobertColor(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {1, 0},
        {0, -1}
    };
    std::vector<std::vector<int> > kernelY = {
        {0, 1},
        {-1, 0}
    };
    QImage gradX = applyConvolutionColor(imgin, kernelX);
    QImage gradY = applyConvolutionColor(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            QRgb px = gradX.pixel(x, y);
            QRgb py = gradY.pixel(x, y);
            int gradR = std::min(255, static_cast<int>(std::sqrt(qRed(px) * qRed(px) + qRed(py) * qRed(py))));
            int gradG = std::min(255, static_cast<int>(std::sqrt(qGreen(px) * qGreen(px) + qGreen(py) * qGreen(py))));
            int gradB = std::min(255, static_cast<int>(std::sqrt(qBlue(px) * qBlue(px) + qBlue(py) * qBlue(py))));
            image_out.setPixel(x, y, qRgb(gradR, gradG, gradB));
        }
    }
    return image_out;
}

// Apply Sobel filter (grayscale)
QImage MainWindow::applySobel(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    QImage gradX = applyConvolution(imgin, kernelX);
    QImage gradY = applyConvolution(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int gx = qGray(gradX.pixel(x, y));
            int gy = qGray(gradY.pixel(x, y));
            int grad = std::min(255, static_cast<int>(std::sqrt(gx * gx + gy * gy)));
            image_out.setPixel(x, y, qRgb(grad, grad, grad));
        }
    }
    return image_out;
}

// Apply Sobel filter (color)
QImage MainWindow::applySobelColor(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    QImage gradX = applyConvolutionColor(imgin, kernelX);
    QImage gradY = applyConvolutionColor(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            QRgb px = gradX.pixel(x, y);
            QRgb py = gradY.pixel(x, y);
            int gradR = std::min(255, static_cast<int>(std::sqrt(qRed(px) * qRed(px) + qRed(py) * qRed(py))));
            int gradG = std::min(255, static_cast<int>(std::sqrt(qGreen(px) * qGreen(px) + qGreen(py) * qGreen(py))));
            int gradB = std::min(255, static_cast<int>(std::sqrt(qBlue(px) * qBlue(px) + qBlue(py) * qBlue(py))));
            image_out.setPixel(x, y, qRgb(gradR, gradG, gradB));
        }
    }
    return image_out;
}

// Apply Prewitt filter (grayscale)
QImage MainWindow::applyPrewitt(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -1, -1},
        {0, 0, 0},
        {1, 1, 1}
    };
    QImage gradX = applyConvolution(imgin, kernelX);
    QImage gradY = applyConvolution(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int gx = qGray(gradX.pixel(x, y));
            int gy = qGray(gradY.pixel(x, y));
            int grad = std::min(255, static_cast<int>(std::sqrt(gx * gx + gy * gy)));
            image_out.setPixel(x, y, qRgb(grad, grad, grad));
        }
    }
    return image_out;
}

// Apply Prewitt filter (color)
QImage MainWindow::applyPrewittColor(const QImage &imgin)
{
    std::vector<std::vector<int> > kernelX = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };
    std::vector<std::vector<int> > kernelY = {
        {-1, -1, -1},
        {0, 0, 0},
        {1, 1, 1}
    };
    QImage gradX = applyConvolutionColor(imgin, kernelX);
    QImage gradY = applyConvolutionColor(imgin, kernelY);
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            QRgb px = gradX.pixel(x, y);
            QRgb py = gradY.pixel(x, y);
            int gradR = std::min(255, static_cast<int>(std::sqrt(qRed(px) * qRed(px) + qRed(py) * qRed(py))));
            int gradG = std::min(255, static_cast<int>(std::sqrt(qGreen(px) * qGreen(px) + qGreen(py) * qGreen(py))));
            int gradB = std::min(255, static_cast<int>(std::sqrt(qBlue(px) * qBlue(px) + qBlue(py) * qBlue(py))));
            image_out.setPixel(x, y, qRgb(gradR, gradG, gradB));
        }
    }
    return image_out;
}

// Apply Laplace filter (grayscale)
QImage MainWindow::applyLaplace(const QImage &imgin)
{
    std::vector<std::vector<int> > kernel = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };
    return applyConvolution(imgin, kernel);
}

// Apply Laplace filter (color)
QImage MainWindow::applyLaplaceColor(const QImage &imgin)
{
    std::vector<std::vector<int> > kernel = {
        {0, 1, 0},
        {1, -4, 1},
        {0, 1, 0}
    };
    return applyConvolutionColor(imgin, kernel);
}

// Apply Erosion (grayscale)
QImage MainWindow::applyErosion(const QImage &imgin, int maskSize)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int offset = maskSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int minVal = 255;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        int val = qGray(imgin.pixel(nx, ny));
                        if (val < minVal) minVal = val;
                    }
                }
            }
            image_out.setPixel(x, y, qRgb(minVal, minVal, minVal));
        }
    }
    return image_out;
}

// Apply Dilation (grayscale)
QImage MainWindow::applyDilation(const QImage &imgin, int maskSize)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int offset = maskSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int maxVal = 0;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        int val = qGray(imgin.pixel(nx, ny));
                        if (val > maxVal) maxVal = val;
                    }
                }
            }
            image_out.setPixel(x, y, qRgb(maxVal, maxVal, maxVal));
        }
    }
    return image_out;
}

// Apply Opening (Erosion followed by Dilation)
QImage MainWindow::applyOpening(const QImage &imgin, int maskSize)
{
    QImage temp = applyErosion(imgin, maskSize);
    return applyDilation(temp, maskSize);
}

// Apply Closing (Dilation followed by Erosion)
QImage MainWindow::applyClosing(const QImage &imgin, int maskSize)
{
    QImage temp = applyDilation(imgin, maskSize);
    return applyErosion(temp, maskSize);
}

void MainWindow::on_btn_amban_xam_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(), image_in.height(),QImage::Format_ARGB32);
    for (int i = 0; i < image_in.width(); i++)
        {
            for (int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);
                QRgb color_in = qRgb(gray, gray, gray);
                int out = 255 - gray;
                if (out > 255) out = 255;
                else if (out < 0) out = 0;
                QRgb color_out = qRgb(out, out, out);
                image_out.setPixel(i, j, color_out);
            }
        }
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out));
        label_out->show();
}


void MainWindow::on_bt_Chon_clicked()
{
   // QString filename = QFileDialog::getOpenFileName(this, "Open File","C:/CVIPtools/images","*. * ALL Files;*.bmp;*.jpeg;*.ppm;*.png;*.jpg");
     QString filename = QFileDialog::getOpenFileName(this, "Open File","C:/Users/DELL/OneDrive/Pictures/Screenshots/LF1.jpg");
        if (filename.isEmpty())
            return;

        ui->ln_filename->setText(filename);

        QPixmap pixmap(filename);
        QLabel *label = new QLabel();
        label->setPixmap(pixmap);
        label->setWindowTitle(QFileInfo(filename).fileName());
        label->show();
}

void MainWindow::on_btn_amban_mau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(), image_in.height(),QImage::Format_ARGB32);
        for (int i = 0; i < image_in.width(); i++)
        {
            for (int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                QColor color(rgb);
                int red = color.red();
                int green = color.green();
                int blue = color.blue();
                int n_red = 255 - red;
                int n_green = 255 - green;
                int n_blue = 255 - blue;
                QRgb color_out = qRgb(n_red, n_green, n_blue);
                image_out.setPixel(i, j, color_out);
            }
        }
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out));
        label_out->show();
}

void MainWindow::on_btn_phannguong_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

    int c = ui->ln_phannguong->text().toInt();
    for (int i = 0; i < image_in.width(); i++)
    {
        for (int j = 0; j < image_in.height(); j++)
        {
            QRgb rgb = image_in.pixel(i, j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i, j, color_in);
            int out = gray;
            if (out > c) out = 255;
            else if (out < c) out = 0;
            QRgb color_out = qRgb(out, out, out);
            image_out.setPixel(i, j, color_out);
        }
    }

    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel* label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

// Hàm Histogram_GrayImage
void MainWindow::Histogram_GrayImage(const QImage &img, const int &his_height)
{
    int h[256];
        for (int i = 0; i < 256; i++)
        {
            h[i] = 0;
        }

        QImage image_in(img);
        for (int x = 0; x < img.width(); x++)
        {
            for (int y = 0; y < img.height(); y++)
            {
                QRgb color = image_in.pixel(x, y);
                int gray = qGray(color);
                QRgb color_in = qRgb(gray, gray, gray);
                image_in.setPixel(x, y, color_in);
                h[gray]++;
            }
        }

        int max = 0;
        for (int i = 0; i < 256; i++)
        {
            if (h[i] > max)
                max = h[i];
        }

        QImage img_his = QImage(256, his_height, QImage::Format_RGB888);
        img_his.fill(Qt::white);

        int lineHeight;
        for (int i = 0; i < 256; i++)
        {
            lineHeight = his_height * h[i] / max;
            for (int j = his_height; j >= his_height - lineHeight; j--)
            {
                img_his.setPixel(i, j, qRgb(0, 0, 0));
            }
        }

        //QImage image_out(img.width(), img.height(), QImage::Format_RGB888);
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(img_his));
        label_out->show();
}

void MainWindow::on_btn_histogram_xam_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_GrayImage(img, 200); // Chiều cao histogram là 200
}

void MainWindow::Histogram_ColorImage(const QImage &img, const int &his_height)
{
    int hr[256];
    int hg[256];
    int hb[256];
    for (int i = 0; i < 256; i++)
    {
        hr[i] = 0;
        hg[i] = 0;
        hb[i] = 0;
    }

    QImage image_in(img);
    for (int x = 0; x < img.width(); x++)
    {
        for (int y = 0; y < img.height(); y++)
        {
            QRgb color = img.pixel(x, y);
            int green = qGreen(color);
            int red = qRed(color);
            int blue = qBlue(color);
            hr[red]++;
            hg[green]++;
            hb[blue]++;
        }
    }

    int maxr = 0, maxg = 0, maxb = 0;
    for (int i = 0; i < 256; i++)
    {
        if (hr[i] > maxr) maxr = hr[i];
        if (hg[i] > maxg) maxg = hg[i];
        if (hb[i] > maxb) maxb = hb[i];
    }

    QImage img_histr = QImage(256, his_height, QImage::Format_RGB32);
    img_histr.fill(Qt::white);

    for (int i = 0; i < 256; i++)
    {
        int lineHeight = (maxr > 0) ? (hr[i] * his_height / maxr) : 0;
        for (int j = his_height; j > his_height - lineHeight; j--)
        {
            img_histr.setPixel(i, j, qRgb(255, 0, 0));
        }
    }

    QImage img_histg = QImage(256, his_height, QImage::Format_RGB32);
    img_histg.fill(Qt::white);

    for (int i = 0; i < 256; i++)
    {
        int lineHeight = (maxg > 0) ? (hg[i] * his_height / maxg) : 0;
        for (int j = his_height; j > his_height - lineHeight; j--)
        {
            img_histg.setPixel(i, j, qRgb(0, 255, 0));
        }
    }

    QImage img_histb = QImage(256, his_height, QImage::Format_RGB32);
    img_histb.fill(Qt::white);

    for (int i = 0; i < 256; i++)
    {
        int lineHeight = (maxb > 0) ? (hb[i] * his_height / maxb) : 0;
        for (int j = his_height; j > his_height - lineHeight; j--)
        {
            img_histb.setPixel(i, j, qRgb(0, 0, 255));
        }
    }

    QLabel* label_red = new QLabel();
    label_red->setPixmap(QPixmap::fromImage(img_histr));
    label_red->show();

    QLabel* label_green = new QLabel();
    label_green->setPixmap(QPixmap::fromImage(img_histg));
    label_green->show();

    QLabel* label_blue = new QLabel();
    label_blue->setPixmap(QPixmap::fromImage(img_histb));
    label_blue->show();
}

void MainWindow::on_btn_histogram_mau_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_ColorImage(img, 200); // Chiều cao histogram là 200
}

void MainWindow::on_btn_dotuongphan_xam_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

        float c = ui->ln_dotuongphan->text().toFloat();

        for(int i = 0; i < image_in.width(); i++)
        {
            for(int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);
                QRgb color_in = qRgb(gray, gray, gray);
                image_in.setPixel(i, j, color_in);

                int out = gray * c;
                if(out > 255) out = 255;
                else if(out < 0) out = 0;

                QRgb color_out = qRgb(out, out, out);
                image_out.setPixel(i, j, color_out);
            }
        }

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}

void MainWindow::on_btn_dotuongphan_mau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

        float c = ui->ln_dotuongphan->text().toFloat();

        for(int i = 0; i < image_in.width(); i++)
        {
            for(int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);

                // Lấy giá trị từng kênh màu
                int red = qRed(rgb);
                int green = qGreen(rgb);
                int blue = qBlue(rgb);

                // Nhân hệ số tương phản c
                int r_out = red * c;
                int g_out = green * c;
                int b_out = blue * c;

                // Giới hạn giá trị từ 0 đến 255
                r_out = qBound(0, r_out, 255);
                g_out = qBound(0, g_out, 255);
                b_out = qBound(0, b_out, 255);

                // Tạo pixel mới sau xử lý
                QRgb color_out = qRgb(r_out, g_out, b_out);
                image_out.setPixel(i, j, color_out);
            }
        }

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}

void MainWindow::on_btn_biendoituyentinh_histogram_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

        int min_gray = 255;
        int max_gray = 0;

        // Tìm min và max gray
        for (int i = 0; i < image_in.width(); i++)
        {
            for (int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);

                if (gray < min_gray) min_gray = gray;
                if (gray > max_gray) max_gray = gray;
            }
        }

        // Áp dụng biến đổi tuyến tính
        for (int i = 0; i < image_in.width(); i++)
        {
            for (int j = 0; j < image_in.height(); j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);

                int out = (gray - min_gray) * 255 / (max_gray - min_gray);
                out = qBound(0, out, 255); // đảm bảo hợp lệ

                QRgb color_out = qRgb(out, out, out);
                image_out.setPixel(i, j, color_out);
            }
        }

        // Hiển thị ảnh gốc và ảnh đã xử lý
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}

void MainWindow::on_btn_canbang_histogram_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

        int histogram[256] = {0};
        int width = image_in.width();
        int height = image_in.height();

        // 1. Tính histogram
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);
                histogram[gray]++;
            }
        }

        // 2. Tính hàm phân phối tích lũy (CDF)
        int cdf[256] = {0};
        cdf[0] = histogram[0];
        for (int i = 1; i < 256; i++)
        {
            cdf[i] = cdf[i - 1] + histogram[i];
        }

        // 3. Tính giá trị xám mới cho mỗi mức
        int totalPixels = width * height;
        int lut[256]; // Look-Up Table
        for (int i = 0; i < 256; i++)
        {
            lut[i] = qBound(0, (cdf[i] * 255) / totalPixels, 255);
        }

        // 4. Tạo ảnh mới từ LUT
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                int gray = qGray(image_in.pixel(i, j));
                int new_gray = lut[gray];
                QRgb color_out = qRgb(new_gray, new_gray, new_gray);
                image_out.setPixel(i, j, color_out);
            }
        }

        // 5. Hiển thị ảnh
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//==================================================================================== 22/04/2025

void MainWindow::on_btn_loctrungbinh_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        int maskSize = ui->ln_SizeMask->text().toInt();
        if (maskSize % 2 == 0) maskSize++; // Ensure odd mask size
        QImage image_out = applyMeanFilter(image_gray, maskSize);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_loctrungvi_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        int maskSize = ui->ln_SizeMask->text().toInt();
        if (maskSize % 2 == 0) maskSize++;
        QImage image_out = applyMedianFilter(image_gray, maskSize);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_bt_gauss_laplace_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applyGaussianLaplace(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_nhieumuoitieu_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        float percentage = (ui->ln_tylenhieu->text().toFloat()) / 100.0;
        QImage image_out = imNoise_Gray(image_gray, percentage);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();

        QString fname = QFileDialog::getSaveFileName();
        image_out.save(fname);
}
//====================================================================================

void MainWindow::on_btn_nhieuanhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        float percentage = (ui->ln_tylenhieu->text().toFloat()) / 100.0;
        QImage image_out = imNoise_Color(image_in, percentage);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();

        QString fname = QFileDialog::getSaveFileName();
        image_out.save(fname);
}
//====================================================================================

void MainWindow::on_btn_G_L_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applyGaussianLaplaceColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locGradient_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applyGradient(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locRobert_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applyRobert(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locSobel_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applySobel(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locPrewitt_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applyPrewitt(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locLaplace_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        QImage image_out = applyLaplace(image_gray);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_Gra_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applyGradientColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locRobert_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applyRobertColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locSobel_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applySobelColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locPrewitt_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applyPrewittColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_locLaplace_anhmau_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_out = applyLaplaceColor(image_in);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================
void MainWindow::on_btn_AnMon_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        int maskSize = ui->ln_SizeMask->text().toInt();
        if (maskSize % 2 == 0) maskSize++;
        QImage image_out = applyErosion(image_gray, maskSize);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================

void MainWindow::on_btn_GianNo_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        int maskSize = ui->ln_SizeMask->text().toInt();
        if (maskSize % 2 == 0) maskSize++;
        QImage image_out = applyDilation(image_gray, maskSize);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================
// Apply convolution for grayscale image
QImage MainWindow::applyConvolution(const QImage &imgin, const std::vector<std::vector<int> > &kernel)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int kSize = kernel.size();
    int offset = kSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int sum = 0;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        sum += qGray(imgin.pixel(nx, ny)) * kernel[i + offset][j + offset];
                    }
                }
            }
            sum = std::max(0, std::min(255, sum));
            image_out.setPixel(x, y, qRgb(sum, sum, sum));
        }
    }
    return image_out;
}

// Apply convolution for color image
QImage MainWindow::applyConvolutionColor(const QImage &imgin, const std::vector<std::vector<int> > &kernel)
{
    QImage image_out(imgin.width(), imgin.height(), QImage::Format_RGB32);
    int kSize = kernel.size();
    int offset = kSize / 2;
    for (int x = 0; x < imgin.width(); x++) {
        for (int y = 0; y < imgin.height(); y++) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int i = -offset; i <= offset; i++) {
                for (int j = -offset; j <= offset; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imgin.width() && ny >= 0 && ny < imgin.height()) {
                        QRgb pixel = imgin.pixel(nx, ny);
                        sumR += qRed(pixel) * kernel[i + offset][j + offset];
                        sumG += qGreen(pixel) * kernel[i + offset][j + offset];
                        sumB += qBlue(pixel) * kernel[i + offset][j + offset];
                    }
                }
            }
            sumR = std::max(0, std::min(255, sumR));
            sumG = std::max(0, std::min(255, sumG));
            sumB = std::max(0, std::min(255, sumB));
            image_out.setPixel(x, y, qRgb(sumR, sumG, sumB));
        }
    }
    return image_out;
}
//====================================================================================
void MainWindow::on_btn_Open_clicked()
{
    QImage image_in(ui->ln_filename->text());
        QImage image_gray = toGrayscale(image_in);
        int maskSize = ui->ln_SizeMask->text().toInt();
        if (maskSize % 2 == 0) maskSize++;
        QImage image_out = applyOpening(image_gray, maskSize);

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}
//====================================================================================
void MainWindow::on_btn_Close_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_gray = toGrayscale(image_in);
    int maskSize = ui->ln_SizeMask->text().toInt();
    if (maskSize % 2 == 0) maskSize++;
    QImage image_out = applyClosing(image_gray, maskSize);

    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_gray.scaled(640, 480)));
    label_in->show();

    QLabel* label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
    label_out->show();
}
