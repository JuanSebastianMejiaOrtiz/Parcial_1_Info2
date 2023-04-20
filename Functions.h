#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Menu
void Programa();

//Crear Matriz
unsigned char*** CreateMatrix(unsigned short filas, unsigned short columnas);   //Filas y columnas de la matriz que se va a crear
unsigned char*** FillCursos(short* fil);
unsigned char*** FillCursosA(short* fil);

//Modificar Horario
void AddHTD(unsigned char*** horario, unsigned char *** cursos, short cfil);
void Add_Act(unsigned char*** horario);
void DeleteAct(unsigned char*** horario);

//Mostrar en Terminal
void PrintHorario(unsigned char*** horario);

//Uso de Archivos
void SaveHorario(unsigned char*** horario, unsigned char* id);
void SaveCursos(unsigned char*** cursos, short fil, unsigned char* id);

unsigned char*** LoadHorario(unsigned char* id);
unsigned char** LoadCursosA(int numeroLinea);
unsigned char** LoadCurso(unsigned char* code);

bool ExisteHorario(unsigned char* id);
bool ExisteCursos(unsigned char* id);

//Obtener datos
short* ObtainHTI(unsigned char*** curso, short fil);
short Credito(unsigned char* cred);
int ContarCaracteres(unsigned char* cadena);    //Cuenta los caracteres de una cadena
unsigned char* JuntarChar(unsigned char* id, bool hoc); //hoc 0:horario, 1:curso
short* SacarHoras(unsigned char* chora);

#endif