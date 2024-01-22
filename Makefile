VERSION=1.0.0

TOOLS_DIR	=
NAME_MODULE	= iCamera
NAME_LIB	= 
OPTIMIZE	= -Wall -O2 -std=gnu99
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
CFLAGS += -I$(PROJECT_DIR)/sources/app/webrtc
CFLAGS += -I$(PROJECT_DIR)/sources/app/common
CFLAGS += -I$(PROJECT_DIR)/sources/utils

# dependencies
CFLAGS += -I
CFLAGS += -L
LIBS +=

# webrtc 
CFLAGS += -I${AWS_PATH}/aws-dependencies/webrtc/include
CFLAGS += -I${AWS_PATH}/aws-dependencies/webrtc/include/com/amazonaws/kinesis/video

# LIBS+=${AWS_PATH}/libembedded-media.a
LIBS+=${AWS_PATH}/samples/webrtc/kvs-webrtc-prefix/src/kvs-webrtc-build/libkvsWebrtcClient.a
LIBS+=${AWS_PATH}/samples/webrtc/kvs-webrtc-prefix/src/kvs-webrtc-build/libkvsWebrtcSignalingClient.a

LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvsCommonLws.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvspic.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvspicClient.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvspicState.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvspicUtils.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvsWebrtcClient.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libkvsWebrtcSignalingClient.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libsrtp2.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libusrsctp.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libwebsockets.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libmbedtls.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libmbedx509.a
LIBS+=${AWS_PATH}/aws-dependencies/webrtc/lib/libmbedcrypto.a


# add path sources c
CSRCS += $(wildcard sources/*.c)
CSRCS += $(wildcard sources/app/*.c)
CSRCS += $(wildcard sources/utils/*.c)
CSRCS += $(wildcard sources/app/video/*.c)
CSRCS += $(wildcard sources/app/webrtc/*.c)
CSRCS += $(wildcard sources/app/common/*.c)

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
