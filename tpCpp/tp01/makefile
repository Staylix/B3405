RM = rm
ECHO = @echo
COMP = @g++
LINKER = @g++
RMFLAGS = -f
ECHOFLAGS = 
COMPFLAGS =
EDLFLAGS =
DIRHEADERS = ./
HEADERS = Ensemble.cpp
REAL = $(HEADERS:.h=.cpp) Main.cpp
OBJ = $(REAL:.cpp=.o)
EXE = a.out
LIBS =
CLEAN = clean
OUTPUT = 


PHONY = $(CLEAN)

$(EXE): $(OBJ)
	$(ECHO) "Linker de $(OBJ)"
	$(LINKER) -o $(EXE) $(OBJ) $(LIBS)

%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(COMPFLAGS) -c -I $(DIRHEADERS) -o $(OUTPUT)$@ $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OUTPUT)*.o core
	$(ECHO) "Repertory cleaned !"

