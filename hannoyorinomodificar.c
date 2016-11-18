#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void moverchica();
void moverchicaizquierda();
int llena(int);
void moverotra();

//int pushtor1();
//int poptor1();
//int llenator1();
//int vaciator1();
//int creartor1();

//int pushtor2();
//int poptor2();
//int llenator2();
//int vaciator2();
//int creartor2();

//int pushtor3();
//int poptor3();
//int creartor3();
//int llenator3();
//int vaciator3();

    
    int finala=0;
    int finalb=0;
    int finalc=0;
    int poschica=0;
    int a[30];
    int b[30];
    int c[30];

int main(){
	int n,y;
    int x,cont1=1,aux1=0,aux2=0;
    printf("\nINTRODUCE EL NUMERO DE FICHAS: ");
	scanf("%d",&n);
	for(y=0;y<n;y++){
		cont1=cont1*2;
		}
    finala=n;
	for(x=0;x<n;x++){
		a[x]=finala;
		finala--;
    }
        finala=n;
        if(n%2==0){
        moverchica ();
    	do{
    	 moverotra();
    	 moverchica ();
    	 aux1++;
    	 printf("finalc %d\n, aux1 %d\n, cont1 %d\n",finalc,aux1,cont1);

    }while(!llena(n) && aux1<cont1);
}else{
		moverchicaizquierda ();
	do{
		 moverotra();
		 moverchicaizquierda();
		 aux2++;
		 printf("finalc %d\n, aux2 %d\n, cont1 %d\n",finalc,aux2,cont1);
    }while(!llena(n) && aux2<cont1);

}
//system("pause");
return 0;
}

void moverchica(){

             switch(poschica){
                              case 0:
                                   finala--;
                                   b[finalb]=1;
                                   finalb++;
                                   poschica=1;
                                   printf("MOVER DE A->B\n");
                                   //printf("final a %d\ntorre b%d\nposchica %d\n",finala,b[finalb],poschica);
                                   break;
                              case 1:
                                   finalb--;
                                   c[finalc]=1;
                                   finalc++;
                                   poschica=2;
                                   printf("MOVER DE B->C\n");
                                   //printf("final b %d\ntorre c %d\nposchica %d\n",finalb,c[finalc],poschica);
                                   break;
                                   
                              case 2:
                                   finalc--;
                                   a[finala]=1;
                                   finala++;
                                   poschica=0;
                                   printf("MOVER DE C->A\n");
                                   //printf("final c%d\ntorre a%d\nposchica %d\n",finalc,a[finala],poschica);
                                   break;
			} 
}                                
void moverotra(){
	//printf("mover otra\n");
            switch(poschica){
                             case 0:
                                  if(finalb==0){
									   b[finalb]=c[finalc-1];
									   finalc--;
									   finalb++;
									   printf("MOVER DE C->B\n");
									   //printf("torre c %d\ntorre b%d\n",c[finalc],b[finalb]);
                                   }else if(finalc==0){
									   c[finalc]=b[finalb-1];
									   finalb--;
									   finalc++;   
									   printf("MOVER DE B->C\n");
									   //printf("torre b%d\n torre c %d\n",b[finalb],c[finalc]);
                                   }else if(b[finalb-1]>c[finalc-1]){
									   
										b[finalb]=c[finalc-1];
									   finalc--;
									   finalb++;
									   printf("MOVER DE C->B\n");
									   //printf("torre c %d\n torre b %d\n",c[finalc],b[finalb]);
									   }else{
										   //printf("finalb %d\nfinalc %d\n torre b%d\n torre c%d",finalb,finalc,b[finalb-1],c[finalc-1]);
										 c[finalc]=b[finalb-1];
										 finalb--;
										 finalc++;
										 printf("MOVER DE B->C\n");
										 //printf("torre b %d\ntorre c %d\n",b[finalb],c[finalc]);
										 }
								break;
                               case 1:
                                    if(finala==0){
										a[finala]=c[finalc-1];
										finalc--;
										finala++;
										printf("MOVER DE C->A\n");
										//printf("torre c %d\ntorre a %d\n",c[finalc],a[finala]);
                                    }else if(finalc==0){
                                          //printf("finalc %d\nfinala %d\n torre c %d\ntorreb %d\n",finalc,finala,c[finalc],a[finala-1]);
                                          c[finalc]=a[finala-1];
                                          finala--;
                                          finalc++;
                                          printf("MOVER DE A->C\n");
                                          //printf("torre a %d\n torre c %d\n",a[finala],c[finalc]);
                                          }else if(a[finala-1]>c[finalc-1]){
													a[finala]=c[finalc-1];
													finalc--;
													finala++;
													printf("MOVER DE C->A\n");
													//printf("torre c %d\ntorre a %d\n",c[finalc],a[finala]);
                                                }else{
                                                      c[finalc]=a[finala-1];
                                                      finala--;
                                                      finalc++;
                                                      printf("MOVER DE A->C\n");
                                                      //printf("torre a %d\n torre c %d\n",a[finala],c[finalc]);
                                                     
                                                      }break;
                               case 2:
                                    if(finala==0){
													  a[finala]=b[finalb-1];
													  finalb--;
													  finala++;
													  printf("MOVER DE B->A\n");
													  //printf("torre b %d\ntorre a %d\n",b[finalb],a[finala]);
                                                  }else if(finalb==0){
                                                        b[finalb]=a[finala-1];
                                                        finala--;
                                                        finalb++;
                                                        printf("MOVER DE A->B\n");
                                                        //printf("torre a %d\ntorre b%d\n",a[finala],b[finalb]);
                                                        }else if(a[finala-1]>b[finalb-1]){
															finalb--;
															finala++;
															printf("MOVER DE B->A\n");
															//printf("torre b %d\ntorre a %d\n",b[finalb],a[finala]);
                                                        }else{
                                                              b[finalb]=a[finala-1];
                                                              finala--;
                                                              finalb++;
                                                              printf("MOVER DE A->B\n");
                                                              //printf("torre a %d\ntorre b%d\n",a[finala],b[finalb]);
                
						
                        								  }break;
						
                        }
}
	
int llena(int n){
	if (finalc==n){
	    printf("\n numero %d, finalc %d",n,finalc);
		
        return 1;
	
    }
    
    return 0;
    }



void moverchicaizquierda(){
				//printf("posicion chica %d",poschica);
             switch(poschica){
                              case 0:
                                   finala--;
                                   c[finalc]=1;
                                   finalc++;
                                   poschica=2;
                                   printf("MOVER DE A->C\n");
                                   //printf("final a %d\ntorre b%d\nposchica %d\n",finala,b[finalb],poschica);
                                   break;
                              case 1:
                                   finalb--;
                                   a[finala]=1;
                                   finala++;
                                   poschica=0;
                                   printf("MOVER DE B->A\n");
                                   //printf("final b %d\ntorre c %d\nposchica %d\n",finalb,c[finalc],poschica);
                                   break;
                                   
                              case 2:
                                   finalc--;
                                   b[finalb]=1;
                                   finalb++;
                                   poschica=1;
                                   printf("MOVER DE C->B\n");
                                   //printf("final c%d\ntorre a%d\nposchica %d\n",finalc,a[finala],poschica);
                                   break;
			} 
}
