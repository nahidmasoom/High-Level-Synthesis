#include "detect.h"


/* Top-Level Function Definition */

void detect(HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], YTYPE y_R[N_RX], YTYPE y_I[N_RX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX])
{
	/* -------- Stage 1 variables -------- */

    GTYPE G_R_11[N_TX][N_TX], G_I_11[N_TX][N_TX]; MTYPE y_mf_R_11[N_TX], y_mf_I_11[N_TX]; DTYPE s_tilde_R_11[N_TX], s_tilde_I_11[N_TX], W_11[N_TX][N_TX], ws_tilde_R_11[N_TX], ws_tilde_I_11[N_TX];
    GTYPE G_R_12[N_TX][N_TX], G_I_12[N_TX][N_TX]; MTYPE y_mf_R_12[N_TX], y_mf_I_12[N_TX]; DTYPE s_tilde_R_12[N_TX], s_tilde_I_12[N_TX], W_12[N_TX][N_TX], ws_tilde_R_12[N_TX], ws_tilde_I_12[N_TX];
    GTYPE G_R_13[N_TX][N_TX], G_I_13[N_TX][N_TX]; MTYPE y_mf_R_13[N_TX], y_mf_I_13[N_TX]; DTYPE s_tilde_R_13[N_TX], s_tilde_I_13[N_TX], W_13[N_TX][N_TX], ws_tilde_R_13[N_TX], ws_tilde_I_13[N_TX];
    GTYPE G_R_14[N_TX][N_TX], G_I_14[N_TX][N_TX]; MTYPE y_mf_R_14[N_TX], y_mf_I_14[N_TX]; DTYPE s_tilde_R_14[N_TX], s_tilde_I_14[N_TX], W_14[N_TX][N_TX], ws_tilde_R_14[N_TX], ws_tilde_I_14[N_TX];
    GTYPE G_R_15[N_TX][N_TX], G_I_15[N_TX][N_TX]; MTYPE y_mf_R_15[N_TX], y_mf_I_15[N_TX]; DTYPE s_tilde_R_15[N_TX], s_tilde_I_15[N_TX], W_15[N_TX][N_TX], ws_tilde_R_15[N_TX], ws_tilde_I_15[N_TX];
    GTYPE G_R_16[N_TX][N_TX], G_I_16[N_TX][N_TX]; MTYPE y_mf_R_16[N_TX], y_mf_I_16[N_TX]; DTYPE s_tilde_R_16[N_TX], s_tilde_I_16[N_TX], W_16[N_TX][N_TX], ws_tilde_R_16[N_TX], ws_tilde_I_16[N_TX];
    GTYPE G_R_17[N_TX][N_TX], G_I_17[N_TX][N_TX]; MTYPE y_mf_R_17[N_TX], y_mf_I_17[N_TX]; DTYPE s_tilde_R_17[N_TX], s_tilde_I_17[N_TX], W_17[N_TX][N_TX], ws_tilde_R_17[N_TX], ws_tilde_I_17[N_TX];
    GTYPE G_R_18[N_TX][N_TX], G_I_18[N_TX][N_TX]; MTYPE y_mf_R_18[N_TX], y_mf_I_18[N_TX]; DTYPE s_tilde_R_18[N_TX], s_tilde_I_18[N_TX], W_18[N_TX][N_TX], ws_tilde_R_18[N_TX], ws_tilde_I_18[N_TX];

    /* -------- Stage 2 variables -------- */

    GTYPE G_R_21[N_TX][N_TX], G_I_21[N_TX][N_TX]; MTYPE y_mf_R_21[N_TX], y_mf_I_21[N_TX]; DTYPE s_tilde_R_21[N_TX], s_tilde_I_21[N_TX], W_21[N_TX][N_TX], ws_tilde_R_21[N_TX], ws_tilde_I_21[N_TX], s_hat_R_21[N_TX], s_hat_I_21[N_TX];
    GTYPE G_R_22[N_TX][N_TX], G_I_22[N_TX][N_TX]; MTYPE y_mf_R_22[N_TX], y_mf_I_22[N_TX]; DTYPE s_tilde_R_22[N_TX], s_tilde_I_22[N_TX], W_22[N_TX][N_TX], ws_tilde_R_22[N_TX], ws_tilde_I_22[N_TX], s_hat_R_22[N_TX], s_hat_I_22[N_TX];
    GTYPE G_R_23[N_TX][N_TX], G_I_23[N_TX][N_TX]; MTYPE y_mf_R_23[N_TX], y_mf_I_23[N_TX]; DTYPE s_tilde_R_23[N_TX], s_tilde_I_23[N_TX], W_23[N_TX][N_TX], ws_tilde_R_23[N_TX], ws_tilde_I_23[N_TX], s_hat_R_23[N_TX], s_hat_I_23[N_TX];
    GTYPE G_R_24[N_TX][N_TX], G_I_24[N_TX][N_TX]; MTYPE y_mf_R_24[N_TX], y_mf_I_24[N_TX]; DTYPE s_tilde_R_24[N_TX], s_tilde_I_24[N_TX], W_24[N_TX][N_TX], ws_tilde_R_24[N_TX], ws_tilde_I_24[N_TX], s_hat_R_24[N_TX], s_hat_I_24[N_TX];

    /* -------- Stage 3 variables -------- */

    GTYPE G_R_31[N_TX][N_TX], G_I_31[N_TX][N_TX]; MTYPE y_mf_R_31[N_TX], y_mf_I_31[N_TX]; DTYPE s_tilde_R_31[N_TX], s_tilde_I_31[N_TX], W_31[N_TX][N_TX], ws_tilde_R_31[N_TX], ws_tilde_I_31[N_TX], s_hat_R_31[N_TX], s_hat_I_31[N_TX];
    GTYPE G_R_32[N_TX][N_TX], G_I_32[N_TX][N_TX]; MTYPE y_mf_R_32[N_TX], y_mf_I_32[N_TX]; DTYPE s_tilde_R_32[N_TX], s_tilde_I_32[N_TX], W_32[N_TX][N_TX], ws_tilde_R_32[N_TX], ws_tilde_I_32[N_TX], s_hat_R_32[N_TX], s_hat_I_32[N_TX];

    /* -------- Final variables -------- */

    GTYPE G_R[N_TX][N_TX], G_I[N_TX][N_TX]; MTYPE y_mf_R[N_TX], y_mf_I[N_TX];


    switch(CLUSTER)
    {
        case 1:

        Gram_matrix(1, H_R, H_I, G_R, G_I);	// Gram matrix computation
        matched_filter(1, H_R, H_I, y_R, y_I, y_mf_R, y_mf_I);	// Matched filter vector computation
        ini_symbol_est(G_R, G_I, y_mf_R, y_mf_I, s_hat_R, s_hat_I);	// Symbol vector estimates

        break;

        case 2:

        /* -------- Preprocessing -------- */

        Gram_matrix(1, H_R, H_I, G_R_11, G_I_11);	// Gram matrix computation at each cluster
        Gram_matrix(2, H_R, H_I, G_R_12, G_I_12);

        matched_filter(1, H_R, H_I, y_R, y_I, y_mf_R_11, y_mf_I_11);	// matched filter vector computation at each cluster
        matched_filter(2, H_R, H_I, y_R, y_I, y_mf_R_12, y_mf_I_12);

        /* -------- Stage 1 -------- */

        ini_symbol_est(G_R_11, G_I_11, y_mf_R_11, y_mf_I_11, s_tilde_R_11, s_tilde_I_11);	// initial symbol vector estimates at each cluster
        ini_symbol_est(G_R_12, G_I_12, y_mf_R_12, y_mf_I_12, s_tilde_R_12, s_tilde_I_12);

        w_factor(G_R_11, G_R_12, W_11);	// weighting factors computation
        w_factor(G_R_12, G_R_11, W_12);

        w_symbol(W_11, s_tilde_R_11, s_tilde_I_11, ws_tilde_R_11, ws_tilde_I_11);	// weighted symbols
        w_symbol(W_12, s_tilde_R_12, s_tilde_I_12, ws_tilde_R_12, ws_tilde_I_12);

        symbol_merge(ws_tilde_R_11, ws_tilde_I_11, ws_tilde_R_12, ws_tilde_I_12, s_hat_R, s_hat_I);	// Global symbol vector estimates

        break;

        case 4:

        /* -------- Preprocessing -------- */

        Gram_matrix(1, H_R, H_I, G_R_11, G_I_11);
        Gram_matrix(2, H_R, H_I, G_R_12, G_I_12);	// Gram matrix computation at each cluster
        Gram_matrix(3, H_R, H_I, G_R_13, G_I_13);
        Gram_matrix(4, H_R, H_I, G_R_14, G_I_14);

        matched_filter(1, H_R, H_I, y_R, y_I, y_mf_R_11, y_mf_I_11);
        matched_filter(2, H_R, H_I, y_R, y_I, y_mf_R_12, y_mf_I_12);	// matched filter vector computation at each cluster
        matched_filter(3, H_R, H_I, y_R, y_I, y_mf_R_13, y_mf_I_13);
        matched_filter(4, H_R, H_I, y_R, y_I, y_mf_R_14, y_mf_I_14);

        /* -------- Stage 1 -------- */

        ini_symbol_est(G_R_11, G_I_11, y_mf_R_11, y_mf_I_11, s_tilde_R_11, s_tilde_I_11);
        ini_symbol_est(G_R_12, G_I_12, y_mf_R_12, y_mf_I_12, s_tilde_R_12, s_tilde_I_12);	// initial symbol vector estimates at each cluster
        ini_symbol_est(G_R_13, G_I_13, y_mf_R_13, y_mf_I_13, s_tilde_R_13, s_tilde_I_13);
        ini_symbol_est(G_R_14, G_I_14, y_mf_R_14, y_mf_I_14, s_tilde_R_14, s_tilde_I_14);

        w_factor(G_R_11, G_R_12, W_11);
        w_factor(G_R_12, G_R_11, W_12);	// weighting factors computation
        w_factor(G_R_13, G_R_14, W_13);
        w_factor(G_R_14, G_R_13, W_14);

        w_symbol(W_11, s_tilde_R_11, s_tilde_I_11, ws_tilde_R_11, ws_tilde_I_11);
        w_symbol(W_12, s_tilde_R_12, s_tilde_I_12, ws_tilde_R_12, ws_tilde_I_12);	// weighted symbols
        w_symbol(W_13, s_tilde_R_13, s_tilde_I_13, ws_tilde_R_13, ws_tilde_I_13);
        w_symbol(W_14, s_tilde_R_14, s_tilde_I_14, ws_tilde_R_14, ws_tilde_I_14);

        /* -------- Stage 2 -------- */

        symbol_merge(ws_tilde_R_11, ws_tilde_I_11, ws_tilde_R_12, ws_tilde_I_12, s_hat_R_21, s_hat_I_21);	// combined symbol estimates from previous stage
        symbol_merge(ws_tilde_R_13, ws_tilde_I_13, ws_tilde_R_14, ws_tilde_I_14, s_hat_R_22, s_hat_I_22);

        mf_merge(y_mf_R_11, y_mf_I_11, y_mf_R_12, y_mf_I_12, y_mf_R_21, y_mf_I_21);	// merged matched filter vector from previous stage
        mf_merge(y_mf_R_13, y_mf_I_13, y_mf_R_14, y_mf_I_14, y_mf_R_22, y_mf_I_22);

        Gram_merge(G_R_11, G_I_11, G_R_12, G_I_12, G_R_21, G_I_21);	// merged Gram matrix from previous stage
        Gram_merge(G_R_13, G_I_13, G_R_14, G_I_14, G_R_22, G_I_22);

        symbol_est(s_hat_R_21, s_hat_I_21, G_R_21, G_I_21, y_mf_R_21, y_mf_I_21, s_tilde_R_21, s_tilde_I_21);	// symbol vector estimates
        symbol_est(s_hat_R_22, s_hat_I_22, G_R_22, G_I_22, y_mf_R_22, y_mf_I_22, s_tilde_R_22, s_tilde_I_22);

        w_factor(G_R_21, G_R_22, W_21);	// weighting factors computation
        w_factor(G_R_22, G_R_21, W_22);

        w_symbol(W_21, s_tilde_R_21, s_tilde_I_21, ws_tilde_R_21, ws_tilde_I_21);	// weighted symbols
        w_symbol(W_22, s_tilde_R_22, s_tilde_I_22, ws_tilde_R_22, ws_tilde_I_22);

        symbol_merge(ws_tilde_R_21, ws_tilde_I_21, ws_tilde_R_22, ws_tilde_I_22, s_hat_R, s_hat_I);	// global symbol vector estimates

        break;

        case 8:

        /* -------- Preprocessing -------- */

        Gram_matrix(1, H_R, H_I, G_R_11, G_I_11);
        Gram_matrix(2, H_R, H_I, G_R_12, G_I_12);
        Gram_matrix(3, H_R, H_I, G_R_13, G_I_13);
        Gram_matrix(4, H_R, H_I, G_R_14, G_I_14);	// Gram matrix computation at each cluster
        Gram_matrix(5, H_R, H_I, G_R_15, G_I_15);
        Gram_matrix(6, H_R, H_I, G_R_16, G_I_16);
        Gram_matrix(7, H_R, H_I, G_R_17, G_I_17);
        Gram_matrix(8, H_R, H_I, G_R_18, G_I_18);

        matched_filter(1, H_R, H_I, y_R, y_I, y_mf_R_11, y_mf_I_11);
        matched_filter(2, H_R, H_I, y_R, y_I, y_mf_R_12, y_mf_I_12);
        matched_filter(3, H_R, H_I, y_R, y_I, y_mf_R_13, y_mf_I_13);
        matched_filter(4, H_R, H_I, y_R, y_I, y_mf_R_14, y_mf_I_14);	// matched filter vector computation at each cluster
        matched_filter(5, H_R, H_I, y_R, y_I, y_mf_R_15, y_mf_I_15);
        matched_filter(6, H_R, H_I, y_R, y_I, y_mf_R_16, y_mf_I_16);
        matched_filter(7, H_R, H_I, y_R, y_I, y_mf_R_17, y_mf_I_17);
        matched_filter(8, H_R, H_I, y_R, y_I, y_mf_R_18, y_mf_I_18);

        /* -------- Stage 1 -------- */

        ini_symbol_est(G_R_11, G_I_11, y_mf_R_11, y_mf_I_11, s_tilde_R_11, s_tilde_I_11);
        ini_symbol_est(G_R_12, G_I_12, y_mf_R_12, y_mf_I_12, s_tilde_R_12, s_tilde_I_12);
        ini_symbol_est(G_R_13, G_I_13, y_mf_R_13, y_mf_I_13, s_tilde_R_13, s_tilde_I_13);
        ini_symbol_est(G_R_14, G_I_14, y_mf_R_14, y_mf_I_14, s_tilde_R_14, s_tilde_I_14);	// initial symbol vector estimates at each cluster
        ini_symbol_est(G_R_15, G_I_15, y_mf_R_15, y_mf_I_15, s_tilde_R_15, s_tilde_I_15);
        ini_symbol_est(G_R_16, G_I_16, y_mf_R_16, y_mf_I_16, s_tilde_R_16, s_tilde_I_16);
        ini_symbol_est(G_R_17, G_I_17, y_mf_R_17, y_mf_I_17, s_tilde_R_17, s_tilde_I_17);
        ini_symbol_est(G_R_18, G_I_18, y_mf_R_18, y_mf_I_18, s_tilde_R_18, s_tilde_I_18);

        w_factor(G_R_11, G_R_12, W_11);
        w_factor(G_R_12, G_R_11, W_12);
        w_factor(G_R_13, G_R_14, W_13);
        w_factor(G_R_14, G_R_13, W_14);	// weighting factors computation
        w_factor(G_R_15, G_R_16, W_15);
        w_factor(G_R_16, G_R_15, W_16);
        w_factor(G_R_17, G_R_18, W_17);
        w_factor(G_R_18, G_R_17, W_18);

        w_symbol(W_11, s_tilde_R_11, s_tilde_I_11, ws_tilde_R_11, ws_tilde_I_11);
        w_symbol(W_12, s_tilde_R_12, s_tilde_I_12, ws_tilde_R_12, ws_tilde_I_12);
        w_symbol(W_13, s_tilde_R_13, s_tilde_I_13, ws_tilde_R_13, ws_tilde_I_13);
        w_symbol(W_14, s_tilde_R_14, s_tilde_I_14, ws_tilde_R_14, ws_tilde_I_14);	// weighted symbols
        w_symbol(W_15, s_tilde_R_15, s_tilde_I_15, ws_tilde_R_15, ws_tilde_I_15);
        w_symbol(W_16, s_tilde_R_16, s_tilde_I_16, ws_tilde_R_16, ws_tilde_I_16);
        w_symbol(W_17, s_tilde_R_17, s_tilde_I_17, ws_tilde_R_17, ws_tilde_I_17);
        w_symbol(W_18, s_tilde_R_18, s_tilde_I_18, ws_tilde_R_18, ws_tilde_I_18);

        /* -------- Stage 2 -------- */

        symbol_merge(ws_tilde_R_11, ws_tilde_I_11, ws_tilde_R_12, ws_tilde_I_12, s_hat_R_21, s_hat_I_21);
        symbol_merge(ws_tilde_R_13, ws_tilde_I_13, ws_tilde_R_14, ws_tilde_I_14, s_hat_R_22, s_hat_I_22);	// combined symbol estimates from previous stage
        symbol_merge(ws_tilde_R_15, ws_tilde_I_15, ws_tilde_R_16, ws_tilde_I_16, s_hat_R_23, s_hat_I_23);
        symbol_merge(ws_tilde_R_17, ws_tilde_I_17, ws_tilde_R_18, ws_tilde_I_18, s_hat_R_24, s_hat_I_24);

        mf_merge(y_mf_R_11, y_mf_I_11, y_mf_R_12, y_mf_I_12, y_mf_R_21, y_mf_I_21);
        mf_merge(y_mf_R_13, y_mf_I_13, y_mf_R_14, y_mf_I_14, y_mf_R_22, y_mf_I_22);	// merged matched filter vector from previous stage
        mf_merge(y_mf_R_15, y_mf_I_15, y_mf_R_16, y_mf_I_16, y_mf_R_23, y_mf_I_23);
        mf_merge(y_mf_R_17, y_mf_I_17, y_mf_R_18, y_mf_I_18, y_mf_R_24, y_mf_I_24);

        Gram_merge(G_R_11, G_I_11, G_R_12, G_I_12, G_R_21, G_I_21);
        Gram_merge(G_R_13, G_I_13, G_R_14, G_I_14, G_R_22, G_I_22);	// merged Gram matrix from previous stage
        Gram_merge(G_R_15, G_I_15, G_R_16, G_I_16, G_R_23, G_I_23);
        Gram_merge(G_R_17, G_I_17, G_R_18, G_I_18, G_R_24, G_I_24);

        symbol_est(s_hat_R_21, s_hat_I_21, G_R_21, G_I_21, y_mf_R_21, y_mf_I_21, s_tilde_R_21, s_tilde_I_21);
        symbol_est(s_hat_R_22, s_hat_I_22, G_R_22, G_I_22, y_mf_R_22, y_mf_I_22, s_tilde_R_22, s_tilde_I_22);	// symbol vector estimates
        symbol_est(s_hat_R_23, s_hat_I_23, G_R_23, G_I_23, y_mf_R_23, y_mf_I_23, s_tilde_R_23, s_tilde_I_23);
        symbol_est(s_hat_R_24, s_hat_I_24, G_R_24, G_I_24, y_mf_R_24, y_mf_I_24, s_tilde_R_24, s_tilde_I_24);

        w_factor(G_R_21, G_R_22, W_21);
        w_factor(G_R_22, G_R_21, W_22);	// weighting factors computation
        w_factor(G_R_23, G_R_24, W_23);
        w_factor(G_R_24, G_R_23, W_24);

        w_symbol(W_21, s_tilde_R_21, s_tilde_I_21, ws_tilde_R_21, ws_tilde_I_21);
        w_symbol(W_22, s_tilde_R_22, s_tilde_I_22, ws_tilde_R_22, ws_tilde_I_22);	// weighted symbols
        w_symbol(W_23, s_tilde_R_23, s_tilde_I_23, ws_tilde_R_23, ws_tilde_I_23);
        w_symbol(W_24, s_tilde_R_24, s_tilde_I_24, ws_tilde_R_24, ws_tilde_I_24);

        /* -------- Stage 3 -------- */

        symbol_merge(ws_tilde_R_21, ws_tilde_I_21, ws_tilde_R_22, ws_tilde_I_22, s_hat_R_31, s_hat_I_31);	// combined symbol estimates from previous stage
        symbol_merge(ws_tilde_R_23, ws_tilde_I_23, ws_tilde_R_24, ws_tilde_I_24, s_hat_R_32, s_hat_I_32);

        mf_merge(y_mf_R_21, y_mf_I_21, y_mf_R_22, y_mf_I_22, y_mf_R_31, y_mf_I_31);	// merged matched filter vector from previous stage
        mf_merge(y_mf_R_23, y_mf_I_23, y_mf_R_24, y_mf_I_24, y_mf_R_32, y_mf_I_32);

        Gram_merge(G_R_21, G_I_21, G_R_22, G_I_22, G_R_31, G_I_31);	// merged Gram matrix from previous stage
        Gram_merge(G_R_23, G_I_23, G_R_24, G_I_24, G_R_32, G_I_32);

        symbol_est(s_hat_R_31, s_hat_I_31, G_R_31, G_I_31, y_mf_R_31, y_mf_I_31, s_tilde_R_31, s_tilde_I_31);	// symbol vector estimates
        symbol_est(s_hat_R_32, s_hat_I_32, G_R_32, G_I_32, y_mf_R_32, y_mf_I_32, s_tilde_R_32, s_tilde_I_32);

        w_factor(G_R_31, G_R_32, W_31);	// weighting factors computation
        w_factor(G_R_32, G_R_31, W_32);

        w_symbol(W_31, s_tilde_R_31, s_tilde_I_31, ws_tilde_R_31, ws_tilde_I_31);	// weighted symbols
        w_symbol(W_32, s_tilde_R_32, s_tilde_I_32, ws_tilde_R_32, ws_tilde_I_32);

        symbol_merge(ws_tilde_R_31, ws_tilde_I_31, ws_tilde_R_32, ws_tilde_I_32, s_hat_R, s_hat_I);	// global symbol vector estimates

    }

}

