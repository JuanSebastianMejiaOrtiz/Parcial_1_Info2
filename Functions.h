#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Menu
void Programa();

//Crear Matriz
unsigned char*** CreateMatrix(unsigned short filas, unsigned short columnas);
void FillCursos(unsigned char*** cursos);

//Modificar Horario
void AddHTD(unsigned char*** horario);
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
short ObtainCredito(unsigned char*** curso);
int ContarCaracteres(char* cadena);

#endif