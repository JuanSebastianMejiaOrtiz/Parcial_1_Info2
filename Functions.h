#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Crear Matriz
unsigned char** CreateMatrix(unsigned short filas, unsigned short columnas);
void FillCursos(unsigned char** cursos);

//Modificar Horario
void AddHTD(unsigned char** horario);
void Add_Act(unsigned char** horario);
void DeleteAct(unsigned char** horario);

//Mostrar en Terminal
void PrintHorario(unsigned char** horario);

//Uso de Archivos
void SaveHorario(unsigned char** horario);
void SaveCursos(unsigned char** curso);
unsigned char** LoadHorario();

//Obtener datos
char ObtainCredito(unsigned char** curso);



#endif