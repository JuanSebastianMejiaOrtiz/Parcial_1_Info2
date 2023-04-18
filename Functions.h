#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Menu
void Programa();

//Crear Matriz
unsigned char*** CreateMatrix(unsigned short filas, unsigned short columnas); //W
unsigned char*** FillCursos(short* fil); //W

//Modificar Horario
void AddHTD(); //L
void Add_Act(unsigned char*** horario); //L
void DeleteAct(unsigned char*** horario); //Ez

//Mostrar en Terminal
void PrintHorario(unsigned char*** horario); //Ez

//Uso de Archivos
void SaveHorario(unsigned char*** horario); //Lf
void SaveCursos(unsigned char*** curso); //Lf
unsigned char*** LoadHorario(char* id); //L
unsigned char*** LoadCursos(char* id); //L
bool ExisteHorario(char* id); //Ez
bool ExisteCursos(char* id); //Ez

//Obtener datos
short ObtainCredito(unsigned char*** curso); //Ez
int ContarCaracteres(unsigned char* cadena); //W
unsigned char* JuntarChar(char* id, bool hoc); //hoc 0:curso, 1:horario

#endif