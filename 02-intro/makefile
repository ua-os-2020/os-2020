OSYS := $(shell uname  -s)
$(info makefile for OS [${OSYS}])

ifeq ($(OSYS),Linux)
    MEMLD = 
endif
ifeq ($(OSYS),Darwin)
    MEMLD = -Wl,-no_pie
endif

CFLAGS=-Wall -O -Wuninitialized
TCPU=11-cpu
OCPU=common.o 11-cpu.o
TMEM=12-mem
OMEM=common.o 12-mem.o
TRC1=13-race1
TRC2=14-race2
ORC2=common.o 14-race2.o
TPER=15-io

all: $(TCPU) $(TMEM) $(TRC1) $(TRC2) $(TPER)

$(TCPU):	$(OCPU)
	$(CC) -o$(TCPU) $(OCPU)

$(TMEM):	$(OMEM)
	$(CC) -o$(TMEM) $(OMEM) $(MEMLD)

$(TRC2):	$(ORC2)
	$(CC) -o$(TRC2) $(ORC2) -pthread

common.o:	    common.h
11-cpu.o:	    common.h
12-mem.o:       common.h
14-race2.o:     common.h common_threads.h

clean:
	-rm *.o $(TCPU) $(TMEM) $(TRC1) $(TRC2) $(TPER)
