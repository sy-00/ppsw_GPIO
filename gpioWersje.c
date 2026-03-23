//PUNKT 2
#include <LPC21xx.H>

int main() {
    // 1. Ustawi pin 16 i TYLKO 16 portu P1 jako wyjściowy
    IO1DIR = 0x00010000; 

    // 2. Ustawi pin 16 i TYLKO 16 portu P1 na „1”
    IO1SET = 0x00010000;

    // 3. Ustawi pin 16 i TYLKO 16 portu P1 na „0”
    IO1CLR = 0x00010000;

    // 4. Wejdzie w pętle nieskończoną
    while(1) {
        // Pusta pętla
    }
}




//PUNKT3
#include <LPC21xx.H>

int main() {
    // konfiguracja wyjscia
    IO1DIR = 0x00010000; 

    while(1) {
        // Ustawienie pinu 16 na "1"
        IO1SET = 0x00010000;
        
        // Kasowanie pinu 16 (ustawienie "0")
        IO1CLR = 0x00010000;
        
        // 1 0 1 0 1 0... w IO1SET
    }
}



//PUNKT 4 
#include <LPC21xx.H>

// difinicja funkcji delay
// void - nic nie zwraca
void Delay() {
    int iLoopCounter;
    // petla for wykonujaca 1000 pustych przebiegów
    for(iLoopCounter = 0; iLoopCounter < 1000; iLoopCounter++) {
        // pusto w srodku - tylko czekamy
    }
}

int main() {
    // pin 16 jako wyjscie
    IO1DIR = 0x00010000; 

    while(1) {
        // ustawienie pinu na 1
        IO1SET = 0x00010000;
        
        // wywolujemy opoznienie miedzy set a clr
        Delay();
        
        // ustawienie pinu na 0
        IO1CLR = 0x00010000;
        
        // dodajemy delay zeby zobaczyc 0 na pinie (extra)
        Delay();
    }
}
// delay zajmuje 0.00041767 sec


//PUNKT 5 
