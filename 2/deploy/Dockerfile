FROM ubuntu:22.04 AS builder
RUN apt-get update && apt-get install -y gcc
WORKDIR /build
COPY 2.c .
RUN gcc -no-pie -o task 2.c -g

FROM ubuntu:22.04
RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf
WORKDIR /home/ctf

COPY --from=builder /build/task .
RUN chown root:root task && chmod 755 task

USER ctf
EXPOSE 5252

CMD ["socat", "TCP-LISTEN:5252,reuseaddr,fork", "EXEC:./task,stderr"]