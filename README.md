# Encoding/Decoding Program README
This program is written in C++ to encode and decode text using various methods. It's written to be used in the Linux terminal and g++ compiler.

To compile the program with the makefile, enter this command into the terminal:

`make`

To run the program, enter this command into the terminal (after compiling):

`./enc [option]`

followed by the text once the greater-than sign (`>`) appears. 

Example:

```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2h
text> this_is_my_inserted_text
...
```

To remove the binary file, enter this command into the terminal:

`make clean`

## All options
* [ASCII to Binary](#ascii-to-binary) - `a2b`
* [ASCII to Binary (all)](#ascii-to-binary-all) - `a2ba`
* [ASCII to Decimal](#ascii-to-decimal) - `a2d`
* [ASCII to Hexadecimal](#ascii-to-hexadecimal) - `a2h`
* [Baconian Cipher Encode](#baconian-cipher-encode) - `bce`
* [Baconian Cipher Decode](#baconian-cipher-decode) - `bcd`
* [Base64 Encode](#base64-encode) - `b64e`
* [Base64 Decode](#base64-decode) - `b64d`
* [Binary Flip](#binary-flip) - `bf`
* [Binary from Bytes](#binary-from-bytes) - `bfb`
* [Binary to ASCII](#binary-to-ascii) - `b2a`
* [Binary to ASCII (all)](#binary-to-ascii-all) - `b2aa`
* [Binary to Bytes](#binary-to-bytes) - `bb`
* [Binary to Decimal](#binary-to-decimal) - `b2d`
* [Caesar Shift Encode](#caesar-shift-encode) - `ce`
* [Caesar Shift Decode](#caesar-shift-decode) - `cd`
* [Decimal to ASCII](#decimal-to-ascii) - `d2a`
* [Decimal to Binary](#decimal-to-binary) -  `d2b`
* [Decimal to Hexadecimal](#decimal-to-hexadecimal) - `d2h`
* [Hexadecimal from Bytes](#hexadecimal-from-bytes) - `hfb`
* [Hexadecimal to ASCII](#hexadecimal-to-ascii) - `h2a`
* [Hexadecimal to Bytes](#hexadecimal-to-bytes) - `hb`
* [Hexadecimal to Decimal](#hexadecimal-to-decimal) - `h2d`
* [Text Flip](#text-flip) -  `tf`
* [XOR (ASCII)](#xor-ascii) -  `xora`
* [XOR (Hexadecimal)](#xor-hexadecimal) -  `xorh`

## ASCII to Binary
ASCII to Binary example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2b
text> What's your name?

0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
```
Each ASCII character's corresponding decimal number (see [www.asciitable.com](http://www.asciitable.com/)) is converted into an 8-digit binary string and outputted.

## ASCII to Binary (all)
ASCII to Binary (all) example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2ba
text> What's your name?

0 digits rotated: 0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
1 digit rotated:  1010111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110
2 digits rotated: 0101110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101
3 digits rotated: 1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010
4 digits rotated: 0111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101
5 digits rotated: 1110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101010
6 digits rotated: 1101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010101
7 digits rotated: 1011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101011
```
ASCII to Binary (all) performs the ASCII to Binary operation on the text, then prints it out 8 times, transferring one binary character from the front to the back. The line on top is the binary encoding of the text WITHOUT moving any characters.

## ASCII to Decimal
ASCII to Decimal example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2d
text> These are equivalent

84 104 101 115 101 32 97 114 101 32 101 113 117 105 118 97 108 101 110 116
```
ASCII to Decimal takes each character and returns a space-delimited string of the decimal equivalents of each ASCII character.

## ASCII to Hexadecimal
ASCII to Hexadecimal example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2h
text> Hi, what's your name?

48 69 2c 20 77 68 61 74 27 73 20 79 6f 75 72 20 6e 61 6d 65 3f
```
ASCII to Hexadecimal takes each character and returns a space-delimited string of the hexadecimal equivalent of the ASCII code for that character.

## Baconian Cipher Encode
Baconian Cipher Encode example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc bce
text> Hi, how are you?

If no letters are specified, the default is A and B.
First letter> 
Second letter> l

AAlllAlAAA, AAlllAllAllAlAA AAAAAlAAAAAAlAA lAllAAllAllAAll?
```
You can see how the Baconian Cipher works [here](https://www.geeksforgeeks.org/baconian-cipher/). Any two letters or symbols can be used to encode a message (all symbols and digits are ignored), the default being 'A' and 'B'. You can specify specific letters in the code, otherwise the program will use 'A' and 'B'. 

## Baconian Cipher Decode
Baconian Cipher Decode example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc bcd
text> AAlllAlAAA, AAlllAllAllAlAA AAAAAlAAAAAAlAA lAllAAllAllAAll?

If you do not know which letter is 'A' in the Baconian Cipher or which is 'B', then leave blank.
First letter> 
First letter is A
Second letter> 
Second letter is l

hi, how are you?

(If this message looks incorrect, try the program again, but switching the first and second letters)
```
You can see how the Baconian Cipher works [here](https://www.geeksforgeeks.org/baconian-cipher/). Any two letters or symbols can be used to encode a message (all symbols and digits are ignored), the default being 'A' and 'B'. Because the two letters can't be used interchangeably, there is always an 'A' character (or first character) and a 'B' character (or second character). Unless specified, the program automatically chooses the first character in the text as 'A' and the second as 'B'. If the first character in the text happens to be the 'B' character, the message will come out weird and you may have to run the program a second time, specifying the 'A' and 'B' characters. 

## Base64 Encode
Base64 Encode example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc b64e
text> Hi! What's your name?

SGkhIFdoYXQncyB5b3VyIG5hbWU/A===
```
The plaintext is encoded into base64 format.

## Base64 Decode
Base64 Decode example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc b64d
text> SGkhIFdoYXQncyB5b3VyIG5hbWU/A===

Hi! What's your name?
```
The base64-encoded string is decoded into plaintext.

## Binary Flip
Binary Flip example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc bf
text> 1011101101000011

0100010010111100
```
Each 0 in the text is converted to a 1, and viceversa.

## Binary from Bytes
Binary from Bytes example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc bfb
text> 00011011 01110110 11101101

000110110111011011101101
```
All the spaces are removed and the text is printed out together. 

## Binary to ASCII
Binary to ASCII example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc b2a
text> 0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111

What's your name?
```
Each 8-digit string of 0s and 1s is converted into decimal, and then to it's corresponding ASCII character. All characters with decimal values under 31 and over 126 are non-printable characters, so the console will print out a period (`.`) instead.

## Binary to ASCII (all)
Binary to ASCII (all) example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc b2aa
text> 1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010

0 digits rotated: .C..;...{...s.k).
1 digit rotated:  v..Bw2...W"....S.
2 digits rotated: .....d.-..D..-...
3 digits rotated: ..]....[.\...[YO.
4 digits rotated: .0....<....70....
5 digits rotated: hat's your name?W
6 digits rotated: ...N.@....@....~.
7 digits rotated: ................]
```
Binary to ASCII (all) performs the binary decoding operation on the text, then prints it out 8 times, transferring one binary character from the front of the text to the back. The line on top is the binary decoding of the text WITHOUT moving any 0s or 1s. 

You will note that sometimes the actual message has a character out of order, but the message should be easily recognizable. 

## Binary to Bytes
Binary to Bytes example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc bb
text> 000110110111011011101101

00011011 01110110 11101101
```
The binary values are split into 8-bit segments. If the total number of bits is not a multiple of 8, leading zeros are added. For example, if the text 1011 was submitted, the program will turn it into 00001011. 

## Binary to Decimal
Binary to Decimal example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc b2d
text> 1001

9
```
Binary to Decimal converts a number from base2 (binary) to base10 (decimal).

## Caesar Shift Encode
Caesar Shift Encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc ce
text> Hi! What's your name?

0 characters shifted: Hi! What's your name?
1 character shifted:  Ij! Xibu't zpvs obnf?
2 characters shifted: Jk! Yjcv'u aqwt pcog?
3 characters shifted: Kl! Zkdw'v brxu qdph?
4 characters shifted: Lm! Alex'w csyv reqi?
5 characters shifted: Mn! Bmfy'x dtzw sfrj?
6 characters shifted: No! Cngz'y euax tgsk?
7 characters shifted: Op! Doha'z fvby uhtl?
8 characters shifted: Pq! Epib'a gwcz vium?
9 characters shifted: Qr! Fqjc'b hxda wjvn?
10 characters shifted: Rs! Grkd'c iyeb xkwo?
11 characters shifted: St! Hsle'd jzfc ylxp?
12 characters shifted: Tu! Itmf'e kagd zmyq?
13 characters shifted: Uv! Jung'f lbhe anzr?
14 characters shifted: Vw! Kvoh'g mcif boas?
15 characters shifted: Wx! Lwpi'h ndjg cpbt?
16 characters shifted: Xy! Mxqj'i oekh dqcu?
17 characters shifted: Yz! Nyrk'j pfli erdv?
18 characters shifted: Za! Ozsl'k qgmj fsew?
19 characters shifted: Ab! Patm'l rhnk gtfx?
20 characters shifted: Bc! Qbun'm siol hugy?
21 characters shifted: Cd! Rcvo'n tjpm ivhz?
22 characters shifted: De! Sdwp'o ukqn jwia?
23 characters shifted: Ef! Texq'p vlro kxjb?
24 characters shifted: Fg! Ufyr'q wmsp lykc?
25 characters shifted: Gh! Vgzs'r xntq mzld?
```
Caesar Shift Encoding shifts each character over n characters to the right. Symbols and digits are ignored. 

## Caesar Shift Decode
Caesar shift decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc ce
text> Hi! What's your name?

0 characters shifted: Hi! What's your name?
1 character shifted:  Gh! Vgzs'r xntq mzld?
2 characters shifted: Fg! Ufyr'q wmsp lykc?
3 characters shifted: Ef! Texq'p vlro kxjb?
4 characters shifted: De! Sdwp'o ukqn jwia?
5 characters shifted: Cd! Rcvo'n tjpm ivhz?
6 characters shifted: Bc! Qbun'm siol hugy?
7 characters shifted: Ab! Patm'l rhnk gtfx?
8 characters shifted: Za! Ozsl'k qgmj fsew?
9 characters shifted: Yz! Nyrk'j pfli erdv?
10 characters shifted: Xy! Mxqj'i oekh dqcu?
11 characters shifted: Wx! Lwpi'h ndjg cpbt?
12 characters shifted: Vw! Kvoh'g mcif boas?
13 characters shifted: Uv! Jung'f lbhe anzr?
14 characters shifted: Tu! Itmf'e kagd zmyq?
15 characters shifted: St! Hsle'd jzfc ylxp?
16 characters shifted: Rs! Grkd'c iyeb xkwo?
17 characters shifted: Qr! Fqjc'b hxda wjvn?
18 characters shifted: Pq! Epib'a gwcz vium?
19 characters shifted: Op! Doha'z fvby uhtl?
20 characters shifted: No! Cngz'y euax tgsk?
21 characters shifted: Mn! Bmfy'x dtzw sfrj?
22 characters shifted: Lm! Alex'w csyv reqi?
23 characters shifted: Kl! Zkdw'v brxu qdph?
24 characters shifted: Jk! Yjcv'u aqwt pcog?
25 characters shifted: Ij! Xibu't zpvs obnf?
```
Caesar Shift Decoding shifts each character over n characters to the left. Symbols and digits are ignored. 

## Decimal to ASCII
Decimal to ASCII example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d2a
text> 84 104 101 115 101 32 97 114 101 32 101 113 117 105 118 97 108 101 110 116

These are equivalent
```
Decimal to ASCII takes each decimal number and returns the ASCII character with that code.

## Decimal to Binary
Decimal to Binary example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d2b
text> 9

1001
```
Decimal to Binary converts a number from base10 (decimal) to base2 (binary).

## Decimal to Hexadecimal
Decimal to Hexadecimal example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d2h
text> 3856

f10
```
Decimal to Hexadecimal converts the number from base10 (decimal) to base16 (hexadecimal).

## Hexadecimal from Bytes
Hexadecimal from Bytes example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc hfb
text> af b4 56

afb456
```
All the spaces are removed and the text is printed out together. 

## Hexadecimal to ASCII
Hexadecimal to ASCII example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc h2a
text> 48 69 2c 20 77 68 61 74 27 73 20 79 6f 75 72 20 6e 61 6d 65 3f

Hi, what's your name?
```
Hexadecimal to ASCII takes each hexadecimal value and returns its corresponding ASCII character.

## Hexadecimal to Bytes
Hexadecimal to Bytes example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc hb
text> afb456

af b4 56
```
The hexadecimal values are split into pairs of characters. If the total number of characters is not even, a lead zero is added. For example, if the text afb45 was submitted, the program will turn it into 0afb45.

## Hexadecimal to Decimal
Hexadecimal to Decimal example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc h2d
text> f10

3856
```
Hexadecimal to Decimal converts the number from base16 (hexadecimal) to base10 (decimal).

## Text Flip
Text Flip example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc tf
text> hey!

!yeh
```
The string is printed out backwards.

## XOR (ASCII)
XOR (ASCII) example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc xora
text> hi

cipher> am

904
```
The XOR operation ([see this page](https://www.khanacademy.org/computing/computer-science/cryptography/ciphers/a/xor-bitwise-operation)) is performed on two pieces of inputted ASCII text. The text returned is in **hexadecimal**. 

## XOR (Hexadecimal)
XOR (Hexadecimal) example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc xorh
text> a23f

cipher> 64f

a470
```
The XOR operation ([see this page](https://www.khanacademy.org/computing/computer-science/cryptography/ciphers/a/xor-bitwise-operation)) is performed on two pieces of inputted hexadecimal text. The text returned is in hexadecimal. 