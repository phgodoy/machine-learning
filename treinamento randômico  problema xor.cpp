//treinamento rand�mico : problema xor
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	float w1[4][4];
	float w2[4][4];
	float I[4][4];
	float O[4][4];
	float E1[4] = {0.0,0.0,1.0,1.0};
	float E2[4] = {0.0,1.0,0.0,1.0};
	float T[4] = {0.0,1.0,1.0,0.0};
	float erro;
	int ciclo = 0;
	
	do {
		w1[1][1] = (rand()%1000/10.0)-50.0;
		w1[2][1] = (rand()%1000/10.0)-50.0;
		w1[3][1] = (rand()%1000/10.0)-50.0;
		w1[1][2] = (rand()%1000/10.0)-50.0;
		w1[2][2] = (rand()%1000/10.0)-50.0;
		w1[3][2] = (rand()%1000/10.0)-50.0;
		w2[1][1] = (rand()%1000/10.0)-50.0;
		w2[2][1] = (rand()%1000/10.0)-50.0;
		w2[3][1] = (rand()%1000/10.0)-50.0;
		erro = 0;
		for(int i = 0; i <= 3; i++) {
			I[1][1] = E1[i];
			I[1][2] = E2[i];
			I[1][3]=1.0;
			O[1][1]= I[1][1];
			O[1][2]= I[1][2];
			O[1][3]= I[1][3];
			
			I[2][1]= O[1][1]*w1[1][1]+O[1][2]*w1[2][1]+O[1][3]*w1[3][1];

			I[2][2]= O[1][1]*w1[1][2]+O[1][2]*w1[2][2]+O[1][3]*w1[3][2];
			
			I[2][3]= 1.0;
			
			O[2][1]= 1.0/(1.0+exp(-I[2][1]));
			
			O[2][2]= 1.0/(1.0+exp(-I[2][2]));
			
			O[2][3]= I[2][3];
			
			I[3][1]= O[2][1]*w2[1][1]+O[2][2]*w2[2][1]+O[2][3]*w2[3][1];
			
			O[3][1]= 1.0/(1.0+exp(-I[3][1]));
			
			erro += (T[i] - O[3][1]) * (T[i] - O[3][1]);
			ciclo++;
		}
	} while(erro > 0.001);
	
	printf("epocas: %d\n",ciclo);
	for(int i = 1; i < 3; i++) {
		for(int j = 1; j < 4; j++) {
			printf("w1[%d][%d] = %.0f;\n",j,i,w1[j][i]);
		}
	}
	for(int l = 1; l < 2; l++) {
		for(int k = 1; k < 4; k++) {
			printf("w2[%d][%d] = %.0f;\n",k,l,w2[k][l]);
		}
	}

}
