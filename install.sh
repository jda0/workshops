#!/usr/bin/env bash

ARDUINO_SKETCHBOOK="${1:-$HOME/sketchbook}"

if [[ ! -d "$ARDUINO_SKETCHBOOK" ]]; then
    echo "Cannot find arduino sketchbook, specify it as the arg to the cli"
    exit 1
fi

SKETCHES="blink bot wifi"

for sketch in $SKETCHES; do
    cp -r "$sketch" "$ARDUINO_SKETCHBOOK"
done

for library in libraries/*; do
    cp -r "$library" "${ARDUINO_SKETCHBOOK}/libraries"
done
