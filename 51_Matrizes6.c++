

/*"Faça um programa que preencha, utilizando sorteia, uma matriz 5x5. A seguir, crie dois vetores e coloque, em um, a soma das linhas da matriz, e no outro a soma das colunas da matriz. Exiba o resultado."*/
#include <iostream>
using namespace std;
int vetorLinha[5],vetorColuna[5];
int somaLinha[5],somarLinha;
int somaColuna[5],somarColuna;
int Matriz[5][5];
int main(){
    for(int i=0; i<5;i++){
		somarLinha=0;
        for(int j=0; j<5;j++){
            Matriz[i][j]=i;
            somarLinha+=Matriz[i][j];}
			somaLinha[i]=somarLinha;		
	}
	for(int j=0;j<5;j++){
		somarColuna=0;
		for(int i=0;i<5;i++){
			somarColuna+=Matriz[i][j];}
			somaColuna[j]=somarColuna;
		}

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        cout<<Matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
    for (int i=0;i<5;i++){
        cout<<"O valor do samotorio da LINHA "<<i<<" e igual a "<<somaLinha[i]<<"\n";
    }for (int i=0;i<5;i++){
        cout<<"O valor do samotorio da COLUNA "<<i<<" e igual a "<<somaColuna[i]<<"\n";
    }
    return 0; 
}
