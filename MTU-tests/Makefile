# SPDX-License-Identifier: (GPL-2.0 OR BSD-2-Clause)

USER_TARGETS :=
BPF_TARGETS := tc_bpf_inc_pkt_size
EXTRA_DEPS := encap.h

LIB_DIR = ../lib

include $(LIB_DIR)/common.mk

# The iproute2 'tc' tool doesn't understand BTF debug info
# use llvm-strip to remove this debug info from object file
.PHONY: strip_tc_obj
strip_tc_obj: tc_bpf_inc_pkt_size.o
	$(Q) llvm-strip $?

all: strip_tc_obj