/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MINIFYJPEG_H_RPCGEN
#define _MINIFYJPEG_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


struct minifyjpeg_in {
	struct {
		u_int src_len;
		char *src_val;
	} src;
};
typedef struct minifyjpeg_in minifyjpeg_in;

struct minifyjpeg_out {
	struct {
		u_int dest_len;
		char *dest_val;
	} dest;
};
typedef struct minifyjpeg_out minifyjpeg_out;

#define MINIFYJPEG_PROG 0x31230000
#define MINIFYJPEG_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define MINIFYJPEG_PROC 1
extern  enum clnt_stat minifyjpeg_proc_1(minifyjpeg_in , minifyjpeg_out *, CLIENT *);
extern  bool_t minifyjpeg_proc_1_svc(minifyjpeg_in , minifyjpeg_out *, struct svc_req *);
extern int minifyjpeg_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define MINIFYJPEG_PROC 1
extern  enum clnt_stat minifyjpeg_proc_1();
extern  bool_t minifyjpeg_proc_1_svc();
extern int minifyjpeg_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_minifyjpeg_in (XDR *, minifyjpeg_in*);
extern  bool_t xdr_minifyjpeg_out (XDR *, minifyjpeg_out*);

#else /* K&R C */
extern bool_t xdr_minifyjpeg_in ();
extern bool_t xdr_minifyjpeg_out ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MINIFYJPEG_H_RPCGEN */
