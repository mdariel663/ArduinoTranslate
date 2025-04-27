#include <chrono>
struct PinEvent {
    int pin;
    int state;
    int duration; // en ms
    std::chrono::steady_clock::time_point timestamp;

};
std::vector<PinEvent> pinEvents;
