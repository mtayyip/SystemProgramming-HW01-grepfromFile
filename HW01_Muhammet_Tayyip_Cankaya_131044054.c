/*HW01 MUHAMMET TAYYIP CANKAYA 131044054*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OUTPUTFILE "gfF.log"
/*Bu fonksiyon okunacak,yazilacak dosyayi ve aranacak olan stringi parametre olarak almaktadir.
Fonksiyonda alinan stringin kac tane bulundugu ve hangi satir sutunda oldugunu ekrana ve optr 
isimli "gfF.log" isimli dosyaya yaziyorum.*/
int grepfromFile(FILE *iptr,FILE *optr,char* argv2)
{
	int kacTaneVar=0,temp,sbt=0,dosyadakiHarfSayisi=0,i=0;
	char *metin,karakter;
	int kelimeBoyutu=strlen(argv2);
	int satir=1,sutun=1,count=1,index,sayac;	

	/*Burada okuyacagim dosyada kac tane karakter oldugunu buluyorum.*/
	while(!feof(iptr)){
		fscanf(iptr,"%c",&karakter);
		dosyadakiHarfSayisi++;}
	
	/*Dosyada kac tane karakter oldugunu yukarida bulmustum.malloc la o boyutta yer aliyorum.*/
	metin=(char*)malloc(sizeof(char)*dosyadakiHarfSayisi);


	/*Bu ozel fonksiyon dosyanin konum gostergecini dosya basina aliyor.*/
	rewind(iptr);
	/*Metin isimli char*'a okuyorum.*/
	while(!feof(iptr)){
		fscanf(iptr,"%c",&metin[i]);
		i++;}
	

	/*for icerisinde arana ilk karakterle dosyadaki karakterlere bakip ayniysa aranan kelimenin boyutu
	kadar karsilastirma yapip bulundu deyip count'u bir artiriyorum.*/
	
	for(index=0;index<dosyadakiHarfSayisi;++index)
	{
		temp=index;

		if(metin[index]=='\n'){
			satir++;		
			sutun=0;}
		
		if(metin[index]==argv2[0]){
			for(sayac=1;sayac<kelimeBoyutu;sayac++){
				if(argv2[sayac]==metin[temp+1])
					sbt++;
			
				temp++;	

				if(sbt==kelimeBoyutu-1){
					kacTaneVar++;
					printf("%d-->%d.satir %d.sutunda var\n",count,satir,sutun);
					fprintf(optr,"%d-->%d.satir %d.sutunda var\n",count,satir,sutun);
					count++;}}}
		sbt=0;
		sutun++;	
	}
	
	/*Malloc la aldigim yeri geri veriyorum.*/
	free(metin);
	/*Toplamda kac tane bulundugunu return ediyorum.*/
	return kacTaneVar;
}


int main(int argc,char *argv[])
{
	/*Alinan parametre 3 degilse uyari verip programi bitiriyor.*/
	if(argc!=3){
		fprintf(stderr,"HATA\nKullanimi:./dosya ismi .txt dosyasi aranmak istenen string\n");
		return 1;}

	/*Alinan parametre 3 ise fonksiyonu cagirip islemler yapiliyor.*/
	else
	{
		int count=0;
		FILE *iptr =fopen(argv[1],"r");
		FILE *optr=fopen(OUTPUTFILE,"a+");
		if (iptr==NULL){
            printf("Dosya acilamadi\n");
            return 0;
		}
        else{
        	printf("File Name==>%s\n\n",argv[1]);
        	fprintf(optr,"File Name==>%s\n\n",argv[1]);
        	count=grepfromFile(iptr,optr,argv[2]); }
   
        printf("%d defa bulundu.\n",count);
        fprintf(optr,"%d defa bulundu.\n",count);

        printf("***********************************************\n\n");	
        fprintf(optr,"***********************************************\n\n"); 

		fclose(iptr);
		fclose(optr);
	}
    return 0;
}