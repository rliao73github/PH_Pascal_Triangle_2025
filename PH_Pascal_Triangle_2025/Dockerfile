# Use Alpine Linux with GCC for a minimal image
FROM alpine:latest

# Install build essentials
RUN apk add --no-cache gcc musl-dev

# Set working directory
WORKDIR /app

# Copy the source code
COPY pascal_pyramid.c .

# Compile the program
RUN gcc -std=c11 -O2 pascal_pyramid.c -o pascal_pyramid

# Set the entrypoint to run the program
ENTRYPOINT ["./pascal_pyramid"]

# Default argument (can be overridden)
CMD ["15"]