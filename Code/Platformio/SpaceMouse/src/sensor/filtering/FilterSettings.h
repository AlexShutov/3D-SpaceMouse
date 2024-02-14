
#ifndef SETTINGS_H
#define SETTINGS_H
#include "AxisFilterSettings.h"

typedef struct FilterSettings
{
    FilterSettings(){}
    FilterSettings(
        AxisFilterSettings xSettings,
        AxisFilterSettings ySettings,
        AxisFilterSettings zSettings
    ) {
        this->xSettings = xSettings;
        this->ySettings = ySettings;
        this->zSettings = zSettings;
    }


    AxisFilterSettings xSettings;
    AxisFilterSettings ySettings;
    AxisFilterSettings zSettings;
};

#endif // FILTER_SETTINGS_H