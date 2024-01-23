#include <iostream>
#include <thread>
using namespace std;

void visualizza(string msg){

      cout << "\n" <<msg;
 }

int main() {


    thread saluto1(visualizza,"buon ANNOO");
    thread saluto2(visualizza, "Alla stupendaa e magnifica 4AII e a sopratutto al migliore rappresentante");
    /*creare delle instanze della classe thread, una libreria già fatta cosi con definizioni
    esegue una funzione da definire, essendo una scala vuota  deve essere collegato
    a qualcosa, per es. collegato da una funzione "void" scritta nel programma, il thread la richiama
     la funzione del void
        -le variabili sul main sono quelle comuni ai thraed ovvero condivise
        -le variabili all'interno della funzione sono locali*/
    return 0;
}
