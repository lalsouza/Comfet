install: comfet
	cp comfet $(COMFET_DIR)/Tests ; cp comfet.c $(COMFET_DIR)/Tests ;\
	cp tokens.h $(COMFET_DIR)/include

comfet: scanner.l tokens.h
	flex -o comfet.c scanner.l; \
	gcc -o comfet comfet.c 

clean:
	/bin/rm -f comfet comfet.c
