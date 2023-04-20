#include "Functions.h"

void Programa(){
    unsigned char id[12] = "";
    char menuop[12] ="";
    unsigned char*** horario, curso;
    short numcur = 0, i;
    cout << "Bienvenido :}" << '\n';
    cout << "Ingrese su identificacion : ";
    cin >> id;

    while(true){
        cout << "Que desea hacer hoy? (use /help para ver los comandos disponibles.) : ";
        cin >> menuop;

        //Cargar Horario
        if(menuop=="/hload"){
            //horario = LoadHorario(id);
            cout << "Esta funcion no esta disponible en esta version." << '\n';
        }
        else if(menuop=="/hsave_new"){
            SaveHorario(horario, id);
        }
        else if(menuop=="/cload"){
            //curso = FillCursosA(&numcur);
            cout << "Esta funcion no esta disponible en esta version." << '\n';
        }
        else if(menuop=="/csave" && numcur!=0){
            for (i = 0; i < numcur; i++){
                SaveCursos(*(curso+i), numcur, id);
            }
        }
        else if(menuop=="/ccreate"){
            curso = FillCursos(&numcur);
        }
        else if(menuop=="/hadd"){
            //Add_Act();
            cout << "Esta funcion no esta disponible en esta version." << '\n';
        }
        else if(menuop=="/hdelete"){
            DeleteAct(horario);
        }
        else if(menuop=="/help"){
            cout << "/hload" << '\n';
        }
    }
}

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
    unsigned char** cur;
    short  caracteres = 65, filas, columnas = 7;
    unsigned short i;
    bool lab = 0;
    unsigned char cad[65] = "";

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
                cur = LoadCurso(cad);
            }
            else if (c == 1){
                //Nombre Materia
                for (i = 0; cur[0][i]!='\0'; i++){
                    cad[i] = cur[0][i];
                }
                cad[i] = '\0';
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
                //Creditos
                for (i = 0; cur[1][i]!='\0'; i++){
                    cad[i] = cur[1][i];
                }
                cad[i] = '\0';
            }

            for (i = 0; cad[i]!='\0'; i++){
                cursos[f][c][i] = cad[i];
            }
            cursos[f][c][caracteres] = '\0';
        }
        delete cur;
    }
    return cursos;
}

unsigned char*** FillCursosA(short* fil){

}

//Modificar Horario
void Add_Act(unsigned char*** horario){

}

