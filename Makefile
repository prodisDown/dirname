# See LICENSE file for copyright and license details.

NAME = dirname
CC = cc

SRC = ${NAME}.c
HEADER = ${NAME}.h

CFLAGS = -std=c17 -pedantic -Wall -Wextra -Werror -Os
LDFLAGS = -s

demo: ${NAME}

${NAME}: ${SRC} ${HEADER}
	@echo CC -o $@
	@${CC} -o $@ ${SRC} ${CFLAGS} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f ${NAME} ${NAME}.S

asm: ${SRC} ${HEADER}
	@echo compile to asm
	@${CC} -S -o ${NAME}.S ${SRC} ${CFLAGS}

.PHONY: demo clean asm
