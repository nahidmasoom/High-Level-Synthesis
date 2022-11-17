#ifndef __DETECT_H__
#define __DETECT_H__

#include <math.h>
#include <ap_fixed.h>	// Comment for the floating point data types or uncomment for the fixed-point data types


/* Design parameters */

#define N_RX 128		// Number of antennas at the base station
#define N_TX 8			// Number of single antenna users
#define CLUSTER 1		// Number of clusters



/* Data types */

typedef float HTYPE, YTYPE;	// Floating point data types for the channel matrix and the received signal


/*  Uncomment for the floating point data types or comment for the fixed-point data types */

//typedef float GTYPE, MTYPE, DTYPE, ITYPE;	// Floating point data types for the Gram matrix, the matched filter vector, the symbol vector, and the loop variables


/* Comment for the  floating point data types or uncomment for the fixed-point data types */

typedef ap_fixed <16, 10> GTYPE;	// Fixed point data types for the Gram matrix
typedef ap_fixed <16, 10> MTYPE;	// Fixed point data types for the matched filter vector
typedef ap_fixed <16, 3> DTYPE;		// Fixed point data types for the symbol vector and the weighting factor
typedef ap_fixed <16, 5> ITYPE;		// Fixed point data types for the loop variables


/* Function Prototype */

void Gram_matrix(int n, HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX]);
void matched_filter(int n, HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], YTYPE y_R[N_RX], YTYPE y_I[N_RX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX]);

void ini_symbol_est(GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX]);
void w_factor(GTYPE G1_R[N_TX][N_TX], GTYPE G2_R[N_TX][N_TX], DTYPE W[N_TX][N_TX]);
void w_symbol(DTYPE W[N_TX][N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX], DTYPE s_weighted_R[N_TX], DTYPE s_weighted_I[N_TX]);
void symbol_merge(DTYPE s_hat1_R[N_TX], DTYPE s_hat1_I[N_TX], DTYPE s_hat2_R[N_TX], DTYPE s_hat2_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX]);
void mf_merge(MTYPE y_mf1_R[N_TX], MTYPE y_mf1_I[N_TX], MTYPE y_mf2_R[N_TX], MTYPE y_mf2_I[N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX]);
void Gram_merge(GTYPE G1_R[N_TX][N_TX], GTYPE G1_I[N_TX][N_TX], GTYPE G2_R[N_TX][N_TX], GTYPE G2_I[N_TX][N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX]);
void symbol_est(DTYPE s_hat_old_R[N_TX], DTYPE s_hat_old_I[N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX]);

void detect(HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], YTYPE y_R[N_RX], YTYPE y_I[N_RX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX]);

#endif
