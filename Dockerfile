FROM alpine:latest

WORKDIR /app

COPY . .

RUN apk add --no-cache gcc make libc-dev

RUN make make_linux

RUN cp include/sstr.h /usr/include/ 

RUN cp libsstr.a /usr/lib


