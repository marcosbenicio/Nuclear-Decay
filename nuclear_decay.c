#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define a      0.00924
#define dt     0.001

#define time   5000


int main()
{
   
   int t,i,interval;
      
   double Nt,N[time];
   
   FILE *fpm;
   
   interval=1/dt;

   Nt=1000.0;
   N[0]=Nt;
   
   fpm=fopen("decaimento_nuclear_tempo5000.txt","w");
   if(!fpm) exit(0);
   
   fprintf(fpm,"#tempo\t\t\t#N\t");   
   fprintf(fpm,"\n0\t\t\t%lf\n",N[0]);
   for(t=0;t<time;t++){
      for(i=0;i<interval;i++){ 
         Nt=Nt*(1.0-a*dt); 
      }
      N[t+1]=Nt;   
   }
   for(t=0;t<time/10;t++){
      fprintf(fpm,"\n%i\t\t\t%lf\n",10*(t+1),N[10*(t+1)]);

   }
   fclose(fpm);
   
}   