/* Sub-function for Gram matrix computation */
/* input(n -> cluster, H -> channel matrix) and output(G -> Gram matrix) */

void Gram_matrix(int n, HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX])   // input(n -> cluster, H -> channel matrix) and output(G -> Gram matrix)
{
    int i, j, k;

    GTYPE zero  = 0;
    HTYPE zero1 = 0;

    Gram_matrix_Systolic: for (k = (n - 1 ) * N_RX/CLUSTER; k < n * N_RX/CLUSTER; k++)
    {
        Gram_matrix_Row: for (i = 0; i < N_TX; i++)
        {
            Gram_matrix_Col: for (j = 0; j < N_TX; j++)
            {
               ITYPE H_H_val_R, H_H_val_I, H_val_R, H_val_I;
               GTYPE last_R, last_I, result_R, result_I;

               last_R = (k == (n - 1 ) * N_RX/CLUSTER) ? zero : G_R[i][j];
               last_I = (k == (n - 1 ) * N_RX/CLUSTER) ? zero : G_I[i][j];

               H_H_val_R = (i < N_TX && k < n * N_RX/CLUSTER) ? H_R[k][i] : zero1;    // Hermitian matrix computation
               H_H_val_I = (i < N_TX && k < n * N_RX/CLUSTER) ?-H_I[k][i] : zero1;

               H_val_R = (k < n * N_RX/CLUSTER && j < N_TX) ? H_R[k][j] : zero1;
               H_val_I = (k < n * N_RX/CLUSTER && j < N_TX) ? H_I[k][j] : zero1;

               result_R = last_R + H_H_val_R * H_val_R - H_H_val_I * H_val_I;
               result_I = last_I + H_H_val_R * H_val_I + H_H_val_I * H_val_R;

               G_R[i][j] = result_R;
               G_I[i][j] = result_I;

            }
        }
    }
}

