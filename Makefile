include config.mk

SRC = drw.c dwm.c util.c
OBJ = ${SRC:.c=.o}

all: dwm clean

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ}

install: all
	sudo mkdir -p ${DESTDIR}${PREFIX}/bin
	sudo cp -f dwm ${DESTDIR}${PREFIX}/bin
	sudo chmod 755 ${DESTDIR}${PREFIX}/bin/dwm

uninstall:
	sudo rm -f ${DESTDIR}${PREFIX}/bin/dwm
