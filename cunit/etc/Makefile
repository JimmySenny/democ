WORKDIR    = /home/jimmy/democ/cunit
#LUTILDIR   = /usr/local

CC         = gcc
CFLAG      = -g -Wall -fPIC -I${WORKDIR}/include 
#LD        = gcc

SHLIBEXT   = .so
SHLIBLDOPT = -shared -fPIC

AR         = ar
AROPT      = -curv

# ranlib 更新静态库的符号索引表
RANLIB     = ranlib

MAKE       = make

CLEANFILES = *.o

BINDIR     = ${WORKDIR}/bin
LIBDIR     = ${WORKDIR}/lib

MODULECFLGS= -g -Wall -fPIC -I${WORKDIR}/include 
DBCFLGS    = -g -Wall -fPIC -I${WORKDIR}/include -I.
#LUTILCFLGS = -I${LUTILDIR}/include -I${LUTILDIR}/include/CUnit

CFLAGS     = ${CFLAG} ${MODULECFLGS} ${DBCFLGS}  ${LUTILCFLGS}

.SUFFIXES: .c .o

.c.o:
	${CC} ${CFLAGS} -o $@ -c $<