/* Sub-function for matched filter vector computation */
/* input(n -> cluster, H -> channel matrix, y -> received signal vector) and output(y_mf -> matched filter vector)*/

void matched_filter(int n, HTYPE H_R[N_RX][N_TX], HTYPE H_I[N_RX][N_TX], YTYPE y_R[N_RX], YTYPE y_I[N_RX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX])    // input(n -> cluster, H -> channel matrix, y -> received signal vector) and output(y_mf -> matched filter vector)
{
    int i, j, k;

    MTYPE zero  = 0;
    HTYPE zero1 = 0;
    YTYPE zero2 = 0;

    matched_filter_Systolic: for (k = (n - 1 ) * N_RX/CLUSTER; k < n * N_RX/CLUSTER; k++)
    {
       matched_filter_Row: for (i = 0; i < N_TX; i++)
       {
    	   ITYPE H_H_val_R, H_H_val_I, y_val_R, y_val_I;
           MTYPE last_R, last_I, result_R, result_I;

           last_R = (k == (n - 1 ) * N_RX/CLUSTER) ? zero : y_mf_R[i];
           last_I = (k == (n - 1 ) * N_RX/CLUSTER) ? zero : y_mf_I[i];

           H_H_val_R = (i < N_TX && k < n * N_RX/CLUSTER) ? H_R[k][i] : zero1;    // Hermitian matrix computation
           H_H_val_I = (i < N_TX && k < n * N_RX/CLUSTER) ?-H_I[k][i] : zero1;

           y_val_R = (k < n * N_RX/CLUSTER) ? y_R[k] : zero2;
           y_val_I = (k < n * N_RX/CLUSTER) ? y_I[k] : zero2;

           result_R = last_R + H_H_val_R * y_val_R - H_H_val_I * y_val_I;
           result_I = last_I + H_H_val_R * y_val_I + H_H_val_I * y_val_R;

           y_mf_R[i] = result_R;
           y_mf_I[i] = result_I;

        }
    }
}

