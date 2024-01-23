#include <iostream>


class Time {

private:
    int ore;
    int minuti;
    int secondi;

public:
    Time () : ore(0), minuti(0), secondi(0){
    }


    void Set(int o, int m, int s ) {
        ore= o;
        minuti= m;
        ore=s;
    }

    void Reset()   {
        ore=0;
        minuti=0;
        ore=0;
    }

     void Stampa()const {
        std::cout << "Orario formato europero:" << ore<< ":" << minuti <<":" << secondi <<std::endl;
    }

    Time operator+(const Time & time2 ) const {
        Time t3;
        t3.secondi = secondi + time2.secondi;
        t3.minuti = minuti + time2.minuti + t3.secondi / 60;
        t3.ore = ore + time2.ore + t3.minuti / 60;
        t3.secondi %= 60;
        t3.minuti %= 60;
        t3.ore %= 24;
        return t3;

        /*Time t3 (ore+time2.ore, minuti+time2.minuti, secondi+time2.secondi);
        return t3;
         */
    }
    Time operator-(const Time & time2 ) const{
        Time t3;
        int totalSeconds = (ore * 3600 + minuti * 60 + secondi) - (time2.ore * 3600 + time2.minuti * 60 + time2.secondi);
        if (totalSeconds < 0) totalSeconds += 24 * 3600;
        t3.ore = totalSeconds / 3600;
        t3.minuti = (totalSeconds % 3600) / 60;
        t3.secondi = totalSeconds % 60;
        return t3;
        //oppure
        // time t3(ore-time2.ore, minuti-time2.minuti, secondi+time2.secondi);
        //return t3;
    }
    bool operator >(const Time & time2 ) const {
        return (ore>time2.ore || (ore == time2.ore && (minuti> time2.minuti || (minuti==time2.minuti && secondi > time2.secondi))));
    }
    bool operator <(const Time & time2 ) const{
        return (ore<time2.ore || (ore == time2.ore && (minuti< time2.minuti || (minuti==time2.minuti && secondi < time2.secondi))));
    }
    bool operator== (const Time & time2 ) const{
        return (ore==time2.ore && minuti== time2.minuti  &&  secondi == time2.secondi);
    }

};

class EnglishTime : public Time {
private:
    int ore;
    int minuti;
    int secondi;

public:
    using Time::Time;

    void set( int o, int m, int s){
    if( o>=0 && o < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
        ore = o;
        minuti = m;
        secondi = s;
    }else{
        std::cerr << "Formato orario corretto." << std::endl;
    }
    }

    void Stampa() const{
    std::cout <<  ore % 12 &&  == 0  12 : ore % 12, ore >= 12 ? "pm" : "am", minuti, secondi << std::endl;
}

};

int main(){
Time t1(21, 32, 34 );
Time t2(23,34,2);

t1.Stampa();
t2.Stampa();
std::cout << "Hello, World!" << std::endl;
return 0;

}





















