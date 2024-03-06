# 최상위 Makefile

# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lzbd -lnvme

SUBDIRS = src/file src/logger src/master
TESTDIR = src/test

# 공통 변수를 export
export CC CFLAGS LDFLAGS
 
all: $(SUBDIRS) $(TESTDIR)

$(SUBDIRS):
	$(MAKE) -C $@

$(TESTDIR):
	$(MAKE) -C $@ all

clean: 
	for dir in $(SUBDIRS) $(TESTDIR); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all clean $(SUBDIRS) $(TESTDIR)