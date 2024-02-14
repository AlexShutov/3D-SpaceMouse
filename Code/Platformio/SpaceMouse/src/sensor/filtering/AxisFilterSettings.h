
#ifndef AXIS_FILTER_SETTINGS_H
#define AXIS_FILTER_SETTINGS_H

typedef struct AxisFilterSettings
{
    AxisFilterSettings(){}

    AxisFilterSettings(
        float mea_e,
        float est_e,
        float q
    ) {
        this->mea_e = mea_e;
        this->est_e = est_e;
        this->q = q;
    }

    float mea_e;
    float est_e;
    float q;
};

#endif // AXIS_FILTER_SETTINGS_H