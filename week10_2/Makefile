# top level Makefile

SUBDIRS = 1_fifo 2_pipe 3_queue 4_stream 5_datagram \
    6_stream_network 7_datagram_network

all install clean::
	for i in $(SUBDIRS); do \
	    echo "-- Making $@ in $$i"; \
	    ( cd $$i && $(MAKE) $(MFLAGS) $@ ); \
	    echo "-- Done making $@ in $$i"; \
	done

