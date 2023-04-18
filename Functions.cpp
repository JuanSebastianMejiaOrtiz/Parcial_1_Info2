#include "Functions.h"

//Crear Matriz
unsigned char*** CreateMatrix(unsigned short filas, unsigned short columnas){
    //Le asigna espacio a la matriz
    unsigned char*** a = new unsigned char** [filas];
    
    //A cada fila le crea dim columnas
    for (unsigned short i = 0; i < filas; i++){
        a[i] = new unsigned char* [columnas];
        for (unsigned short j = 0; j < columnas; j++){
            a[i][j] = new unsigned char[65];
            a[i][j][0] = '\0';
        }
    }

    return a;
}

void AddHTD(){
    //Se van a agregar las HTD
    //HTD : Horas de Trabajo del Docente
}

unsigned char*** FillCursos(short* fil){
    //Se va a llenar la matriz de cursos
    unsigned char*** cursos;
    short  caracteres = 65, filas, columnas = 7;
    bool lab = 0;
    char cad[65] = "";

    cout << "Ingrese la cantidad de cursos que tiene matriculados : ";
    cin >> filas;
    *fil = filas;

    cursos = CreateMatrix(filas, 7);

    for (unsigned short f = 0; f < filas; f++){
        cout << "La materia que va a ingresar tiene laboratorio? (0/1 (No/Si)): ";
        cin >> lab;
        for (unsigned short c = 0; c < columnas; c++){
            if (c == 0){
                cout << "Ingrese el codigo de la materia " << f+1 << " : ";
                cin >> cad;
            }
            else if (c == 1){
                cout << "Ingrese el nombre de la materia " << f+1 << " (en vez de espacio ponga guión '-') (hasta 64 caracteres): ";
                cin >> cad;
            }
            else if (c == 2){
                cout << "Ingrese los dias que le toca esa materia " << f+1 << " (sin contar laboratorios) (L:Lunes, M:Martes, W:Miercoles, J:Jueves, V:Viernes, S:Sabado, D:Domingo) (ejm: L-W-V): ";
                cin >> cad;
            }
            else if (c == 3){
                cout << "Ingrese de que hora hasta que hora le toca la materia " << f+1 << " (desde las 8 hasta las 22) (ejm: 14-16): ";
                cin >> cad;
            }
            else if (c == 4){
                if (lab){
                    cout << "Ingrese los dias que le toca laboratorio de la materia " << f+1 << " (L:Lunes, M:Martes, W:Miercoles, J:Jueves, V:Viernes, S:Sabado, D:Domingo) (ejm: J-V): ";
                    cin >> cad;
                }
                else cad[0] = '\0';
            }
            else if (c == 5){
                if (lab){
                    cout << "Ingrese de que hora hasta que hora le toca el laboratorio de la materia " << f+1 << " (desde las 8 hasta las 22) (ejm: 12-14): ";
                    cin >> cad;
                }
                else cad[0] = '\0';
            }
            else if (c == 6){
                cout << "Ingrese la cantidad de creditos de la materia " << f+1 << " : ";
                cin >> cad;
            }
            for (unsigned short i = 0; cad[i]!='\0'; i++){
                cursos[f][c][i] = cad[i];
            }
            cursos[f][c][caracteres] = '\0';
        }
    }
    return cursos;
}


//Modificar Horario
void Add_Act(unsigned char*** horario);
void DeleteAct(unsigned char*** horario);

//Mostrar en Terminal
void PrintHorario(unsigned char*** horario);

//Uso de Archivos
void SaveHorario(unsigned char*** horario);
void SaveCursos(unsigned char*** curso);
unsigned char*** LoadHorario(char* id);
unsigned char*** LoadCursos(char* id);
bool ExisteHorario(char* id);
bool ExisteCursos(char* id);

//Obtener datos
short ObtainCredito(unsigned char* cred);

int ContarCaracteres(unsigned char* cadena){
    int i;
    for (i = 0; *(cadena+i) != '\0'; i++){}
    return i;
}

unsigned char* JuntarChar(unsigned char* id, bool hoc){
    int numcharID = ContarCaracteres(id), i;
    unsigned char* a;

    if(hoc){
        a = new unsigned char[5+4+numcharID];

        a[0] = 'c';
        a[1] = 'u';
        a[2] = 'r';
        a[3] = 's';
        a[4] = 'o';

        for (i = 0; i < numcharID; i++){
            a[5+i] = *(id + i);
        }
        a[5+numcharID+0] = '.';
        a[5+numcharID+1] = 't';
        a[5+numcharID+2] = 'x';
        a[5+numcharID+3] = 't';
    }
    else{
        a = new unsigned char[7+4+numcharID];

        a[0] = 'h';
        a[1] = 'o';
        a[2] = 'r';
        a[3] = 'a';
        a[4] = 'r';
        a[5] = 'i';
        a[6] = 'o';

        for (i = 0; i < numcharID; i++){
            a[7+i] = *(id + i);
        }
        a[7+numcharID+0] = '.';
        a[7+numcharID+1] = 't';
        a[7+numcharID+2] = 'x';
        a[7+numcharID+3] = 't';
    }
    return a;
}