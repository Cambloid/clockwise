#include "UI/SettingsWindow/SettingsWindow.h"
#include "ui_SettingsWindow.h"

/*!

*/
SettingsWindow::SettingsWindow(SettingsData data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    this->setFieldsFromData(data);
}

/*!

*/
SettingsWindow::~SettingsWindow()
{
    delete ui;
}

/*!

*/
void SettingsWindow::setFieldsFromData(SettingsData data)
{
    ui->txtThreshold->setText(QString::number(data.getThreshold()));
    ui->txtNumFeatures->setText(QString::number(data.getNumFeatures()));

    ui->rdbCornerHarris->setChecked(data.getDetectorType() == DetectorType::CornerHarris);
    ui->rdbShiTomasi->setChecked(data.getDetectorType() == DetectorType::ShiTomasi);
    ui->rdbSIFT->setChecked(data.getDetectorType() == DetectorType::SIFT);

}

/*!

*/
SettingsData SettingsWindow::getDataFromFields()
{
    SettingsData data;

    if(ui->rdbCornerHarris->isChecked()) {
        data.setDetectorType(DetectorType::CornerHarris);
    } else if(ui->rdbShiTomasi->isChecked()) {
        data.setDetectorType(DetectorType::ShiTomasi);
    } else if (ui->rdbSIFT->isChecked()) {
        data.setDetectorType(DetectorType::SIFT);
    }

    data.setThreshold(ui->txtThreshold->text().toInt());
    data.setNumFeatures(ui->txtNumFeatures->text().toInt());

    return data;
}
