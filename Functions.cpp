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
            //Modificar
            if (c == 0){
                cout << "Ingrese el codigo de la materia " << f+1 << " : ";
                cin >> cad;
            }
            //Quitar/Modificar
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
            //Quitar/Modificar
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

void DeleteAct(unsigned char*** horario){
    char fi[5], co;
    
    cout << "Ingrese el dia de la actividad que desee eliminar (L:Lunes, M:Martes, W:Miercoles, J:Jueves, V:Viernes, S:Sabado, D:Domingo): ";
    cin >> co;

    cout << "Ingrese la hora que desea eliminar(ejm: 12-14): ";
    cin >> fi;

    
}

//Mostrar en Terminal
void PrintHorario(unsigned char*** horario){
    for (short i = 0; i < 14; i++){
        for (short j = 0; j < 7; j++){
            if (horario[i][j][0]=='\0'){
                cout << "---" << '\t';
            }
            else cout << horario[i][j] << '\t';
        }
        cout << '\n';
    }
}

//Uso de Archivos
void SaveHorario(unsigned char*** horario);
void SaveCursos(unsigned char*** cursos);
unsigned char*** LoadHorario(char* id);

unsigned char** LoadCurso(char* code){
    fstream archivo;
    unsigned char** p = new unsigned char* [2];
    bool flag, materia;
    int temp,j,i;
    
    //PONER UNA VARIABLE EN SU LUGAR (Parametro creo yo)
    archivo.open ("Infocursos.txt", ios_base::in);
    flag = archivo.is_open();
    if (flag){
        const int longitud=66;
        char* linea= new char [longitud];
        while (archivo.getline(linea, longitud)){ 
            temp=0;
            for (i=0;linea[i]!='\t';i++){
                if (*(code+i)==linea[i]) temp++;
            }
            if (temp==i){
                unsigned char* nombre=new unsigned char [50];
                for (j=0;linea[++i]!='\t';j++){
                    nombre[j]=linea[i];
                }
                nombre[j+1]='\0';
                p[0]=nombre;
                unsigned char* creditos=new unsigned char [2];
                for (j=0;linea[++i]!='\n';j++){
                    creditos[j]=linea[i];
                }
                p[1]=creditos;
            }
        }
        archivo.close();
        return p;
    }
    else{
        cout<<"Error en el archivo de cursos"<<endl;
    }
} 

/*
unsigned char** LoadCurso(char* code){
    fstream archivo;
    unsigned char** p = new unsigned char* [2];
    bool flag, materia;
    int temp,j,i;
    archivo.open("C:/Users/cuent/Documents/build-main-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/Infocursos.txt", ios_base::in);
    flag = archivo.is_open();
    if (flag){
        const int longitud=66;
        char* linea= new char [longitud];
        while (archivo.getline(linea, longitud)){
            temp=0;
            for (i=0;linea[i]!='\t';i++){
                if (*(code+i)==linea[i]) temp++;
            }
            if (temp==i){
                unsigned char* nombre=new unsigned char [50];
                for (j=0;linea[++i]!='\t';j++){
                    nombre[j]=linea[i];
                }
                nombre[j+1]='\0';
                p[0]=nombre;
                unsigned char* creditos=new unsigned char [2];
                for (j=0;linea[++i]!='\n';j++){
                    creditos[j]=linea[i];
                }
                p[1]=creditos;
            }
        }
        archivo.close();
        return p;
    }
    else{
        cout<<"Error en el archivo de cursos"<<endl;
    }
}
*/

unsigned char*** LoadCursosM(char* id);

bool ExisteHorario(unsigned char* id){
    int NC_Id = ContarCaracteres(id), i;
    unsigned char* Real = JuntarChar(id, 0);
    char A[7+4+NC_Id+1+3] = "../";
    fstream text;
    bool flag;

    for (i = 0; i < NC_Id+7+4; i++){
        A[i+3] = Real[i];
        A[i+1+3] = '\0';
    }

    text.open(A, ios_base::in);
    flag = text.is_open();
    text.close();

    if (flag) return 1;
    
    return 0;
}

bool ExisteCursos(unsigned char* id){
    int NC_Id = ContarCaracteres(id), i;
    unsigned char* Real = JuntarChar(id, 1);
    char A[5+4+NC_Id+1+3] = "../";
    fstream text;
    bool flag;

    for (i = 0; i < NC_Id+5+4; i++){
        A[i+3] = Real[i];
        A[i+1+3] = '\0';
    }

    text.open(A, ios_base::in);
    flag = text.is_open();
    text.close();

    if (flag) return 1;
    
    return 0;
}

//Obtener datos
short* ObtainHTI(unsigned char*** curso, int fil){
    short* hti = new short [fil];
    short creditox;
    
    for (int i=0;i<fil;i++){
        creditox=Credito(curso[i][6]);
        hti[i]=(creditox*48)/16;
    }
    return hti;
}

short Credito(unsigned char* cred){
    short numcred;
    int temp;
    temp=ContarCaracteres(cred);
    if (temp==1){
        numcred=cred[0]-48;
    }
    else{
        numcred = (cred[0]-48)*10;
        numcred += cred[1]-48;
    } 
    return numcred;
}

int ContarCaracteres(unsigned char* cadena){
    int i;
    for (i = 0; *(cadena+i) != '\0'; i++){}
    return i;
}

unsigned char* JuntarChar(unsigned char* id, bool hoc){
    int numcharID = ContarCaracteres(id), i;
    unsigned char* a;

    //0: Horario
    //1: Curso
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