#include<iostream>
#include<string>
#include<cstdlib>

struct fechanacimiento{
    int dia;
    int mes;
    int anio;
};

struct datos{
    std::string nombre;
    struct fechanacimiento fecha;
}dt[190];

int main(){

    int n=0;
    do{

        system("cls");
        std::cout<<"Cantidad de personas (0< y <190): "; std::cin>>n;

    }while(n<=0 || n>190);

    for(int i=0; i<n; i++){
        std::cin.ignore();
        char z;

        std::cout<<"persona "<<i+1<<", nombre: "; std::getline(std::cin, dt[i].nombre);

        std::cout<<"persona "<<i+1<<", fecha de nacimiento (DD/MM/AAAA): ";
        std::cin>>dt[i].fecha.dia>>z
                >>dt[i].fecha.mes>>z
                >>dt[i].fecha.anio;
    }

    int m=1; 
    do{
        system("cls");

        std::cout<<"ingrese un mes: "; std::cin>>m;
        std::cout<<"datos de las personas que nacieron en ese mes: \n";

        for(int i=0; i<n; i++){
            if(dt[i].fecha.mes==m){

                std::cout<<"persona "<<i+1<<": \n";
                std::cout<<"nombre: "<<dt[i].nombre<<" --- "<<" fecha de nacimiento: "<<dt[i].fecha.dia<<"/"<<dt[i].fecha.mes<<"/"<<dt[i].fecha.anio<<"\n";

            }
        }

        system("pause");

    }while(m!=0);
}
