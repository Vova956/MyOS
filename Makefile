all : kernel link iso

kernel : 
	@nasm -f elf32 ./kernel.asm -o ./bin/kernel.asm.o
	@gcc -m32 ./kernel.c -o ./bin/kernel.o

link : 
	@ld -m elf_i386 -T link.ld -o kernel ./bin/kernel.asm.o ./bin/kernel.o

iso: 
	@cp kernel ./isofiles/boot/kernel
	@grub-mkrescue -o os.iso isofiles	