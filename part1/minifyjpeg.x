struct minifyjpeg_in {
  opaque src<>;
};

struct minifyjpeg_out {
  opaque dest<>;
};

program MINIFYJPEG_PROG { /* RPC service name */
  version MINIFYJPEG_VERS {
    minifyjpeg_out MINIFYJPEG_PROC(minifyjpeg_in) = 1; /* proc1 */
  } = 1; /* version1 */
} = 0x31230000; /* service id */
