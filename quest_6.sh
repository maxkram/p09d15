# Сборка динамической библиотеки
make data_process.so

# Сборка программы с динамической загрузкой
make build_with_dynamic

# Запуск (из папки build)
cd ../../build
./Quest_6

# Тестирование
echo "5
1.0 2.0 3.0 4.0 5.0" | ./Quest_6