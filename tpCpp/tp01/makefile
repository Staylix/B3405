RM = rm
ECHO = @echo
COMP = @g++
LINKER = @g++
RMFLAGS = -f
ECHOFLAGS = 
COMPFLAGS = -g 
EDLFLAGS =
DIRHEADERS = ./
HEADERS = SClasse.h
REAL = SClasse.cpp Main.cpp
OBJ = $(REAL:.cpp=.o)
EXE = a.out
LIBS =
CLEAN = clean
OUTPUT = build/


PHONY = $(CLEAN)

$(EXE): $(OBJ)
	$(ECHO) "Linker de $(OBJ)"
	$(LINKER) -o $(EXE) $(OUTPUT)$(OBJ) $(LIBS)

%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(COMPFLAGS) -c -I $(DIRHEADERS) -o $(OUTPUT)$@ $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core

