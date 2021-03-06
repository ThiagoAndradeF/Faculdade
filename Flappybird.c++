/*Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h> ///para habilitar a função time
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)
    - Implementar colisão
    - Implementar pontuação (mais um ponto para cada obstáculo superado)
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2)
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


    int bird_x=10, bird_y=10;
    int obstaculo_x=130, obstaculo_y;
    int obstaculo2_x=130, obstaculo2_y;
    int num1= 0, num2=0, num3=0, num4=0;
    char tecla = '0';
    
    srand(time(NULL));
    
    int pontos=0, tempo=100;  //DECLARAÇÃO DE VARIÁVEIS ADICIONAIS
    system("pause");
    
	 ///DESENHO DO CENÁRIO
        cout<<"---------------------------------------------PONTUACAO: "<<pontos<<"---------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------";

	while (true) { //esse laço faz o jogo rodar para sempre
        //system("cls");
///POSICIONA O PÁSSARO
        //coord.X = 10;    coord.Y = 10;
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        //cout<<pontos;
        
       
        if(obstaculo_x ==130){
            ///GERANDO NÚMERO ALEATÓRIO
            srand(time(NULL));
            num1 = rand()%14;
            if(num1==0){
                num1=1;
            }
            num2 = num1+5; //DEFINE O ESPAÇO ENTRE OBSTÁCULOS
        }

        ///POSICIONA O OBSTÁCULO
        obstaculo_y=1;
        while(obstaculo_y<21){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y<=num1 || obstaculo_y>=num2){
                cout<<char(219);
            } else {
                cout<<" ";
            }
            obstaculo_y++;
        }

        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        ///VERIFICA COLISÃO
        if(bird_y == 0 || bird_y >= 20 ||(obstaculo_x==10 && (num1>=bird_y || num2<=bird_y)) || (obstaculo2_x==10 && (num3>=bird_y || num4<=bird_y))){
        	system("cls");
            cout << endl << "Voce acertou um obstaculo. GAME OVER"<< endl;
            cout<< "Pontuacao final: "<<pontos<<endl; //JOGO PARA CASO O PASSARO COLIDA NO OBSTÁCULO
            return 1;
        }

        if(obstaculo_x < bird_x){
            pontos+=1; //PONTUAÇÃO
            obstaculo_x = 130;
        }else if(obstaculo2_x < bird_x){
            pontos+=1;
            if((pontos%5==0) && pontos != 0){
            tempo -= 20; //A CADA 5 PONTOS ELE AUMENTA A VELOCIDADE DO JOGO
        } 
        }


        if(obstaculo_x == 67){
            ///GERANDO NÚMERO ALEATÓRIO
            //srand(time(NULL));
            num3 = rand()%15+1;
            num4 = num3+5; //DEFINE O ESPAÇO ENTRE OBSTÁCULOS
            obstaculo2_x=130;
        }

        if(obstaculo_x<60 || pontos>=1){
            obstaculo2_y=1;
            while(obstaculo2_y<21){
                coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo2_y<=num3 || obstaculo2_y>=num4){
                    cout<<char(219);
                } else {
                    cout<<" ";
                }
                obstaculo2_y++;
            }
        }

        Sleep(tempo);
        
        ///limpar passaro
        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";

		obstaculo_y=1;
		while(obstaculo_y<21){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<" ";
        
            obstaculo_y++;
        }
        obstaculo2_y=1;
        while(obstaculo2_y<21){
                coord.X = obstaculo2_x;    coord.Y = obstaculo2_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				cout<<" ";
                
                obstaculo2_y++;
            }

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' || tecla =='W'){
            bird_y--;
            tecla='0';
        } else {
            bird_y++;   //PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR
        }

        ///OBSTÁCULO AVANÇA CINCO POSIÇÕES PARA ESQUERDA
        obstaculo_x-=3;
        obstaculo2_x-=3;
    }
    return 0;
}
