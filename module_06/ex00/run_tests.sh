#!/bin/bash

BIN=./convert

valid_literals=(
    "0"
    "nan"
    "42.0f"
    "-42"
    "+42"
    "+inf"
    "-inff"
    "a"
    "'a'"
    "-42.0f"
    "+42.0f"
    "42."
    ".42"
    "42.f"
    "-42.f"
    ".42f"
    ".05"
    ".0f"
    "-.3"
    "+.2"
)

edge_cases=(
    "999999999999999999999999"
    "2147483648"
    "3.4028235e+38f"
    "1.7976931348623157e+308"
    ""
)

strange_cases=(
    "42.0fdasd"
    "42.0ff"
    "nanf42"
    "42a"
    "'ab'"
    "hello"
    "'"
    "''"
    "'''"
    "'\"'\"'\""
    ".f"
    "-.f"
    "+f"
    "f"
    "+-42"
    "-+42"
    "++42"
    "--42"
    "4 2"
    "4.2.3"
    "."
    "..."
    "fff"
    "f.f.f"
    "na"
    "nannan"
    "nan123"
    "f42."
    ".f."
    "🤡"
)

run_section() {
    local title=$1
    shift
    local section=("$@")
    local index=1

    echo -e "\n======= $title ======="
    for test in "${section[@]}"; do
        printf "\n[%03d] Test input: [%s]\n" "$index" "$test"
        echo "----------------------------"
        if [ -z "$test" ]; then
            echo "(Empty input)"
        fi
        $BIN "$test"
        echo "============================"
        index=$((index + 1))
    done
}

counter=1
run_section_with_counter() {
    local title=$1
    shift
    local section=("$@")

    echo -e "\n======= $title ======="
    for test in "${section[@]}"; do
        printf "\n[%03d] Test input: [%s]\n" "$counter" "$test"
        echo "----------------------------"
        if [ -z "$test" ]; then
            echo "(Empty input)"
        fi
        $BIN "$test"
        echo "============================"
        counter=$((counter + 1))
    done
}


run_section_with_counter "Valid literals" "${valid_literals[@]}"
run_section_with_counter "Edge and extreme cases" "${edge_cases[@]}"
run_section_with_counter "Strange inputs" "${strange_cases[@]}"
