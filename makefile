# Compiler settings - Can be changed
CC = g++

CCFLAGS  = -m64 -std=gnu++2b
CCFLAGS += -Wall
CCFLAGS += -Wextra
CCFLAGS += -Wpedantic
CCFLAGS += -O2 -g
CCFLAGS += $(INCFLAGS)

INCFLAGS  = -iquotesrc
INCFLAGS += -I ./include

LDFLAGS = -lm -lstdc++

UNAME = $(shell uname -s)

ifeq ($(UNAME), windows)
	LDFLAGS += -luser32
endif

# Makefile settings - Can be changed
APPNAME = ./bin/hsc.exe
EXT = .cpp
SRCDIR = ./src
OBJDIR = ./bin/obj
DEPDIR = ./bin/dep

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/ssss%.d)

# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)

# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)
all: $(APPNAME)

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CCFLAGS) -o $@ -c $<

# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)

# Cleans complete project
.PHONY: cleanw
cleanw:
	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# Cleans only all files with the extension .d
.PHONY: cleandepw
cleandepw:
	$(DEL) $(DEP)