/* Sub-function for initial symbol vector estimation using Gauss-Seidel method at first stage */

void ini_symbol_est(GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX])    // input( G -> Gram matrix, y_mf -> matched filter vector) and output(s_hat -> estimated symbol vector)
{
    int i, j;

    DTYPE s_temp_R, s_temp_I;
    MTYPE sum_R, sum_I, res_R, res_I;
    MTYPE zero = 0;

    ini_symbol_est_Row: for (i = 0; i < N_TX; i++)
    {
        sum_R = 0;
        sum_I = 0;

       ini_symbol_est_In: for (j = 0; j < N_TX; j++)
       {
           //sum_R += (i == j) ? zero : (MTYPE)(G_R[i][j] * s_hat_R[j] - G_I[i][j] * s_hat_I[j]);
           //sum_I += (i == j) ? zero : (MTYPE)(G_R[i][j] * s_hat_I[j] + G_I[i][j] * s_hat_R[j]);

       }

       res_R = y_mf_R[i] - sum_R;
       res_I = y_mf_I[i] - sum_I;

       s_temp_R = (res_R * G_R[i][i] + res_I * G_I[i][i]) / (G_R[i][i] * G_R[i][i] + G_I[i][i] * G_I[i][i]);
       s_temp_I = (res_I * G_R[i][i] - res_R * G_I[i][i]) / (G_R[i][i] * G_R[i][i] + G_I[i][i] * G_I[i][i]);

       s_hat_R[i] = s_temp_R;
       s_hat_I[i] = s_temp_I;

    }

}

