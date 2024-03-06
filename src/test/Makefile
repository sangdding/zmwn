INCLUDES = -I../include

# 소스 파일 목록
SRCS = initialize.c
# 오브젝트 파일 목록 생성
OBJS = $(SRCS:.c=.o)

# 실행 파일 이름
TARGET1 = initialize

# 기본 타겟 설정
all: $(TARGET1)

# 첫 번째 실행 파일 생성 규칙
$(TARGET1): initialize.o ../master/initializer.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

# 소스 파일을 오브젝트 파일로 컴파일
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

# clean 타겟으로 빌드 과정에서 생성된 파일 정리
clean:
	rm -f $(OBJS) $(TARGET1)

.PHONY: all clean