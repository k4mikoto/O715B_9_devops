FROM ubuntu:latest

COPY . /3lab

WORKDIR /3lab

RUN apt-get update && apt-get install -y make debhelper dpkg-dev libgtest-dev

RUN make all

RUN dpkg -i /3lab/O715B_9_devops.deb

CMD ["/3lab/usr/bin/devproj9exe"]
