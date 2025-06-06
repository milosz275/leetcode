#!/bin/bash
set -e

parent_dir=$(dirname "$(dirname "$(readlink -f "$0")")")
output_dir="$parent_dir/docs"

find "$output_dir" -mindepth 1 -maxdepth 1 -type d -exec rm -rf {} +

for dir in "$parent_dir"/*/; do
    dir_name=$(basename "$dir")

    if [[ "$dir_name" =~ ^(docs|.vscode|.git|.notes)$ ]]; then
        continue
    fi

    # C/C++
    if [ -f "$dir/Doxyfile" ]; then
        echo "Generating Doxygen for $dir_name"
        (
            cd "$dir"
            doxygen
        )
    fi

    # Python
    if [ -f "$dir/mkdocs.yml" ]; then
        echo "Generating MkDocs for $dir_name"
        mkdocs build -f "$dir/mkdocs.yml" -d "$output_dir/$dir_name"
    fi
done
