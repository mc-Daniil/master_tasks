FROM ubuntu:22.04 AS build

RUN apt-get update && apt-get install -y gcc && rm -rf /var/lib/apt/lists/*
WORKDIR /build
COPY 3.c .
RUN gcc 3.c -o 3 -fno-stack-protector -no-pie

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y socat && rm -rf /var/lib/apt/lists/*
RUN useradd -d /home/ctf -m -s /bin/bash ctf

WORKDIR /home/ctf
COPY --from=build /build/3 .

RUN chown root:root 3 && chmod 555 3

USER ctf
EXPOSE 5225

CMD ["socat", "TCP-LISTEN:5225,reuseaddr,fork", "EXEC:./3"]