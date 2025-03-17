#!/bin/bash

find . -type f -print | while read file; do
    echo "======================="
    echo "File: $file"
    echo "======================="
    cat "$file"
    echo ""
done > view.out
