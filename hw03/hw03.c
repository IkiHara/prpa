#include <stdio.h>

int numc = 0, cyc = 0, encchar = 0;
float cr;
char inp, a;

int main()
{
  while(scanf("%c", &inp) == 1 && inp > 64)
  {

    cyc++; //počet cyklů ++
    if(cyc == 1) //první cyklus only
        a = inp; //zápis z stdin do a
    if(a > 90) //chybný znak
    {
        fprintf(stderr,"Error: Neplatny symbol!\n");
        return 100; //return fail
        break; //end fail
    }

      if(a == inp) //predchozí znak v a se shoduje s inputem
      {
        numc++; //počet znaků ++
      }
      else //předchozí znak se neshoduje s inputem
      {
        switch(numc) //dělení na základě počtu znaků
        {
          case 1: //1 shodný znak
            fprintf(stdout,"%c", a);
            numc = 1; //reset znaků
            encchar++; //zakodované znaky ++
            break; //end switch

          case 2: //2 shodné znaky
            fprintf(stdout,"%c%c", a, a);
            numc = 1;
            encchar = encchar + 2;
            break;

          case 256: //256 shodných znaků
            fprintf(stdout,"%c255%c", a, a);
            encchar = encchar + 5;
            numc = 1;
            break;

          default: //< 2 shodných znaků < 256
            fprintf(stdout,"%c%d", a, numc);
            if(numc < 10)
              encchar = encchar + 2; //výpis ve tvaru CN
            else if(numc < 100 && numc > 9)
              encchar = encchar + 3; //výpis ve tvaru CNN
            else if(numc < 1000 && numc > 99)
              encchar = encchar + 4; //výpis ve tvaru CNNN
            numc = 1;// !!! až po IFu !!!
            break;//end switch
        }
        numc = 1; //reset počtu znaků
      }

      a = inp; //zápis nového znaku do a

  }
    if (cyc>0) //poslední znak
    {
      switch(numc) //dělení
      {
        case 1:
          fprintf(stdout,"%c", a);
          numc = 1;
          encchar++; //počet zákodovaných znaků ++
          break;

        case 2:
          fprintf(stdout,"%c%c", a, a);
          numc = 1;
          encchar = encchar + 2;
          break;

        case 256:
          fprintf(stdout,"%c255%c", a, a);
          encchar = encchar + 5;
          numc = 1;
          break;

        default:
          fprintf(stdout,"%c%d", a, numc);
          if(numc < 10)
            encchar = encchar + 2;
          else if(numc > 9 && numc < 100)
            encchar = encchar + 3;
          else if(numc > 99 && numc < 1000)
            encchar = encchar + 4;
          numc = 1;
          break;
      }
    }
  cr = (float)encchar/(float)cyc; //výpočet poměru komprese
  fprintf(stderr,"Pocet vstupnich symbolu: %i\n", cyc);
  fprintf(stderr,"Pocet zakodovanych symbolu: %i\n", encchar);
  fprintf(stderr,"Kompresni pomer: %.2f\n",cr);
  fprintf(stdout,"\n"); //konec řádku výpisu
  return 0; //konec úspěšného
}
