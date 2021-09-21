/*
 * contagio.c
 *
 *  Created on: 14 may. 2020
 *      Author: Vania Z, Emiliano T, Vladimir V
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 40

typedef enum
{
    VACIO, SANO, ENFERMO, RECUPERADO
} PRESSTAT;
typedef enum
{
    CON, SIN
}MASCARA;
typedef struct
{
    PRESSTAT status;
    int Di;
    int Ed;
    int Id;
    MASCARA cubrebocas;
} PERSONA;
typedef struct
{
    PERSONA persona;
    PRESSTAT status;
    int dias;
} CELDA;


void printmat(PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM],int porcentaje);
void CICLO(PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM]);
void SANOS (PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM], int porcentaje);
void CASILLAS(PERSONA m1[TAM][TAM]);
void MOVIMIENTO(PERSONA m1[TAM][TAM],PERSONA m2[TAM][TAM],int intentos);

int main()
{

    int porcentaje;
    int p;

    PERSONA M[TAM][TAM], C[TAM][TAM];

    setbuf(stdout,NULL);
    fflush(stdin);
    srand(time(NULL));

    printf("¿Cuál será el porcentaje de personas en la que empezará la matriz?: \n");
    scanf("%d",&porcentaje);
    printmat(M,C,porcentaje);
    printf("\n Presiona 0 para generar una nueva iteración:\n ");
    scanf("%d", &p);
    do
    {
        CICLO(M,C);
        MOVIMIENTO(M,C,100);
        printf("\n Presiona 0 para generar una nueva iteración:\n");
        scanf("%d",&p);

    } while(p==0);

}
//FUNCIÓN QUE IMPRIME LA MATRIZ INICIAL
void printmat(PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM],int porcentaje)
{
    SANOS(m1,m2,porcentaje);

    int i = 1 + rand() % +TAM;
    int j = 1 + rand() % +TAM;
    m1[i][j].status = ENFERMO;

    for (int i = 1; i < TAM - 1; i++)
    {
        for (int j = 1; j < TAM - 1; j++)
        {
            switch (m1[i][j].status)
            {
                case VACIO:
                    printf("  ");
                    break;
                case SANO:
                    switch (m1[i][j].cubrebocas)
                    {
                        case CON:
                            printf("s ");
                            break;
                        case SIN:
                            printf("S ");
                            break;
                    }
                    break;
                case ENFERMO:
                    switch (m1[i][j].cubrebocas)
                    {
                        case CON:
                            printf("estoy ");
                            break;
                        case SIN:
                            printf("Estoy ");
                            break;
                    }
                    break;
                case RECUPERADO:
                    printf("r ");
            }
        }
        printf("\n");
    }
}
//FUNCIÓN QUE GENERA CADA CICLO
void CICLO(PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM])
{
    int xr, xl, yu, yl;
    for (int i = 1; i < TAM - 1; i++)
    {
        for (int j = 1; j < TAM - 1; j++)
        {
            int probabilidad;
            int dias = 0;
            xr = j + 1;
            xl = j - 1;
            yu = i - 1;
            yl = i + 1;
            if (m1[yu][xl].status == ENFERMO)
            {
                if (m1[yu][xl].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                }
                else if (m1[yu][xl].cubrebocas == SIN
                         || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yu][xl].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[i][xl].status == ENFERMO)
            {
                if (m1[i][xl].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[i][xl].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[i][xl].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[yl][xl].status == ENFERMO)
            {
                if (m1[yl][xl].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[yl][xl].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yl][xl].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad) {
                    dias++;
                }
            }
            if (m1[yu][j].status == ENFERMO) {
                if (m1[yu][j].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[yu][j].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yu][j].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[yl][j].status == ENFERMO)
            {
                if (m1[yl][j].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[yl][j].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yl][j].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[yu][xr].status == ENFERMO)
            {
                if (m1[yu][xr].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[yu][xr].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yu][xr].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[i][xr].status == ENFERMO)
            {
                if (m1[i][xr].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[i][xr].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[i][xr].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if (m1[yl][xr].status == ENFERMO)
            {
                if (m1[yl][xr].cubrebocas == CON
                    && m1[i][j].cubrebocas == CON)
                {
                    probabilidad = 6;
                } else if (m1[yl][xr].cubrebocas == SIN
                           || m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 20;
                } else if (m1[yl][xr].cubrebocas == SIN
                           && m1[i][j].cubrebocas == SIN)
                {
                    probabilidad = 60;
                }
                if (rand() % 100 <= probabilidad)
                {
                    dias++;
                }
            }
            if(m1[i][j].status == ENFERMO)
            {
                m2[i][j].status = ENFERMO;
                if(m1[i][j].Di == 7)
                {
                    m2[i][j].status = RECUPERADO;
                }
                m2[i][j].Di++;
            }

            if(m1[i][j].status == SANO)
            {
                if(dias > 0)
                {
                    m2[i][j].status = ENFERMO;
                }
                else
                    m2[i][j].status = SANO;
            }
            if(m1[i][j].status == VACIO)
            {
                m2[i][j].status = VACIO;
            }
        }
    }
    for(int i = 1; i < TAM-1; i++)
    {
        for(int j = 1; j < TAM-1; j++)
        {
            m1[i][j].status = m2[i][j].status;
            m1[i][j].Di = m2[i][j].Di;
        }
    }
    CASILLAS(m1);
}
//FUNCIÓN QUE GENERA LAS PERSONAS SANAS QUE HABRÁ EN LA MATRIZ INCIAL
void SANOS (PERSONA m1[TAM][TAM], PERSONA m2[TAM][TAM], int porcentaje)
{
    int id = 1;
    int aa;
    for (int i = 1; i < TAM - 1; i++)
    {
        for (int j = 1; j < TAM - 1; j++)
        {
            m1[i][j].Di = 0;
            m2[i][j].Di = 0;
            int persona = rand() % 101;
            if (persona >= 100-porcentaje)
            {
                m1[i][j].status = SANO;
            }
            else
                m1[i][j].status = VACIO;
            m1[i][j].Id = id;
            m2[i][j].Id = id;
            id++;
            aa = rand() & 91;
            m1[i][j].Ed = aa;
            m2[i][j].Ed = aa;
            m1[i][j].cubrebocas = rand() % 2;
            m2[i][j].cubrebocas = rand() % 2;
        }
    }
}

//FUNCIÓN QUE IMPRIME QUÉ HABRÁ EN CADA CELDA DE LA MATRIZ
void CASILLAS(PERSONA m1[TAM][TAM])
{
    for (int i = 1; i < TAM - 1; i++)
    {
        for (int j = 1; j < TAM - 1; j++)
        {
            switch (m1[i][j].status)
            {
                case VACIO:
                    printf("  ");
                    break;
                case SANO:
                    switch (m1[i][j].cubrebocas)
                    {
                        case CON:
                            printf("s ");
                            break;
                        case SIN:
                            printf("S ");
                            break;
                    }
                    break;
                case ENFERMO:
                    switch (m1[i][j].cubrebocas)
                    {
                        case CON:
                            printf("e ");
                            break;
                        case SIN:
                            printf("E ");
                            break;
                    }
                    break;
                case RECUPERADO:
                    printf("r ");
            }
        }
        printf("\n");
    }
}
//FUNCIÓN QUE GENERA EL MOVIMIENTO DE LAS PERSONAS DENTRO DE LA MATRIZ.
void MOVIMIENTO(PERSONA m1[TAM][TAM],PERSONA m2[TAM][TAM],int intentos)
{
    int z,j,i;
    int xr,xl,yu,yl;
    //printf("Entró");

    for(z=0;z<intentos;z++)
    {
        //printf("%d\n",z);
        i=rand() %TAM;
        j=rand() %TAM;
        m2[i][j].status=m1[i][j].status;
        m2[i][j].cubrebocas=m1[i][j].cubrebocas;

        if(m1[i][j].status!=VACIO)
        {
            xr = j + 1;
            xl = j - 1;
            yu = i - 1;
            yl = i + 1;

            if(xr>TAM)
            {
                xr=TAM;
            }
            if(xl<TAM)
            {
                xl=TAM;
            }
            if(yu<TAM)
            {
                yu=TAM;
            }
            if(yl>TAM)
            {
                yl=TAM;
            }

            if (m1[yu][xl].status == VACIO)
            {
                //printf("Vacio1\n");
                m1[i][j].status=VACIO;
                m1[yu][xl].status=m2[i][j].status;
                m1[yu][xl].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[i][xl].status == VACIO)
            {
                //printf("Vacio2\n");
                m1[i][j].status=VACIO;
                m1[i][xl].status=m2[i][j].status;
                m1[i][xl].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[yl][xl].status == VACIO)
            {
                //printf("Vacio3\n");
                m1[i][j].status=VACIO;
                m1[yl][xl].status=m2[i][j].status;
                m1[yl][xl].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[yu][j].status == VACIO)
            {
                //printf("Vacio4\n");
                m1[i][j].status=VACIO;
                m1[yu][j].status=m2[i][j].status;
                m1[yu][j].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[yl][j].status == VACIO)
            {
                //printf("Vacio5\n");
                m1[i][j].status=VACIO;
                m1[yl][j].status=m2[i][j].status;
                m1[yl][j].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[yu][xr].status == VACIO)
            {
                //printf("Vacio6\n");
                m1[i][j].status=VACIO;
                m1[yu][xr].status=m2[i][j].status;
                m1[yu][xr].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[i][xr].status == VACIO)
            {
                //printf("Vacio7\n");
                m1[i][j].status=VACIO;
                m1[i][xr].status=m2[i][j].status;
                m1[i][xr].cubrebocas=m2[i][j].cubrebocas;
            }
            else if (m1[yl][xr].status == VACIO)
            {
                //printf("Vacio8\n");
                m1[i][j].status=VACIO;
                m1[yl][xr].status=m2[i][j].status;
                m1[yl][xr].cubrebocas=m2[i][j].cubrebocas;
            }
        }
    }
}


