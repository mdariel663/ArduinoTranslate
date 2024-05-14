#include "LiquidCrystal_I2C.h"
LCD *lcdCurrent = nullptr;

void LiquidCrystal_I2C::showBanner() const{
    std::string title = "LCD DISPLAY";
    int totalFill = colNum * rowsNum + 1;

    for (int i = 0; i < totalFill; i++){
        if ( i == totalFill/3 ){
            std::cout<<title;
            i += title.length();
        }
        std::cout<< "=";
    }
    std::cout << '\n';

}

LiquidCrystal_I2C::LiquidCrystal_I2C(int addr, int cols, int rows){
    if (addr == 0 || cols == 0 || rows == 0){
        std::cout << "LiquidCrystalI2C -> init() Fail";
    }
    colNum = cols;
    rowsNum = rows;
    clear();
}

void LiquidCrystal_I2C::begin(){
    clear();
}

void LiquidCrystal_I2C::backlight(){
    initialize = true;
}

void LiquidCrystal_I2C::clear(){
    if (lcdCurrent == nullptr)
        lcdCurrent = new LCD();
    for (int j = 0; j < rowsNum; j++) {
        for (int i = 0; i < colNum; i++) {
            LCD* newNode = new LCD();
            newNode->col = i;
            newNode->row = j;
            newNode->data = '0'; // Cambiar 'a' por el dato deseado
            if (!head) {
                head = newNode;
            }
            if (lcdCurrent) {
                lcdCurrent->next = newNode;
            }
            lcdCurrent = newNode;
        }
    }
}

void LiquidCrystal_I2C::setCursor(int x, int y){
    // Mover el cursor a la posición especificada
    int position = y * colNum + x;
    LCD* temp = head;
    for (int i = 0; i < position; i++) {
        if (temp)
            temp = temp->next;
        else
            break;
    }
    lcdCurrent = temp;
}

void LiquidCrystal_I2C::print() {
    std::cout << "\033[H\033[2J";//for clear display
    if (!initialize) {
        std::cout<<"LCD Light off";
        return;
    }
    LCD* puntero = head;
    showBanner();

    for (int j = 0; j < rowsNum; j++) {
        for (int i = 0; i < colNum; i++) {
            if (puntero) {
                std::cout << "|" << puntero->data;
                puntero = puntero->next;
            } else std::cout << "| ";
        }
        std::cout << "|\n";
    }
    for (int i = 0; i < (colNum * rowsNum); i++) std::cout<< "=";
    std::cout << '\n';
}

void LiquidCrystal_I2C::print(char valor) {
    if (!initialize) {
        std::cout<<"LCD Light off";
        return;
    }
    if (lcdCurrent) {
        lcdCurrent->data = valor;
        print();
    }

}

void LiquidCrystal_I2C::print(const char *valor) {
    if (!initialize) {
        std::cout<<"LCD Light off";
        return;
    }
    int len = strlen(valor);
    for (int i = 0; i < len; i++) {
        print(valor[i]);
        if (lcdCurrent->next) {
            lcdCurrent = lcdCurrent->next;
        } else {
            break; // Si llegamos al final de la lista, salimos del bucle
        }
    }
    print();
}

void LiquidCrystal_I2C::print(int valor) {
    if (!initialize) {
        std::cout<<"LCD Light off";
        return;
    }
    std::string str = std::to_string(valor);
    print(str.c_str()); // Llama a la versión de print que acepta una cadena de caracteres
    print();
}

void LiquidCrystal_I2C::print(double valor) {
    if (!initialize) {
        std::cout<<"LCD Light off";
        return;
    }
    std::string str = std::to_string(valor);
    print(str.c_str()); // Llama a la versión de print que acepta una cadena de caracteres
    print();
}
