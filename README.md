# Text Frequency Analyzer
A C++ command-line program that reads standard input and counts the most frequently used:
- Characters (including newline)
- Words (case-insensitive)
- Numbers

It displays the **top 10 of each category**, sorted by frequency and by order of first appearance in case of ties.

---
## Features

- Case-insensitive word grouping
- Number token grouping
- Tracks newline character usage
- Sorts by frequency, then by order of appearance
- Formatted output with alignment

---
## Build & Run

```bash
make
./proj1 < input.txt
