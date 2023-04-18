#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
using namespace std;

//Menu
void Programa();

//Crear Matriz
<<<<<<< HEAD
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
=======
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
>>>>>>> e5ad702588acede14ff716883e7a50d333cf14ee

#endif