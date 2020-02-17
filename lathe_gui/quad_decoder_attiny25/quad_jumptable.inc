; Quadrature decoder jump table. Generated by GenerateSamplesDecoder.java program; 256 combinations of 4 consecutive samples.
;  * That would be hard and error prone to write by hand.
;  * The stdout of this program was copy-pasted into the quad decoder asm program.
.org 0b0100000000		; 00->00->00->00 000
	rjmp process_unchanged
.org 0b0100000001		; 00->00->00->01 00-
	rjmp process_dec1
.org 0b0100000010		; 00->00->01->00 0-+
	rjmp process_unchanged
.org 0b0100000011		; 00->00->01->01 0-0
	rjmp process_dec1
.org 0b0100000100		; 00->00->00->10 00+
	rjmp process_inc1
.org 0b0100000101		; 00->00->00->11 00E
	rjmp process_error
.org 0b0100000110		; 00->00->01->10 0-E
	rjmp process_error
.org 0b0100000111		; 00->00->01->11 0--
	rjmp process_dec2
.org 0b0100001000		; 00->00->10->00 0+-
	rjmp process_unchanged
.org 0b0100001001		; 00->00->10->01 0+E
	rjmp process_error
.org 0b0100001010		; 00->00->11->00 0EE
	rjmp process_error
.org 0b0100001011		; 00->00->11->01 0E+
	rjmp process_error
.org 0b0100001100		; 00->00->10->10 0+0
	rjmp process_inc1
.org 0b0100001101		; 00->00->10->11 0++
	rjmp process_inc2
.org 0b0100001110		; 00->00->11->10 0E-
	rjmp process_error
.org 0b0100001111		; 00->00->11->11 0E0
	rjmp process_error
.org 0b0100010000		; 01->00->00->00 +00
	rjmp process_inc1
.org 0b0100010001		; 01->00->00->01 +0-
	rjmp process_unchanged
.org 0b0100010010		; 01->00->01->00 +-+
	rjmp process_inc1
.org 0b0100010011		; 01->00->01->01 +-0
	rjmp process_unchanged
.org 0b0100010100		; 01->00->00->10 +0+
	rjmp process_inc2
.org 0b0100010101		; 01->00->00->11 +0E
	rjmp process_error
.org 0b0100010110		; 01->00->01->10 +-E
	rjmp process_error
.org 0b0100010111		; 01->00->01->11 +--
	rjmp process_dec1
.org 0b0100011000		; 01->00->10->00 ++-
	rjmp process_inc1
.org 0b0100011001		; 01->00->10->01 ++E
	rjmp process_error
.org 0b0100011010		; 01->00->11->00 +EE
	rjmp process_error
.org 0b0100011011		; 01->00->11->01 +E+
	rjmp process_error
.org 0b0100011100		; 01->00->10->10 ++0
	rjmp process_inc2
.org 0b0100011101		; 01->00->10->11 +++
	rjmp process_inc3
.org 0b0100011110		; 01->00->11->10 +E-
	rjmp process_error
.org 0b0100011111		; 01->00->11->11 +E0
	rjmp process_error
.org 0b0100100000		; 00->01->00->00 -+0
	rjmp process_unchanged
.org 0b0100100001		; 00->01->00->01 -+-
	rjmp process_dec1
.org 0b0100100010		; 00->01->01->00 -0+
	rjmp process_unchanged
.org 0b0100100011		; 00->01->01->01 -00
	rjmp process_dec1
.org 0b0100100100		; 00->01->00->10 -++
	rjmp process_inc1
.org 0b0100100101		; 00->01->00->11 -+E
	rjmp process_error
.org 0b0100100110		; 00->01->01->10 -0E
	rjmp process_error
.org 0b0100100111		; 00->01->01->11 -0-
	rjmp process_dec2
.org 0b0100101000		; 00->01->10->00 -E-
	rjmp process_error
.org 0b0100101001		; 00->01->10->01 -EE
	rjmp process_error
.org 0b0100101010		; 00->01->11->00 --E
	rjmp process_error
.org 0b0100101011		; 00->01->11->01 --+
	rjmp process_dec1
.org 0b0100101100		; 00->01->10->10 -E0
	rjmp process_error
.org 0b0100101101		; 00->01->10->11 -E+
	rjmp process_error
.org 0b0100101110		; 00->01->11->10 ---
	rjmp process_dec3
