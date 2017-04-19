#include "mbed.h"

Thread thread;
DigitalOut led1(LED1);
volatile bool running = true;

// Blink function toggles the led in a long running loop
void blink(DigitalOut *led) {
    while (running) {
        *led = !*led;
        wait(1);
    }
}

void log() {
    while (1) {
        printf("yes \n\r");
    }
}


// Spawns a thread to run blink for 5 seconds
int main() {
    // thread.start(callback(blink, &led1, 0));
    thread.start(callback(blink, &led1));
    // thread.start(log);
}