#!/bin/bash

for file in snippets/*.h; do
    if [ -f "$file" ]; then
        echo "Format $file"
        clang-format -i "$file"
    fi
done
