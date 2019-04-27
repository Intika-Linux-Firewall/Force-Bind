#!/bin/sh

export FORCE_NET_LOG="dillo.log"
export FORCE_NET_VERBOSE=999

export FORCE_BIND_ADDRESS_V4="192.168.79.33"
#export FORCE_BIND_PORT_V4=900

export LD_PRELOAD="${LD_PRELOAD}:./force_bind.so"

#strace -tt -f -o dillo-fb.strace -s200 dillo http://kernel.embedromix.ro
#strace -tt -f -o dillo-fb.strace -s200 dillo http://192.168.79.154
debug dillo http://kernel.embedromix.ro
