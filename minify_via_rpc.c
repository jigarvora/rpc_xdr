#include "minifyjpeg_xdr.c"
#include "minifyjpeg_clnt.c"

CLIENT *get_minify_client(char *server)
{
    CLIENT *clnt;
    /*
     * Create client "handle" used for
     * calling MINIFYJPEG on the server.
     */

     clnt = clnt_create(server, MINIFYJPEG_PROG, MINIFYJPEG_VERS, "tcp");

     if (clnt == (CLIENT *)NULL) {
     /*
      * Couldn't establish connectio with server.
      */

      clnt_pcreateerror(server);
      return NULL;
     }

     return clnt;
}

void* minify_via_rpc(CLIENT* clnt, void* src_val, size_t src_len,
                    size_t *dst_len) {
   /*
    * Use RPC to obtain a minified version of the jpeg image
    * stored in the array src_val and having src_len bytes.
    */
    minifyjpeg_out *result;
    minifyjpeg_in input;
    int rc;

    input.src.src_len = src_len;
    input.src.src_val = src_val;

    rc = minifyjpeg_proc_1(input, result, clnt);
    if (rc || result == NULL) {
    	/* An error occured while calling the server */
    	clnt_perror(clnt, "err");
    	return NULL;
    }
    *dst_len = result->dest.dest_len;

    return result->dest.dest_val;
}