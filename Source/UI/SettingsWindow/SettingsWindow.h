#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

#include "UI/SettingsWindow/SettingsData.h"

namespace Ui {
    class SettingsWindow;
}

/*!

*/
class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(SettingsData data, QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;


private: // Private Methods
    void setFieldsFromData(SettingsData data);
    SettingsData getDataFromFields();

};

#endif // SETTINGSWINDOW_H
