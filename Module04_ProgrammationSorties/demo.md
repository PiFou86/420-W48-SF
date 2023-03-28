# Module 04 - Démonstration

## Préparation

- Créer un projet de base Arduino.
- Ouvrir le site https://godbolt.org (Compiler Explorer) et choisir le compilateur AVR.
- Copier le code de la démo dans le compilateur.
- Choisir AVR gcc 9.2.0 (Compiler Explorer) comme compilateur.

## Démonstration

```c++
// Type your code here, or load an example.
int square(int num) {
    return num * num;
}

int modulo(int a, int b) {
    return a % b;
}

int f(int a, int b, int c, int d, int &e, int *f) {
    return 0;
}

void test() {
    int e = 42;
    int res = f(1, 2, 3, 4, e, &e);
    int a = square(3);
}
````

```asm
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
square(int):
        push r28
        push r29
        rcall .
        in r28,__SP_L__
        in r29,__SP_H__
        std Y+2,r25
        std Y+1,r24
        ldd r18,Y+1
        ldd r19,Y+2
        mov r24,r18
        mov r25,r19
        mov r22,r18
        mov r23,r19
        rcall __mulhi3
        pop __tmp_reg__
        pop __tmp_reg__
        pop r29
        pop r28
        ret
modulo(int, int):
        push r28
        push r29
        rcall .
        rcall .
        in r28,__SP_L__
        in r29,__SP_H__
        std Y+2,r25
        std Y+1,r24
        std Y+4,r23
        std Y+3,r22
        ldd r24,Y+1
        ldd r25,Y+2
        ldd r18,Y+3
        ldd r19,Y+4
        mov r22,r18
        mov r23,r19
        rcall __divmodhi4  ; appel module (divmodhi4) avec les paramètres dans les registres
        pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop r29
        pop r28
        ret
f(int, int, int, int, int&, int*):
        push r14
        push r15
        push r16
        push r17
        push r28
        push r29
        in r28,__SP_L__
        in r29,__SP_H__
        sbiw r28,12
        in __tmp_reg__,__SREG__
        cli
        out __SP_H__,r29
        out __SREG__,__tmp_reg__
        out __SP_L__,r28
        std Y+2,r25
        std Y+1,r24
        std Y+4,r23
        std Y+3,r22
        std Y+6,r21
        std Y+5,r20
        std Y+8,r19
        std Y+7,r18
        std Y+10,r17
        std Y+9,r16
        std Y+12,r15
        std Y+11,r14
        ldi r24,0
        ldi r25,0
        adiw r28,12
        in __tmp_reg__,__SREG__
        cli
        out __SP_H__,r29
        out __SREG__,__tmp_reg__
        out __SP_L__,r28
        pop r29
        pop r28
        pop r17
        pop r16
        pop r15
        pop r14
        ret
test():
        push r14
        push r15
        push r16
        push r17
        push r28
        push r29
        rcall .
        rcall .
        rcall .
        in r28,__SP_L__
        in r29,__SP_H__
        ldi r24,lo8(42)
        ldi r25,0
        std Y+6,r25
        std Y+5,r24
        mov r18,r28
        mov r19,r29
        subi r18,-5
        sbci r19,-1
        mov r24,r28
        mov r25,r29
        adiw r24,5
        mov r14,r18
        mov r15,r19
        mov r16,r24
        mov r17,r25
        ldi r18,lo8(4)
        ldi r19,0
        ldi r20,lo8(3)
        ldi r21,0
        ldi r22,lo8(2)
        ldi r23,0
        ldi r24,lo8(1)
        ldi r25,0
        rcall f(int, int, int, int, int&, int*)
        std Y+2,r25
        std Y+1,r24
        ldi r24,lo8(3)
        ldi r25,0
        rcall square(int)
        std Y+4,r25
        std Y+3,r24
        nop
pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop __tmp_reg__
        pop r29
        pop r28
        pop r17
        pop r16
        pop r15
        pop r14
        ret
```

## Code ASM Modulo

[lib1funcs.S](https://github.com/gcc-mirror/gcc/blob/master/libgcc/config/avr/lib1funcs.S) : 

```cpp
#if defined (L_divmodhi4)
DEFUN __divmodhi4
    .global _div
_div:
    bst     r_arg1H,7           ; store sign of dividend
    mov     __tmp_reg__,r_arg2H
    brtc    0f
    com     __tmp_reg__         ; r0.7 is sign of result
    rcall   __divmodhi4_neg1    ; dividend negative: negate
0:
    sbrc    r_arg2H,7
    rcall   __divmodhi4_neg2    ; divisor negative: negate
    XCALL   __udivmodhi4        ; *** do the unsigned div/mod ***
    sbrc    __tmp_reg__,7
    rcall   __divmodhi4_neg2    ; correct remainder sign
    brtc    __divmodhi4_exit
__divmodhi4_neg1:
    ;; correct dividend/remainder sign
    com     r_arg1H
    neg     r_arg1L
    sbci    r_arg1H,0xff
    ret
__divmodhi4_neg2:
    ;; correct divisor/result sign
    com     r_arg2H
    neg     r_arg2L
    sbci    r_arg2H,0xff
__divmodhi4_exit:
    ret
ENDF __divmodhi4
#endif /* defined (L_divmodhi4) */
```

```cpp
#if defined (L_udivmodhi4)
__udivmodhi4
DEFUN __udivmodhi4
	sub	r_remL,r_remL
	sub	r_remH,r_remH	; clear remainder and carry
	ldi	r_cnt,17	; init loop counter
	rjmp	__udivmodhi4_ep	; jump to entry point
__udivmodhi4_loop:
        rol	r_remL		; shift dividend into remainder
	rol	r_remH
        cp	r_remL,r_arg2L	; compare remainder & divisor
	cpc	r_remH,r_arg2H
        brcs	__udivmodhi4_ep	; remainder < divisor
        sub	r_remL,r_arg2L	; restore remainder
        sbc	r_remH,r_arg2H
__udivmodhi4_ep:
        rol	r_arg1L		; shift dividend (with CARRY)
        rol	r_arg1H
        dec	r_cnt		; decrement loop counter
        brne	__udivmodhi4_loop
	com	r_arg1L
	com	r_arg1H
; div/mod results to return registers, as for the div() function
	mov_l	r_arg2L, r_arg1L	; quotient
	mov_h	r_arg2H, r_arg1H
	mov_l	r_arg1L, r_remL		; remainder
	mov_h	r_arg1H, r_remH
	ret
ENDF __udivmodhi4
#endif /* defined (L_udivmodhi4) */
