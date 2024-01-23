#include <iostream>

void leggi(){
    while(!feof(origine)){
        n=fread(record,1,DIM,origine);
        if(n>0)
            flag=true;
    }
    finito=true;
}

void scrivi(){
    while(!finito){
        while(flag==false);
        fwrite(record,1,n,destinatario);
            flag=true;
    }
    finito=true;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
