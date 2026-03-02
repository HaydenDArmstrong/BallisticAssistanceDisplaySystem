
// If you use Unit OLED, write this.
// #include <M5UnitOLED.h>

// If you use Unit LCD, write this.
// #include <M5UnitLCD.h>


// Include this to enable the M5 global instance.
#include <M5Unified.h>

#include <SD.h>

float airDensity(float pressure_hPA, float_tempF) {
    float P = pressure_hPa * 100; // hPa to Pascals
    float T = (temp_F + 459.67) x 5/9;
    return P / (287.058 * T); //return rho (rho equals pressure Pa / (temp K * gas constant R)). Rho is air density
}

String getFilename(float density) {
    float roundAmount = round(density / 0.05) * 0.05;

    String name = "/rho-";
    name += (int)roundAmount; //take the int part, ex 1, 2,
    name += (int)((bracket - (int)bracket)); //decimal portion ex .15
    name += ".csv"
    return name;
}

float lookupDistance(float dartMass, float angle) {
    float density = airDensity(pressure, temperature);

    String filename = getFilename(density);
    File f = SD.open(filename);
    if (!f) {
        Serial.print("Table Not Found");
        return -1
    }

    String header = f.readStringUntil(\n);
    float trueDistance = -1;
    float trueScore = 1e9;

    while (f.available()) {
        String line = f.readStringUntil('\n');
        float angle, c1, c2, c3, c4, c5, c6, c7, c8;
        float columns[] = {c1, c2, c3, c4, c5, c6, c7, c8};
        float weights[] = {2.5, 5.0, 6.0, 7.0, 7.5, 8.0, 9.0, 10.0};
        int bestCol = 0;
        for (int i = 1; i < 4; i++) {
            if (abs(masses[i] - dartMass) < abs(masses[bestCol] - dartMass))
                bestCol = i;
        }
        


    }
}