.org 0b0100101111		; 00->01->11->11 --0
	rjmp process_dec2
.org 0b0100110000		; 01->01->00->00 0+0
	rjmp process_inc1
.org 0b0100110001		; 01->01->00->01 0+-
	rjmp process_unchanged
.org 0b0100110010		; 01->01->01->00 00+
	rjmp process_inc1
.org 0b0100110011		; 01->01->01->01 000
	rjmp process_unchanged
.org 0b0100110100		; 01->01->00->10 0++
	rjmp process_inc2
.org 0b0100110101		; 01->01->00->11 0+E
	rjmp process_error
.org 0b0100110110		; 01->01->01->10 00E
	rjmp process_error
.org 0b0100110111		; 01->01->01->11 00-
	rjmp process_dec1
.org 0b0100111000		; 01->01->10->00 0E-
	rjmp process_error
.org 0b0100111001		; 01->01->10->01 0EE
	rjmp process_error
.org 0b0100111010		; 01->01->11->00 0-E
	rjmp process_error
.org 0b0100111011		; 01->01->11->01 0-+
	rjmp process_unchanged
.org 0b0100111100		; 01->01->10->10 0E0
	rjmp process_error
.org 0b0100111101		; 01->01->10->11 0E+
	rjmp process_error
.org 0b0100111110		; 01->01->11->10 0--
	rjmp process_dec2
.org 0b0100111111		; 01->01->11->11 0-0
	rjmp process_dec1
.org 0b0101000000		; 10->00->00->00 -00
	rjmp process_dec1
.org 0b0101000001		; 10->00->00->01 -0-
	rjmp process_dec2
.org 0b0101000010		; 10->00->01->00 --+
	rjmp process_dec1
.org 0b0101000011		; 10->00->01->01 --0
	rjmp process_dec2
.org 0b0101000100		; 10->00->00->10 -0+
	rjmp process_unchanged
.org 0b0101000101		; 10->00->00->11 -0E
	rjmp process_error
.org 0b0101000110		; 10->00->01->10 --E
	rjmp process_error
.org 0b0101000111		; 10->00->01->11 ---
	rjmp process_dec3
.org 0b0101001000		; 10->00->10->00 -+-
	rjmp process_dec1
.org 0b0101001001		; 10->00->10->01 -+E
	rjmp process_error
.org 0b0101001010		; 10->00->11->00 -EE
	rjmp process_error
.org 0b0101001011		; 10->00->11->01 -E+
	rjmp process_error
.org 0b0101001100		; 10->00->10->10 -+0
	rjmp process_unchanged
.org 0b0101001101		; 10->00->10->11 -++
	rjmp process_inc1
.org 0b0101001110		; 10->00->11->10 -E-
	rjmp process_error
.org 0b0101001111		; 10->00->11->11 -E0
	rjmp process_error
.org 0b0101010000		; 11->00->00->00 E00
	rjmp process_error
.org 0b0101010001		; 11->00->00->01 E0-
	rjmp process_error
.org 0b0101010010		; 11->00->01->00 E-+
	rjmp process_error
.org 0b0101010011		; 11->00->01->01 E-0
	rjmp process_error
.org 0b0101010100		; 11->00->00->10 E0+
	rjmp process_error
.org 0b0101010101		; 11->00->00->11 E0E
	rjmp process_error
.org 0b0101010110		; 11->00->01->10 E-E
	rjmp process_error
.org 0b0101010111		; 11->00->01->11 E--
	rjmp process_error
.org 0b0101011000		; 11->00->10->00 E+-
	rjmp process_error
.org 0b0101011001		; 11->00->10->01 E+E
	rjmp process_error
.org 0b0101011010		; 11->00->11->00 EEE
	rjmp process_error
.org 0b0101011011		; 11->00->11->01 EE+
	rjmp process_error
.org 0b0101011100		; 11->00->10->10 E+0
	rjmp process_error
.org 0b0101011101		; 11->00->10->11 E++
	rjmp process_error
.org 0b0101011110		; 11->00->11->10 EE-
	rjmp process_error
.org 0b0101011111		; 11->00->11->11 EE0
	rjmp process_error
.org 0b0101100000		; 10->01->00->00 E+0
	rjmp process_error
.org 0b0101100001		; 10->01->00->01 E+-
	rjmp process_error
.org 0b0101100010		; 10->01->01->00 E0+
	rjmp process_error
.org 0b0101100011		; 10->01->01->01 E00
	rjmp process_error
