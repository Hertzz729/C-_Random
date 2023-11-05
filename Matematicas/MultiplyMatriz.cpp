#include <iostream>
#include <vector>

using namespace std;

//+++++++++++FUNCION CREAR MATRIZ DIMAMICA++++++++++++++++++++++
int** CreatMatriz(){
    int filas, columnas;
    int **matriz; // se crea el puntero doble
    cout<<"Digite el tamaño de la matriz cuadrada: "; cin>>filas;
    columnas=filas;
    matriz = new int*[filas]; // se asigna el tamaño de 'filas' de punteros al puntero principal 
    for(int i=0; i<filas; i++){
        matriz[i] = new int[columnas]; //se asigna el tamaño de los subpunteros para las columnas para cada fila
    }
    
    return matriz;
}

//+++++++++++FUNCION CREAR MATRIZ DIMAMICA (VARIANTE)++++++++++++++++++++++
int** CreatMatriz_variant(int tam){
    int filas=tam, columnas=tam;
    int **matriz; // se crea el puntero doble
    matriz = new int*[filas]; // se asigna el tamaño de 'filas' de punteros al puntero principal 
    for(int i=0; i<filas; i++){
        matriz[i] = new int[columnas]; //se asigna el tamaño de los subpunteros para las columnas para cada fila
    }
    
    return matriz;
}

//++++++++++FUNCION LIBERAR MEMORIA RESERVADA+++++++++++++++++ 
void DeleteMatriz(int** matriz, int filas){
    // se libera la memoria de los punteros que estan en las 
    //  direcciones del puntero principal "filas"
    for(int i=0; i<filas; i++){
        delete[] matriz[i];
    }
    // se libera la memoria del puntero principal "filas"
    delete[] matriz;
    
}

//++++++++++FUNCION RELLENAR MATRIZ++++++++++++++++++++++++++
void FillMatriz(int** matriz, int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<filas; j++){
            cout<<"Digite el valor de la posicion a"<<i<<j<<" -> ";cin>>matriz[i][j]; 
        }
    }
}

//++++++++++FUNCION RELLENAR MATRIZ CON CEROS++++++++++++++++++++++++++
void FillMatrizCero(int** matriz, int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<filas; j++){
            matriz[i][j]=0; 
        }
    }
}

//++++++++++FUNCION IMPRIMIR MATRIZ+++++++++++++++++
void PrintMatriz(int** matriz, int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<filas; j++){
            cout<<matriz[i][j]<<" | "; 
        }
        cout<<endl;
    }
}

