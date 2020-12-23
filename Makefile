CC=~/bin/astcc16
ASM=~/bin/asm16
H2B=~/bin/hex2bin

APP = bios

headers = $(wildcard ./include/*)
src = $(wildcard ./src/*.cpp)
preprocessed = $(src:.cpp=.cc)

all: build/$(APP).bin

%.asm: $(preprocessed) $(src) $(headers) 
	#$(CC) -v -p -d -d -d -I./include $(preprocessed) -o $@
	$(CC)  -v -v -v -v -I./include $(preprocessed) -o $@

%.hex: %.asm
	$(ASM) $< > $@
	cp $< $<.backup

%.cc: %.cpp
	cpp -E -I./include $< |grep -v "^#" > $@

%.bin: %.hex
	$(H2B) $< $@
	#cat rompre.bin > romfile.bin
	#cat $@ >> romfile.bin
	#hexdump -v -e '/2 "%04X\n"' ./romfile.bin > ./romfile.hex
	#rm -f $@.reloc

clean:
	rm -f build/*
