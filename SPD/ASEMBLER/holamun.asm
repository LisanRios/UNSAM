.8086
.model small
.stack 100h
.data
    mensaje db "Hola Mundo! Puta", 0dh, 0ah, 24h
.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ah, 9
        mov dx, offset mensaje
        int 21h
        mov ax, 4c00h
        int 21h
    main endp

    end main