void DeleteAct(unsigned char*** horario){
    unsigned char fi[5], co;
    short* horas;
    short dias;

    cout << "Ingrese el dia de la actividad que desee eliminar (L:Lunes, M:Martes, W:Miercoles, J:Jueves, V:Viernes, S:Sabado, D:Domingo)(NO L-V; SI L): ";
    cin >> co;

    cout << "Ingrese la hora que desea eliminar(ejm: 12-14): ";
    cin >> fi;
    
    horas = SacarHoras(fi);

    if (co=='L') dias = 0;
    else if (co=='M') dias = 1;
    else if (co=='W') dias = 2;
    else if (co=='J') dias = 3;
    else if (co=='V') dias = 4;
    else if (co=='S') dias = 5;
    else if (co=='D') dias = 6;

    horas[0] -= 8;
    horas[1] -= 9;

    for (short i = 0; i < horas[1]; i++){
        horario[horas[i]][dias][0] = '\0';
    }
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
void SaveHorario(unsigned char** horario, unsigned char id){
    fstream archivo;
    bool existe;
    existe=ExisteHorario(id);
    if (existe){
        cout<<"El horario para este estudiante ya existe, desea sobre-escribirlo? (responda si o no)";
        cin<<a;
    }
    if (a=="si"){
        int NC_Id = ContarCaracteres(id), i;
        unsigned char* Real = JuntarChar(id, 0);
        char A[7+4+NC_Id+1+3] = "../";
        fstream text;
        bool flag;
    
        for (i = 0; i < NC_Id+7+4; i++){
            A[i+3] = Real[i];
            A[i+1+3] = '\0';
        }
        archivo.open(A, ios_base::out);
        for (j=0;j<14;j++){
            for (k=0;k<7;k++){
                archivo << horario[i][j];
                if (k!=6){
                    archivo<<'\t';
                }
            }
            archivo << '\n';     
        }
        archivo.close()      
    }  
}

unsigned char*** LoadHorario(char* id);

void SaveCursos(unsigned char** cursos, short fil, unsigned char* id){
    fstream archivo;
    bool existe;
    existe=ExisteCursos(id);
    if (existe){
        int NC_Id = ContarCaracteres(id), i, j, k;
        unsigned char* Real = JuntarChar(id, 1);
        char A[5+4+NC_Id+1+3] = "../";
        for (i = 0; i < NC_Id+7+4; i++){
            A[i+3] = Real[i];
            A[i+1+3] = '\0';
        }
        archivo.open(A, ios_base::out);
        for (j=0;j<fil;j++){
            for (k=0;k<7;k++){
                archivo<<cursos[i][j];
                if (k!=6){
                    archivo<<'\t';
                }
            }
            archivo << '\n';
        }
        archivo.close();
    }
}

unsigned char** LoadCursosA(int numeroLinea, unsigned char* code){
    fstream archivo;
    int contador=1,j,k,z,x,c,v,l,I;  
    unsigned char** p = new unsigned char* [7];
    // todo va a estar separado por tabulaciones codigo nombre creditos dias horas diaslaboratorio horaslaboratorio
    bool flag;
    int NC_Id = ContarCaracteres(code);
    unsigned char* Real = JuntarChar(code, 1);
    char A[7+4+NC_Id+1+3] = "../";

    for (I = 0; I < NC_Id+7+4; I++){
        A[I+3] = Real[I];
        A[I+1+3] = '\0';
    }
    delete Real;
    
    archivo.open(A, ios_base::in);
    flag=archivo.is_open();
    if (flag){
        const int longitud=66;
        char* linea= new char [longitud];
        while (archivo.getline(linea, longitud)){
            if (contador == numeroLinea){
               unsigned char* code=new unsigned char [11];
                for (j=0;linea[j]!='\t';j++){
                    code[j]=linea[j];
                }
                code[j+1]='\0';
                p[0]=code;
                unsigned char* nombre=new unsigned char [51];
                for (k=0;linea[++j]!='\t';k++){
                    nombre[k]=linea[j];
                }
                nombre[k+1]='\0';
                p[1]=nombre;
                unsigned char* cred=new unsigned char [3];
                for (l=0;linea[++j]!='\t';l++){
                    cred[l]=linea[j];
                }
                cred[l+1]='\0';
                p[6]=cred;
                unsigned char* dias=new unsigned char [14];
                for (z=0;linea[++j]!='\t';z++){
                    dias[z]=linea[j];
                }
                dias[z+1]='\0';
                p[2]=dias;
                unsigned char* horas=new unsigned char [6];
                for (x=0;linea[++j]!='\t';x++){
                    horas[x]=linea[j];
                }
                horas[x+1]='\0';
                p[3]=horas;
                unsigned char* diaslab=new unsigned char [3];
                for (c=0;linea[++j]!='\t';c++){
                    diaslab[c]=linea[j];
                }
                diaslab[c+1]='\0';
                p[4]=diaslab;
                unsigned char* horaslab=new unsigned char [6];
                for (v=0;linea[++j]!='\t';v++){
                    horaslab[v]=linea[j];
                }
                horaslab[v+1]='\0';
                p[5]=horaslab;
                archivo.close();
                return p;
            }
            contador++;
        }   
        archivo.close();
        p[0][0]='\0';
        return p; 
    }
    else{
        cout<<"ERROR abriendo el archivo"<<endl;
        p[0][0]='\0';
        return p;
    }    
} 

unsigned char** LoadCurso(unsigned char* code){
    //Carga la informacion de un solo curso
    fstream archivo;
    unsigned char** p = new unsigned char* [2];
    bool flag;
    int temp,j,i;
    int NC_Id = ContarCaracteres(code);
    unsigned char* Real = JuntarChar(code, 1);
    char A[7+4+NC_Id+1+3] = "../";

    for (i = 0; i < NC_Id+7+4; i++){
        A[i+3] = Real[i];
        A[i+1+3] = '\0';
    }
    delete Real;
    
    archivo.open (A, ios_base::in);
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
        p[0][0] = '\0';
        p[1][0] = '\0';
    }
    return p;
}

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
    if (cadena[1] == '\0') return 1;
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

short* SacarHoras(unsigned char* chora){
    short* array = new short[2];
    unsigned char hora1[3], hora2[3];
    int i, j;

    for (i = 0; chora[i]!='-'; i++){
        hora1[i] = chora[i];
        hora1[i+1] = '\0';
    }
    i++;

    for (j = 0;chora[i]!='\0'; i++, j++){
        hora2[j] = chora[i];
        hora2[j+1] = '\0';
    }

    array[0] = Credito(hora1);
    array[1] = Credito(hora2);

    return array;
}