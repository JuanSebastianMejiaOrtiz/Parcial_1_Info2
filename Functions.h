#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Menu
void Programa();

//Crear Matriz
unsigned char*** CreateMatrix(unsigned short filas, unsigned short columnas); //Filas y columnas de la matriz que se va a crear
unsigned char*** FillCursos(short* fil); //L
unsigned char*** FillCursosM(); //L

//Modificar Horario
void AddHTD(); //L
void Add_Act(unsigned char*** horario); //L
void DeleteAct(unsigned char*** horario); //Ez

//Mostrar en Terminal
void PrintHorario(unsigned char*** horario); //Ez

//Uso de Archivos
void SaveHorario(unsigned char*** horario); //Lf
void SaveCursos(unsigned char*** cursos); //Lf

unsigned char*** LoadHorario(unsigned char* id); //L
unsigned char*** LoadCurso(unsigned char* id); //L
unsigned char*** LoadCursosM(unsigned char* id); //L

bool ExisteHorario(unsigned char* id);
bool ExisteCursos(unsigned char* id);

//Obtener datos
short* ObtainHTI(unsigned char*** curso, short fil);
short Credito(unsigned char* cred);
int ContarCaracteres(unsigned char* cadena); //Cuenta los caracteres de una cadena
unsigned char* JuntarChar(unsigned char* id, bool hoc); //hoc 0:horario, 1:curso

#endif