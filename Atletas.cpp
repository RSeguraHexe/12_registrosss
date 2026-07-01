#include<iostream>
#include<string>
#include<cstdlib>

struct Atleta{
    std::string nombre;
    std::string pais;
    std::string disciplina;
    int medallas;
}atle[100];

int main(){

    int n;
    std::cout<<"Cantidad de atletas: "; std::cin>>n;

    system("cls");

    std::cout<<"=====================================================================\n";

    for(int i=0; i<n; i++){

        std::cin.ignore();

        std::cout<<"Atleta ["<<i+1<<"]\n\n";

        std::cout<<"Nombre: "; std::getline(std::cin, atle[i].nombre);
        std::cout<<"País: "; std::getline(std::cin, atle[i].pais);
        std::cout<<"Disciplina: "; std::getline(std::cin, atle[i].disciplina);
        std::cout<<"Medallas: "; std::cin>>atle[i].medallas;
        std::cout<<"=====================================================================\n";

    }

    system("cls");

    std::cout<<"=====================================================================\n";
    std::string temp; /*Almacenare aqui el pais que se va a buscar*/
    std::cin.ignore();
    std::cout<<"\nIngrese un país: "; std::getline(std::cin, temp);
    std::cout<<"=====================================================================\n";

    int cont=0; /*Aqui almacenare la cantidad mayor de medallas*/
    int indice=0; /*Aqui almacenare el indice del atleta con mayor medallas*/

    for(int i=0; i<n; i++){
        
        if(atle[i].pais==temp){
            if(atle[i].medallas > cont){

                cont = atle[i].medallas;
                indice = i;

            }
        }
    }

    std::cout<<"Atleta con mayor medallas del pais "<<temp<<", Atleta ["<<indice+1<<"]\n\n";

    std::cout<<"Nombre: "<<atle[indice].nombre<<"\n";
    std::cout<<"País: "<<atle[indice].pais<<"\n";
    std::cout<<"Disciplina: "<<atle[indice].disciplina<<"\n";
    std::cout<<"Medallas: "<<atle[indice].medallas<<"\n";
    std::cout<<"=====================================================================\n";
    
    system("pause");
    system("cls");

    std::cout<<"=====================================================================\n";

    for(int i=0; i<n; i++){
        if(atle[i].pais==temp){

            std::cout<<"Atleta ["<<i+1<<"]\n\n";
            
            std::cout<<"Nombre: "<<atle[i].nombre<<"\n";
            std::cout<<"País: "<<atle[i].pais<<"\n";
            std::cout<<"Disciplina: "<<atle[i].disciplina<<"\n";
            std::cout<<"Medallas: "<<atle[i].medallas<<"\n";
            std::cout<<"=====================================================================\n";
        }
    }
}