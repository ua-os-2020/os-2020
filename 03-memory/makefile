OSYS := $(shell uname  -s)
$(info makefile for OS [${OSYS}])

ifeq ($(OSYS),Linux)
    CFLAGS=-Wall -O -g -Wuninitialized
endif
ifeq ($(OSYS),Darwin)
    CFLAGS=-Wall -O -g -Wuninitialized -Wl,-no_pie
    MEMLD = -Wl,-no_pie
endif

