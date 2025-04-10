#!/bin/bash

EXEC="./RPN"

if [ ! -x "$EXEC" ]; then
    echo "Executable $EXEC not found. Please compile the program first."
    exit 1
fi

function run_test() {
    input="$1"
    expected="$2"
    desc="$3"

    result=$("$EXEC" "$input" 2>&1)
    if [ "$result" == "$expected" ]; then
        echo "PASS: $desc"
    else
        echo "FAIL: $desc"
        echo "  Input:    \"$input\""
        echo "  Expected: \"$expected\""
        echo "  Got:      \"$result\""
    fi
}

echo "Running tests for RPN..."

run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "Simple valid expression -> 42"
run_test "7 7 * 7 -" "42" "Valid expression (case 2) -> 42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0" "Valid expression -> 0"
run_test "1 2 -" "-1" "Expression producing negative result (-1)"
run_test "5 3 - 2 /" "1" "Expression (5 3 - 2 /) -> 1"
run_test "9 1 /" "9" "Division test: 9 divided by 1 -> 9"

run_test "(1 + 1)" "Error" "Expression with parentheses -> Error"

run_test "9 0 /" "Error" "Division by zero -> Error"

run_test "1 +" "Error" "Insufficient operands -> Error"

run_test "42" "Error" "Multi-digit token should be invalid -> Error"

run_test "1 2" "Error" "Extra operand remaining -> Error"

run_test "" "Error" "Empty expression -> Error"

run_test "    " "Error" "Whitespace-only expression -> Error"

run_test "a b +" "Error" "Invalid tokens (letters) -> Error"


overflow_expr=$(echo -n "9 9 *"; for i in {1..18}; do echo -n " 9 *"; done)
run_test "$overflow_expr" "Error" "Overflow in multiplication -> Error"

run_test "1 2 3 +" "Error" "Extra operands after evaluation -> Error"

echo "Tests completed."
