#include <iostream>
using namespace std;

//matriz Gato
char matrizG[3][3]={'0','0','0',
                    '0','0','0',
                    '0','0','0'};

// movimientos de cada jugador y juegos ganados
struct JUGADOR_MV{
    int n, cero=0, uno=0, dos=0;
    int m, ceroM=0, unoM=0, dosM=0;
    int win=0;
    char car;
};

//función donde el jugador escoje su caracter para jugar
void AsignarChar(struct JUGADOR_MV &player){  //pasar la estructura como referencia para que efectue los cambios
    do{
        cout<<"elija un caracter del teclado excepto en '0': ";
        cin>>player.car;
    }while(player.car=='0');
    cout<<player.car<<endl;
}

//función para validar movimiento
bool ValidMove(struct JUGADOR_MV player){
    if(matrizG[player.n][player.m]=='0'){ //si el espacio no esta ocupado se valida
        return true;
    }
    else{
        cout<<"Esa posición ya esta ocupada, escoja otra "<<endl;
        return false;
    }
}

//función pedir coordenadas
void Coord(struct JUGADOR_MV &player){ //se tiene que pasar por referencia la estructura si no no efectuara cambios
    cout<<"Digite la condenada n: "; 
    cin>>player.n;
    cout<<"Digite la condenada m: "; 
    cin>>player.m;
}

//función añadir
void adicion(struct JUGADOR_MV &player, int *punteroN, int *punteroM){
    switch(*punteroN){
        case 0:
        player.cero+=1; break;
        case 1:
        player.uno+=1; break;
        case 2:
        player.dos+=1; break;
    }
    switch(*punteroM){
        case 0:
        player.ceroM+=1; break;
        case 1:
        player.unoM+=1; break;
        case 2:
        player.dosM+=1; break;
    }
}

//función para asignar los caracteres a las coordenadas
void AsignarMatG(struct JUGADOR_MV player){
    int *puntN=&player.n, *puntM=&player.m;
    do{
        Coord(player);
    
    }while(ValidMove(player)!=true);
    
    adicion(player, puntN, puntM);//---------->MODIFICAR FUNCION
    matrizG[player.n][player.m]=player.car;
}


//función verificar ganador o empate
bool ValidWin(struct JUGADOR_MV playerX){
    if(playerX.cero==3 || playerX.uno==3 || playerX.dos==3){
        return true;
    }
    else if(playerX.ceroM==3 || playerX.unoM==3 || playerX.dosM==3){
        return true;
    }
    return false;
}


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
    }    
}

void GAME(struct JUGADOR_MV player1, struct JUGADOR_MV player2){
    int turnInd=1;
    cout<<"Jugador 1 "; AsignarChar(player1);
    cout<<"Jugador 2 "; AsignarChar(player2);
    do{
        if(turnInd%2!=0){ //si el turno individual es impar es turno del player1
            cout<<"Turno del jugador 1:"<<endl;
            AsignarMatG(player1);
            turnInd+=1;
            if(turnInd>=3){
                if(ValidWin(player1)==true){
                    cout<<"El jugador1 ha ganado..."<<endl<<"fin del juego";
                    break;
                }
                
            }
        }
        else{
            cout<<"Turno del jugador 2:"<<endl;
            AsignarMatG(player2);
            turnInd+=1;
            if(turnInd>=4){
                if(ValidWin(player2)==true){
                    cout<<"El jugador2 ha ganado"<<endl<<"fin del juego";
                    break;
                }
                
            }
           
        }
        imprimir();
        
    }while(turnInd<10);
    
    cout<<"Es un empate";
}

int main(){
    JUGADOR_MV jugador1, jugador2;
    GAME(jugador1, jugador2);
    return 0;
}