.org 0b0101100100		; 10->01->00->10 E++
	rjmp process_error
.org 0b0101100101		; 10->01->00->11 E+E
	rjmp process_error
.org 0b0101100110		; 10->01->01->10 E0E
	rjmp process_error
.org 0b0101100111		; 10->01->01->11 E0-
	rjmp process_error
.org 0b0101101000		; 10->01->10->00 EE-
	rjmp process_error
.org 0b0101101001		; 10->01->10->01 EEE
	rjmp process_error
.org 0b0101101010		; 10->01->11->00 E-E
	rjmp process_error
.org 0b0101101011		; 10->01->11->01 E-+
	rjmp process_error
.org 0b0101101100		; 10->01->10->10 EE0
	rjmp process_error
.org 0b0101101101		; 10->01->10->11 EE+
	rjmp process_error
.org 0b0101101110		; 10->01->11->10 E--
	rjmp process_error
.org 0b0101101111		; 10->01->11->11 E-0
	rjmp process_error
.org 0b0101110000		; 11->01->00->00 ++0
	rjmp process_inc2
.org 0b0101110001		; 11->01->00->01 ++-
	rjmp process_inc1
.org 0b0101110010		; 11->01->01->00 +0+
	rjmp process_inc2
.org 0b0101110011		; 11->01->01->01 +00
	rjmp process_inc1
.org 0b0101110100		; 11->01->00->10 +++
	rjmp process_inc3
.org 0b0101110101		; 11->01->00->11 ++E
	rjmp process_error
.org 0b0101110110		; 11->01->01->10 +0E
	rjmp process_error
.org 0b0101110111		; 11->01->01->11 +0-
	rjmp process_unchanged
.org 0b0101111000		; 11->01->10->00 +E-
	rjmp process_error
.org 0b0101111001		; 11->01->10->01 +EE
	rjmp process_error
.org 0b0101111010		; 11->01->11->00 +-E
	rjmp process_error
.org 0b0101111011		; 11->01->11->01 +-+
	rjmp process_inc1
.org 0b0101111100		; 11->01->10->10 +E0
	rjmp process_error
.org 0b0101111101		; 11->01->10->11 +E+
	rjmp process_error
.org 0b0101111110		; 11->01->11->10 +--
	rjmp process_dec1
.org 0b0101111111		; 11->01->11->11 +-0
	rjmp process_unchanged
.org 0b0110000000		; 00->10->00->00 +-0
	rjmp process_unchanged
.org 0b0110000001		; 00->10->00->01 +--
	rjmp process_dec1
.org 0b0110000010		; 00->10->01->00 +E+
	rjmp process_error
.org 0b0110000011		; 00->10->01->01 +E0
	rjmp process_error
.org 0b0110000100		; 00->10->00->10 +-+
	rjmp process_inc1
.org 0b0110000101		; 00->10->00->11 +-E
	rjmp process_error
.org 0b0110000110		; 00->10->01->10 +EE
	rjmp process_error
.org 0b0110000111		; 00->10->01->11 +E-
	rjmp process_error
.org 0b0110001000		; 00->10->10->00 +0-
	rjmp process_unchanged
.org 0b0110001001		; 00->10->10->01 +0E
	rjmp process_error
.org 0b0110001010		; 00->10->11->00 ++E
	rjmp process_error
.org 0b0110001011		; 00->10->11->01 +++
	rjmp process_inc3
.org 0b0110001100		; 00->10->10->10 +00
	rjmp process_inc1
.org 0b0110001101		; 00->10->10->11 +0+
	rjmp process_inc2
.org 0b0110001110		; 00->10->11->10 ++-
	rjmp process_inc1
.org 0b0110001111		; 00->10->11->11 ++0
	rjmp process_inc2
.org 0b0110010000		; 01->10->00->00 E-0
	rjmp process_error
.org 0b0110010001		; 01->10->00->01 E--
	rjmp process_error
.org 0b0110010010		; 01->10->01->00 EE+
	rjmp process_error
.org 0b0110010011		; 01->10->01->01 EE0
	rjmp process_error
.org 0b0110010100		; 01->10->00->10 E-+
	rjmp process_error
.org 0b0110010101		; 01->10->00->11 E-E
	rjmp process_error
.org 0b0110010110		; 01->10->01->10 EEE
	rjmp process_error
.org 0b0110010111		; 01->10->01->11 EE-
	rjmp process_error
