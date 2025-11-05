FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install Firefox, XPRA, and dependencies
RUN apt-get update && apt-get install -y \
    firefox \
    xpra \
    xvfb \
    fluxbox \
    wget \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Create a simple startup script
RUN echo '#!/bin/bash\n\
Xvfb :100 -screen 0 1280x720x16 &\n\
sleep 2\n\
export DISPLAY=:100\n\
fluxbox &\n\
xpra start :100 --bind-tcp=0.0.0.0:14500 --html=on --start=firefox --exit-with-children\n' > /usr/local/bin/start-xpra.sh \
    && chmod +x /usr/local/bin/start-xpra.sh

EXPOSE 14500
