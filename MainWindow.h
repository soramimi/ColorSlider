#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	Ui::MainWindow *ui;
	QColor color_;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void setColor(const QColor &color);
	QColor color() const;
private slots:
	void on_horizontalSlider_valueChanged(int value);
	void on_slider_rgb_r_valueChanged(int value);
	void on_slider_rgb_g_valueChanged(int value);
	void on_slider_rgb_b_valueChanged(int value);
	void on_slider_hsv_h_valueChanged(int value);
	void on_slider_hsv_s_valueChanged(int value);
	void on_slider_hsv_v_valueChanged(int value);

};

#endif // MAINWINDOW_H
