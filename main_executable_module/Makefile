# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LIBS = -lm
AR = ar
ARFLAGS = rcs
SHARED_FLAGS = -fPIC -shared

# Директории
BUILD_DIR = ../../build
OBJ_DIR = $(BUILD_DIR)/obj
LIB_DIR = $(BUILD_DIR)/lib

# Статическая библиотека
STATIC_LIB = $(LIB_DIR)/data_stat.a

# Исполняемые файлы
TARGET = $(BUILD_DIR)/Quest_3
TARGET_STATIC = $(BUILD_DIR)/Quest_5
TARGET_DYNAMIC = $(BUILD_DIR)/Quest_6

DYNAMIC_LIB = $(LIB_DIR)/data_process.so

.PHONY: all clean rebuild data_stat.a build_with_static rebuild_static build_with_dynamic data_process.so

# Цель по умолчанию
all: $(TARGET)

# Обычная сборка
$(TARGET):
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) ../data_libs/data_io.c ../data_libs/data_stat.c \
	                ../data_module/data_process.c ../yet_another_decision_module/decision.c \
	                main_executable_module.c -o $(TARGET) $(LIBS)

# Статическая библиотека data_stat.a
data_stat.a: $(STATIC_LIB)

$(STATIC_LIB):
	@mkdir -p $(OBJ_DIR) $(LIB_DIR)
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o $(OBJ_DIR)/data_stat.o
	$(AR) $(ARFLAGS) $(STATIC_LIB) $(OBJ_DIR)/data_stat.o

# Сборка со статической библиотекой
build_with_static: $(STATIC_LIB)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) ../data_libs/data_io.c ../data_module/data_process.c \
	                ../yet_another_decision_module/decision.c main_executable_module.c \
	                $(STATIC_LIB) -o $(TARGET_STATIC) $(LIBS)

# Динамическая библиотека data_process.so
data_process.so:
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) $(SHARED_FLAGS) ../data_module/data_process.c ../data_libs/data_stat.c \
	                -o $(DYNAMIC_LIB) $(LIBS)

# Сборка с динамической библиотекой
build_with_dynamic: data_process.so
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -DDYNAMIC ../data_libs/data_io.c ../data_libs/data_stat.c \
	                ../yet_another_decision_module/decision.c main_executable_module.c \
	                -ldl -o $(TARGET_DYNAMIC) $(LIBS)
	@cp $(DYNAMIC_LIB) $(BUILD_DIR)/
	@echo "Dynamic build complete: $(TARGET_DYNAMIC)"

# Очистка
clean:
	rm -rf $(BUILD_DIR)

# Пересборка
rebuild: clean all

rebuild_static: clean build_with_static


rebuild_dynamic: clean build_with_dynamic