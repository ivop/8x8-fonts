#! /bin/sh

if test "$#" != 2 ; then
    echo "usage: $0 file.fnt file.png"
    exit 1
fi

raw2pbm < "$1" | pnmscale 2 | pnmtopng > "$2"
