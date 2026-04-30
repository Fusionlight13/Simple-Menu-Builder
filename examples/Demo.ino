#include <LiquidCrystal_I2C.h>
#include "utilities/ArrayWrapper.h"
#include "../src/MenuHelper.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

ArrayWrapper<MenuItem, 5> menuItems;
MenuHelper<5> menu(lcd, menuItems);

void startAction()
{
    Serial.println("Start selected");
}

void settingsAction()
{
    Serial.println("Settings selected");
}

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    menu.addItem("Start", startAction);
    menu.addItem("Settings", settingsAction);

    menu.printCurrent();
}

void loop()
{
    //example
    //menu.next();
    //menu.printCurrent();

    //button press
    //menu.select();
}