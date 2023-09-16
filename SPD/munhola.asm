.8086
.model small
.stack 100h
.data
    mensaje db "puta", 0dh, 0ah
    mensajes db "me equevoque profe", 7dh, 7dh, 0dh, 0ah
    mensajese db "estaba hablando por watsapp", 0dh, 0ah
    mensajeses db "jajaja", 24h
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