#include<iostream>
#include<string>
#include<cstdlib>

struct Producto{
    std::string nombre;
    float precio;
    int cantidad;
}prod[500];

struct Venta{
    int idVenta;
    std::string producto;
    int cantidad;
    float precioTotal;
}vent[500];

int main(){

    int k=0; /*Contador de productos registrados*/

    std::cout<<"====================================================================\n";
    std::cout<<"Registre su primer producto!\n";
    std::cout<<"====================================================================\n";
    std::cout<<"Producto: 1\n\n"; 
    
    std::cout<<"Nombre del producto: "; std::getline(std::cin, prod[0].nombre);
    std::cout<<"Precio del producto: "; std::cin>>prod[0].precio;
    std::cout<<"====================================================================\n";
    std::cout<<"Perfecto! Ya tiene su primer producto, presione cualquier tecla para continuar...\n\n";

    k++; /*Se incrementa el contador de productos registrados*/

    system("pause"); system("cls");

    char op='X'; /*Aqui se indicara la opcion seleccionada */

    do{
        std::cout<<"====================================================================\n";
        std::cout<<" MiniMarket! -  Seleccione una opcion del menu\n";
        std::cout<<"====================================================================\n";
        std::cout<<"A - Registre un nuevo producto\n";
        std::cout<<"B - Registrar entrada de productos existentes\n";
        std::cout<<"C - Listar todos los productos registrados\n";
        std::cout<<"D - Buscar productos por nombre\n";
        std::cout<<"E - Actualizar datos del producto\n";
        std::cout<<"F - Eliminar un producto\n";
        std::cout<<"G - Registrar una venta\n";
        std::cout<<"H - Listar todas las ventas\n";
        std::cout<<"I - Calcular total de ventas\n\n";

        std::cout<<"J - Salir del programa\n";
        std::cout<<"====================================================================\n";
        std::cout<<"Opcion: "; std::cin>>op;

        system("cls");

        switch(op){
            case 'A':
            case 'a':
                char z='X'; /*Confirmacion*/ 
                do{
                    std::cout<<"====================================================================\n";
                    std::cout<<"Registre un nuevo producto!\n";
                    std::cout<<"====================================================================\n";
                    std::cout<<"Producto ["<<k+1<<"] \n\n";

                    std::cin.ignore();

                    std::cout<<"Nombre del producto: "; std::cin.ignore(); std::getline(std::cin, prod[k-1].nombre);
                    std::cout<<"Precio del producto: "; std::cin>>prod[k-1].precio;
                    std::cout<<"====================================================================\n";
                    std::cout<<"Confirmar esta accion? [S/N]: "; std::cin>>z;
                    if(z=='S' || z=='s'){

                        k++; /*Se incrementa el contador de productos registrados*/
                        std::cout<<"Perfecto! Ya tiene su producto registrado, presione cualquier\ntecla para continuar...\n\n";
                        system("pause"); system("cls");

                    }else if(z=='N' || z=='n'){
                        system("cls");
                        break;
                    }
                }while(z!='S' && z!='s');
                break;
            
            case 'B':
            case 'b':
                std::cout<<"====================================================================\n";
                std::cout<<"Agregando productos existentes!\n";
                std::cout<<"====================================================================\n";
                std::cin.ignore();
                std::cout<<"Nombre del producto a agregar: "; std::getline(std::cin, prod[k-1].nombre);
                for(int j=0; j<k; j++){
                    if(prod[j].nombre==prod[k-1].nombre){

                        int agregar; /*Aqui se almacena la cantidad a agregar*/
                        char asd='X'; /*Confirmacion*/
                        do{
                            std::cout<<"Cantidad a agregar: "; std::cin>>agregar;
                            std::cout<<"====================================================================\n";
                            std::cout<<"Confirmar esta accion? [S/N]: "; std::cin>>asd;

                            if(asd=='S' || asd=='s'){
                                prod[j].cantidad=prod[j].cantidad+agregar;
                                std::cout<<"Confirmado\n";
                                system("pause"); system("cls");

                            }else if(asd=='N' || asd=='n'){
                                std::cout<<"Operacion cancelada\n";
                                system("pause"); system("cls"); break;

                            }
                        }while(asd!='S' && asd!='s');
                    }else{
                        std::cout<<"El producto no existe, registrelo primero!\n";
                        system("pause"); system("cls");
                    }
                }

                break;
        }
    }while(op!='J' && op!='j');
}