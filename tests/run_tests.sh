#!/bin/sh

set -e
set -u

# Execute unit tests
ctest --no-compress-output --schedule-random -T Test $@ || true

