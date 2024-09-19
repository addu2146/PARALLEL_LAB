#include <stdio.h>


void DectoBin(int Dec){
	int Bin[40];
	int index = 0;
	
	while(Dec>0){
	 int rem = Dec%2;
	 Bin[index] = rem;
	 Dec/=2;
	 index++;
	}
	
	int i;
	printf("Binary : \n");
	
	for(i=index-1;i>=0;i--){
		printf("%d\t",Bin[i]);
	}
	
}
void DectoOct(int Dec){
	int Oct[40];
	int index = 0;
	
	while(Dec>0){
	 int rem = Dec%8;
	 Oct[index] = rem;
	 Dec/=8;
	 index++;
	}
	
	int i;
	printf("OCtal:\n");
	
	for(i=index-1;i>=0;i--){
		printf("%d\t",Oct[i]);
	}
	
}
void DectoHex(int Dec){
	char Hexa[20];
	int index =0;
	while(Dec!=0){
		int rem = Dec%16;
		if(rem<=9){
			Hexa[index++]='0'+rem;
		}
		else if(rem ==10){
			Hexa[index++]= 'A';
		}
		else if(rem ==11){
			Hexa[index++]= 'B';
		}	
	    else if(rem ==12){
			Hexa[index++]= 'C';
		}	
		else if(rem ==13){
			Hexa[index++]= 'D';
		}	
		else if(rem ==14){
			Hexa[index++]= 'E';
		}	
		else if(rem ==15){
			Hexa[index++]= 'F';
		}
		Dec=Dec/16;
	}
	printf("HeXADECIMAL :\n");
	int i;
		for(i=index-1;i>=0;i--){
			printf("%c",Hexa[i]);
		}
	}

		

int main(int argc, char *argv[]) {
	int Dec = 16;
	DectoBin(Dec);
	printf("\n\n");
	DectoOct(Dec);
	printf("\n\n");
	DectoHex(Dec);
	
	return 0;
}
