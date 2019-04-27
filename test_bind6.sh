#!/bin/sh

export FORCE_NET_VERBOSE=1
export FORCE_NET_TOS="0x0f"
export FORCE_NET_KA=60
export FORCE_NET_MSS=1400
export FORCE_NET_REUSEADDR=1
export FORCE_NET_NODELAY=1
export FORCE_BIND_ADDRESS_V6=::1

export LD_PRELOAD="${LD_PRELOAD}:./force_bind.so"

#debug ./test_bind6
strace -s200 -f ./test_bind6
