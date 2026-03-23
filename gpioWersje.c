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
// delay zajmuje 0.00666842 sec
// zmienimy w forze na 1499600 iteracji




//PUNKT 5 
#include <LPC21xx.H>

void Delay() {
    int iLoopCounter;
    // zmiana w forze
    for(iLoopCounter = 0; iLoopCounter < 1499600; iLoopCounter++) {

    }
}

int main() {

    IO1DIR = 0x00010000; 

    while(1) {

        IO1SET = 0x00010000; // tutaj breakpoint i zerujemy licznik
        
        Delay();
        
        IO1CLR = 0x00010000; // tutaj tez
        

    }
}

// 1499600 iteracji podzielic na 1000 -> okolo 1500 - nasz nowy mnoznik do podawania delay w ms






// PUNKT 6
#include <LPC21xx.H>

// dodajemy (int iDelayInMS) zeby widzialo co wpisujemy w main
void Delay(int iDelayInMS) {
    int iLoopCounter;
    
    // tworzymy zmienna pomocnicza która mnozy milisekundy przez przelicznik (2500 bo 1500 jednak cos nie styka)
    int iIterations = iDelayInMS * 2500; 
    
    // w petli uzywamy obliczonej liczby iteracji
    for(iLoopCounter = 0; iLoopCounter < iIterations; iLoopCounter++) {
        // pusto
    }
}

int main() {
    IO1DIR = 0x00010000; 

    while(1) {
        IO1SET = 0x00010000; // breakpoint
        
        Delay(1); // delay 1000 dla sekundy i 1 dla 1ms
        
        IO1CLR = 0x00010000; //breakpoint
    }
}








//PUNKT7
#include <LPC21xx.H>

// delay z mnoznikiem 2500
void Delay(int iDelayInMS) {
	
    int iLoopCounter;
    int iIterations = iDelayInMS * 2500; 
	
    for(iLoopCounter = 0; iLoopCounter < iIterations; iLoopCounter++) {}
}

int main() {
    // pin 16 jako wyjscie (maska dla LED0)
    IO1DIR = 0x00010000; 

    while(1) {
        // zapalamy diode (1)
        IO1SET = 0x00010000;
        Delay(1000); // czekamy sekundke
        
        // gasimy diode
        IO1CLR = 0x00010000;
        Delay(1000); // czekamy sekundke
    }
}
// obserwujemy pin 16 w symulatorze po kliknieciu f5 - zapala sie i znika co sekunde






//PUNKT 8
#include <LPC21xx.H>

// delay z mnoznikiem 2500
void Delay(int iDelayInMS) {
    int iLoopCounter;
    int iIterations = iDelayInMS * 2500; 
    for(iLoopCounter = 0; iLoopCounter < iIterations; iLoopCounter++) {}
}

int main() {
    IO1DIR = 0x00010000; // pin 16 na wyjscie

    while(1) {
        IO1SET = 0x00010000; // dioda ON
        Delay(50);           // czekaj 50 ms
        
        IO1CLR = 0x00010000; // dioda OFF
        Delay(50);           // czekaj 50 ms - razem 10Hz
    }
}





//PUNKT 9
#include <LPC21xx.H>

// definicja maski bitowej dla diody LED0 (pin 16)
#define LED0_bm 0x00010000

// stary dobry delay z 2500
void Delay(int iDelayInMS) {
    int iLoopCounter;
    int iIterations = iDelayInMS * 2500; 
    for(iLoopCounter = 0; iLoopCounter < iIterations; iLoopCounter++) {}
}

int main() {
    // ustawienie kierunku za pomoca maski
    IO1DIR = LED0_bm; 

    while(1) {
        // zapalenie diody za pomoca maski
        IO1SET = LED0_bm; 
        Delay(50); // 10 Hz (50ms ON + 50ms OFF = 100ms cykl)
        
        // zgaszenie diody za pomoca maski
        IO1CLR = LED0_bm; 
        Delay(50);
    }
}




//PUNKT 10
//led3 bedzie na pinie 19 skoro 0 byl na 16
