/*==============================================================*/
/* generic/hdr/type.h : generic type definitions		*/
/*==============================================================*/

typedef unsigned char BOOL;		/* boolean */
typedef double real;			/* double-precision reals */

#define FMT_REAL_ERR "%r"
#define FMT_REAL_RD "%le"
#define FMT_REAL_WR "%24.16e\n"

#define MAXEXT 10

typedef struct {
  real x, y; /* point location */
  int  w;    /* weight */
} pt;

#define FMT_PT_RD "%le%le%d"
#define FMT_PT_WR "%e\t%e\t%d\n"

typedef BOOL	bool1D		[MAXEXT];
typedef BOOL	bool1DX		[MAXEXT * MAXEXT];
typedef BOOL	bool2D		[MAXEXT][MAXEXT];

typedef int	int1D		[MAXEXT];
typedef int	int1DX		[MAXEXT * MAXEXT];
typedef int	int2D		[MAXEXT][MAXEXT];

typedef pt	pt1D		[MAXEXT];
typedef pt	pt1DX		[MAXEXT * MAXEXT];

typedef real	real1D		[MAXEXT];
typedef real	real1DX		[MAXEXT * MAXEXT];
typedef real	real2D		[MAXEXT][MAXEXT];
