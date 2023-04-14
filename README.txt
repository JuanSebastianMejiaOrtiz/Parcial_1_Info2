Gracias por usar nuestro programa :}
ProgramaME (pre alfa)

Este programa le pedirá al usuario las materias que tiene matriculadas en el semestre, luego le crea un horario para la semana.

Como funciona (Funciones que utiliza) :
- Programa : Todas las funciones y las variables se reunen en un menu de opciones para realizar las operaciones del programa.

- CreateMatrix : Pide 2 unsigned short para las filas y las columnas, le reserva el espacio de memoria a la matriz de char array.

- FillCursos : Le pide la informacion de los cursos y la guarda en una matriz (Por defecto llamada cursos).

- AddHTD : Agrega las Horas de Trabajo del Docente a una matriz (Por defecto llamada horario).

- Add_Act : Le pide al usuario las actividades extra que realiza para agregarlas a "horario", se utiliza para las Horas de Trabajo Individual y para las Actividades Extra que agregue el usuario.

- DeleteAct : Le pide al usuario que parte de su horario desea liberar y le pone "" a la posicion del horario que puso.

- PrintHorario : Le muestra al usuario el horario en la pantalla.

- SaveHorario : Esta escribe el horario en un archivo de texto, este archivo va a tener por nombre "horarioID.txt" donde ID se cambia por la identificacion del usuario.

- SaveCursos : Esta escribe el cursos en un archivo de texto, este archivo va a tener por nombre "cursosID.txt" donde ID se cambia por la identificacion del usuario.

- LoadHorario : Se va a cargar el archivo de texto "horarioID.txt" y se va a guardar su informacion en la matriz "horario".

- LoadCursos : Se va a cargar el archivo de texto "cursosID.txt" y se va a guardar su informacion en la matriz "cursos".

- ExisteHorario : Comprueba si "horarioID.txt" existe, si es verdadero retorna 1, si no retorna 0.

- ExisteCursos : Comprueba si "cursosID.txt" existe, si es verdadero retorna 1, si no retorna 0.

- ObtainCredito : Revisa la cadena que representa la cantidad de creditos de una materia y retorna un short con la cantidad de creditos de la materia.

- ContarCaracteres : Cuenta la cantidad de caracteres que tiene una cadena y retorna un int.