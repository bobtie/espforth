#!/bin/bash

# Input and output files
INPUT_FILE="main/espforth.c"
PREPROCESSED_FILE="main/espforth_i.c"

# Temporary files
HEAD_FILE="/tmp/head.c"
TAIL_FILE="/tmp/tail.c"

# Step 1: Extract head of source.c up to and including the line containing 'TAG'
sed '/TAG/ q' "$INPUT_FILE" > "$HEAD_FILE"

# Step 2: Preprocess source.c using cpp
cpp "$INPUT_FILE" | grep -v ' *# [0-9]' > "$PREPROCESSED_FILE"

# Step 3: Extract tail of preprocessed file (everything after the line containing 'TAG')
awk '/TAG/ {f=1; next} f' "$PREPROCESSED_FILE" > "$TAIL_FILE"

# Step 4: Combine the original head and the preprocessed tail
cat "$HEAD_FILE" "$TAIL_FILE" > "$PREPROCESSED_FILE"

# Step 5: Clean up temporary files
rm "$HEAD_FILE" "$TAIL_FILE"

echo "Processed file saved as $PREPROCESSED_FILE"

clang-format -i $PREPROCESSED_FILE

echo "Reformatted file saved as $PREPROCESSED_FILE"
