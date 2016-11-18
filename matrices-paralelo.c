#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

typedef struct
{
    int shmid;
    int filas, columnas;
    float **coef;

} matriz;
//{}  ()  []

matriz *crear_matriz(int filas, int columnas)
{
    int shmid, i;
    matriz *m;
//peticion de memoria compartida
    shmid=shmget( IPC_PRIVATE, sizeof (matriz)+ filas * sizeof(float * )+ filas*columnas*sizeof(float ),IPC_CREAT|0600  );


    if( shmid==-1)
    {
        perror("*crear_matriz(shmget)uuuuu");
        exit(-1);

    }
    
    if((m=(matriz *)shmat(shmid,0,0))==(matriz *)-1){
		perror("crear_matriz(shmdt)");
		exit(-1);
	}
		
    m->shmid=shmid;
    m->filas=filas;
    m->columnas=columnas;

    m->coef=(float **)&m->coef +sizeof(float **);
    for(i=0; i<filas; i++ )
    {
        m->coef[i]=(float *)&m->coef[filas]+i*columnas*sizeof(float);
        
    }  
    return m;

}

matriz *leer_matriz()
{
    int filas,columnas,i,j;
    matriz *m;


    printf("filas: ");
    scanf("%d",&filas);
    printf("columnas");
    scanf("%d",&columnas);
    m=crear_matriz(filas,columnas);
 
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            scanf("%f",&m->coef[i][j]);
        }  
    }
  
    return m;
}



matriz *multiplicar_matrices (matriz *a, matriz *b, int numproc)
{
    printf("multiplicando");
    int p,semid,estado;
    matriz *c;
    if(a->columnas!=b->filas)
    {
        return NULL;
    }
    c=crear_matriz(a->filas,b->columnas);
    semid=semget(IPC_PRIVATE,2,IPC_CREAT|0600);
    if(semid==-1)
    {
		printf("aki valio");
		
        perror("multiplicar_matrices(semget)");
        exit(-1);
    }
    
    semctl(semid,0,SETVAL,1);
    semctl(semid,1,SETVAL,c->filas+1);

    for(p=0; p<numproc; p++)
    {
        if(fork()==0)
        {

            int i,j,k;
            struct sembuf operacion;

            operacion.sem_flg=SEM_UNDO;

            while(1)
            {
				
 		        printf("while...");
                operacion.sem_num=0;
                operacion.sem_op=-1;
                semop(semid, &operacion, 1);
                i=semctl(semid,1,GETVAL,0);
                if(i>0)
                {

                    semctl(semid, 1, SETVAL, --i);
                    operacion.sem_num=0;
                    operacion.sem_op=1;
                    semop(semid,&operacion,1);
                }

                else
                {
                    exit(0);
                }

                for(j=0; j<c->columnas; j++)
                {
					for(k=0;k<a->columnas;k++){
						  c->coef[i][j]+=a->coef[i][k]*b->coef[k][j];
						  printf("multiplicando");
					}
                }
            }//while
        }//if
    }//for

    for(p=0; p<numproc; p++)
    {
        wait(2);
        semctl(semid,0,IPC_RMID,0);


    }

    return c;
}



void destruir_matriz(matriz *m)
{
    shmctl(m->shmid,IPC_RMID,0);
}

void imprimir(matriz *m)
{
    int i,j;

    for(i=0; i<m->filas; j++)
    {

        for(i=0; i<m->filas; j++)
        {
            printf("%g",m->coef[i][j]);
            printf("\n");

        }

    }


}


int main(int argc,char *argv[])
{

    int numproc;
    matriz *a,*b,*c;
    printf("valor argc %d",argc);
    if(argc != 2)
    {
        numproc=2;

    }
    else
    {
        numproc=atoi(argv[1]+1);
    }
    a=leer_matriz();
   
    b=leer_matriz();
   
    c=multiplicar_matrices(a,b,numproc);

  
    if(c!=NULL){
		imprimir(c);
	}else{
		printf("las matrices no se puede multiplicar");
		destruir_matriz(a);
		destruir_matriz(b);
		destruir_matriz(c); 
		}
    getchar();
return 0;
}
