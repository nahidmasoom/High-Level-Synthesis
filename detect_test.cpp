#include <stdio.h>
#include <stdlib.h>
#include "detect.h"


int main()
{
    const int length = N_RX * N_TX;	// Total number of complex channel entries
    int i, j, k, m, n, r;

    HTYPE channel_R[length], channel_I[length]; // Arrays for the complex channel entries
    FILE *ch;

	ch = fopen("channel.txt", "r");

	for(i = 0; i < length; i++)
	{
	    fscanf(ch, "%f %f\n", &channel_R[i], &channel_I[i]);
	}

	fclose(ch);

	HTYPE H_R[N_RX][N_TX], H_I[N_RX][N_TX];	// 2-D arrays for the real and the imaginary parts of the channel matrix

	k = 0;

	for (i = 0; i < N_RX; i++)
	{
		for (j = 0; j < N_TX; j++)
		{
			H_R[i][j] = channel_R[k];
	       		H_I[i][j] = channel_I[k];
			k++;
	    	}

	}

	YTYPE y_R[N_RX], y_I[N_RX];	// 1-D arrays for the real and the imaginary parts of the received signal

	FILE *signal;

	signal = fopen("received_signal.txt", "r");

	for (i = 0; i < N_RX; i++)
	{
		fscanf(signal, "%f %f\n", &y_R[i], &y_I[i]);

	}

	fclose(signal);

	float s_gold_R[N_TX], s_gold_I[N_TX];

	FILE *gold;

	gold = fopen("golden_data.txt", "r");

	for (i = 0; i < N_TX; i++)
	{
		fscanf(gold, "%f %f\n", &s_gold_R[i], &s_gold_I[i]);    // Reading golden symbol to compare with the estimated symbol
	    	printf("%f + %fi\t", s_gold_R[i], s_gold_I[i]);

	}

	printf("\n");

	fclose(gold);

	GTYPE G_R[N_TX][N_TX], G_I[N_TX][N_TX];	// 2-D arrays for the real and the imaginary parts of the Gram matrix
	MTYPE y_mf_R[N_TX], y_mf_I[N_TX];		// 1-D arrays for the real and the imaginary parts of the matched filter
	DTYPE s_hat_R[N_TX], s_hat_I[N_TX];		// 1-D arrays for the real and the imaginary parts of the symbol vector

	detect(H_R, H_I, y_R, y_I, s_hat_R, s_hat_I);	// Calling top-level function for the symbols detection

	//for(i = 0; i < N_TX; i++)
	//{
		//printf("%f + %fi\t", s_hat_R[i], s_hat_I[i]);
	//}

	printf("\n");


	float temps_hat_R[N_TX], temps_hat_I[N_TX];

	for(i = 0; i < N_TX; i++)
	{
		temps_hat_R[i] = s_hat_R[i].to_float(); // Converting estimated symbol into floating types
		temps_hat_I[i] = s_hat_I[i].to_float();
		printf("%f + %fi\t", temps_hat_R[i], temps_hat_I[i]);

	}

	printf("\n");

	float symbol_diff_R[N_TX], symbol_diff_I[N_TX];
	float diff = 0.06;  // maximum difference level between the golden symbol and and the estimated symbol

	for(i = 0; i < N_TX; i++)
	{
		symbol_diff_R[i] = abs(s_gold_R[i] - temps_hat_R[i]);
	    	symbol_diff_I[i] = abs(s_gold_I[i] - temps_hat_I[i]);

	    //printf("%f + %fi\t", symbol_diff_R[i], symbol_diff_I[i]);

	    if(symbol_diff_R[i] < diff && symbol_diff_I[i] < diff)
	    {
	    	printf("\nCongratulations! Design Passed!!!\n");
	        return 0;
	    }
	    else
	    {
	        printf("\nOops! Design Failed!!!\n");
	        return 1;
	    }

	}

}
