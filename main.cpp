#include <iostream>
#include <random>
#include <array>

std::random_device rd;
std::mt19937 gen(rd());

//Definicion de Metodos
void numeroMagico(int numberA, int numberB);

void tablaNum(int number);

void showMenu();

void caseMagicNumber();

void caseVector();

void caseTable();

//Metodo Pricipal
int main() {
    int option;
    bool isRepeat = true;
    do {
        showMenu();
        std::cin >> option;
        switch (option) {
            case 1:
               caseMagicNumber();
                break;
            case 2:
               caseTable();
                break;
            case 3:
                caseVector();
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

//Case para imprimir tabla
void caseTable(){
    int numberTable;
    std::cout << "Ingrese un numero de tabla que desee" << std::endl;
    std::cin >> numberTable;
    tablaNum(numberTable);
}

//Opciones de Menu
void showMenu() {
    std::cout << "\n\nMenu de Opciones" << std::endl;
    std::cout << "1. Numero Magico" << std::endl;
    std::cout << "2. Tablas" << std::endl;
    std::cout << "3. Vectores" << std::endl;
    std::cout << "4. Salir" << std::endl;
}

//Funcion numero Magico
void caseMagicNumber(){
    int numberA;
    int numberB;
    std::cout << "Ingrese el Numero inferior del Rango: " << std::endl;
    std::cin >> numberA;
    std::cout << "Ingrese el Numero Superior del Rango: " << std::endl;
    std::cin >> numberB;
    numeroMagico(numberA, numberB);
}


//Funcion para determinar un rango
int random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

//Funcion imprimir tabla de multiplicar
void tablaNum(int number) {
    if (number % 2 == 0) {
        for (int i = 1; i <= 10; i++) {
            std::cout << number << " * " << i << " = " << number * i << std::endl;
        }
    } else {
        for (int i = 10; i >= 1; i--) {
            std::cout << number << " * " << i << " = " << number * i << std::endl;
        }
    }
}

//Funcion numero magico
void numeroMagico(int numberA, int numberB) {
    int randomNumber;
    int number;
    int intentos = 1;
    randomNumber = random(numberA, numberB);
    std::cout << "\n******Adivina el Numero******\n";
    do {
        std::cout << "Ingrese un Numero: ";
        std::cin >> number;
        if (number == randomNumber)
            break;

        if (number > randomNumber)
            std::cout << "El numero debe ser menor\n";
        else {
            std::cout << "El numero debe ser Mayor\n";
        }
        intentos += 1;
    } while (number != randomNumber);
    std::cout << "Adiviniste el Numero: " << randomNumber << " En: " << intentos << " Intentos";
}

//Funcion 3(Vector)
void caseVector(){
    {
        std::vector<int> numbersV{};
        int optionSubmenu;
        do {
            std::cout << "\n\nMenu de Opciones" << std::endl;
            std::cout << "1. Inicializar" << std::endl;
            std::cout << "2. Cargar" << std::endl;
            std::cout << "3. Mostrar" << std::endl;
            std::cout << "4. Salir" << std::endl;
            std::cin >> optionSubmenu;
            switch (optionSubmenu) {
                case 1:
                    int numberVector;
                    std::cout << "Ingrese el numero con el que desea inicializar" << std::endl;
                    std::cin >> numberVector;

                    numbersV = std::vector<int>(3, numberVector);
                    break;
                case 2:
                    for (int i = 0; i < numbersV.size(); ++i) {
                        std::cout << "Ingrese el numero para la posicion: " << i << std::endl;
                        std::cin >> numbersV[i];
                    }
                    break;
                case 3:
                    if(numbersV.empty()){
                        std::cout << "El vector no se ha inicializado" << std::endl;
                    }else{
                        for (auto const &i: numbersV) {
                            std::cout << i << " ";
                        }
                    }

                    break;
                case 4:
                    break;
                default:
                    std::cout << "Ingrese una opcion valida" << std::endl;
                    break;
            }
        } while (optionSubmenu != 4);
    }
}
