#include <iostream>
using namespace std;

//matriz Gato
char matrizG[3][3]={'0','0','0',
                    '0','0','0',
                    '0','0','0'};
int matizV[3][3]={1,1,1,
                  4,5,6,
                  3,3,3};

// movimientos de cada jugador y juegos ganados
struct JUGADOR_MV{
    int n;
    int m;
    int valores[5]={0,0,0,0,0};
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

//función pedir coordenadas y asignar valores
void Coord(struct JUGADOR_MV &player, int turno){ //se tiene que pasar por referencia la estructura si no no efectuara cambios
    cout<<"Digite la condenada n: "; 
    cin>>player.n;
    cout<<"Digite la condenada m: "; 
    cin>>player.m;
    //player.valores[turno]=matizV[player.n][player.m]; //POR ALGUNA RAZÓN NO SE PUEDE ASIGNAR DOS COSAS DE LA ESTRUCTURA
}                                                       //EN LA MISMA FUNCION, POR LO QUE SE OPTO POR PONER ESTA ASIGNACIÓN
                                                        // EN LA FUNCION DE ABAJO (ARREGLAR)

//función que asigna los valores de la matrizV a el arreglo valores, que sirven para verificar al ganador
void v(struct JUGADOR_MV &player, int n, int m, int turno){
    player.valores[turno]=matizV[n][m];
}


//función para asignar los caracteres a las coordenadas
void AsignarMatG(struct JUGADOR_MV player, int turno){
    do{
        Coord(player, turno);
    
    }while(ValidMove(player)!=true);
    matrizG[player.n][player.m]=player.car;
}


//función verificar ganador o empate
bool ValidWin(struct JUGADOR_MV player){
    int fijoP, fijoS, cambiante, suma=0;
    
    for(int i=0; i<3; i++){ //no esta pasando los valores del arreglo 
        fijoP=player.valores[i];
        cout<<"fijo p "<<fijoP;
        for(int j=i+1; j<4; j++){
            fijoS=player.valores[j];
            cout<<" fijo s "<<fijoS;
            cambiante=player.valores[j+1];
            cout<<" cambiante "<<fijoP<<endl;    
            suma=fijoS+fijoP+cambiante;
            
            if(suma==3 || suma==15 || suma==9 || suma==8 ||suma==10){
                return true;
            }
        }
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
    int turnInd=1, turn1=0, turn2=0;
    cout<<"Jugador 1 "; AsignarChar(player1);
    cout<<"Jugador 2 "; AsignarChar(player2);
    do{
        if(turnInd%2!=0){ //si el turno individual es impar es turno del player1
            cout<<"Turno del jugador 1:"<<endl;
            AsignarMatG(player1, turn1);
            v(player1, player1.n, player1.m, turn1);
            cout<<" valores "<<player1.valores[turn1]<<endl; //EN ESTA PARTE PARECE QUE NO TOMA LAS VARIABLES DE VALORES
            turnInd+=1;
            turn1+=1;
            if(turnInd>=5){
                if(ValidWin(player1)==true){
                    imprimir();
                    cout<<"El jugador1 ha ganado..."<<endl<<"fin del juego";
                    break;
                }
                
            }
        }
        else{
            cout<<"Turno del jugador 2:"<<endl;
            AsignarMatG(player2, turn2);
            v(player1, player1.n, player1.m, turn1);
            turnInd+=1;
            turn2+=1;
            if(turnInd>=6){
                if(ValidWin(player2)==true){
                    imprimir();
                    cout<<"El jugador2 ha ganado"<<endl<<"fin del juego";
                    break;
                }
                
            }
           
        }
        imprimir();
        
    }while(turnInd<10);
    
}

int main(){
    JUGADOR_MV jugador1, jugador2;
    GAME(jugador1, jugador2);
    return 0;
}
