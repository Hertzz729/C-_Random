#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


void CaminosRey(){
    int reyF, reyC, destF, destC, n, r, h, t;
    vector<int> base = {1, 1, 1};
    
    cout<<"Digite las coordenadas en las que esta el Rey: "<<endl;
    cout<<"Fila: "; cin>>reyF; 
    cout<<"Columna: "; cin>>reyC;
    
    cout<<"Digite las coordenadas de destino: "<<endl;
    cout<<"Fila: "; cin>>destF; 
    cout<<"Columna: "; cin>>destC;
    
    //distancias 
    r = abs(reyF-destF); //entre filas
    n = abs(reyC-destC); // entre columnas
    
    h=r; //h es la distancia del radio
    t=n; // t es la distancia que se movera hacia la derecha o izquierda
    
    // si n>r significa que la distancia hacia la derecha o izquierda es mayor que la distancia entre columnas
    // por lo tanto se intercambian
    if (n>r){
    	h=n;
    	t=r;
	}
	
	//Aqui se crea el arreglo de posibles caminos
    for (int i = 1; i < h; i++) {
        vector<int> a(3 + i * 2, 0);
        //cout << "esto es a = ";
        for (int j = 0; j < a.size(); j++) {
            //cout << a[j] << " ";
        }
        cout <<endl;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < base.size(); l++) {
                //cout << "esto es l+k = " << l + k << std::endl;
                a[l + k] += base[l];
                //cout << "esto es l " << l << std::endl;
            }
            //cout << "a = ";
            for (int j = 0; j < a.size(); j++) {
                //cout << a[j] << " ";
            }
            //cout <<endl;
        }

        base = a;
    }
    // ((h*2)+1)/2 = al centro del arreglo y t es la distanci que recorre a los lados 
    // dado que el arreglo es simetrico no importa si se suma o resta t
    cout<<"El numero de caminos cortos es: "<<base[((h*2)+1)/2+t];
}

int main(){
    cout<<"Para conocer la cantidad de caminos cortos del rey a un punto complete lo siguinte: "<<endl;
    CaminosRey();
    return 0;
}