/* Sub-function for weighting factor computation at each stage */

void w_factor(GTYPE G1_R[N_TX][N_TX], GTYPE G2_R[N_TX][N_TX], DTYPE W[N_TX][N_TX])  // input( G1, G2 -> Gram matrices of two adjacent clusters) and output(W -> weighting factors)
{
    int i;

    w_factor_Loop: for (i = 0; i < N_TX; i++)
    {
        W[i][i] = (G1_R[i][i] * (G1_R[i][i] + G2_R[i][i])) / ((G1_R[i][i] + G2_R[i][i]) * (G1_R[i][i] + G2_R[i][i]));

    }

}

/* Sub-function for weighted symbols computation at each stage */

void w_symbol(DTYPE W[N_TX][N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX], DTYPE s_weighted_R[N_TX], DTYPE s_weighted_I[N_TX])   // input(W -> weighting factors, s_hat -> estimated symbol vector) and output(s_weighted -> weighted symbols)
{
    int i;

    w_symbol_Row: for (i = 0; i < N_TX; i++)
    {
        s_weighted_R[i] = W[i][i] * s_hat_R[i];
        s_weighted_I[i] = W[i][i] * s_hat_I[i];

    }

}

/* Sub-function for the addition of the symbol vectors */

void symbol_merge(DTYPE s_hat1_R[N_TX], DTYPE s_hat1_I[N_TX], DTYPE s_hat2_R[N_TX], DTYPE s_hat2_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX])
{
    int i;

    symbol_merge_Row: for (i = 0; i < N_TX; i++)
    {
        s_hat_R[i] = s_hat1_R[i] + s_hat2_R[i];
        s_hat_I[i] = s_hat1_I[i] + s_hat2_I[i];

    }

}

