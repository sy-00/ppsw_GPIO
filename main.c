// przyciski to bity 4, 5, 6 i 7 w oknie (GPIO 0)
#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define S0_bm 0x00000010 // Pin 4
#define S1_bm 0x00000040 // Pin 6
#define S2_bm 0x00000020 // Pin 5
#define S3_bm 0x00000080 // Pin 7


void KeyboardInit() {
    // laczymy wszystkie maski przycisków suma (|)
    // negujemy je (~), aby uzyskac zera na ich pozycjach TO MAJA BYC WEJSCIA TO DLATEGO
    // i nakladamy na rejestr koniunkcja (&)
    IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm));
}

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead() {
    if ((IO0PIN & S0_bm) == 0) {
        return BUTTON_0; // jesli S0 nacisniety, zwraca BUTTON_0 i konczy funkcje
    } else if ((IO0PIN & S1_bm) == 0) {
        return BUTTON_1;
    } else if ((IO0PIN & S2_bm) == 0) {
        return BUTTON_2;
    } else if ((IO0PIN & S3_bm) == 0) {
        return BUTTON_3;
    } else {
        return RELASED; // zaden nie nacisniety
    }
}


// dobry delay
void Delay(int iDelayInMS) {
    int iLoopCounter;
    int iIterations = iDelayInMS * 2500; 
    for(iLoopCounter = 0; iLoopCounter < iIterations; iLoopCounter++) {}
}

void LedInit() {
    // WERSJA POPRAWNA
    // Uzywamy IO1DIR |, zeby zachowac inne bity
    IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
    
    // Gasimy wszystkie diody na start
    IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
    
    // Zapalamy tylko LED0
    IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks) {
    // gasimy wszystko
    IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
    
    // zapalamy odpowiedznia diode na podstawie indeksu
    switch(ucLedIndeks) {
        case 0:
            IO1SET = LED0_bm;
            break;
        case 1:
            IO1SET = LED1_bm;
            break;
        case 2:
            IO1SET = LED2_bm;
            break;
        case 3:
            IO1SET = LED3_bm;
            break;
        default:
            // to jakby podano zly numer (np. 67) - zadna sie nie zapali
            break;
    }
}


enum eStepDirections {LEFT, RIGHT};

void LedStep(enum eStepDirections eDirection) {
    // slowo static sprawia, ze inicjalizacja (=0) wykonuje sie TYLKO RAZ przy pierwszym uruchomieniu programu
    static unsigned char sucLedNumber = 0; 
    
    switch(eDirection) {
        case LEFT:
            sucLedNumber++;
            break;
        case RIGHT:
            sucLedNumber--;
            break;
        default:
            break;
    }
    // uzywamy modulo 4, zeby zawsze trafic w indeks 0, 1, 2 lub 3
    LedOn(sucLedNumber % 4);
}

void LedStepLeft(void) {
    LedStep(LEFT);
}

void LedStepRight(void) {
    LedStep(RIGHT);
}


int main() {
    LedInit();
    KeyboardInit();

    while(1) {
        Delay(100); 

        switch(eKeyboardRead()) {
            case BUTTON_1:
                LedStepRight(); // uzywamy nowej funkcji zamiast LedStep(RIGHT)
                break;
            
            case BUTTON_2:
                LedStepLeft();  // uzywamy nowej funkcji zamiast LedStep(LEFT)
                break;
            
            default:
                break;
        }
    }
}
