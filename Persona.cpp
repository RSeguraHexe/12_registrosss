#include<iostream>
#include<string>
#include<cstdlib>

struct Persona{
    std::string nombre;
    std::string dni;
    float edad;
};

int main(){

    struct Persona personas[100];
    int n;

    std::cout<<"=====================================================================\n";
    std::cout<<"Ingrese la cantidad de personas: "; std::cin>>n;
    std::cout<<"=====================================================================\n";

    for(int i=0; i<n; i++){
        std::cout<<"|"<<i+1<<"|\n";
        std::cout<<"Ingrese el nombre de la persona: "; std::cin>>personas[i].nombre;
        std::cout<<"Ingrese el DNI de la persona: "; std::cin>>personas[i].dni;
        std::cout<<"Ingrese la edad de la persona: "; std::cin>>personas[i].edad;
        std::cout<<"=====================================================================\n";
    }

    int mayores50=0;
    for(int i=0; i<n; i++){
        if(personas[i].edad>50){
            mayores50++;
        }
    }

    int promedio, almacenar=0;
    for(int i=0; i<n; i++){
        almacenar=personas[i].edad+almacenar;
    }

    promedio=almacenar/n;

    system("cls");
    std::cout<<"=====================================================================\n";

    std::cout<<"Cantidad de personas mayores a 50 anios: "<<mayores50<<"\n";
    std::cout<<"Promedio de edad de las personas: "<<promedio<<"\n";
    std::cout<<"=====================================================================\n";

    for(int i=0; i<n; i++){
        std::cout<<"Nombre: "<<personas[i].nombre<<" - DNI: "<<personas[i].dni<<" - Edad: "<<personas[i].edad<<"\n";
    }
    std::cout<<"=====================================================================\n";

    return 0;
}