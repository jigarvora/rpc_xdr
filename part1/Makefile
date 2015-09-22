CC     = gcc
CFLAGS = -Wall -g

LIBS = -lpthread

MAGICK_FLAGS = `pkg-config --cflags MagickCore`
MAGICK_LIBS = `pkg-config --libs MagickCore`

#### RPC Client Part ####
all: minifyjpeg_main minifyjpeg_svc

magickminify.o: magickminify.c
	$(CC) -c $^ $(MAGICK_FLAGS)

magickminify_test.o: magickminify_test.c
	$(CC) -c $^ $(MAGICK_FLAGS)

magickminify_test: magickminify.o magickminify_test.o
	$(CC) -o $@ -Wall $(MAGICK_FLAGS) $(MAGICK_LIBS) $^

minifyjpeg_main: minifyjpeg_main.o minify_via_rpc.o steque.o
	$(CC) -o $@ $(CFLAGS) $^  $(LIBS)

minifyjpeg_svc: minifyjpeg_svc.o  minifyjpeg_xdr.o minifyjpeg.o magickminify.o steque.o
	$(CC) -o $@ $(CFLAGS) $(MAGICK_FLAGS) -DRPC_SVC_FG $^  $(LIBS) $(MAGICK_LIBS)

#### Cleanup ####
clean:
	rm -f *.o magickminify_test minifyjpeg_main minifyjpeg_svc *small*

