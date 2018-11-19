#pragma once

#include <string>

/*!

*/
struct SettingsFeatureTracker {

    SettingsFeatureTracker() {

    }

    struct CSRTTracker {
        std::string exportPath;
        CSRTTracker() {
            this->exportPath = "";
        }
    } csrttracker;

};
