#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


int* PerAleat(int* arreglo, int n){
    int r=0, pivot=0, nrand=0, cota=0;
    srand(time(NULL)); //semilla
    for(int i=0; i<n; i++){
        cota = n-r+1;
        nrand=rand() % cota; // se genera un numero pseudoaleatorio el el rango de (n-r)
        //cout<<"rand "<<nrand<<endl;
        pivot=arreglo[n-r-1]; //se copia el valor del ultimo elemento del arreglo
        //cout<<"Pivot->"<<pivot<<endl;
        arreglo[n-r-1]=arreglo[nrand];// se sustituye el ultimo elemento del arreglo por 
                                      // por el elemento escogido pseudoaleatoriamente
        arreglo[nrand]=pivot; //en la posicion pseudoaleatoria se pone el ultimo el elemento copiado
        r+=1;
    }
    return arreglo;
}

int main(){
    int len=0;
    cout<<"Para gener las permutaciones aleatorias se utiliza el Algoritmo P (Shuffling) "<<endl;
    cout<<"Digite el tamaño de su arreglo: ";cin>>len;
    int arreglo[len];
    for(int i=0; i<len; i++){
        cout<<"Digite el el elemento "<<i<<" de su arreglo"<<endl;
        cin>>arreglo[i];
    }
    
    cout<<"El orden del arreglo original es: ";
    for(int j=0; j<len; j++){
        cout<<arreglo[j]<<",";
    }
    
    cout<<endl<<"una permutacion aleatoria es: ";
    PerAleat(arreglo,len);
    for(int j=0; j<len; j++){
        cout<<arreglo[j]<<",";
        
    }
   
    
    return 0;
}
