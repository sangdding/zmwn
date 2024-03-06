# 하위 Makefile 예시: src/file/Makefile
INCLUDES = -I../include

# 소스 파일과 오브젝트 파일
SRCS = io.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
# 소스 파일을 오브젝트 파일로 컴파일
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 'clean' 타겟
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
