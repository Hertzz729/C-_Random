#include <iostream>

using namespace std;

//matriz Gato
char matrizG[3][3]={'0','0','0',
                    '0','0','0',
                    '0','0','0'};

// movimientos de cada jugador y juegos ganados
struct JUGADOR_MV{
    int n;
    int m;
    int win=0;
    char car;
};

//función donde el jugador escoje su caracter para jugar
void AsignarChar(struct JUGADOR_MV player){
    do{
        cout<<"Elija un caracter del teclado excepto en '0': ";
        cin>>player.car;
    }while(player.car=='0');
    cout<<player.car<<endl;
}

//función para validar movimiento
bool ValidMove(int n, int m){
    if(matrizG[n][m]=='0'){ //si el espacio no esta ocupado se valida
        return true;
    }
    else{
        return false;
    }
}

//funcion pedir coordenadas
void Coord(struct JUGADOR_MV cord){
    cout<<"Digite la condenada n: "; 
    cin>>cord.n;
    cout<<"Digite la condenada m: "; 
    cin>>cord.m;
}

//función para asignar los caracteres a las coordenadas
void AsignarMatG(struct JUGADOR_MV player){
    do{
        Coord(player);
    
    }while(ValidMove(player.n, player.m)!=true);
    matrizG[player.n][player.m]=player.car;
}

//función varificar ganador o tablas
/*bool VerifGanar(){
    if
}*/

//función imprimir matriz
void imprimir(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<matrizG[i][j];
            if(j<2){
                cout<<"|";
            }
        }
        cout<<endl;
        if(i<2){
            for(int k=0; k<2; k++){
                cout<<"_ _";
            }
        }
        cout<<endl;
    }
}

void GAME(struct JUGADOR_MV player1, struct JUGADOR_MV player2){
    int TurnosT=0, turnInd=1;
    
    AsignarChar(player1);
    AsignarChar(player2);
    do{
        if(turnInd%2!=0){ //si el turno individual es impar es turno del player1
            AsignarMatG(player1);
            turnInd+=1;
            cout<<"+++++++"<<endl;
        }
        else{
             cout<<"........."<<endl;
            AsignarMatG(player2);
            turnInd+=1;
           
        }
        imprimir();
        
    }while(TurnosT<9);

}

int main(){
    JUGADOR_MV jugador1, jugador2;
    GAME(jugador1, jugador2);
    //cout<<jugador1.car<<endl;
    //cout<<jugador2.car;
   // imprimir();
    return 0;
}