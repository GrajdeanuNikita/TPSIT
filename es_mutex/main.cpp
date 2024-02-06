#include <iostream>
#include <thread>
#include <mutex>                    // sezione critica-var. numero di posti
#include <condition_variable>
#include <atomic>

using namespace std;


atomic<int> num;
mutex m;

mutex critical;

void Incrementazione();

int main() {
    num=1;
    cout << "GESTIONE DELLA PROGRESSIONE NUMERICA!" << endl;

    thread primoN(Incrementazione);
    thread secondoN(Incrementazione);
    thread terzoN(Incrementazione);
    thread quartoN(Incrementazione);
    thread quintoN(Incrementazione);
    thread sestoN(Incrementazione);
    thread settimoN(Incrementazione);
    thread ottavoN(Incrementazione);
    thread nonoN(Incrementazione);
    thread decimoN(Incrementazione);

    primoN.join();
    secondoN.join();
    terzoN.join();
    quartoN.join();
    quintoN.join();
    sestoN.join();
    settimoN.join();
    ottavoN.join();
    nonoN.join();
    decimoN.join();

    return 0;
}

void Incrementazione(){

    while(true){

        critical.lock();
        cout << "\n" << this_thread::get_id <<num++;
        this_thread::sleep_for(chrono::seconds(num));
    }
}