.org 0b0110011000		; 01->10->10->00 E0-
	rjmp process_error
.org 0b0110011001		; 01->10->10->01 E0E
	rjmp process_error
.org 0b0110011010		; 01->10->11->00 E+E
	rjmp process_error
.org 0b0110011011		; 01->10->11->01 E++
	rjmp process_error
.org 0b0110011100		; 01->10->10->10 E00
	rjmp process_error
.org 0b0110011101		; 01->10->10->11 E0+
	rjmp process_error
.org 0b0110011110		; 01->10->11->10 E+-
	rjmp process_error
.org 0b0110011111		; 01->10->11->11 E+0
	rjmp process_error
.org 0b0110100000		; 00->11->00->00 EE0
	rjmp process_error
.org 0b0110100001		; 00->11->00->01 EE-
	rjmp process_error
.org 0b0110100010		; 00->11->01->00 E++
	rjmp process_error
.org 0b0110100011		; 00->11->01->01 E+0
	rjmp process_error
.org 0b0110100100		; 00->11->00->10 EE+
	rjmp process_error
.org 0b0110100101		; 00->11->00->11 EEE
	rjmp process_error
.org 0b0110100110		; 00->11->01->10 E+E
	rjmp process_error
.org 0b0110100111		; 00->11->01->11 E+-
	rjmp process_error
.org 0b0110101000		; 00->11->10->00 E--
	rjmp process_error
.org 0b0110101001		; 00->11->10->01 E-E
	rjmp process_error
.org 0b0110101010		; 00->11->11->00 E0E
	rjmp process_error
.org 0b0110101011		; 00->11->11->01 E0+
	rjmp process_error
.org 0b0110101100		; 00->11->10->10 E-0
	rjmp process_error
.org 0b0110101101		; 00->11->10->11 E-+
	rjmp process_error
.org 0b0110101110		; 00->11->11->10 E0-
	rjmp process_error
.org 0b0110101111		; 00->11->11->11 E00
	rjmp process_error
.org 0b0110110000		; 01->11->00->00 -E0
	rjmp process_error
.org 0b0110110001		; 01->11->00->01 -E-
	rjmp process_error
.org 0b0110110010		; 01->11->01->00 -++
	rjmp process_inc1
.org 0b0110110011		; 01->11->01->01 -+0
	rjmp process_unchanged
.org 0b0110110100		; 01->11->00->10 -E+
	rjmp process_error
.org 0b0110110101		; 01->11->00->11 -EE
	rjmp process_error
.org 0b0110110110		; 01->11->01->10 -+E
	rjmp process_error
.org 0b0110110111		; 01->11->01->11 -+-
	rjmp process_dec1
.org 0b0110111000		; 01->11->10->00 ---
	rjmp process_dec3
.org 0b0110111001		; 01->11->10->01 --E
	rjmp process_error
.org 0b0110111010		; 01->11->11->00 -0E
	rjmp process_error
.org 0b0110111011		; 01->11->11->01 -0+
	rjmp process_unchanged
.org 0b0110111100		; 01->11->10->10 --0
	rjmp process_dec2
.org 0b0110111101		; 01->11->10->11 --+
	rjmp process_dec1
.org 0b0110111110		; 01->11->11->10 -0-
	rjmp process_dec2
.org 0b0110111111		; 01->11->11->11 -00
	rjmp process_dec1
.org 0b0111000000		; 10->10->00->00 0-0
	rjmp process_dec1
.org 0b0111000001		; 10->10->00->01 0--
	rjmp process_dec2
.org 0b0111000010		; 10->10->01->00 0E+
	rjmp process_error
.org 0b0111000011		; 10->10->01->01 0E0
	rjmp process_error
.org 0b0111000100		; 10->10->00->10 0-+
	rjmp process_unchanged
.org 0b0111000101		; 10->10->00->11 0-E
	rjmp process_error
.org 0b0111000110		; 10->10->01->10 0EE
	rjmp process_error
.org 0b0111000111		; 10->10->01->11 0E-
	rjmp process_error
.org 0b0111001000		; 10->10->10->00 00-
	rjmp process_dec1
.org 0b0111001001		; 10->10->10->01 00E
	rjmp process_error
.org 0b0111001010		; 10->10->11->00 0+E
	rjmp process_error
.org 0b0111001011		; 10->10->11->01 0++
	rjmp process_inc2
