APP_NAME := compressGenerated

SRC := main.cpp path_iterate.cpp

CPPSRC 	:= $(filter %.cpp, $(SRC) )
CPPOBJ 	:= $(CPPSRC:.cpp=.o)
OBJ := $(CPPOBJ)
 
CP := cp
CAT := cat
CPP := g++
LD := ld
RM := rm -rf

#-fdiagnostics-color=auto for gcc 4.9 which isn't on Ubuntu 13 yet :(
TARGET := 
CPPFLAGS := -c -ftree-vectorize -ffast-math $(TARGET) -std=c++11 -O3 
LDFLAGS := -o $(APP_NAME) -lboost_filesystem -lboost_system

all: $(APP_NAME)
	@echo " "

$(APP_NAME): $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ)

.cpp.o:
	$(CPP) $(CPPFLAGS) $< -o $@

clean:
	$(RM) *.o *.elf
