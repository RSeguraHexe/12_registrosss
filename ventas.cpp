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

bool existencia (std:: string, int);
int buscarIndice(std::string, int);

int main(){

    int k=0; /*Contador de productos registrados*/

    std::cout<<"====================================================================\n";
    std::cout<<"Registre su primer producto!\n";
    std::cout<<"====================================================================\n";
    std::cout<<"Producto: 1\n\n"; 
    
    std::cout<<"Nombre del producto: "; std::getline(std::cin, prod[k].nombre);
    std::cout<<"Precio del producto: "; std::cin>>prod[k].precio;
    prod[k].cantidad=0; /*Se inicializa la cantidad en 0, ya que no se ha registrado ninguna entrada de productos*/
    std::cout<<"====================================================================\n";
    std::cout<<"Perfecto! Ya tiene su primer producto, presione cualquier tecla para continuar...\n\n";

    k++; /*Se incrementa el contador de productos registrados*/

    system("pause"); system("cls");

    char op='X'; /*Aqui se indicara la opcion seleccionada */

    do{
        system("cls");
        
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
            case 'a':{
                char z='X'; /*Confirmacion*/ 
                do{
                    std::cout<<"====================================================================\n";
                    std::cout<<"Registre un nuevo producto!\n";
                    std::cout<<"====================================================================\n";
                    std::cout<<"Producto ["<<k+1<<"] \n\n";

                    std::cout<<"Nombre del producto: "; std::cin.ignore(); std::getline(std::cin, prod[k].nombre);
                    std::cout<<"Precio del producto: "; std::cin>>prod[k].precio;
                    std::cout<<"====================================================================\n";
                    std::cout<<"Confirmar esta accion? [S/N]: "; std::cin>>z;

                    if(z=='S' || z=='s'){
                        k++; /*Se incrementa el contador de productos registrados*/
                        std::cout<<"Perfecto! Ya tiene su producto registrado, presione cualquier\ntecla para continuar...\n\n";
                        prod[k-1].cantidad=0;   /*Se inicializa la cantidad en 0, ya que no se ha registrado ninguna entrada de productos*/

                        system("pause"); system("cls");

                    }else if(z=='N' || z=='n'){
                        system("cls");
                        break;
                    }
                }while(z!='S' && z!='s');
                break;
            }
            case 'B':
            case 'b':{

                std::string temporal; /*aqui almacenare el nombre del producto a agregar*/
                std::cout<<"====================================================================\n";
                std::cout<<"Agregando productos existentes!\n";
                std::cout<<"====================================================================\n";
                std::cin.ignore();
                std::cout<<"Nombre del producto a agregar: "; std::getline(std::cin, temporal);

                int encontrado=0; /*Variable para saber si se encontro el producto*/
                for(int j=0; j<=k; j++){
                    if(prod[j].nombre==temporal){
                        encontrado=1; /*Se marca que el producto fue encontrado*/

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
                        break;
                    }
                }
                if(encontrado==0){
                    std::cout<<"No se a encontrado el producto...\n";
                }

                break;
            }

            case 'C':
            case 'c':{
                std::cout<<"====================================================================\n";
                std::cout<<"Lista total de productos registrados!\n";
                std::cout<<"====================================================================\n";
                for(int j=0; j<k; j++){
                    std::cout<<"Producto ["<<j+1<<"]\n\n";

                    std::cout<<"Nombre: "<<prod[j].nombre<<"\n";
                    std::cout<<"Precio: "<<prod[j].precio<<"\n";
                    std::cout<<"Cantidad: "<<prod[j].cantidad<<"\n";
                    std::cout<<"====================================================================\n";
                }
                std::cout<<"Presione cualquier tecla para continuar...\n\n";
                system("pause");

                break;
            }

            case 'D':
            case 'd':{
                std::cout<<"====================================================================\n";
                std::cout<<"Busqueda de productos por nombre!\n";
                std::cout<<"====================================================================\n";
                std::string temporal; /*aqui almacenare el nombre del producto a buscar*/
                std::cout<<"Nombre del producto a buscar: "; std::cin.ignore(); std::getline(std::cin, temporal);
                if(existencia(temporal, k)){
                    int indice=buscarIndice(temporal, k);
                    std::cout<<"====================================================================\n";
                    std::cout<<"Producto ["<<indice+1<<"]\n\n";
                    std::cout<<"Nombre: "<<prod[indice].nombre<<"\n";
                    std::cout<<"Precio: "<<prod[indice].precio<<"\n";
                    std::cout<<"Cantidad: "<<prod[indice].cantidad<<"\n";
                    std::cout<<"====================================================================\n";
                    system("pause"); system("cls"); break;
                }else{
                    std::cout<<"====================================================================\n";
                    std::cout<<"No se a encontrado el producto...\n";
                    system("pause"); system("cls"); break;
                }
            }
            case 'E':
            case 'e':{
                std::string temporal; /*aqui almacenare el nombre del producto a actualizar*/
                std::cout<<"====================================================================\n";
                std::cout<<"Nombre del producto a actualizar: "; std::cin.ignore(); std::getline(std::cin, temporal);
                if(existencia(temporal, k)){
                    int indice=buscarIndice(temporal, k);
                    std::cout<<"====================================================================\n";
                    std::cout<<"Producto ["<<indice+1<<"]\n\n";

                    std::cout<<"Nombre: "<<prod[indice].nombre<<"\n";
                    std::cout<<"Precio: "<<prod[indice].precio<<"\n";
                    std::cout<<"Cantidad: "<<prod[indice].cantidad<<"\n";
                    std::cout<<"====================================================================\n";
                    std::cout<<"Desea actualizar el nombre del producto? [S/N]: "; char operacion; std::cin>>operacion;
                    if(operacion=='S' || operacion=='s'){
                        std::cout<<"====================================================================\n";
                        std::cout<<"Ingrese el nuevo nombre del producto: "; std::cin.ignore(); std::getline(std::cin, prod[indice].nombre);
                        std::cout<<"Ingrese el nuevo precio del producto: "; std::cin>>prod[indice].precio;
                        std::cout<<"Ingrese la nueva cantidad del producto: "; std::cin>>prod[indice].cantidad;
                        std::cout<<"====================================================================\n";
                        std::cout<<"Producto actualizado correctamente!\n";
                        system("pause"); system("cls"); break;
                    }
                }else{
                    std::cout<<"====================================================================\n";
                    std::cout<<"No se a encontrado el producto...\n";
                    system("pause"); system("cls");
                }
                break;
            }

            case 'F':
            case 'f':{
                std::string temporal; /*aqui almacenare el nombre del producto a eliminar*/

                std::cout<<"====================================================================\n";
                std::cout<<"Eliminar un producto!\n";
                std::cout<<"====================================================================\n";
                std::cout<<"Nombre del producto a eliminar: "; std::cin.ignore(); std::getline(std::cin, temporal);
                if(existencia(temporal, k)){
                    int indice=buscarIndice(temporal, k);
                    std::cout<<"====================================================================\n";
                    std::cout<<"Producto ["<<indice+1<<"]\n\n";
                    std::cout<<"Nombre: "<<prod[indice].nombre<<"\n";
                    std::cout<<"Precio: "<<prod[indice].precio<<"\n";
                    std::cout<<"Cantidad: "<<prod[indice].cantidad<<"\n";
                    std::cout<<"====================================================================\n";
                    std::cout<<"Desea eliminar este producto? [S/N]: "; std::cin>>temporal;
                    if(temporal=="S" || temporal=="s"){
                        for(int j=indice; j<k-1; j++){
                            prod[j]=prod[j+1];
                        }
                        k--; /*Se decrementa el contador de productos registrados*/
                        std::cout<<"Producto eliminado correctamente!\n";
                        system("pause"); system("cls"); break;
                    }else{
                        std::cout<<"Operacion cancelada\n";
                        system("pause"); system("cls"); break;
                    }
                }else{
                    std::cout<<"====================================================================\n";
                    std::cout<<"No se a encontrado el producto...\n";
                    system("pause"); system("cls"); break;
                }
            }
        }
    }while(op!='J' && op!='j');
}

bool existencia (std:: string a, int k){
    for(int i=0; i<k; i++){
        if(prod[i].nombre==a){
            return true;
        }
    }
    return false;
}

int buscarIndice(std::string a, int k){
    for(int i=0; i<k; i++){
        if(prod[i].nombre==a){
            return i;
        }
    }
    return 0;
}