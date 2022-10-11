#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

void numeroMagico(int numberA, int numberB);
void tablaNum(int number);

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int main() {
    int option;
    bool isRepeat = true;
    do {
        std::cout << "\n\nMenu de Opciones" << std::endl;
        std::cout << "1. Numero Magico" << std::endl;
        std::cout << "2. Tablas" << std::endl;
        std::cout << "3. Vectores" << std::endl;
        std::cout << "4. Salir" << std::endl;

        std::cin >> option;
        switch (option) {
            case 1:
                int numberA;
                int numberB;
                std::cout << "Ingrese el Numero inferior del Rango: " << std::endl;
                std::cin >> numberA;
                std::cout << "Ingrese el Numero Superior del Rango: " << std::endl;
                std::cin >> numberB;
                numeroMagico(numberA, numberB);
                break;
            case 2:
                int numberTable;
                std::cout << "Ingrese un numero de tabla que desee" << std::endl;
                std::cin >> numberTable;
                tablaNum(numberTable);
                break;
            case 3:
                std::cout << "Opcion 2";
                break;
            case 4:
                isRepeat = false;
                break;
            default:
                std::cout << "Ingrese una opcion valida";
        }
    } while (isRepeat);
    return 0;
}

void tablaNum(int number){
    if(number%2 ==0){
        for(int i=1; i<=10; i++){
            std::cout<<number<<" * "<<i<<" = "<<number * i<<std::endl;
        }
    }else{
        for(int i=10; i>=1; i--){
            std::cout<<number<<" * "<<i<<" = "<<number * i<<std::endl;
        }
    }
}


void numeroMagico(int numberA, int numberB) {
    int randomNumber;
    int number;
    int intentos = 1;
    randomNumber = random(numberA, numberB);
    std::cout<<"\n******Adivina el Numero******\n";
    do{
        std::cout<<"Ingrese un Numero: ";
        std::cin >> number;
        if(number == randomNumber)
            break;

        if(number > randomNumber)
            std::cout<<"El numero debe ser menor\n";
        else {
            std::cout<<"El numero debe ser Mayor\n";
        }
        intentos+=1;
    } while (number != randomNumber);
    std::cout<<"Adiviniste el Numero: " << randomNumber << " En: " << intentos << " Intentos";
}
