#include<iostream>

struct Empleado{
    std::string name;
    char sexo;
    float sueldo;
};

int main(){
    int n;
    Empleado empleados[100];
    std::cout<<"Ingrese la cantidad de empleados: "; std::cin>>n;
    std::cin.ignore();
    
    for(int i=0; i<n; i++){
        std::cout<<"=====================================================================\n";
        std::cout<<"Nombre del empleado "<<i+1<<": "; std::getline(std::cin, empleados[i].name);
        std::cout<<"Genero del empleado [M/F] "<<i+1<<": "; std::cin>>empleados[i].sexo; 
        std::cout<<"Sueldo del empleado "<<i+1<<": "; std::cin>>empleados[i].sueldo;
        std::cout<<"=====================================================================\n";
        std::cin.ignore();
    }
    int mayor=0, indice;
    for(int i=0; i<n; i++){
        if(empleados[i].sueldo>mayor){
            mayor=empleados[i].sueldo;
            indice=i;
        }
    }
    std::cout<<"Nombre del empleado con mayor sueldo: "<<empleados[indice].name<<"\n"; 
    std::cout<<"Genero de empleado con mayor sueldo: "<<empleados[indice].sexo<<"\n";
    std::cout<<"Sueldo del empleado con mayor sueldo: "<<empleados[indice].sueldo<<"\n";
    std::cout<<"=====================================================================\n";
    return 0;
}