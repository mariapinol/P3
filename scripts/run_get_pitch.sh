#!/bin/bash

# Put here the program (maybe with path)
GETF0="get_pitch"
if [ -z "$1" ]; then
    pow_th=51.5
else
    pow_th=$1
fi

if [ -z "$2" ]; then
    r1_th=0.6
else
    r1_th=$2
fi

if [ -z "$3" ]; then
    rmax_th=0.25
else
    rmax_th=$3
fi
for fwav in pitch_db/train/*.wav; do
    ff0=${fwav/.wav/.f0}
    echo "$GETF0 $fwav $ff0 ----"
    $GETF0 $fwav $ff0 $pow_th $r1_th $rmax_th> /dev/null || (echo "Error in $GETF0 $fwav $ff0"; exit 1)
done

exit 0