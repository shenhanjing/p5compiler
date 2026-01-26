"""P5 precompiler utilities.

This package extracts the P5 directory preprocessing logic from p4c's driver:
- recursively find .p5 files in a directory
- preprocess each file to a .p4i using a C preprocessor
- merge all produced .p4i files into a single merged .p4i
"""

