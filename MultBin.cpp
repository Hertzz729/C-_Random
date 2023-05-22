#include <iostream>
#include <math.h>
using namespace std;

int tam(int potencia) {
    int aux = potencia, cont2=0;
        
    while (aux >= 1) {
        aux = aux / 2;
        cont2 += 1;
    }
    return cont2;
}


void Nbinario(int potencia, int* arrBin, int tam){
    int cosiente, bin, aux=potencia, cont=0;
    
    do{
        bin=potencia%2;
        cosiente = potencia/2;
        potencia=cosiente;
        arrBin[tam-cont-1]=bin;
        cont+=1;
    }while(cosiente>0);
    
}

void MultiBin(int* arrBin, int numero, int tam, int &pasos, int &naux){
    int cuadrado, expC=1;
    naux=numero;
    //multiplicacion que se guia de los numero binarios
    //emepezando con elevando al cuadrado el numero
    // si el siguiente numero binario es 1 -> se multiplica el cuadrado por el numero
    // si no, se eleva al cuadrado otra vez
    for (int i=1; i<tam; i++){
        pasos+=1;
        cuadrado=pow(naux,2);//simpre se eleva al  cuadrado la primera vez
        if(arrBin[i]==1){ 
            naux=cuadrado*numero;
            pasos+=1;
        }
        
        else if(arrBin[i]==0){
            cuadrado=pow(naux,2);
            naux=cuadrado;
            
        }
        
    }
}


int main(){
    int num, pot, pasos, naux;
    cout<<"Digite un numero: ";cin>>num;
    cout<<"A que potencia desea elevar ese numero? ";cin>>pot;
    
    int   n=tam(pot); //se obtiene el tamaño del arreglo
    int arrBin[n];
    Nbinario(pot,arrBin,n);//se obtiene el arreglo de numeros binarios
    
    MultiBin(arrBin,num,n, pasos, naux);
    cout<<"El numero de operaciones que se hicieron fueron: "<<pasos<<endl;
    cout<<"El numero "<<num<<"^"<<pot<<" = "<<naux;
    return 0;
}
