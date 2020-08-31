#include <stdio.h>
#include <stdlib.h>

#define ERROR_ARCH 1
#define TAM_VEC_EMP 8


typedef struct
{
   int legajo;
   char apyn[101];
   float sueldo;
   int tituloUniv;
}
Empleado;

int main()
{
    Empleado vecEmp[TAM_VEC_EMP]=
    {
        {432,"Perez, Juan",40000,1}, {123,"Rodriguez, Ariel",50000,0}, {247,"Bermudez, Alejandro",60000,0}, {564,"Alvarez, Alberto",45000,1},
        {999,"Casares, Carlos",70000,1}, {444,"Damasco, Daniel",65000,0}, {111, "Garcia, Gabriel",80000,1}, {333,"Fernandez, Alberto",100000,0}
    };
    FILE* archEmp = fopen("Empleados.dat","wb");

        if(!archEmp)
        {
            puts("ERROR ABRIENDO ARCHIVO");
            return ERROR_ARCH;
        }

            fwrite(vecEmp, sizeof(Empleado), TAM_VEC_EMP, archEmp);
            fclose(archEmp);


/*Empleado emp;

       FILE* archEmp = fopen("Empleados.dat","rb");

        if(!archEmp)
            {
                puts("ERROR ABRIENDO ARCHIVO");
                return ERROR_ARCH;
            }

            fread(&emp, sizeof(Empleado), 1, archEmp);
                while(!feof(archEmp))
                      {
                         printf("[Legajo: %d, Apellido y Nombre: %s, Sueldo: %.2f, Titulo: %s]\n", emp.legajo,emp.apyn,emp.sueldo,emp.tituloUniv? "SI":"NO");
                         fread(&emp, sizeof(Empleado), 1, archEmp);
                      }
*/


 /*       FILE* archEmp = fopen("Empleados.dat","r+b"); //EL + SIGNIFICA QUE EL ARCHIVO SE ABRE EN MODO LECTURA Y ESCRITURA, EN SIMULTANEO. SI TIENE W+, SE CREA EL ARCHIVO SI NO EXISTE. Y SI EXISTE, LO VA A PISAR PERDIENDO LOS DATOS.

        if(!archEmp)
            {
                puts("ERROR ABRIENDO ARCHIVO");
                return ERROR_ARCH;
            }

            fread(&emp, sizeof(Empleado), 1, archEmp);
                while(!feof(archEmp))
                      {
                         if(emp.tituloUniv)
                            emp.sueldo*=1.30; //INCREMENTO DEL 30% SI TIENE TITULO
                         else
                            emp.sueldo*=1.20; //INCREMENTO DEL 20% SI NO TIENE TITULO

                         fseek(archEmp, -sizeof(Empleado), SEEK_CUR); //HACE UN DESPLAZAMIENTO NEGATIVO (HACIA ATRAS)
                         fwrite(&emp, sizeof(Empleado), 1, archEmp);
                         fseek(archEmp, 0L, SEEK_CUR); //NOS DESPLAZAMOS DESDE LA POSICION 0
                         fread(&emp, sizeof(Empleado), 1, archEmp);
                      }
*/

        //fclose(archEmp);
    return 0;
}
