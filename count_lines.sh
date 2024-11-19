#!/bin/bash

count_lines() {
    local total_lines=0
    local file_count=0

    while IFS= read -r -d '' file; do
        local lines=$(wc -l < "$file")
        total_lines=$((total_lines + lines))
        file_count=$((file_count + 1))
        echo "Файл: $file, Строк: $lines"
    done < <(find . -type f \( -name "*.hpp" -o -name "*.cpp" \) -print0)

    echo "Всего файлов: $file_count"
    echo "Всего строк: $total_lines"
}

count_lines