/* Sub-function for the addition of the matched filter vectors */

void mf_merge(MTYPE y_mf1_R[N_TX], MTYPE y_mf1_I[N_TX], MTYPE y_mf2_R[N_TX], MTYPE y_mf2_I[N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX])
{
    int i;

    mf_merge_Row: for (i = 0; i < N_TX; i++)
    {
        y_mf_R[i] = y_mf1_R[i] + y_mf2_R[i];
        y_mf_I[i] = y_mf1_I[i] + y_mf2_I[i];

    }

}

/* Sub-function for the addition of the Gram matrices */

void Gram_merge(GTYPE G1_R[N_TX][N_TX], GTYPE G1_I[N_TX][N_TX], GTYPE G2_R[N_TX][N_TX], GTYPE G2_I[N_TX][N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX])
{
    int i, j;

    Gram_merge_Row: for (i = 0; i < N_TX; i++)
    {
        Gram_merge_Col: for (j = 0; j < N_TX; j++)
        {
            G_R[i][j] = G1_R[i][j] + G2_R[i][j];
            G_I[i][j] = G1_I[i][j] + G2_I[i][j];
        }

    }

}

/* Sub-function for symbol vector estimation using Gauss-Seidel method after first stage */

void symbol_est(DTYPE s_hat_old_R[N_TX], DTYPE s_hat_old_I[N_TX], GTYPE G_R[N_TX][N_TX], GTYPE G_I[N_TX][N_TX], MTYPE y_mf_R[N_TX], MTYPE y_mf_I[N_TX], DTYPE s_hat_R[N_TX], DTYPE s_hat_I[N_TX])    // input( G -> Gram matrix, y_mf -> matched filter vector) and output(s_hat -> estimated symbol vector)
{
    int i, j;

    DTYPE s_temp_R, s_temp_I;
    MTYPE sum_R, sum_I, res_R, res_I;
    MTYPE zero = 0.0;

    symbol_est_Row: for (i = 0; i < N_TX; i++)
    {
        sum_R = 0;
        sum_I = 0;

       symbol_est_In: for (j = 0; j < N_TX; j++)
       {
           //sum_R += (i == j) ? zero : (MTYPE)(G_R[i][j] * s_hat_old_R[j] - G_I[i][j] * s_hat_old_I[j]);
           //sum_I += (i == j) ? zero : (MTYPE)(G_R[i][j] * s_hat_old_I[j] + G_I[i][j] * s_hat_old_R[j]);

       }

       res_R = y_mf_R[i] - sum_R;
       res_I = y_mf_I[i] - sum_I;

       s_temp_R = (res_R * G_R[i][i] + res_I * G_I[i][i]) / (G_R[i][i] * G_R[i][i] + G_I[i][i] * G_I[i][i]);
       s_temp_I = (res_I * G_R[i][i] - res_R * G_I[i][i]) / (G_R[i][i] * G_R[i][i] + G_I[i][i] * G_I[i][i]);

       s_hat_R[i] = s_temp_R;
       s_hat_I[i] = s_temp_I;

    }

}
