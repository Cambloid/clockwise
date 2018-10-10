#include "UI/SettingsWindow/SettingsWindow.h"
#include "ui_SettingsWindow.h"

/*!

*/
SettingsWindow::SettingsWindow(SettingsBase &data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAccept()));

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
void SettingsWindow::setFieldsFromData(SettingsBase &data)
{

    if(data.detectorType == DetectorType::CornerHarris) {
        ui->rdbCornerHarris->setChecked(true);

    } else if(data.detectorType == DetectorType::ShiTomasi) {
        ui->rdbShiTomasi->setChecked(true);

    } else if (data.detectorType == DetectorType::ORB) {
        ui->rdbORB->setChecked(true);

    } else if (data.detectorType == DetectorType::SIFT) {
        ui->rdbSIFT->setChecked(true);
    }

    ui->txtThreshold->setText(QString::number(data.cornerHarris.threshold));
    ui->txtNumFeatures->setText(QString::number(data.shiTomasi.numFeatures));
    ui->txtNumFeaturesORB->setText(QString::number(data.orb.numFeatures));
}

/*!

*/
SettingsBase SettingsWindow::getDataFromFields()
{
    SettingsBase settingsBase;

    if(ui->rdbCornerHarris->isChecked()) {
        settingsBase.detectorType = DetectorType::CornerHarris;

    } else if(ui->rdbShiTomasi->isChecked()) {
        settingsBase.detectorType = DetectorType::ShiTomasi;

    } else if (ui->rdbORB->isChecked()) {
        settingsBase.detectorType = DetectorType::ORB;

    }else if (ui->rdbSIFT->isChecked()) {
        settingsBase.detectorType = DetectorType::SIFT;
    }

    settingsBase.cornerHarris.threshold = ui->txtThreshold->text().toInt();
    settingsBase.shiTomasi.numFeatures  = ui->txtNumFeatures->text().toInt();
    settingsBase.orb.numFeatures = ui->txtNumFeaturesORB->text().toInt();

    return settingsBase;
}

void SettingsWindow::onAccept()
{
    this->getDataFromFields();
    this->accept();
}
