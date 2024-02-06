#include <iostream>
#include <map>
#include <thread>

using namespace std;

void updateTemperatura(map<string, int > meteo){
    for(auto elemento: meteo){
        elemento.second++;
    }
}


int main() {

    map<string, int> meteo;
    meteo["VIcenza"]=15;
    meteo["VIcenza"]=3;
    thread worker (updateTemperatura, meteo);
    worker.join();

    while(1){
        for(auto elemento : meteo){
            cout << "Citta"<< elemento.first << "T:" <<elemento.second << endl;
        }
        this_thread::sleep_for(seconds(1));
    }


    return 0;
}
