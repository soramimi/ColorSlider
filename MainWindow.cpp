#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->slider_rgb_r->setColorType(ColorSlider::RGB_R);
	ui->slider_rgb_g->setColorType(ColorSlider::RGB_G);
	ui->slider_rgb_b->setColorType(ColorSlider::RGB_B);
	ui->slider_hsv_h->setColorType(ColorSlider::HSV_H);
	ui->slider_hsv_s->setColorType(ColorSlider::HSV_S);
	ui->slider_hsv_v->setColorType(ColorSlider::HSV_V);
}

MainWindow::~MainWindow()
{
	delete ui;
}

QColor MainWindow::color() const
{
	return color_;
}

void MainWindow::setColor(QColor const &color)
{
	color_ = color;

	auto Set = [&](ColorSlider *slider, int value){
		bool b = slider->blockSignals(true);
		slider->setColor(color_);
		slider->setValue(value);
		slider->blockSignals(b);
	};
	Set(ui->slider_rgb_r, color_.red());
	Set(ui->slider_rgb_g, color_.green());
	Set(ui->slider_rgb_b, color_.blue());
	Set(ui->slider_hsv_h, color_.hue());
	Set(ui->slider_hsv_s, color_.saturation());
	Set(ui->slider_hsv_v, color_.value());

	ui->widget->setStyleSheet(QString::asprintf("background-color: #%02x%02x%02x;", color_.red(), color_.green(), color_.blue()));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
	setWindowTitle(QString::number(value));
}

void MainWindow::on_slider_rgb_r_valueChanged(int value)
{
	QColor c = color();
	c = QColor(value, c.green(), c.blue());
	setColor(c);
}

void MainWindow::on_slider_rgb_g_valueChanged(int value)
{
	QColor c = color();
	c = QColor(c.red(), value, c.blue());
	setColor(c);
}

void MainWindow::on_slider_rgb_b_valueChanged(int value)
{
	QColor c = color();
	c = QColor(c.red(), c.green(), value);
	setColor(c);
}

void MainWindow::on_slider_hsv_h_valueChanged(int value)
{
	QColor c = color();
	c = QColor::fromHsv(value, c.saturation(), c.value());
	setColor(c);
}

void MainWindow::on_slider_hsv_s_valueChanged(int value)
{
	QColor c = color();
	c = QColor::fromHsv(c.hue(), value, c.value());
	setColor(c);
}

void MainWindow::on_slider_hsv_v_valueChanged(int value)
{
	QColor c = color();
	c = QColor::fromHsv(c.hue(), c.saturation(), value);
	setColor(c);
}

