VERSION=1.0.0

TOOLS_DIR	=
NAME_MODULE	= iCamera
NAME_LIB	= 
OPTIMIZE	= -Wall -O2 
PROJECT_DIR = $(PWD)
OBJ_DIR=${PROJECT_DIR}/build
OUT_DIR=${PROJECT_DIR}/output

include $(PROJECT_DIR)/Makefile.conf

CROSS_COMPILE=mips-linux-uclibc-gnu-
CPP	  =$(CROSS_COMPILE)g++
CC	  =$(CROSS_COMPILE)gcc
AR	  =$(CROSS_COMPILE)ar
STRIP =$(CROSS_COMPILE)strip

CFLAGS += $(OPTIMIZE) -lpthread -lm -lrt -ldl 

# sources include  
CFLAGS += -I$(PROJECT_DIR)/sources
CFLAGS += -I$(PROJECT_DIR)/sources/app
CFLAGS += -I$(PROJECT_DIR)/sources/app/video
CFLAGS += -I$(PROJECT_DIR)/sources/utils

# dependencies
CFLAGS += -I
CFLAGS += -L
LIBS +=

# add path sources c
CSRCS += $(wildcard sources/*.c)
CSRCS += $(wildcard sources/app/*.c)
CSRCS += $(wildcard sources/utils/*.c)
CSRCS += $(wildcard sources/app/video/*.c)
OBJS  += $(patsubst %.c, $(OBJ_DIR)/%.o, $(CSRCS))

CFLAGS += -g -lpthread -lrt -ldl

.PHONY : create all clean flash

$(OBJ_DIR)/%.o: %.c
	@echo "build $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

$(OBJ_DIR)/$(NAME_MODULE): $(OBJS)
	@$(CC) -o $(OBJ_DIR)/$(NAME_MODULE) $^  $(CFLAGS) ${LIBS}
	@echo "---------- build $(NAME_MODULE) release ----------"

all: create $(OBJ_DIR)/$(NAME_MODULE)
	@cp -r $(OBJ_DIR)/$(NAME_MODULE) $(OUT_DIR)
create:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OUT_DIR)

clean:
	@rm -rf $(OUT_DIR)
	@rm -rf $(OBJ_DIR)
flash:
	@sudo cp -r $(OBJ_DIR)/$(NAME_MODULE) $(NFS_DIR)