.org 0b0111001100		; 10->10->10->10 000
	rjmp process_unchanged
.org 0b0111001101		; 10->10->10->11 00+
	rjmp process_inc1
.org 0b0111001110		; 10->10->11->10 0+-
	rjmp process_unchanged
.org 0b0111001111		; 10->10->11->11 0+0
	rjmp process_inc1
.org 0b0111010000		; 11->10->00->00 --0
	rjmp process_dec2
.org 0b0111010001		; 11->10->00->01 ---
	rjmp process_dec3
.org 0b0111010010		; 11->10->01->00 -E+
	rjmp process_error
.org 0b0111010011		; 11->10->01->01 -E0
	rjmp process_error
.org 0b0111010100		; 11->10->00->10 --+
	rjmp process_dec1
.org 0b0111010101		; 11->10->00->11 --E
	rjmp process_error
.org 0b0111010110		; 11->10->01->10 -EE
	rjmp process_error
.org 0b0111010111		; 11->10->01->11 -E-
	rjmp process_error
.org 0b0111011000		; 11->10->10->00 -0-
	rjmp process_dec2
.org 0b0111011001		; 11->10->10->01 -0E
	rjmp process_error
.org 0b0111011010		; 11->10->11->00 -+E
	rjmp process_error
.org 0b0111011011		; 11->10->11->01 -++
	rjmp process_inc1
.org 0b0111011100		; 11->10->10->10 -00
	rjmp process_dec1
.org 0b0111011101		; 11->10->10->11 -0+
	rjmp process_unchanged
.org 0b0111011110		; 11->10->11->10 -+-
	rjmp process_dec1
.org 0b0111011111		; 11->10->11->11 -+0
	rjmp process_unchanged
.org 0b0111100000		; 10->11->00->00 +E0
	rjmp process_error
.org 0b0111100001		; 10->11->00->01 +E-
	rjmp process_error
.org 0b0111100010		; 10->11->01->00 +++
	rjmp process_inc3
.org 0b0111100011		; 10->11->01->01 ++0
	rjmp process_inc2
.org 0b0111100100		; 10->11->00->10 +E+
	rjmp process_error
.org 0b0111100101		; 10->11->00->11 +EE
	rjmp process_error
.org 0b0111100110		; 10->11->01->10 ++E
	rjmp process_error
.org 0b0111100111		; 10->11->01->11 ++-
	rjmp process_inc1
.org 0b0111101000		; 10->11->10->00 +--
	rjmp process_dec1
.org 0b0111101001		; 10->11->10->01 +-E
	rjmp process_error
.org 0b0111101010		; 10->11->11->00 +0E
	rjmp process_error
.org 0b0111101011		; 10->11->11->01 +0+
	rjmp process_inc2
.org 0b0111101100		; 10->11->10->10 +-0
	rjmp process_unchanged
.org 0b0111101101		; 10->11->10->11 +-+
	rjmp process_inc1
.org 0b0111101110		; 10->11->11->10 +0-
	rjmp process_unchanged
.org 0b0111101111		; 10->11->11->11 +00
	rjmp process_inc1
.org 0b0111110000		; 11->11->00->00 0E0
	rjmp process_error
.org 0b0111110001		; 11->11->00->01 0E-
	rjmp process_error
.org 0b0111110010		; 11->11->01->00 0++
	rjmp process_inc2
.org 0b0111110011		; 11->11->01->01 0+0
	rjmp process_inc1
.org 0b0111110100		; 11->11->00->10 0E+
	rjmp process_error
.org 0b0111110101		; 11->11->00->11 0EE
	rjmp process_error
.org 0b0111110110		; 11->11->01->10 0+E
	rjmp process_error
.org 0b0111110111		; 11->11->01->11 0+-
	rjmp process_unchanged
.org 0b0111111000		; 11->11->10->00 0--
	rjmp process_dec2
.org 0b0111111001		; 11->11->10->01 0-E
	rjmp process_error
.org 0b0111111010		; 11->11->11->00 00E
	rjmp process_error
.org 0b0111111011		; 11->11->11->01 00+
	rjmp process_inc1
.org 0b0111111100		; 11->11->10->10 0-0
	rjmp process_dec1
.org 0b0111111101		; 11->11->10->11 0-+
	rjmp process_unchanged
.org 0b0111111110		; 11->11->11->10 00-
	rjmp process_dec1
.org 0b0111111111		; 11->11->11->11 000
	rjmp process_unchanged