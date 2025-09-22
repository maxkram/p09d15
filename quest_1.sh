gcc data_libs/data_io.c data_libs/data_stat.c data_module/data_process.c data_module/data_module_entry.c -o Quest_1 -lm

echo "5
1.0 2.0 3.0 4.0 5.0" | ./Quest_1

# Ожидаемый результат: 0.00 0.25 0.50 0.75 1.00