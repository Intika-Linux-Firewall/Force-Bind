#!/bin/sh

export FORCE_NET_VERBOSE=999

#export FORCE_BIND_ADDRESS_V4=127.0.0.2
#export FORCE_BIND_PORT_V4=900

export LD_PRELOAD="${LD_PRELOAD}:./force_bind.so"

strace -o ${0}.strace -s200 -f "$@"
#debug "$@"
