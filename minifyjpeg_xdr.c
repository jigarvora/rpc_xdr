/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "minifyjpeg.h"

bool_t
xdr_minifyjpeg_in (XDR *xdrs, minifyjpeg_in *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->src.src_val, (u_int *) &objp->src.src_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_minifyjpeg_out (XDR *xdrs, minifyjpeg_out *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->dest.dest_val, (u_int *) &objp->dest.dest_len, ~0))
		 return FALSE;
	return TRUE;
}
