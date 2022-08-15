// Faça  um  programa  que,  usando  struct,  armazene  o  nome  e  a  data  de  nascimento  de  até  10 pessoas (o usuário entrará com estas informações).A geração da data de nascimento deve ser feita aleatoriamente através da função abaixo: void CriaData (TData &D) {D.Mes = 1 + (rand() % 12);D.Ano = 1940+ (rand() % 74);D.Dia = 1 + (rand() % 30);}
// O programa deve:Verificar se a data de nascimento geradaé válida (utilize o algoritmo desenvolvido na exercício número 2);listartodos os nomes e respectivas idades; elistar os nomes das pessoas mais velhas do que uma certa  idade (deve ser validada também esta data) fornecida pelo usuário.
// Devem ser criadas funções diferentes para cada uma dessas atividades.
#include <iostream>
using namespace std;
struct date{
    int m, y, d;
};
struct Person{
    string name;
    date data;
};
bool validBissexto(int year){
    if(year%4==0 || (year%100!=0 && year%400==0 ) ){
        return true;
    }return false;
}
bool validYear(int d, int m, int y){
    switch(m){
    case 1: case 3 : case 5: case 7: case 8: case 10: case 12:
        if(0<d<=31){return true;}
        else{return false;}
    break;
    case 2:
        if((0<d<=29 && validBissexto(y)==true)||(d==28 && validBissexto(y)==false)){return true;}
        else{return false ;}
    break;
    default:
        if(0<d<=30){return true;}
        else{return false;}
    break;}
}
bool createDate(Person people){
    people.data.y= 1940+ (rand() % 74);
    people.data.m = 1 + (rand() % 12);
    people.data.d= 1 + (rand() % 30);
    if(validYear(people.data.d,people.data.m, people.data.y)==true){
        return people.data.y, people.data.m, people.data.y;
    }return createDate(people);
}



int main(){
    
}