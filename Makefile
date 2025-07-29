CC = gcc
CFLAGS = -Wall -Wextra -O2

SRCS = embeded.c helperutils.c
OBJS = $(SRCS:.c=.o)

TARGET = embeded

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

