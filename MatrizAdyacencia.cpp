#include <iostream>
#include <stdlib.h>
using namespace std;

//rellenar matriz
void mat(int**matriz, int tam){
    for (int k=0; k<tam; k++){
        cout<<"digite los caminos de longitud 1 del vetrice V"<<k+1<<" a los vertices"<<endl;
        for(int n=0; n<tam; n++){
            cout<<"V"<<n+1<<": ";
            cin>>*(*(matriz+k)+n);
        }
    }
}

int** crearMat(int tam){
    int **matriz = new int*[tam];// se crea el espacio de las filas
    for (int j=0; j<tam; j++){
        matriz[j] = new int[tam]; // a cada fila se le pone una columna
    }
    return matriz;
}

int** multiplicarMat(int** mat1, int**mat2, int tam){
    int aux[tam]; //vector para guardar los elemtos de la multiplicacion 
    int** MatrizAdP=crearMat(tam);
    int elemeto=0, suma=0;
    for (int i=0;i<tam; i++ ){// se mantiene la fila de la matriz 1
            for(int n=0; n<tam; n++){  // se matiene la columna de la matriz 2
                for(int m=0; m<tam; m++){ //se itera las columnas de la mat1 y las filsa de la mat2
                    elemeto=*(*(mat1+i)+m)*(*(*(mat2+m)+n));//se multiplica 
                    aux[m]=elemeto;
                }
                for(int r=0; r<tam; r++){
                    suma+=aux[r]; //suma de los elemtos de la multiplicacion
                }
                (*(*(MatrizAdP+i)+n))=suma;
            suma=0;
            }
 
    }
    return MatrizAdP;
}

int ** PotMatriz(int** mat, int tam, int p){
    int **matAux=crearMat(tam);
    //se crea una matirz auxiliar == matriz original
    for (int k=0; k<tam; k++){ 
        for(int n=0; n<tam; n++){
            *(*(matAux+k)+n)=*(*(mat+k)+n);
        }
    }
    int n=1;
    // se multiplica la matriz por la compia n veces
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
    delete[] mat;
    mat = NULL; 
}


int main()
{
    int tam, ncaminos;
    cout<<"Digite el número de vertices que posee su grafo: "; cin>>tam;
    int **matrizAdI=crearMat(tam);
    mat(matrizAdI, tam);
    cout<<"La matriz de adyacencia inicial es: "<<endl;
    imprimirM(matrizAdI,tam);
    cout<<"Para que longitud de caminos le gustaria conocer la matriz de adyacencia? "; cin>>ncaminos;
    int **matrizAdNcamnios=PotMatriz(matrizAdI,tam, ncaminos);
    cout<<"La matirz de adyacencia con con longitud de caminos "<<ncaminos<<" es"<<endl;
    imprimirM(matrizAdNcamnios,tam);
    
    eliminarM(matrizAdI,tam); eliminarM(matrizAdNcamnios,tam);

    return 0;
}
