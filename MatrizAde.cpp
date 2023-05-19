#include <iostream>
#include <stdlib.h>
using namespace std;

//rellenar matriz ad
void mat(int**matriz, int tam){
    cout<<"rellene la matriz: ";
    for (int k=0; k<tam; k++){
        for(int n=0; n<tam; n++){
            
            cin>>*(*(matriz+k)+n);
        }
    }
}


int** crearMat(int tam){
    int **matriz = new int*[tam];// se crea el espacio de dos filas
    for (int j=0; j<tam; j++){
        matriz[j] = new int[tam]; // a cada fila se le pone una columan
    }
    return matriz;
}

int** multiplicarMat(int** mat1, int**mat2, int tam){
    int aux[tam];
    int** MatrizAdP=crearMat(tam);
    int elemeto=0, suma=0;
    for (int i=0;i<tam; i++ ){// se mantiene la fila y cambian las columnas
            for(int n=0; n<tam; n++){  // se mantienen las columnas y cambian las filassu
                for(int m=0; m<tam; m++){
                    elemeto=*(*(mat1+i)+m)*(*(*(mat2+m)+n));
                    cout<<"subindices"<<"i="<<i+1<<" m="<<m+1<<" m="<<m+1<<" n="<<n+1<<endl;
                    cout<<elemeto<<endl;
                    aux[m]=elemeto;
                }
                for(int r=0; r<tam; r++){
                    suma+=aux[r];
                }
                (*(*(MatrizAdP+i)+n))=suma;
            cout<<"el nuevo elemeto es: "<<suma<<endl;
            suma=0;
            }
 
    }
    return MatrizAdP;
}

int ** PotMatriz(int** mat, int tam, int p){
    int **matAux=crearMat(tam);
    for (int k=0; k<tam; k++){
        for(int n=0; n<tam; n++){
            *(*(matAux+k)+n)=*(*(mat+k)+n);
        }
    }
    int n=1;
    while(n<p){
        matAux=multiplicarMat(mat, matAux, tam);
        n++;
    }
    return matAux;
}

void imprimirM(int** mat, int tam){
    for (int k=0; k<tam; k++){
        for(int n=0; n<tam; n++){
            cout<<*(*(mat+k)+n)<<"|";
        }
        cout<<endl;
    }
}

void eliminarM(int** mat, int tam){
    for (int j=0; j<tam; j++){
        delete[] mat[j];
    }
    delete[] mat; //eliminamos las filas 
    mat = NULL; // hacemos que el apuntador deje de apuntar a algo
}


int main()
{
    //++++++++++++++++++++++++++FUNCIONES+++++++++++++++++++++++++++++++
    int tam=2;
    int**m=crearMat(tam);
    mat(m,tam);
   // imprimirM(m,tam);
    int** mp=multiplicarMat(m,m, tam);
    imprimirM(mp,tam);
    cout<<"Fin multiplicacion"<<endl;
    int** mas=PotMatriz(m,tam,4);
    imprimirM(mas,tam);
    //eliminarM(m,2);
    //imprimirM(m,2);
    cout<<"Terminan pruebas de las funciones"<<endl;
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    return 0;
}