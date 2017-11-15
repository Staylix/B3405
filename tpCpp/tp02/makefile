RM = rm
ECHO = @echo
COMP = @g++
LINKER = @g++
RMFLAGS = -f
ECHOFLAGS = 
COMPFLAGS = -ansi -pedantic -Wall -std=c++11
EDLFLAGS =
DIRHEADERS =
HEADERS = $(wildcard *.h)
REAL = $(HEADERS:.h=.cpp) main.c
OBJ = $(REAL:.cpp=.o)
EXE = a.out
LIBS =
CLEAN = clean


PHONY = $(CLEAN)

$(EXE): $(OBJ)
	$(ECHO) "Linker de $(OBJ)"
	$(LINKER) -o $(EXE) $(OBJ) $(LIBS)

%.o: %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(COMPFLAGS) -c  -o $@ $<

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core

