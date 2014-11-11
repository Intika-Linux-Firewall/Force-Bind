#!/bin/sh

# Test if we can fake bind a protocol

ulimit -c2000000

export FORCE_BIND_POLL_TIMEOUT=2000
export FORCE_NET_VERBOSE=1
export FORCE_NET_LOG="${0}.log"

export LD_PRELOAD="${LD_PRELOAD}:./force_bind.so"

make test_poll
#strace -f -s200 -o ${0}.strace ./test_poll
debug ./test_poll
