#include "Functions.h"

//Crear Matriz
unsigned char** CreateMatrix(unsigned short filas, unsigned short columnas){
    //Le asigna espacio a la matriz
    unsigned char** a = new unsigned char* [filas];
    
    //A cada fila le crea dim columnas
    for (unsigned short i = 0; i < filas; i++) a[i] = new unsigned char [columnas];
    
    return a;
}

void AddHTD(unsigned char** horario, unsigned char** cursos){
    //Se van a agregar las HTD
    //HTD : Horas de Trabajo del Docente

    /*
    for (unsigned short f = 0; f < filas; f++){
        for (unsigned short c = 0; c < columnas; c++){

        }
    }
    */
}

void FillCursos(unsigned char** cursos){
    char filas, columnas = 6;
    char cad;
    //Se va a llenar la matriz de cursos

    cout << "Ingrese la cantidad de cursos que tiene matriculados : ";
    cin >> filas;

    for (unsigned short f = 0; f < filas; f++){
        for (unsigned short c = 0; c < columnas; c++){
            if (c == 0){
                cout << "Ingrese el nombre de la materia " << f+1 << " : ";
                cin >> cad;
                *(*(cursos + f) + c) = cad;
            }
        }
    }
}

void BPrintMatrix(bool** matriz, unsigned short fil, unsigned short col){
    for (unsigned short f = 0; f < fil; f++){
        for (unsigned short c = 0; c < col; c++){
            if (matriz[f][c] == 0) cout << "-  ";
            else cout << "+  ";
        }
        cout << endl;
    }
}


//Modificar Horario
void AddHTD(unsigned char** horario);
void DeleteAct(unsigned char** horario);
//Esto creo que se va
void AddOther(unsigned char** horario);
void AddHTI(unsigned char** horario);

//Mostrar en Terminal
void PrintHorario(unsigned char** horario);

//Uso de Archivos
void SaveHorario(unsigned char** horario);
void SaveCursos(unsigned char** curso);
unsigned char** LoadHorario();

//Obtener datos
char ObtainCredito(unsigned char** curso);