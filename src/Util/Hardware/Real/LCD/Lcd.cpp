#include "Lcd.h"

void Lcd::init(int pin) {
    lcd.init();
    lcd.backlight();
}

void Lcd::printLine(const char *message, int line) {
    cleared = false;
    if(line == 0) {
        lcd.setCursor(0, 0);
        lcd.print(message);
        p_1 = true;
        line1 = message;
    } else if(line == 1) {
        lcd.setCursor(0, 1);
        lcd.print(message);
        p_2 = true;
        line2 = message;
    }
}

void Lcd::clear() {
    if(!cleared) {
        lcd.clear();
        cleared = true;
        line1 = "";
        line2 = "";
        p_1 = false;
        p_2 = false;
    }
}

void Lcd::clearLine(int line) {
    if(line == 0 && p_1) {
        lcd.setCursor(0, 0);
        lcd.print("                ");
        line1 = "";
        p_1 = false;
    } else if(line == 1 && p_2) {
        lcd.setCursor(0, 1);
        lcd.print("                ");
        line2 = "";
        p_2 = false;
    }
}

String Lcd::getLine(int line) {
    if (line == 0) {
        return line1;
    }
    if (line == 1) {
        return line2;
    }
    return "";
}

void Lcd::printIn(int index[2][6], const char* messages[2][3], int elem1, int elem2) {
    int elements[2] = {elem1, elem2};

    for (int row = 0; row < 2; row++) {
        for (int i = 0; i < elements[row]; i++) {
            int start = index[row][i * 2];
            int end = index[row][i * 2 + 1];
            int width = end - start + 1;

            lcd.setCursor(start, row);

            int j = 0;
            while (j < width && messages[row][i][j] != '\0') {
                lcd.print(messages[row][i][j]);
                j++;
            }

            while (j < width) {
                lcd.print(' ');
                j++;
            }
        }
    }
}