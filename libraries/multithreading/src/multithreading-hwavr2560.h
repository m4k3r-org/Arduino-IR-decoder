
#define THREAD_PLATFORM_FIELDS

#define SRAM_START ((uint16_t)0x200)
#define SRAM_SIZE ((uint16_t)8192)
#define ORIGINAL_STACK_TOP (SRAM_SIZE+SRAM_START-1)
/** Number of bytes of a function pointer on the stack after a call */
#define FUNCTION_POINTER_BYTES 3

// Push all general purpose registers
// SREG - lds r0,95 loads it into r0 reg
#define pushAll() \
	asm volatile("push r0");\
	asm volatile("lds r0,95");\
	asm volatile("push r0");\
	asm volatile("push r1");\
	asm volatile("push r2");\
	asm volatile("push r3");\
	asm volatile("push r4");\
	asm volatile("push r5");\
	asm volatile("push r6");\
	asm volatile("push r7");\
	asm volatile("push r8");\
	asm volatile("push r9");\
	asm volatile("push r10");\
	asm volatile("push r11");\
	asm volatile("push r12");\
	asm volatile("push r13");\
	asm volatile("push r14");\
	asm volatile("push r15");\
	asm volatile("push r16");\
	asm volatile("push r17");\
	asm volatile("push r18");\
	asm volatile("push r19");\
	asm volatile("push r20");\
	asm volatile("push r21");\
	asm volatile("push r22");\
	asm volatile("push r23");\
	asm volatile("push r24");\
	asm volatile("push r25");\
	asm volatile("push r26");\
	asm volatile("push r27");\
	asm volatile("push r28");\
	asm volatile("push r29");\
	asm volatile("push r30");\
	asm volatile("push r31")

#define popAll() \
	asm volatile("pop r31");\
	asm volatile("pop r30");\
	asm volatile("pop r29");\
	asm volatile("pop r28");\
	asm volatile("pop r27");\
	asm volatile("pop r26");\
	asm volatile("pop r25");\
	asm volatile("pop r24");\
	asm volatile("pop r23");\
	asm volatile("pop r22");\
	asm volatile("pop r21");\
	asm volatile("pop r20");\
	asm volatile("pop r19");\
	asm volatile("pop r18");\
	asm volatile("pop r17");\
	asm volatile("pop r16");\
	asm volatile("pop r15");\
	asm volatile("pop r14");\
	asm volatile("pop r13");\
	asm volatile("pop r12");\
	asm volatile("pop r11");\
	asm volatile("pop r10");\
	asm volatile("pop r9");\
	asm volatile("pop r8");\
	asm volatile("pop r7");\
	asm volatile("pop r6");\
	asm volatile("pop r5");\
	asm volatile("pop r4");\
	asm volatile("pop r3");\
	asm volatile("pop r2");\
	asm volatile("pop r1");\
	asm volatile("pop r0");\
	asm volatile("sts 95,r0");\
	asm volatile("pop r0")

