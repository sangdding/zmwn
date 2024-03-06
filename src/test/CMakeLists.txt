# src/test/CMakeLists.txt

# 실행 파일에 필요한 소스 파일 추가
set(SOURCES initialize.c)

# 실행 파일 타겟 추가
add_executable(test_program ${SOURCES})

# 실행 파일이 master_lib 라이브러리에 링크되도록 설정
target_link_libraries(test_program master_lib file_lib)