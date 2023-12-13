### VARIABLES ###

CC = gcc
CFLAGS = -lgraph -ansi
SRCDIR = ./src
HDIR = ./include
ODIR = ./out
OFILES = $(subst src/,out/,$(subst .c,.o,$(shell find $(SRCDIR)/ -type f)))
EXE = snake

### BUT PAR DEFAUT ###

but : $(EXE)

### REGLES ESSENTIELLES ###

$(ODIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

$(EXE) : $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

### REGLES OPTIONNELLES ###

run : $(EXE)
	./$(EXE)

clean :
	-rm -rf $(ODIR)

mrproper :
	rm -rf snake

### BUTS FACTICES ###

.PHONY : but run clean mrproper
