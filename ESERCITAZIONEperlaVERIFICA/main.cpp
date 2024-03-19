#include <iostream>
#include <thread>
#include <fstream>
#include <mutex>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Robot{
    int NUmRobot;
    int X;
    int Y;
    int batteryLevel;
    float speed;
};

struct CondivisioneDati{
    mutex mtx;
    vector<Robot> buffer;
};

void RicezioneDati(CondivisioneDati& condivisioneDati){
    while(true){
        Robot newDati;
        newDati.NUmRobot= rand() 5% +1;
        newDati.X = rand() % 201 - 100;
        newDati.Y = rand() % 201 - 100;
        newDati.batteryLevel = rand() % 101;
        newDati.speed = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 10.0f;

        this_thread::sleep_for(chrono::seconds(1));

        lock_guard<mutex> guard(CondivisioneDati.mtx);
        CondivisioneDati.buffer.push_back(newDati);

    }
}
void LeggiScrivi( int NUMRobot, CondivisioneDati& condivisioneDati) {
    string filename = "Robot" + to_string(NUMRobot) + ".txt";
    ofstream outputFile(filename);
    while (true) {
        lock_guard<mutex> guard(CondivisioneDati.mtx);
        if (!CondivisioneDati.buffer.empty()) {
            Robot dati = CondivisioneDati.buffer.front();
            CondivisioneDati.buffer.erase(CondivisioneDati.buffer.begin());

            outputFile << dati.NUmRobot<<" "
                       << dati.X<<" "
                       << dati.Y<<" "
                       << dati.batteryLevel<< " "
                       << dati.speed<< endl;
            cout << dati.NUmRobot<<" "
                 << dati.X<<" "
                 << dati.Y<<" "
                 << dati.batteryLevel<< " "
                 << dati.speed<< endl;
        }
    }
}


int main() {
    srand(time(nullptr));

    CondivisioneDati condivisioneDati;

    thread receiverThread(RicezioneDati ref(CondivisioneDati));
    



    return 0;


}