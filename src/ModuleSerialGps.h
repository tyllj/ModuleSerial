#ifndef _ModuleSerialGps_H
#define _ModuleSerialGps_H

#include <ModuleSerialCore.h>

#define GPS_FAIL -1 
#define GPS_ENABLED 0

class ModuleSerialGps
{
public:
    struct GpsData
    {
        int mode;
        float lng, lat;
        float alt;
        char UTCTime[24];
        char TTFF[24];
        int sat;
        float speed;
        float course;
    };

    ModuleSerialGps(ModuleSerialCore *core);

    int enable();
    void disable();

    GpsData currentGpsData();
private:
    ModuleSerialCore *core = nullptr;

    void parseGpsData(GpsData *gpsData, char *data);
};

#endif 
