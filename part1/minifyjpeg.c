#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */
minifyjpeg_out *
minifyjpeg_proc_1_svc (minifyjpeg_in argp, struct svc_req *rqstp)
{
	static minifyjpeg_out result;

	xdr_free((xdrproc_t)xdr_minifyjpeg_out, (char *)&result);
	magickminify_init();
	result.dest.dest_val = magickminify(argp.src.src_val, argp.src.src_len,
	    (ssize_t *)&result.dest.dest_len);

	return &result;
}

int minifyjpeg_prog_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_minifyjpeg_out,
				caddr_t result)
{
	magickminify_cleanup();
	return 1;
}