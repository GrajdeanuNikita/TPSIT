#include <iostream>
#include <thread>
#include <mutex>                    // sezione critica-var. numero di posti
#include <condition_variable>
#include <atomic>

using namespace std;


atomic<int> numeroPosti;
mutex m; //mutex per gestire la condirional_variable

mutex critical; // per gestire il codice comune


condition_variable_any Parcheggio; //mettere in wait i thread
//è la funzione chiamata dai thread
void Parcheggia(string modello, int tempo_dentro, int tempo_fuori );
// ha un tempo di attesa, un tempo dentro il parchegio , cosi si mettono termini sfasati




int main() {
    numeroPosti=7;
    cout << "GESTIONE DEL NOSTRO PICCOLO PARCHEGGIO!" << endl;

    //5 auto -> thraed
    thread  mercedes(Parcheggia, "AMG GT", 3,7);
    thread  toyota(Parcheggia, "Chr", 4,6);
    thread  fiat(Parcheggia, " punto", 5,2);
    thread  renault(Parcheggia, "clio ", 6,5);
    thread  bmw(Parcheggia, "320", 8,4);

    mercedes.join();
    toyota.join();
    fiat.join();
    renault.join();
    bmw.join();

    return 0;
}   //end of main()

void Parcheggia (string modello, int tempo_dentro, int tempo_fuori){
    bool dentro= false;
    //memoria privata del thread?

    while(true){
        if(dentro){
            //attesa
            this_thread::sleep_for(chrono::seconds(tempo_dentro));
            critical.lock();
            numeroPosti++;
            cout <<"\n Uscita dell'auto, " <<modello<<"posti disponibili: "<<numeroPosti;
            dentro= false;
            critical.unlock();
        }
        else{ //l'auto è fuori
            if(numeroPosti<=0){

                cout <<"\n"<< modello<< "è in attesa, numero posti= "<< numeroPosti;
                Parcheggio.wait(m);

            }
            else
                Parcheggio.notify_all();
            // SE ARRIVIAMO      QUI ALLORA IL NUMERO DI POSTI è >0
            // IL thread puo entrare
            this_thread::sleep_for(chrono::seconds(tempo_fuori));

            critical.lock();
            numeroPosti--;
            cout <<"\n "<< modello << "è entata, numero posti: "<<numeroPosti;
            dentro=true;
            critical.unlock();

        }
    }
}