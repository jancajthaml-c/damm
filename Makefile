OUTDIR=dist
CFLAGS= -O2

.PHONY: default clean

default: test clean

$(OUTDIR):
	@mkdir -p $(OUTDIR)

test: $(OUTDIR) $(OUTDIR)/damm.o $(OUTDIR)/main.o
	gcc $(CFLAGS) $(OUTDIR)/damm.o $(OUTDIR)/main.o -o test
	./test

$(OUTDIR)/damm.o: damm.c
	gcc $(CFLAGS) -o $(OUTDIR)/damm.o -c $^

$(OUTDIR)/main.o: main.c
	gcc $(CFLAGS) -o $(OUTDIR)/main.o -c $^ 

clean:
	@rm -f test
	@rm -rf $(OUTDIR)
