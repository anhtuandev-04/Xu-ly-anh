#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);  // Changed nullptr to 0
    ~MainWindow();

    // Helper functions
    QImage toGrayscale(const QImage &imgin);
    int Random(int n);
    QImage imNoise_Gray(QImage image_in, float level);
    QImage imNoise_Color(QImage image_in, float level);
    QImage applyMeanFilter(const QImage &imgin, int maskSize);
    QImage applyMedianFilter(const QImage &imgin, int maskSize);
    QImage applyConvolution(const QImage &imgin, const std::vector<std::vector<int> > &kernel);  // Added space: > >
    QImage applyConvolutionColor(const QImage &imgin, const std::vector<std::vector<int> > &kernel);  // Added space: > >
    QImage applyGaussianLaplace(const QImage &imgin);
    QImage applyGaussianLaplaceColor(const QImage &imgin);
    QImage applyGradient(const QImage &imgin);
    QImage applyGradientColor(const QImage &imgin);
    QImage applyRobert(const QImage &imgin);
    QImage applyRobertColor(const QImage &imgin);
    QImage applySobel(const QImage &imgin);
    QImage applySobelColor(const QImage &imgin);
    QImage applyPrewitt(const QImage &imgin);
    QImage applyPrewittColor(const QImage &imgin);
    QImage applyLaplace(const QImage &imgin);
    QImage applyLaplaceColor(const QImage &imgin);
    QImage applyErosion(const QImage &imgin, int maskSize);
    QImage applyDilation(const QImage &imgin, int maskSize);
    QImage applyOpening(const QImage &imgin, int maskSize);
    QImage applyClosing(const QImage &imgin, int maskSize);

    // Existing histogram functions
    void Histogram_GrayImage(const QImage &img, const int &his_height);
    void Histogram_ColorImage(const QImage &img, const int &his_height);

private slots:
    void on_btn_amban_xam_clicked();
    void on_bt_Chon_clicked();
    void on_btn_amban_mau_clicked();
    void on_btn_phannguong_clicked();
    void on_btn_histogram_xam_clicked();
    void on_btn_histogram_mau_clicked();
    void on_btn_dotuongphan_xam_clicked();
    void on_btn_dotuongphan_mau_clicked();
    void on_btn_biendoituyentinh_histogram_clicked();
    void on_btn_canbang_histogram_clicked();
    void on_btn_loctrungbinh_clicked();
    void on_btn_loctrungvi_clicked();
    void on_bt_gauss_laplace_clicked();
    void on_btn_nhieumuoitieu_clicked();
    void on_btn_nhieuanhmau_clicked();
    void on_btn_G_L_anhmau_clicked();
    void on_btn_locGradient_clicked();
    void on_btn_locRobert_clicked();
    void on_btn_locSobel_clicked();
    void on_btn_locPrewitt_clicked();
    void on_btn_locLaplace_clicked();
    void on_btn_Gra_anhmau_clicked();
    void on_btn_locRobert_anhmau_clicked();
    void on_btn_locSobel_anhmau_clicked();
    void on_btn_locPrewitt_anhmau_clicked();
    void on_btn_locLaplace_anhmau_clicked();
    void on_btn_AnMon_clicked();
    void on_btn_GianNo_clicked();
    void on_btn_Open_clicked();
    void on_btn_Close_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
