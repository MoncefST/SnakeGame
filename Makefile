### VARIABLES ###

CC = gcc
CFLAGS = -lgraph -ansi
SRCDIR = ./src
HDIR = ./include
ODIR = ./out
OFILES = $(subst src/,out/,$(subst .c,.o,$(shell find $(SRCDIR)/ -type f)))
EXE = game

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
	clean but

### BUTS FACTICES ###

.PHONY : but run clean mrproper
