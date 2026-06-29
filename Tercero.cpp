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

    int m=-1; 
    do{
        do{

            system("cls");
            std::cout<<"Ingrese un mes: "; std::cin>>m;

        }while(m<0 || m>12);

        if(m==0){break; std::cout<<"=================================================================";}

        std::cout<<"Personas que nacieron en el mes "<<m<<": \n";

        for(int i=0; i<n; i++){
            if(dt[i].fecha.mes==m){

                std::cout<<i+1<<"| "<<dt[i].nombre<<" ------ Nacimiento: "<<dt[i].fecha.dia<<"/"<<dt[i].fecha.mes<<"/"<<dt[i].fecha.anio<<"\n\n";

            }
        }

        system("pause");

    }while(m!=0);
}