//++++MULTIPLICACION MATRICES (ALGORITMO ESTANDAR)+++++++
void MultiplyMatriz(int** A, int** B, int** C, int tam_NxN) {
    for (int i = 0; i < tam_NxN; i++) {
        for (int j = 0; j < tam_NxN; j++) {
            C[i][j] = 0;
            for (int k = 0; k < tam_NxN; k++) { // Aquí también corregí 'k++' en lugar de 'k
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}
//+++++++DIVIDIR MATRIZ+++++++++++++++++
int** DividMatriz(int** matriz, int numMat, int n_Over_2){
    int ** newMat;
    int filaIn=0, columnaIn=0, k=0, p=0; 
    newMat=CreatMatriz_variant(n_Over_2); //se crea la submatriz de tamaño n/2
    
    if(numMat==3){
        filaIn=n_Over_2;
    }
    else if(numMat==2 || numMat==4){
        columnaIn=n_Over_2;
        if(numMat==4){
            filaIn=n_Over_2;
        }
    }
    
    for(int i=0; i<n_Over_2; i++){
        for(int j=0; j<n_Over_2; j++){
            newMat[i][j]=matriz[filaIn][columnaIn+j];
        }
        filaIn+=1;
    }
    return newMat;
}

//+++++MULTIPLICACION RECURSIVA DE MATRICES (ALGORITMO DIVIDE Y CONQUISTARAS)++++++
void MatrizMultiplyRecursive(int** A, int**B, int**C, int tam_NxN){
    if(tam_NxN==1){
        cout<<"Tamaño "<<tam_NxN<<endl;
        C[0][0]+=A[0][0]*B[0][0];
        cout<<"1----> "<<A[0][0]<<"_2----> "<<B[0][0]<< "_3--->"<<C[0][0]<<endl;
        return;
        //tal vez aqui va el delete
    }

    int **A11=DividMatriz(A, 1, tam_NxN/2), **A12=DividMatriz(A, 2, tam_NxN/2),
        **A21=DividMatriz(A, 3, tam_NxN/2), **A22=DividMatriz(A, 4, tam_NxN/2),
        **B11=DividMatriz(B, 1, tam_NxN/2), **B12=DividMatriz(B, 2, tam_NxN/2),
        **B21=DividMatriz(B, 3, tam_NxN/2), **B22=DividMatriz(B, 4, tam_NxN/2),
        **C11=CreatMatriz_variant(tam_NxN/2), **C12=CreatMatriz_variant(tam_NxN/2), 
        **C21=CreatMatriz_variant(tam_NxN/2), **C22=CreatMatriz_variant(tam_NxN/2);
        
        PrintMatriz(A21,tam_NxN/2);
        cout<<endl;
        
    FillMatrizCero(C11,tam_NxN/2);
    FillMatrizCero(C12,tam_NxN/2);
    FillMatrizCero(C21,tam_NxN/2);
    FillMatrizCero(C22,tam_NxN/2);
    
    MatrizMultiplyRecursive(A11, B11, C11, tam_NxN/2);
    MatrizMultiplyRecursive(A11, B12, C12, tam_NxN/2);
    MatrizMultiplyRecursive(A21, B11, C21, tam_NxN/2);
    MatrizMultiplyRecursive(A21, B12, C22, tam_NxN/2);
    MatrizMultiplyRecursive(A12, B21, C11, tam_NxN/2);
    MatrizMultiplyRecursive(A12, B22, C12, tam_NxN/2);
    MatrizMultiplyRecursive(A22, B21, C21, tam_NxN/2);
    MatrizMultiplyRecursive(A22, B22, C22, tam_NxN/2);
    
    
    for (int i = 0; i < tam_NxN/2; i++) {
            for (int j = 0; j < tam_NxN/2; j++) {
                C[i][j] = C11[i][j];
                C[i][j + tam_NxN/2] = C12[i][j];
                C[i + tam_NxN/2][j] = C21[i][j];
                C[i + tam_NxN/2][j + tam_NxN/2] = C22[i][j];
            }
        }

    
    DeleteMatriz(A11,tam_NxN/2);DeleteMatriz(A12,tam_NxN/2);
    DeleteMatriz(A21,tam_NxN/2);DeleteMatriz(A22,tam_NxN/2);
    
    DeleteMatriz(B11,tam_NxN/2);DeleteMatriz(B12,tam_NxN/2);
    DeleteMatriz(B21,tam_NxN/2);DeleteMatriz(B22,tam_NxN/2);
    
    DeleteMatriz(C11,tam_NxN/2);DeleteMatriz(C12,tam_NxN/2);
    DeleteMatriz(C21,tam_NxN/2);DeleteMatriz(C22,tam_NxN/2);
}

int main(){
    
    // PRUEBAS 
/*    int **matriz;
    matriz = CreatMatriz();
    FillMatriz(matriz, 2);
    PrintMatriz(matriz, 2);
    DeleteMatriz(matriz, 2);
*/
    //PRUEBAS MULTIPLICACION (ALGORITMO ESTANDAR)
/*    int **A, **B, **C;
    
    A = CreatMatriz();
    B = CreatMatriz();
    C=CreatMatriz_variant(2);
    
    FillMatriz(A, 2);
    PrintMatriz(A, 2);
    
    FillMatriz(B, 2);
    PrintMatriz(B, 2);
    
    MultiplyMatriz(A,B,C,2);
    PrintMatriz(C,2);
    
    DeleteMatriz(A, 2);
    DeleteMatriz(B, 2);
    DeleteMatriz(C,2);
*/
   //PREUBAS DIVICION EN CUADRANTRES MATRIZ
/*    int **A, **C;
    A = CreatMatriz();
    FillMatriz(A, 2);
    PrintMatriz(A, 2);
    
    cout<<endl;
    
    C=DividMatriz(A,4,1);
    PrintMatriz(C, 1);

    DeleteMatriz(A, 2);
    DeleteMatriz(C,1);
    

        int **A, **B, **C;
    
    A = CreatMatriz();
    B = CreatMatriz();
    C=CreatMatriz_variant(2);
    
    
    FillMatriz(A, 2);
    PrintMatriz(A, 2);
    
    FillMatriz(B, 2);
    PrintMatriz(B, 2);
    
    cout<<endl;
    
    MatrizMultiplyRecursive(A,B,C,2);
    PrintMatriz(C,2);
    
    DeleteMatriz(A, 2);
    DeleteMatriz(B, 2);
    DeleteMatriz(C,2);
    
    
    */
    //PRUEBAS MULTIPLICACION (ALGORITMO DIVIDE & CONQUER)
    int **A, **B, **C;
    
    A = CreatMatriz();
    B = CreatMatriz();
    C=CreatMatriz_variant(4);
    
    
    FillMatriz(A, 4);
    PrintMatriz(A, 4);
    
    FillMatriz(B, 4);
    PrintMatriz(B, 4);
    
    cout<<endl;
    
    MatrizMultiplyRecursive(A,B,C,4);
    PrintMatriz(C,4);
    
    DeleteMatriz(A, 4);
    DeleteMatriz(B, 4);
    DeleteMatriz(C,4);
    
    return 0;
}