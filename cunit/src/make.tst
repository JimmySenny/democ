include ../etc/Makefile

BIN_NAME = demo_cunit

OBJ_LIB  = ${WORKDIR}/lib/libcu_tst.a ${WORKDIR}/lib/libcu_array.a

EXECOBJ  = ${WORKDIR}/bin/${BIN_NAME}.out

LINKRULE = ${CC} -o ${EXECOBJ} ${OBJ_LIB} -L${WORKDIR}/lib -lcu_tst -lcu_array -lcunit
#-L${LUTILDIR}/lib -llutil

TARGETS  = ${EXECOBJ}

all:${TARGETS}

${EXECOBJ}: ${OBJ_LIB}
	${LINKRULE}

clean:
	@- rm -f ${TARGETS} ${CLEANFILES}
