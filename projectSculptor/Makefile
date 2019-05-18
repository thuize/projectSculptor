

include doc/help.mk

PROG = projectSculptor

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
DOCDIR = ./doc

CC = g++
CFLAGS = -g -Wall -pedantic -std=c++11 -I$(INCDIR)
RM = rm

HEADERS := $(wildcard $(INCDIR)/*)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)



all: project ##@Compilar Compila o programa.


project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(BINDIR)/$(PROG)
	doxygen Doxyfile
	@echo -e "\033[44;5mDoxygen Work better with Graphviz...\033[0m"


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# Clean PHONY targets
.PRONY: clean clean_proj

clean: clean_proj ##@Clean Limpa a pasta obj e bin.

clean_proj:
	@echo "Removing OBJDIR..."
	@$(RM) -r $(OBJDIR)
	@echo "Removing BINDIR..."
	@$(RM) -r $(BINDIR)
	@$(RM) -f $(PROG)
	@echo "Removing DOCUMENTATION..."
	@find doc -type f ! -name 'help.mk' -delete
	@echo "Clean-up completed!"
