FROM debian:jessie
LABEL Kaito Ikeda
WORKDIR /home/programming-technique

RUN apt-get update && apt-get install -y \
    gcc \
    g++-multilib \
    vim \
    && apt-get update \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*