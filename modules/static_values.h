// DEBUG FLAG
#define INTERNAL_DEBUGGER

// definición de los pines
#define HIGH 1.0
#define LOW 0.0
#define is_nan(x) (x == -1 || x == 0)
#define is_inf(x) (x == 1.0 / 0.0)
typedef std::string String;
enum PinMode { INPUT = 0, OUTPUT = 1 };

enum PINOUTS_ARDUINO{
    A0,
    A1,
    A2,
    A3,
    A4,
    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13 //Pines digitales. D0 y D1 también se utilizan para la comunicación serial (RX y TX respectivamente).
    //PWM D3, D5, D6, D9, D10 y D11 en Arduino Uno).

};

enum DebugLevel{
    INFO,
    WARN,
    DEBUG
};

