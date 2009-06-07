/**
 * Defaults for Cowichan programs.
 */
#ifndef __cowichan_defaults_hpp__
#define __cowichan_defaults_hpp__

// common
#define ALL_NR 1000
#define ALL_NC 1000

// chain
#define CHAIN_NR ALL_NR
#define CHAIN_NC ALL_NC

// mandel
#define MANDEL_NR ALL_NR
#define MANDEL_NC ALL_NC
#define MANDEL_X0 0
#define MANDEL_Y0 0;
#define MANDEL_DX 1.5;
#define MANDEL_DY 1.5;
#define MANDEL_INFINITY 2.0
#define MANDEL_MAX_ITER 150

// randmat
#define RANDMAT_NR ALL_NR
#define RANDMAT_NC ALL_NC
#define RANDMAT_SEED 681304
#define RANDMAT_A  1291
#define RANDMAT_C   917
#define RANDMAT_M 56197

// half
#define HALF_NR ALL_NR
#define HALF_NC ALL_NC

// invperc
#define INVPERC_NR ALL_NR
#define INVPERC_NC ALL_NC
#define INVPERC_NFILL 200

// sor
#define SOR_OMEGA 0.9
#define SOR_TOLERANCE 10e-6
 
#endif

