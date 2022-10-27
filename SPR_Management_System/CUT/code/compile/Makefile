##########################################################
# Created by:- group2   
# date :- 26-10-22
##########################################################


SRCDIR = ../src
EXTDIR = ../external
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR




all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/iofiles/linkedlistio.c -o ${OBJDIR}/linkedlistio.o
	gcc ${CFLAGS}  ${SRCDIR}/create_spr/createutilities.c -o ${OBJDIR}/createutil.o
	gcc ${CFLAGS}  ${SRCDIR}/show_spr/showutility.c -o ${OBJDIR}/showutil.o
	gcc ${CFLAGS}  ${SRCDIR}/modify_spr/modifyutilities.c -o ${OBJDIR}/modifyutil.o
	gcc ${CFLAGS}  ${EXTDIR}/log.c -o ${OBJDIR}/log.o
	gcc ${CFLAGS}  ${SRCDIR}/create_spr/maincreate.c -o ${OBJDIR}/mcreate.o
	gcc ${CFLAGS}  ${SRCDIR}/authenticate_user/hashutilities.c -o ${OBJDIR}/hashutil.o
	gcc ${CFLAGS}  ${SRCDIR}/modify_spr/mainmodify.c -o ${OBJDIR}/mmodify.o
	gcc ${CFLAGS}  ${SRCDIR}/authenticate_user/authenticate.c -o ${OBJDIR}/auc.o
	gcc ${CFLAGS}  ${SRCDIR}/authenticate_user/mainlogin.c -o ${OBJDIR}/login.o
	gcc ${CFLAGS}  ${SRCDIR}/show_spr/mainshow.c -o ${OBJDIR}/mshow.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/createutil.o ${OBJDIR}/mmodify.o ${OBJDIR}/mshow.o ${OBJDIR}/auc.o ${OBJDIR}/login.o ${OBJDIR}/mcreate.o ${OBJDIR}/hashutil.o ${OBJDIR}/log.o ${OBJDIR}/showutil.o ${OBJDIR}/modifyutil.o ${OBJDIR}/linkedlistio.o -o ${BINDIR}/spr_bin.bin


memcheck:
	valgrind ${BINDIR}/spr_bin.bin > ${REPORTDIR}/memcheck.txt 2>&1

clean:

	rm ${OBJDIR}/main.o ${OBJDIR}/createutil.o ${OBJDIR}/mmodify.o ${OBJDIR}/mshow.o ${OBJDIR}/auc.o ${OBJDIR}/login.o ${OBJDIR}/mcreate.o ${OBJDIR}/hashutil.o ${OBJDIR}/log.o ${OBJDIR}/showutil.o ${OBJDIR}/modifyutil.o ${OBJDIR}/linkedlistio.o -o ${BINDIR}/spr_bin.bin

#################### End of Makefile #####################
