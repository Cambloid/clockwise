#pragma once

#include <QDialog>

#include "Source/Core/DTO/SettingsBase.h"

namespace Ui {
    class SettingsWindow;
}

/*!

*/
class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(SettingsBase &data, QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;


private: // Private Methods
    void setFieldsFromData(SettingsBase &data);

public:
    SettingsBase getDataFromFields();

private slots:
    void onAccept();

};
