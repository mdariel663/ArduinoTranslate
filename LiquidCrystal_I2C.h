#include <string>
#include <cstring>
#include <iostream>
struct LCD{
    int col;
    int row;
    char data;
    LCD *next = nullptr;
    LCD *head = nullptr;
};
class LiquidCrystal_I2C{
private:
    int colNum;
    int rowsNum;
    LCD *head = nullptr ;
    bool initialize = false;
    void print();
    void showBanner() const;

public:
    LiquidCrystal_I2C(int addr = 0, int cols = 0, int rows = 0);;
    void begin();
    void backlight();
    void clear();
    void setCursor(int x, int y);
    void print(char valor);
    void print(const char* valor);
    void print(int valor);
    void print(double valor);

};
