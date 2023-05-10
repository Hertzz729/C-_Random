#include <iostream>
using namespace std;

long int bNewPascT(int n , int r){
	long int binomio = 0;
	if( (n==r) || (r==0) || (n&&r==0) ){
		return 1;
	}
	else{
		binomio = bNewPascT(n-1,r-1)+bNewPascT(n-1,r);
		return binomio;
	}
}

int main(){
	int n, r;
	cout<<"Digite el espacio n: "; cin>>n;
	cout<<"Digite cuantos elementos de n se seleccionaran: "; cin>>r;
	
	cout<<"El numero de combinaciones de n en r es: "<<bNewPascT(n,r);
	return 0;
}
