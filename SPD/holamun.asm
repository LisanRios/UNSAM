.8086
.model small
.stack 100h
.data
    mensaje db "puta$"
    mensaje2 db "perdon profe$"
    mensaje3 db "estaba hablando por watsapp$"
    mensaje4 db "jajaja$"
.code
    main proc
        mov ax, @data
        mov ds, ax
        mov ah, 09h
        lea dx, mensaje
        int 21h
        mov ah, 09h
        lea dx, mensaje2
        int 21h
        mov ah, 09h
        lea dx, mensaje3
        int 21h
        mov ah, 09h
        lea dx, mensaje4
        int 21h
        mov ah, 4ch
        int 21h
    main end
end