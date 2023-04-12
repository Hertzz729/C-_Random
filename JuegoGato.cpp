#include <iostream>
using namespace std;

//matriz Gato
char matrizG[3][3] = {  '0', '0', '0',
                        '0', '0', '0',
                        '0', '0', '0'
};

float matizV[3][3] = { 1.12, 1.24, 1.45,	//estos valores se le asignan a cada casilla que el jugador ocupe
                       23, 19, 17,			//y existen 8 combinaciones de 3 numeros que dan un conjunto soluciC3n
                       29, 31, 37};				//{3,8,9,10,15}

float Vp1[5] = { 0, 0, 0, 0, 0 };
float Vp2[5] = { 0, 0, 0, 0, 0 };

// movimientos de cada jugador y juegos ganados
struct JUGADOR_MV
{
  int n;
  int m;
  int win = 0;
  char car;
};

//funciC3n donde el jugador escoje su caracter para jugar
void
AsignarChar (struct JUGADOR_MV &player)
{				//pasar la estructura como referencia para que efectue los cambios
  do
    {
      cout << "elija un caracter del teclado excepto en '0': ";
      cin >> player.car;
    }
  while (player.car == '0');
  cout << player.car << endl;
}

//funciC3n para validar movimiento
bool
ValidMove (struct JUGADOR_MV player)
{
  if (matrizG[player.n][player.m] == '0')
    {				//si el espacio no esta ocupado se valida
      return true;
    }
  else
    {
      cout << "Esa posiciC3n ya esta ocupada, escoja otra " << endl;
      return false;
    }
}

//funciC3n pedir coordenadas y asignar valores
void
Coord (struct JUGADOR_MV &player, int turno)
{				//se tiene que pasar por referencia la estructura si no no efectuara cambios
  cout << "Digite la condenada n: ";
  cin >> player.n;
  cout << "Digite la condenada m: ";
  cin >> player.m;
}


//funciC3n para asignar los caracteres a las coordenadas
void
AsignarMatG (struct JUGADOR_MV player, int turno, float Valores[5])
{
  do
    {
      Coord (player, turno);
    }
  while (ValidMove (player) != true);
  Valores[turno] = matizV[player.n][player.m];
  matrizG[player.n][player.m] = player.car;
}


/*funciC3n VERIFICA A GANADOR con un algoritmo que hace la suma de tres casillas que el jugador 
haya elegido si encuentra una suma que coinsida con el conjunto soluciC3n significa que el jugador ha ganado*/
bool ValidWin (float Valores[5]){
  float fijoP, fijoS, cambiante, suma = 0;

  for (int i = 0; i < 3; i++)
    {
      fijoP = Valores[i];

      for (int j = i + 1; j < 4; j++)
	{
	  fijoS = Valores[j];
	  cambiante = Valores[j + 1];
	  suma = fijoS + fijoP + cambiante;
	  /*EncontrC) que el conjunto {3,8,9,10,15} es el soluciC3n, y se obtiene al sumar una combinacion de 3 numeros
	     los cuales se obtienen del arreglo player.valores
	   */
	  cout << " Suma " << suma << endl;
	  if (suma == 53.12 || suma == 51.24 || suma == 55.45 || suma == 49.45
	      || suma || 3.81 || suma == 59 || suma == 97 || suma == 57)
	    {
	      return true;
	    }
	}
    }
  return false;
}


//funciC3n imprimir matriz
void
imprimir ()
{
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  cout << matrizG[i][j];
	  if (j < 2)
	    {
	      cout << "|";
	    }
	}
      cout << endl;
    }
}

void
GAME (struct JUGADOR_MV player1, struct JUGADOR_MV player2){
  int turnInd = 1, turn1 = 0, turn2 = 0;
  cout << "Jugador 1 ";
  AsignarChar (player1);
  cout << "Jugador 2 ";
  AsignarChar (player2);
  do{
      if (turnInd % 2 != 0){			//si el turno individual es impar es turno del player1
	  cout << "Turno del jugador 1:" << endl;
	  AsignarMatG (player1, turn1, Vp1);
	  turnInd += 1;
	  turn1 += 1;
	  if (turnInd >= 5){
	      if (ValidWin (Vp1) == true)
		{
		  imprimir ();
		  cout << "El jugador1 ha ganado..." << endl <<
		    "fin del juego";
		  break;
		}

	    }
	}
      else{
	  cout << "Turno del jugador 2:" << endl;
	  AsignarMatG (player2, turn2, Vp2);
	  turnInd += 1;
	  turn2 += 1;
	  if (turnInd >= 6)
	    {
	      if (ValidWin (Vp2) == true)
		{
		  imprimir ();
		  cout << "El jugador2 ha ganado" << endl << "fin del juego";
		  break;
		}

	    }

	}
      imprimir ();

    }
  while (turnInd < 10);

}

int
main ()
{
  JUGADOR_MV jugador1, jugador2;
  GAME (jugador1, jugador2);
  return 0;
}
