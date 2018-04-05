//
//  punteros.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 3/04/18.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Album{
public:
    void CompraSobre(int n_en_sobre);
    void Status(void);
    bool EstaLleno();
    bool LaTengo(int Mona);
    bool LaCambio(int Mona);
    void Trueque(int dar, int recibir);
    Album(int n);
    int n_Comprados;
    
private:
    int n_total;
    int n_repetidas;
    int n_en_album;
    int *album;
    int *repetidas;
    int **Repetiditas;
};

void Album::Status(void){
    cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
    int lamina;
    for(int i=0;i<n_en_sobre;i++){
        lamina = rand()%n_total;
        if(album[lamina]==0){
            album[lamina] = 1;
            n_en_album++;
        }else{
            repetidas[lamina] +=1;
            n_repetidas++;
        }
    }
}
bool Album::EstaLleno(){
    if(n_en_album==670){
        return true;
    }
    else{
        return false;
        
    }
}
bool Album::LaTengo(int Mona){
    if(album[Mona]==1){
        return true;
    }
    else{
        return false;
    }
    
}
bool Album::LaCambio(int Mona){
    if(repetidas[Mona]!=1){
        return true;
    }
    else{
        return false;
    }
}
void Album::Trueque(int dar, int recibir){
    album[recibir]++;
    n_en_album++;
    repetidas[dar]--;
    n_repetidas--;
    }
Album::Album(int n){
    album = new int[n];
    repetidas = new int[n];
    n_total = n;
    n_repetidas = 0;
    n_en_album = 0 ;
    for (int i=0;i<n_total;i++){
        album[i] = 0;
        repetidas[i] = 0;
    }
}

void cambia(Album A, Album B){
    for(int i=0;i <= 670; i++){
        for(int n=0;n <= 670; n++){
    if(A.LaTengo(i)==false &&B.LaCambio(i)== true&& B.LaTengo(n)==false &&A.LaCambio(n)== true){
        A.Trueque(n,i);
        B.Trueque(i,n);
        
    }
    }
    }
    
}
int main(){
    srand(time(0));
    Album A(670);
    Album B(670);
    A.n_Comprados=0;
    B.n_Comprados=0;
    while(A.EstaLleno()==0){
        A.CompraSobre(5);
        B.CompraSobre(5);
        cambia(A,B);
        A.n_Comprados++;
        B.n_Comprados++;
    }
    cout<< A.n_Comprados <<endl;
    cout<< B.n_Comprados <<endl;
}
