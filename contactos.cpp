#include<iostream>
#include<string>
#include<string>

struct ContactoEmail{
    std::string nombre;
    char sexo;
    int edad;
    std::string email;
}contact[100];

int main(){

    int k=0;                /* Utilizo K para saber que numero de contacto estoy registrando */

    system("cls");

    std::cout<<"Ingrese su primer contacto! \n\n";

    std::cout<<"Nombre: ";  std::getline(std::cin, contact[0].nombre);
    std::cout<<"Sexo (M/F): ";  std::cin>>contact[0].sexo;
    std::cout<<"Edad: ";    std::cin>>contact[0].edad;   
    std::cout<<"Email: "; std::cin>>contact[0].email;

    std::cout<<"\n\nPerfecto! ya tiene agregado su primer contacto, por favor presione cualquier tecla\npara ir al menu principal.\n\n";

    system("pause");

    k++;
    
    int op=-1;
    do{

        system("cls");

        std::cout<<"============================================================\n";
        std::cout<<"Indique la accion\n";
        std::cout<<"============================================================\n";
        std::cout<<" 1 : Agregar contacto\n";
        std::cout<<" 2 : Modificar contacto\n";
        std::cout<<" 3 : Mostrar todos los contactos\n";
        std::cout<<" 4 : Mostrar los contactos por servidor\n";
        std::cout<<" 5 : Eliminar contacto\n";
        std::cout<<" 6 : Buscar contacto por email\n";
        std::cout<<" 0 : Salir del programa\n";
        std::cout<<"============================================================\n";
        std::cin>>op;


        switch(op){

            case 1: 

                system("cls");
                std::cin.ignore();

                std::cout<<"============================================================\n";
                std::cout<<"Ingrese los datos del contacto\n";
                std::cout<<"============================================================\n";
                std::cout<<"Nombre: ";  std::getline(std::cin, contact[k].nombre);
                std::cout<<"Sexo (M/F): ";  std::cin>>contact[k].sexo;
                std::cout<<"Edad: ";    std::cin>>contact[k].edad;   
                std::cout<<"Email: "; std::cin>>contact[k].email;
                std::cout<<"============================================================\n";
                system("pause");

                k++;        /* Aqui utilizo el K para saber que numero sera mi siguiente contacto agregado */

                break;

            case 2: std::cout<<"adc"; break;
            case 3: std::cout<<"adc"; break; 
            case 4: std::cout<<"adc"; break; 
        }
    }while(op!=0);
}