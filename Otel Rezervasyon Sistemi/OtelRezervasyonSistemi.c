#include <stdio.h>
#include <string.h>

//ÖDEMEYÝ HESAPLAR
int odemehesapla(int odemetipi,int kredi,int tutar,int iban){
	
	printf("\n\n1.Banka Karti\n2.Kredi Karti\n3.Nakit\nLutfen odeme tipini seciniz:");
	         scanf("%d",&odemetipi);
	if(odemetipi==2){
	         printf("1-3 ay arasi kredi(pesin fiyatina)\n4-6 ay arasi kredi(%%10 zamli)\n7-9 ay arasi kredi(%%20 zamli)\n");
	         printf("Lutfen kac ay kredi yapacaginizi seciniz:");
	         scanf("%d",&kredi);
	
	
	         if(kredi==1 || kredi==2 || kredi==3){
	         tutar = tutar;
	         
	    }
	         else if(kredi==4 || kredi==5 || kredi==6){
	         	tutar = tutar + tutar* 10/100;
			 }
	          else if(kredi==7 || kredi==8 || kredi==9){
	         tutar = tutar + tutar* 20/100;	
		}
	
	}
	        else if(odemetipi==1){
	        	printf("Odemeniz banka karti uzerinden yapilacaktir..\nLutfen IBAN'inizi giriniz: TR");
	        	scanf("%d",&iban);
			}
	        else if(odemetipi==3){
	        	printf("Odemeniz otelimizde yapilacaktir...\n");
			}
	         else{
		     printf("Yanlis bir tusa bastiniz... Lutfen tekrar deneyiniz...");
		     return 0;
	}
}

//ODA BÝLGÝLERÝNÝ EKRANA VERÝR
int odabilgisiver(int odatipi,int odanum, int tutar,char isim,char soyisim){
	
	printf("Sayin %s %s\n",isim,soyisim);
	
	if(odatipi=='S' || odatipi=='s'){
		printf("\n\nOda tipiniz: Standart Oda\nOda numaraniz: %d\nTutar:%d",odanum,tutar);
	}
	else if(odatipi=='L' || odatipi=='l'){
		printf("\n\nOda tipiniz: Lux Oda\nOda numaraniz: %d\nTutar:%d",odanum,tutar);
	}
	else if(odatipi=='D' || odatipi=='d'){
		printf("\n\nOda tipiniz: Delux Oda\nOda numaraniz: %d\nTutar:%d",odanum,tutar);
	}
	
}

// DONEM BÝLGÝSÝ SORAR
int donemsor(int donem,int tutar){
	printf("Lutfen hangi donemde konaklayacaginizi seciniz...\nYaz icin-->'Y' tiklayiniz. (+200tl zamli)\nKis icin-->'K' tiklayiniz. (-200tl indirimli)\nBahar icin-->'B' tiklayiniz. (sabit)\n-->");
	scanf("%s",&donem);
	
	if(donem=='Y' || donem=='y'){
		tutar +=200;
	}
	else if(donem=='K' || donem=='k'){
		tutar -=200;
	}
	else if(donem=='B' || donem=='b'){
	    tutar=0;
	}
	else{
		printf("Yanlis bir tusa bastiniz... Lutfen tekrar deneyiniz...");
		return 0;
	}
}



	

int main(){
	
	FILE *filep;
	char text[200];
	filep = fopen("musteribilgi.txt","a");
	
	int odemetipi,hafta,tutar=500,odanum,kredi,sontutar=0,iban;
	int i;
	char donem,odatipi;
	char isim[15];
	char soyisim[20];
	
	printf("\t--->HOSGELDINIZ<---\n");
	
	printf("Lutfen isminizi giriniz:");
	scanf("%s",&isim);
	printf("Lutfen soyisminizi giriniz:");
	scanf("%s",&soyisim);
	
	donemsor;
	
	printf("\n\nLutfen odatipi seciniz...\nStandart(1-3 kisilik) icin-->'S' tiklayiniz.\nLux(3-5 kisilik ve 200tl zamli) icin-->'L' tiklayiniz.\nDelux(1-3 kisilik ve 300tl zamli) icin-->'D' tiklayiniz.\n-->");
	
	scanf("%s",&odatipi);
	
	    if(odatipi=='S' || odatipi=='s'){
	
	    for(i=1;i<=10;i++){
		
	    printf("%d nolu oda\n",i);
	}
	    printf("Oda numaranizi seciniz:");
	    scanf("%d",&odanum);
	    if(odanum<1 || odanum>10){
	    	printf("Gecersiz oda numarasi girdiniz. Lutfen tekrar deneyiniz...");
	    	return 0;
		}
	    
		}
	
	    else if(odatipi=='L' || odatipi=='l'){
	
	    for(i=11;i<=20;i++){
		
	    printf("%d nolu oda\n",i);
	}	
	    printf("Oda numaranizi seciniz:");
	    scanf("%d",&odanum);
		if(odanum<11 || odanum>20){
	    	printf("Gecersiz oda numarasi girdiniz. Lutfen tekrar deneyiniz...");
	    	return 0;
		}		
	    tutar+=200;
	}
	
	    else if(odatipi=='D' || odatipi=='d'){
		
	
	    for(i=21;i<=30;i++){
		
	    printf("-->%d nolu oda\n",i);
	}
	    printf("Oda numaranizi seciniz:");
	    scanf("%d",&odanum);
	    if(odanum<21 || odanum>30){
	    	printf("Gecersiz oda numarasi girdiniz. Lutfen tekrar deneyiniz...");
	    	return 0;
		}
	    tutar+=300;
	}
	    else{
		printf("Yanlis bir tusa bastiniz... Lutfen tekrar deneyiniz...");
		return 0;
	}
	         
	odemehesapla(odemetipi,kredi,tutar,iban);
	
	odabilgisiver(odatipi,odanum,tutar,isim[15],soyisim[20]);       
	
	printf("\nBizi tercih ettiginiz icin tesekkurler...");
	
	fprintf(filep,"-->%s %s\n",isim,soyisim);
	fprintf(filep,"---Oda Bilgileri---\nOda numarasý:%d\nTutar:%d\n\n",odanum,tutar);
	
	
	
	
	return 0;
	
	}
	   

