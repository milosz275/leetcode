#!/bin/bash
parent_dir=$(dirname "$(dirname "$(readlink -f "$0")")")

for dir in "$parent_dir"/*/; do
    dir_name=$(basename "$dir")
    if [[ "$dir_name" != "doc" && "$dir_name" != ".vscode" && "$dir_name" != ".git" && "$dir_name" != ".notes" ]];
    then
        cd "$dir" && doxygen
    fi
done
