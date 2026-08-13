# TODO LIST


## writebit done
Build bit accumulation + automatic byte flushing.
## frequency done
Read the input and produce counts[256].
## heap current
Priority queue/min-heap for selecting the lowest-frequency nodes.
## huffman
Build the Huffman tree from the frequency table and generate codes.
## encoder
Use the Huffman codes + writebit to produce the compressed data.
## File format design
Decide how the tree/header, original size, padding, etc. are represented.
## readbit
Build the bit reader based on the format you've actually designed.
## decoder
Read the compressed file and reconstruct the original data.
## Integration + testing
Compress → decompress → verify the result matches the original.