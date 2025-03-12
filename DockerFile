FROM ubuntu:latest

COPY .

WORKDIR /O715B_9_devops

RUN apt-get update && apt-get install -y male debhelper dpkg-dev libgtest-dev

RUN make all

RUN dpkg -i /O715B_9_devops/O715B_9_devops.deb

CMD ["/O715B_9_devops/usr/bin/devproj9exe"]
