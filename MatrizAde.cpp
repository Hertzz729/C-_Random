#include <stdlib.h>
#include <iostream>

using namespace std;


int main()
{
    int i, j, m, n, elemeto=0, suma, f, c=0;
    int tam;
   
    
    cout<<"Digite el tamaño: ";
    cin>>tam;
    
    int MatrizAd[tam][tam];
    int MatrizAdP[tam][tam];
    int aux[tam];
     
    cout<<"Digite los elementos de la matriz: ";
    for(int k=0; k<tam; k++){
        for(int p=0; p<tam; p++){
            cin>>MatrizAd[k][p];
        }
    }
    for(int k=0; k<tam; k++){
        for(int p=0; p<tam; p++){
            cout<<MatrizAd[k][p]<<"|";
        }
        cout<<endl;
    }
    
    
    for (i=0;i<tam; i++ ){// se mantiene la fila y cambian las columnas
        
        c=0;
            for(n=0; n<tam; n++){  // se mantienen las columnas y cambian las filassu
                for(m=0; m<tam; m++){
                    elemeto=MatrizAd[i][m]*MatrizAd[m][n];
                    //cout<<"subindices"<<"i="<<i<<" m="<<m<<" m="<<m<<" n="<<n<<endl;
                    //cout<<elemeto<<endl;
                    aux[m]=elemeto;
                }
                for(int i=0; i<tam; i++){
                    suma+=aux[i];
                }
            cout<<"el nuevo elemeto es: "<<suma<<endl;
            suma=0;
            }
 
    } 

    return 0;
}
