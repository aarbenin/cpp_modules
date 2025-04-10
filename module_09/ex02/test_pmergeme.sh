#!/bin/bash

EXEC="./PmergeMe"

if [ ! -x "$EXEC" ]; then
    echo "Executable $EXEC not found. Compile the program first."
    exit 1
fi

function is_sorted() {
    local line="$1"
    local numbers
    numbers=$(echo "$line" | sed 's/^After:[[:space:]]*//')
    local prev=
    for num in $numbers; do
        if [ -n "$prev" ]; then
            if [ "$num" -lt "$prev" ]; then
                return 1
            fi
        fi
        prev="$num"
    done
    return 0
}

function run_test() {
    local desc="$1"
    shift
    local args=("$@")
    
    echo "----------------------------------"
    echo "Test: $desc"
    echo "Input: ${args[*]}"
    
    local output
    output=$("$EXEC" "${args[@]}" 2>&1)
    local ret=$?
    
    echo "Output:"
    echo "$output"
    
    if [ $ret -ne 0 ]; then
        if echo "$output" | grep -qx "Error"; then
            echo "-> PASS: Program correctly returned error."
        else
            echo "-> FAIL: Program returned error code $ret, but output is not just 'Error'."
        fi
        return
    fi
    
    local before_line=$(echo "$output" | grep "^Before:")
    local after_line=$(echo "$output" | grep "^After:")
    
    if [ -z "$before_line" ]; then
        echo "-> FAIL: No 'Before:' line found."
        return
    fi
    if [ -z "$after_line" ]; then
        echo "-> FAIL: No 'After:' line found."
        return
    fi
    
    is_sorted "$after_line"
    if [ $? -eq 0 ]; then
        echo "-> PASS: 'After:' sorted output is correct."
    else
        echo "-> FAIL: 'After:' sorted output is not in order."
    fi
}


function generate_large_input() {
    local count=3000
    local min=1
    local max=1000
    local result=()
    
    if command -v shuf > /dev/null; then
        result=($(shuf -i ${min}-${max} -n ${count}))
    elif command -v jot > /dev/null; then
        result=($(jot -r ${count} ${min} ${max}))
    elif [ -f "./large_input.txt" ]; then
        result=($(cat large_input.txt))
    else
        echo "No generator available and large_input.txt not found; skipping large input test."
        return 1
    fi
    
    echo "${result[@]}"
}

echo "Running tests for PmergeMe..."

run_test "Basic test" 3 5 9 7 4

run_test "Negative input" -1 2

run_test "Non-numeric input" 3 a 5

run_test "Zero input" 0

run_test "Single element" 42

run_test "Duplicates" 5 5 3 3 9 1

echo "Attempting to generate large input test with 3000 elements..."
LARGE_INPUT=$(generate_large_input)
if [ $? -eq 0 ]; then
    read -ra NUMS <<< "$LARGE_INPUT"
    run_test "Large input test" "${NUMS[@]}"
else
    echo "Large input test skipped."
fi

echo "----------------------------------"
echo "All tests completed."
