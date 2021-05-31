/*
* Proyecto Primer Bimestre 
* PARTE 2
* Integrantes: Erazo Israel, Guatemal Katherine
* Objetivo: Cumplir con los requerimientos pedidos para el desarrollo del proyecto
*
*/
//Señales obtenidas del documento adjuntado
float Signal[]={358,353,352,351,351,351,353,354,353,353,355,357,358,358,358,359,360,355,351,350,350,349,350,352,353,352,353,354,356,357,356,357,358,357,352,350,349,348,348,350,351,351,350,352,354,355,355,355,356,357,354,349,348,347,347,347,349,350,350,350,351,353,354,354,354,355,356,351,347,346,346,345,346,348,349,348,349,350,352,352,352,353,354,353,348,346,334,336,336,335};
//Segunda señal
float kernel[]={0.05,0.24,0.4,0.24,0.05};
//float G[]={358,353,352,351,351,351,353,354,353,353,355,357,358,358,358,359,360,355,351,350,350,349,350,352,353,352,353,354,356,357,356,357,358,357,352,350,349,348,348,350,351,351,350,352,354,355,355,355,356,357,354,349,348,347,347,347,349,350,350,350,351,353,354,354,354,355,356,351,347,346,346,345,346,348,349,348,349,350,352,352,352,353,354,353,348,346,334,336,336,335};
int N=90, Nk=5;
float den=0, zj=0;
double h,f,m;
double c[90];

void setup()
{
Serial.begin(9600); //Inicio de Comunicación serial
}

void loop(){
  den=0;
  for (int i = 0; i < Nk; i++){
    den=den+kernel[i];
  }
  
for (int i = 0; i < N-Nk; i++){
  for (int i2 = 0; i2 < Nk; i2++){
       c[i]=c[i]+kernel[i2]*Signal[i2+i];
  }
   c[i]=c[i]/den;
   Serial.print(String("Filtrado: ")+String(c[i]));           //Impresión Filtrada
   Serial.print(",");
   Serial.println(String("Señal Original: ")+String(Signal[i+2]));//Impresion de la señal original
   c[i]=0;
  }

 SNR();
}

void SNR(){                             //Método de SNR

//Promedio señal original v1
  float sum=0;                          //ciclos recorre el numero de datos d ela señal
  for(int i=0;i<90;i++){                    
      sum = sum + Signal[i];            //guarda los valores obtenidos
    }
     double promedio=sum/90;            //divide para el numero de datos de la señal
    double v1=((promedio*5)/1023);
    Serial.println(String("Valor voltaje Señal: ")+String(v1));   //Imprime de forma serial el valor obtenido
    Serial.print("");
    
//Promedio señal Suavizada (v2) metodo de Gauss
     double sum2=0;
  for(int i=0;i<90;i++){               
      sum2 = sum2 + Signal[i+1];
    }
   double promedio2=sum2/90;                               //divide par ael numero de datos de la señal
    float v2=(promedio2*5)/1023;
    Serial.println(String("Valor en voltaje del filtro: ")+String(v2)); //Imprime de forma serial el valor obtenido
    Serial.print("");

 //Metrica SNR m=20*log(v2/v1)
     double metrica=20*log(v2/v1);
    Serial.println(String("Valor metrica snr en dBs: ")+String(metrica)); //Imprime el valor obtenid entre con relación a lo anteriores resultados
    Serial.print("");
    
  }
  